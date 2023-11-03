add_library(fmath STATIC)

target_sources(fmath
    PRIVATE
    fact.cpp
)

target_include_directories(fmath
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)