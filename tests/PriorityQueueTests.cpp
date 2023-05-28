#include <gtest/gtest.h>
#include <ds/priorityqueue.h>

TEST(PriorityQueueTests, TestPop) {
    int size = 100;
    DS::PriorityQueue<int> pq = DS::PriorityQueue<int>();
    for (int i = size; i > 0; i--) {
        pq.push(i);
    }

    for (int i = 1; i <= size; i++) {
        EXPECT_EQ(pq.pop(), i);
    }
}
