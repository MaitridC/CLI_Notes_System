cmake_minimum_required(VERSION 3.10)

# Project
project(Notes VERSION 1.0 DESCRIPTION "Notes Management System" LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/third_party
)

# All source files
file(GLOB SOURCE_FILES "src/main/*.cpp")

# Create executable
add_executable(Notes ${SOURCE_FILES})

# Link JSON library (nlohmann_json)
find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(Notes PRIVATE nlohmann_json::nlohmann_json)
