#include "gtest.h"
#include "tqueue.h"

TEST(Tqueue, can_create_queue)
{
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(TQueue, push_and_front) 
{
    Queue<int> q(5);
    q.push(1);
    ASSERT_EQ(q.front(), 1);
    q.push(2);
    ASSERT_EQ(q.front(), 1);
    q.push(3);
    ASSERT_EQ(q.front(), 1);
}

TEST(TQueue, pop_and_front) 
{
    Queue<int> q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    ASSERT_EQ(q.front(), 2);
    q.pop();
    ASSERT_EQ(q.front(), 3);
}

TEST(TQueue, empty_and_full) 
{
    Queue<int> q(2);
    ASSERT_TRUE(q.empty());
    ASSERT_FALSE(q.full());
    q.push(1);
    ASSERT_FALSE(q.empty());
    ASSERT_FALSE(q.full());
    q.push(2);
    ASSERT_FALSE(q.empty());
    ASSERT_TRUE(q.full());
}

TEST(TQueue, size) 
{
    Queue<int> q(3);
    ASSERT_EQ(q.size(), 0);
    q.push(1);
    ASSERT_EQ(q.size(), 1);
    q.push(2);
    ASSERT_EQ(q.size(), 2);
    q.pop();
    ASSERT_EQ(q.size(), 1);
}

TEST(TQueue, clear) 
{
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.clear();
    ASSERT_TRUE(q.empty());
    ASSERT_EQ(q.size(), 0);
}

TEST(TQueue, push_full_exception) 
{
    Queue<int> q(2);
    q.push(1);
    q.push(2);
    ASSERT_ANY_THROW(q.push(3));
}

TEST(TQueue, pop_empty_exception) 
{
    Queue<int> q(2);
    ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, front_empty_exception) 
{
    Queue<int> q(2);
    ASSERT_ANY_THROW(q.front());
}

TEST(TQueue, circular_behavior) 
{
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);
    ASSERT_EQ(q.front(), 2);
    q.pop();
    ASSERT_EQ(q.front(), 3);
    q.pop();
    ASSERT_EQ(q.front(), 4);
}

TEST(TQueue, many_pushes_and_pops) {
    Queue<int> q(100);
    for (int i = 0; i < 1000; ++i) {
        q.push(i);
        if (q.size() > q.get_capacity() / 2) { 
            q.pop();
        }
    }
    ASSERT_EQ(q.size(), q.get_capacity() / 2); 
}