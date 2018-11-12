#include <gtest/gtest.h>
#include "net.h"

TEST(NET,GIVEN_NET_WHEN_LETTER_NOT_IN_THEN_RETURN_FALSE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "teeth";

    net n(s,4);
    EXPECT_NE(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_T_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "t";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_TE_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "te";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_TH_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "th";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_TA_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "ta";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_EER_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "eer";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_PEER_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "peer";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_CAT_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "cat";

    net n(s,4);
    EXPECT_EQ(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTER_IS_HEI_THEN_RETURN_TRUE)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    string letter = "hei";

    net n(s,4);
    EXPECT_NE(true,n.in_net(letter));
}

TEST(NET,GIVEN_NET_WHEN_LETTERS_THEN_RETURN_RESULT)
{
    string s[4] = {
        "teca",
        "heht",
        "eerx",
        "phzm",
    };
    
    net n(s,4);

    string letter;
    letter = "teeth";
    EXPECT_NE(true,n.in_net(letter));
    letter = "peer";
    EXPECT_EQ(true,n.in_net(letter));
    letter = "cat";
    EXPECT_EQ(true,n.in_net(letter));
    letter = "hei";
    EXPECT_NE(true,n.in_net(letter));
}
