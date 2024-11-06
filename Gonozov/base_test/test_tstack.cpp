#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(120));
}

TEST(TStack, can_push_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.push(5));
}

TEST(TStack, integrity_of_the_stack_contents)
{
	TStack<int> st(5);
	st.push(5);
	EXPECT_EQ(1, st.pop() == 5);
}

TEST(TStack, cant_to_push_to_an_overflowing_stack)
{
	TStack<int> st(100);
	for (int i = 0; i < 100; i++)
	{
		st.push(i);
	}
	ASSERT_ANY_THROW(st.push(6));
}

TEST(TStack, checking_empty_stack)
{
	TStack<int> st(5);
	EXPECT_EQ(1, st.empty());
}

TEST(TStack, cant_to_pop_to_an_empty_stack)
{
	TStack<int> st(10);
	ASSERT_ANY_THROW(st.pop());
}
