#include "BigInteger.h"
#include "gtest/gtest.h"

// =====================================================Creation tests=====================================================
// ========================================================================================================================

TEST(BigIntegerCreationTest, EmptyStringTest)
{
    try
    {
        BigInteger bi("");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Empty string")
        {
            SUCCEED();
        }
    }
}

TEST(BigIntegerCreationTest, NANTest)
{
    try
    {
        BigInteger bi("gggggg");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }

    try
    {
        BigInteger bi("hhhhh");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }

    try
    {
        BigInteger bi("w");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }

    try
    {
        BigInteger bi("12213gg");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }

    try
    {
        BigInteger bi("123g23");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }

    try
    {
        BigInteger bi("4242-242");
    }
    catch(std::invalid_argument error)
    {
        if(error.what() == "Argument is not a number")
        {
            SUCCEED();
        }
    }
}

// =====================================================Addition tests=====================================================
// ========================================================================================================================

TEST(BigIntegerCreationTest, IntTest)
{
    BigInteger b1(5);
    BigInteger b2("5");
    EXPECT_EQ(b1, b2);

    b1 = -67;
    b2 = BigInteger("-67");
    EXPECT_EQ(b1, b2);

    b1 = 0;
    b2 = BigInteger("0");
    EXPECT_EQ(b1, b2);
}

TEST(BigIntegerCreationTest, CloneTest)
{
    BigInteger b1("55");
    BigInteger b2(b1);
    EXPECT_EQ(b1, b2);

    b1 = BigInteger("-68");
    b2 = b1;
    EXPECT_EQ(b1, b2);
    b1 = BigInteger("0");
    b2 = b1;
    EXPECT_EQ(b1, b2);    
}

TEST(BigIntegerAdditionTest, AboveZeroAddAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("16");
    result = BigInteger("31");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("96");
    result = BigInteger("259");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("72304");
    result = BigInteger("106555");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("9426421942");
    EXPECT_EQ(b1 + b2, result);
}

TEST(BigIntegerAdditionTest, AboveZeroAddBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("-16");
    result = BigInteger("-1");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("-96");
    result = BigInteger("67");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("-72304");
    result = BigInteger("-38053");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("-6426371224");
    result = BigInteger("-3426320506");
    EXPECT_EQ(b1 + b2, result);    
}

TEST(BigIntegerAdditionTest, BelowZeroAddAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("16");
    result = BigInteger("1");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("96");
    result = BigInteger("-67");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("72304");
    result = BigInteger("38053");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("3426320506");
    EXPECT_EQ(b1 + b2, result); 
}

TEST(BigIntegerAdditionTest, BelowZeroAddBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("-16");
    result = BigInteger("-31");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("-96");
    result = BigInteger("-259");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("-72304");
    result = BigInteger("-106555");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("-6426371224");
    result = BigInteger("-9426421942");
    EXPECT_EQ(b1 + b2, result);
}

TEST(BigIntegerAdditionTest, ZeroAddAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("16");
    result = BigInteger("16");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("96");
    result = BigInteger("96");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("72304");
    result = BigInteger("72304");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("6426371224");
    result = BigInteger("6426371224");
    EXPECT_EQ(b1 + b2, result);
}

TEST(BigIntegerAdditionTest, ZeroAddBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("-16");
    result = BigInteger("-16");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-96");
    result = BigInteger("-96");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-72304");
    result = BigInteger("-72304");
    EXPECT_EQ(b1 + b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-6426371224");
    result = BigInteger("-6426371224");
    EXPECT_EQ(b1 + b2, result);
}

TEST(BigIntegerAdditionTest, ZeroAddZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("0");
    result = BigInteger("0");
    EXPECT_EQ(b1 + b2, result);
}

// ===================================================Substraktion tests===================================================
// ========================================================================================================================

TEST(BigIntegerSubstraktionTest, AboveZeroSubstractAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("16");
    result = BigInteger("-1");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("96");
    result = BigInteger("67");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("72304");
    result = BigInteger("-38053");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("-3426320506");
    EXPECT_EQ(b1 - b2, result);
}

TEST(BigIntegerSubstraktionTest, AboveZeroSubstractBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("-16");
    result = BigInteger("31");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("-96");
    result = BigInteger("259");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("-72304");
    result = BigInteger("106555");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("-6426371224");
    result = BigInteger("9426421942");
    EXPECT_EQ(b1 - b2, result);
}

TEST(BigIntegerSubstraktionTest, BelowZeroSubstractAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("16");
    result = BigInteger("-31");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("96");
    result = BigInteger("-259");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("72304");
    result = BigInteger("-106555");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("-9426421942");
    EXPECT_EQ(b1 - b2, result);
}

TEST(BigIntegerSubstraktionTest, BelowZeroSubstractBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("16");
    result = BigInteger("-31");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("96");
    result = BigInteger("-259");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("72304");
    result = BigInteger("-106555");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("-9426421942");
    EXPECT_EQ(b1 - b2, result); 
}

TEST(BigIntegerSubstraktionTest, ZeroSubstractAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("16");
    result = BigInteger("-16");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("96");
    result = BigInteger("-96");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("72304");
    result = BigInteger("-72304");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("6426371224");
    result = BigInteger("-6426371224");
    EXPECT_EQ(b1 - b2, result);
}

TEST(BigIntegerSubstraktionTest, ZeroSubstractBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("-16");
    result = BigInteger("16");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-96");
    result = BigInteger("96");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-72304");
    result = BigInteger("72304");
    EXPECT_EQ(b1 - b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-6426371224");
    result = BigInteger("6426371224");
    EXPECT_EQ(b1 - b2, result);
}

TEST(BigIntegerSubstraktionTest, ZeroSubstractZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("0");
    result = BigInteger("0");
    EXPECT_EQ(b1 - b2, result);
}

// ==================================================Multiplikation tests==================================================
// ========================================================================================================================

TEST(BigIntegerMultiplikationTest, AboveZeroMultiplyByAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("16");
    result = BigInteger("240");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("96");
    result = BigInteger("15648");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("72304");
    result = BigInteger("2476484304");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("19279439604695738832");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, AboveZeroMultiplyByBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("15");
    b2 = BigInteger("-16");
    result = BigInteger("-240");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("163");
    b2 = BigInteger("-96");
    result = BigInteger("-15648");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("34251");
    b2 = BigInteger("-72304");
    result = BigInteger("-2476484304");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("3000050718");
    b2 = BigInteger("-6426371224");
    result = BigInteger("-19279439604695738832");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, BelowZeroMultiplyByAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("16");
    result = BigInteger("-240");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("96");
    result = BigInteger("-15648");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("72304");
    result = BigInteger("-2476484304");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("6426371224");
    result = BigInteger("-19279439604695738832");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, BelowZeroMultiplyByBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("-15");
    b2 = BigInteger("-16");
    result = BigInteger("240");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-163");
    b2 = BigInteger("-96");
    result = BigInteger("15648");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-34251");
    b2 = BigInteger("-72304");
    result = BigInteger("2476484304");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("-3000050718");
    b2 = BigInteger("-6426371224");
    result = BigInteger("19279439604695738832");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, ZeroMultiplyByAboveZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("16");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("96");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("72304");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("6426371224");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, ZeroMultiplyByBelowZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("-16");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-96");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-72304");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);

    b1 = BigInteger("0");
    b2 = BigInteger("-6426371224");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);
}

