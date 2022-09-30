cmake_minimum_required(VERSION 3.15)

project(staller_test LANGUAGES CXX)

set(proj_name "staller_test")

set(source_dir ${PROJECT_SOURCE_DIR}/source)


add_subdirectory(${source_dir})

add_executable(${proj_name} StallerTest.cpp)

target_link_libraries(${proj_name} PRIVATE
  stallar
)

target_include_directories(${proj_name}  PUBLIC
  ${source_dir}
)