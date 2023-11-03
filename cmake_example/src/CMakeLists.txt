add_subdirectory(math)

add_executable(app)

target_sources(app
    PRIVATE
    main.cpp
)

target_link_libraries(app
    fmath
)

set_target_properties(app PROPERTIES OUTPUT_NAME "sdp_homework")