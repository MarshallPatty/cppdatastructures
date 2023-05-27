add_library(DataStructures ds_string.h ds_string.cpp ds_priorityqueue.h ds_list.h ds_linkedlist.h)

# state that anybody linking to us needs to include the current source dir
target_include_directories(DataStructures INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
