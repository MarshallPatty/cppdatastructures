include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(ListTests ListTests.cpp)
target_link_libraries(ListTests PRIVATE GTest::GTest DataStructures)
add_test(ListTests ListTests)

add_executable(PriorityQueueTests PriorityQueueTests.cpp)
target_link_libraries(PriorityQueueTests PRIVATE GTest::GTest DataStructures)
add_test(PriorityQueueTests PriorityQueueTests)
