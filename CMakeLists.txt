cmake_minimum_required(VERSION 3.28)

set(SRC_DIRECTORY src)

project(lightning-am LANGUAGES CXX)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})

find_package(fmt REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(pugixml CONFIG REQUIRED)
find_package(unordered_dense CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

add_library(definitionsOfTranslation ${SRC_DIRECTORY}/definitionsOfTranslation.cpp)
target_include_directories(definitionsOfTranslation PRIVATE ${SRC_DIRECTORY})

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_compile_options(definitionsOfTranslation PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_link_libraries(definitionsOfTranslation PRIVATE fmt::fmt)
target_link_libraries(definitionsOfTranslation PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(definitionsOfTranslation PRIVATE unordered_dense::unordered_dense)
target_link_libraries(definitionsOfTranslation PRIVATE pugixml::shared pugixml::pugixml)

add_executable(${PROJECT_NAME} ${SRC_DIRECTORY}/main.cpp)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIRECTORY})
target_link_libraries(${PROJECT_NAME} PRIVATE definitionsOfTranslation)

target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE pugixml::shared pugixml::pugixml)
