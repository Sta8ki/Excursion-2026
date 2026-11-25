<<<<<<< HEAD
=======
cmake_minimum_required(VERSION 3.16)
project(ExcursionSystem LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(lib)
add_executable(excursion_app src/main.cpp)
target_link_libraries(excursion_app PRIVATE ExcursionLibrary)
>>>>>>> 322914110e38a9e234228460b44fa2534d94592d