TEST(BigIntegerMultiplikationTest, ZeroMultiplyByZeroTest)
{
    BigInteger b1;
    BigInteger b2;
    BigInteger result;
    
    b1 = BigInteger("0");
    b2 = BigInteger("0");
    result = BigInteger("0");
    EXPECT_EQ(b1 * b2, result);
}

// ====================================================Comparison tests====================================================
// ========================================================================================================================

TEST(BigIntegerComparisonTest, LessTest)
{
    BigInteger a;
    BigInteger b;

    a = 70;
    b = 90;
    EXPECT_TRUE(a < b);

    a = -70;
    EXPECT_TRUE(a < b);
    
    b = -90;
    EXPECT_TRUE(b < a);

    a = -90;
    EXPECT_FALSE(a < b);

    a = 0;
    EXPECT_TRUE(b < a);

    b = 0;
    EXPECT_FALSE(a < b);
}

TEST(BigIntegerComparisonTest, GreaterTest)
{
    BigInteger a;
    BigInteger b;

    a = 90;
    b = 70;
    EXPECT_TRUE(a > b);

    a = -90;
    EXPECT_FALSE(a > b);
    
    b = -70;
    EXPECT_TRUE(b > a);

    a = -70;
    EXPECT_FALSE(a > b);

    a = 0;
    EXPECT_FALSE(b > a);

    b = 0;
    EXPECT_FALSE(a > b);
}

TEST(BigIntegerComparisonTest, LessOrEqualTest)
{
    BigInteger a;
    BigInteger b;

    a = 70;
    b = 90;
    EXPECT_TRUE(a <= b);

    a = -70;
    EXPECT_TRUE(a <= b);
    
    b = -90;
    EXPECT_TRUE(b <= a);

    a = -90;
    EXPECT_TRUE(a <= b);

    a = 0;
    EXPECT_TRUE(b <= a);

    b = 0;
    EXPECT_TRUE(a <= b);
}

TEST(BigIntegerComparisonTest, GreaterOrEqualTest)
{
    BigInteger a;
    BigInteger b;

    a = 90;
    b = 70;
    EXPECT_TRUE(a >= b);

    a = -90;
    EXPECT_FALSE(a >= b);
    
    b = -70;
    EXPECT_TRUE(b >= a);

    a = -70;
    EXPECT_TRUE(a >= b);

    a = 0;
    EXPECT_FALSE(b >= a);

    b = 0;
    EXPECT_TRUE(a >= b);
}

TEST(BigIntegerComparisonTest, EqualTest)
{
    BigInteger a;
    BigInteger b;

    a = 90;
    b = 70;
    EXPECT_FALSE(a == b);

    a = -90;
    EXPECT_FALSE(a == b);
    
    b = -70;
    EXPECT_FALSE(a == b);

    a = -70;
    EXPECT_TRUE(a == b);

    a = 0;
    EXPECT_FALSE(a == b);

    b = 0;
    EXPECT_TRUE(a == b);
}

TEST(BigIntegerComparisonTest, UnEqualTest)
{
    BigInteger a;
    BigInteger b;

    a = 90;
    b = 70;
    EXPECT_TRUE(a != b);

    a = -90;
    EXPECT_TRUE(a != b);
    
    b = -70;
    EXPECT_TRUE(a != b);

    a = -70;
    EXPECT_FALSE(a != b);

    a = 0;
    EXPECT_TRUE(a != b);

    b = 0;
    EXPECT_FALSE(a != b);
}