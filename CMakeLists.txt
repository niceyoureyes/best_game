cmake_minimum_required(VERSION 2.8)
add_definitions(--std=c++11)
# Set up your project name.
project(template)
# Set up the main source folder.
set(SOURCE_ROOT src)
# Scan source folder to find all sources and put the result to SRC_LIST.
aux_source_directory(${SOURCE_ROOT} SRC_LIST)
# Create executable by SRC_LIST.
add_executable(${PROJECT_NAME} ${SRC_LIST})
