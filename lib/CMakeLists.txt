add_library(ExcursionLibrary
    src/Person.cpp
    src/Tourist.cpp
    src/Guide.cpp
)
target_include_directories(ExcursionLibrary PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)