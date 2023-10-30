# Add a target for the unit tests
add_executable(test_data_structures)

target_link_libraries(
	test_data_structures
	PRIVATE
		Catch2::Catch2WithMain
		datastructureslib
)

# Currently all .cpp files are listed here.
# You may want to switch to a more flexible configuration if you work with a large number of packages/files
target_sources(
	test_data_structures
	PRIVATE
		data_structures/dynamic_array_test.cpp
)

target_include_directories(
	test_data_structures
	PRIVATE
	${CMAKE_SOURCE_DIR}/src/data_structures)
	

# Automatically register all tests
catch_discover_tests(test_data_structures)