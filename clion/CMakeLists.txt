cmake_minimum_required(VERSION 3.27)
project(clion)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (file IN LISTS files)
    get_filename_component(filename ${file} NAME_WE)
    add_executable(${filename} ${file})
    target_link_libraries(${filename} PRIVATE clang_rt.builtins-x86_64.lib)
endforeach ()