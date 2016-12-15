#include <iostream>
#include <engine/Engine.h>
#include <thread>


#include "state.hpp"
#include "net.h"
#include "http.h"
#include "endpoint.h"
#include "router.h"
#include <json/json.h>
#include "server/UserDB.h"

using namespace std;
using namespace instance;

int main(int argc,char* argv[])
{

Net::Port port(9080);

    int thr = 2;

    if (argc >= 2) {
        port = std::stol(argv[1]);

        if (argc == 3)
            thr = std::stol(argv[2]);
    }

    Net::Address addr(Net::Ipv4::any(), port);
    static constexpr size_t Workers = 4;

    cout << "Cores = " << hardware_concurrency() << endl;
    cout << "Using " << thr << " threads" << endl;

    auto server = std::make_shared<Net::Http::Endpoint>(addr);

    auto opts = Net::Http::Endpoint::options()
            .threads(thr)
            .flags(Net::Tcp::Options::InstallSignalHandler);
    server->init(opts);
    server->setHandler(Http::make_handler<MyHandler>());
    server->serve();

    //Init Node chain
    state::Node* n1 = new state::Node(0);
    n1->setPreviousNode(n1);
    state::Node* n2 = new state::Node(n1, 1);
    n1->setNextNode(n2);
    state::Node* n3 = new state::Node(n2, 2);
    n2->setNextNode(n3);
    state::Node* n4 = new state::Node(n3, 3);
    n3->setNextNode(n4);
    state::Node* n5 = new state::Node(n4, 4);
    n4->setNextNode(n5);
    state::Node* n6 = new state::Node(n5, 5);
    n5->setNextNode(n6);
    state::Node* n7 = new state::Node(n6, 6);
    n6->setNextNode(n7);
    state::Node* n8 = new state::Node(n7, 7);
    n7->setNextNode(n8);
    state::Node* n9 = new state::Node(n8, 8);
    n8->setNextNode(n9);
    n9->setNextNode(n9);

    //Init ElementList
    state::ElementList* e1 = new state::ElementList();

    //Init default state
    state::State* state = new state::State(e1, n1, 0);

    //Init default engine
    engine::Engine* engine = new engine::Engine();
    // first bool = aichar , second bool = aimonster, int = level AI
    //                                                      0 -> AI = RandomChoice
    //                                                      1 -> AI = RandomGoodChoice
    //                                                      2 -> AI = SmartChoice
    // abilities and items are configured in ElementList.cpp
    engine::Rules* rules = new engine::Rules(state, false, true, 1);
    engine->setRules(rules);
    engine->getRules()->setState(state);
    engine->getRules()->init();
    engine->turnInit(engine->getRules()->getTurnList()[0]);

    //Init Engine thread
    std::thread engThread(&engine::Engine::flush, engine);


    Application* FinalFantastique = new Application(state, engine);
    std::cout << std::to_string(e1->element.size()) << std::endl;

    FinalFantastique->play(state, engine);

    engThread.join();

    std::cout << "Shutdowning server" << std::endl;
    server->shutdown();

    return 0;
}

using namespace std;
using namespace Net;

struct PrintException {
    void operator()(std::exception_ptr exc) const {
        try {
            std::rethrow_exception(exc);
        } catch (const std::exception& e) {
            std::cerr << "An exception occurred: " << e.what() << std::endl;
        }
    }
};

server::UserDB* userdb = new server::UserDB;

class MyHandler : public Net::Http::Handler {

HTTP_PROTOTYPE(MyHandler);

    std::vector<Json::Value> commands;

    void onRequest(const Net::Http::Request& req, Net::Http::ResponseWriter response) {

        Rest::Router router;

        if (req.resource() == "/cmd") {
            if (req.method() == Net::Http::Method::Get) {

                using namespace Net::Http;

                int incr = 0;
                Json::Value jsonresponse;

                if (commands.size() > 0) {
                    for (auto i : commands) {
                        jsonresponse[std::to_string(incr)] = i;
                        ++incr;
                    }
                    Json::FastWriter json2str;
                    response.send(Net::Http::Code::Ok, json2str.write(jsonresponse));
                } else {
                    response.send(Net::Http::Code::Not_Found);
                }

            } else if (req.method() == Net::Http::Method::Put) {
                try {
                    Json::Reader str2json;
                    Json::Value jsoncommand;
                    str2json.parse(req.body(), jsoncommand);
                    commands.push_back(jsoncommand);
                    response.send(Net::Http::Code::Ok);
                } catch (int e) {
                    response.send(Net::Http::Code::Bad_Request);
                }
            }
        }

        Rest::Routes::Get(router, "/users/all", Rest::Routes::bind(&server::UserDB::getAllUsers, userdb));
        Rest::Routes::Get(router, "/users/:id", Rest::Routes::bind(&server::UserDB::getUser, userdb));
        Rest::Routes::Put(router, "/users/:id", Rest::Routes::bind(&server::UserDB::addOrModUser, userdb));
        Rest::Routes::Delete(router, "/users/:id", Rest::Routes::bind(&server::UserDB::removeUser, userdb));

    }

    void onTimeout(const Net::Http::Request& req, Net::Http::ResponseWriter response) {
        response
                .send(Net::Http::Code::Request_Timeout, "Timeout")
                .then([=](ssize_t) { }, PrintException());
    }

};


