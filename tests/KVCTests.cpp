#include "KVC.h"
#include "gtest/gtest.h"

TEST(KVCTest, KVCAddTest)
{
    KVC<std::string, int> a;
    a["ggg"] = 5;
    a["mmm"] = 6;
    a["sss"] = 7;

    EXPECT_EQ(a["ggg"], 5);
    EXPECT_EQ(a["mmm"], 6);
    EXPECT_EQ(a["sss"], 7);
}

TEST(KVCTest, KVCChangeTest)
{
    KVC<std::string, int> a;
    a["ggg"] = 5;
    EXPECT_EQ(a["ggg"], 5);
    a["ggg"] = 6;
    EXPECT_EQ(a["ggg"], 6);
}

TEST(KVCTest, KVCCopyTest)
{
    KVC<std::string, int> a;
    a["gg"] = 5;
    a["hh"] = 6;
    a["ss"] = 7;
    KVC<std::string, int> b(a);

    EXPECT_EQ(b["gg"], 5);
    EXPECT_EQ(b["gg"], a["gg"]);

    EXPECT_EQ(b["hh"], 6);
    EXPECT_EQ(b["hh"], a["hh"]);

    EXPECT_EQ(b["ss"], 7);
    EXPECT_EQ(b["ss"], a["ss"]);

    b["ss"] = 10;
    EXPECT_EQ(b["ss"], 10);
    EXPECT_EQ(a["ss"], 7);
}