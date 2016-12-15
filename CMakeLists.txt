cmake_minimum_required (VERSION 3.5)
project (plt)

# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -std=c11   -pthread -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


# Generate headers
set(DIA2CODE "${PROJECT_SOURCE_DIR}/dia2code/bin/dia2code")
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl Ability,AbilityTypeID,SphereGrid,Item,Character,Element,Monster,ItemTypeID,CharacterTypeID,SphereGridTypeID,MonsterTypeID,ElementFactory,AElementAlloc,State,Observer,ElementList,ElementAlloc,Node,StateTypeID ../src/state.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl Application,Screen,FightUI,TargetUI,SpellUI,UI,Intro,Fight,Worldmap,Inn,Rules,Action ../src/instance.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl Renderer,IntroRenderer,FightRenderer,WorldmapRenderer,ElemSprite,InnRenderer,TextureSetter ../src/render.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl AI,SmartChoice,RandomChoice,RandomGoodChoice,ChoiceList ../src/ai.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl Rules,Command,Action,ActionTypeID,MoveInUI,Engine ../src/engine.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl User,UserDB ../src/server.dia)

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/res/jsoncpp/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/res/jsoncpp/dist/jsoncpp.cpp")

# pistache
include_directories (${PROJECT_SOURCE_DIR}/res/pistache/include)
file(GLOB HEADER_FILES "include/*.h")
file(GLOB pistache_sources "${PROJECT_SOURCE_DIR}/res/pistache/src/*.cpp")

#chilkat
include_directories ($PROJECT_SOURCE_DIR}/res/chilkat/include)

# Sources
file(GLOB_RECURSE main_sources src/*.cpp)

# Executables
add_executable(run ${main_sources} ${jsoncpp_sources} ${pistache_sources})

#chilkat
target_link_libraries(run ${PROJECT_SOURCE_DIR}/res/chilkat/lib/libchilkat-9.5.0.a)

# SFML
if(WIN32)
set(SFML_ROOT "D:/Utils/SFML-2.3")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules" ${CMAKE_MODULE_PATH})
else(WIN32)
SET(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
endif(WIN32)
find_package(SFML 2 COMPONENTS graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(run ${SFML_LIBRARIES})
endif()

