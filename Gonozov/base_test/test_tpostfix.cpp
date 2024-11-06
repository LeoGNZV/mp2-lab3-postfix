#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_Tpostfix)
{
	ASSERT_NO_THROW(TPostfix p("a + b"));
}

TEST(TPostfix, can_create_postfix)
{
	TPostfix p("a + (b - c) * ( b / d)");
	ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TPostfix, cant_create_empty_infix)
{
	TPostfix p("   ");
	ASSERT_ANY_THROW(p.ToPostfix());
}
TEST(TPostfix, cant_create_postfix)
{
	TPostfix p("a + (b + c) (*- b /d)");
	ASSERT_ANY_THROW(p.ToPostfix());
}

TEST(TPostfix, checking_calculations)
{
	TPostfix p("a + (b - c) * (b / d)");
	p.ToPostfix();
	map<char, double> values;
	values['a'] = 3;
	values['b'] = 6;
	values['c'] = 3;
	values['d'] = 2;
	EXPECT_EQ(12, p.Calculate(values));
}
TEST(TPostfix, checking_calculations_with_raise)
{
	TPostfix p("a + (b - c) + d ^ (b - d)");
	p.ToPostfix();
	map<char, double> values;
	values['a'] = 3;
	values['b'] = 6;
	values['c'] = 3;
	values['d'] = 2;
	EXPECT_EQ(22, p.Calculate(values));
}

TEST(TPostfix, checking_calculations_with_a_factorial)
{
	TPostfix p("a! + d! * (b / d)!");
	p.ToPostfix();
	map<char, double> values;
	values['a'] = 3;
	values['b'] = 6;
	values['c'] = 3;
	values['d'] = 2;
	EXPECT_EQ(18, p.Calculate(values));
}