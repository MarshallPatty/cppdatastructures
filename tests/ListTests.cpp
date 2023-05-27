#include <gtest/gtest.h>
#include <ds/list.h>

TEST(ListTests, FromArrayConstructor) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DS::List<int> list(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        EXPECT_EQ(nums[i], list[i]);
    }
}

TEST(ListTests, Appending) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DS::List<int> list = DS::List<int>();

    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        list.append(nums[i]);
    }

    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        EXPECT_EQ(nums[i], list[i]);
    }
}
