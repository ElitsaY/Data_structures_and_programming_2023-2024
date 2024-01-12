add_library(BinaryTree)

target_sources(BinaryTree
    PRIVATE
    BinaryTree.cpp
)

set_target_properties(BinaryTree PROPERTIES OUTPUT_NAME "K3_prepare")