add_library(datastructureslib STATIC)

set_target_properties(datastructureslib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(datastructureslib PROPERTIES LIBRARY_OUTPUT_NAME "datastructures.lib")

target_sources(
	datastructureslib
	PRIVATE
		dynamic_array.hpp
)