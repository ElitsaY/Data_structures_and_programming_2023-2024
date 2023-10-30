add_executable(myapp)

set_target_properties(myapp PROPERTIES OUTPUT_NAME "myapp")

target_include_directories(
    myapp
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/data_structures
)

target_link_libraries(
	myapp
	PRIVATE
        datastructureslib
)

target_sources(
	myapp
	PRIVATE
		main.cpp
)