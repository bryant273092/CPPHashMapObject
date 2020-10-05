// HashMapTests.cpp
//
// ICS 45C Spring 2020
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided a few tests
// already, though I've commented them out, because they won't compile and
// link until you've implemented some things.
//
// Of course, you'll want to write lots more of these tests yourself, because
// this is an inexpensive way to know whether things are working the way
// you expect -- including scenarios that you won't happen to hit in the
// course of testing your overall program.  (You might also want to be sure
// that your HashMap implementation is complete and correct before you try
// to write the rest of the program around it, anyway; there's a very
// substantial amount of partial credit available if all that works is
// HashMap.)

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(HashMapTests, sizeOfNewlyCreatedHashMapIsZero)
{
   HashMap empty;
   ASSERT_EQ(0, empty.size());
}


TEST(HashMapTests, emptyMapContainsNoKeys)
{
   HashMap empty;
   ASSERT_FALSE(empty.contains("first"));
   ASSERT_FALSE(empty.contains("second"));
}


TEST(HashMapTests, containKeyAfterAddingIt)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   ASSERT_TRUE(hm.contains("Boo"));
}

// TEST(HashMapTests, getHashFunction)
// {
//     HashMap hm;
//     ASSERT_EQ(4, hm.callfunction());
// }

TEST(HashMapTests, rightbucketcount)
{
    HashMap hm;
    ASSERT_EQ(10, hm.bucketCount());
}
TEST(HashMapTests, addsnode)
{
    HashMap hm;
    hm.add("Bryant", "Password1234");
    ASSERT_TRUE(hm.contains("Bryant"));
}
TEST(HashMapTests, sizeofsinglehashmapisone)
{
    HashMap hm;
    hm.add("Bryant", "Password1234");
    ASSERT_EQ(1, hm.size());
}
TEST(HashMapTests, canGetCorrectValue)
{
    HashMap hm;
    hm.add("Bryant", "Password1234");
    ASSERT_EQ("Password1234", hm.value("Bryant"));
}
TEST(HashMapTests, canGetCorrectValue2)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   ASSERT_EQ("Password1234", hm.value("Bryant"));
   ASSERT_EQ("perfect", hm.value("Baoo"));
   ASSERT_EQ("Password1234", hm.value("Baryant"));
   ASSERT_EQ("perfect", hm.value("Booa"));
   ASSERT_EQ("Password1234", hm.value("Bryaant"));
   ASSERT_EQ("perfect", hm.value("aBoo"));
   ASSERT_EQ("Password1234", hm.value("aBryant"));
   ASSERT_EQ("perfect", hm.value("Bxoo"));
   ASSERT_EQ("Password1234", hm.value("Bxryant"));
   ASSERT_EQ("perfect", hm.value("Booc"));
}
TEST(HashMapTests, canGetCorrectValue3)
{
    HashMap hm;
    hm.add("Bryant", "Password1234");
    ASSERT_EQ("", hm.value("Bryantt"));
}
TEST(HashMapTests, sizeReturnedisone)
{
    HashMap hm;
    hm.add("Bryant", "Password1234");
    ASSERT_EQ(1, hm.size());
}
TEST(HashMapTests, sizeReturnediseleven)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   ASSERT_EQ(10, hm.size());
}
TEST(HashMapTests, pairisRemoved)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   ASSERT_TRUE(hm.remove("Bryant"));
   ASSERT_FALSE(hm.remove("Bryant"));
}
TEST(HashMapTests, nonexistpairisNotRemoved)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   ASSERT_FALSE(hm.remove("Brydhdant"));
}
TEST(HashMapTests, newpaircountafterremoval)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   hm.remove("Bryant");
   ASSERT_EQ(9, hm.size());
}
TEST(HashMapTests, correctMaxBucketCount)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   hm.add("aBoo", "perfect");
   hm.add("aBryant", "Password1234");
   hm.add("Bxoo", "perfect");
   hm.add("Bxryant", "Password1234");
   hm.add("Booc", "perfect");
   ASSERT_EQ(2, hm.maxBucketSize());
}
TEST(HashMapTests, canCopyConstruct)
{
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   HashMap hm2 = hm;
   hm.remove("Bryant");

   ASSERT_TRUE(hm2.contains("Bryant"));
   ASSERT_FALSE(hm.contains("Bryant"));
}

TEST(HashMApTests, canCopyAssign){
   HashMap hm;
   hm.add("Bryant", "Password1234");
   hm.add("Baoo", "perfect");
   hm.add("Baryant", "Password1234");
   hm.add("Booa", "perfect");
   hm.add("Bryaant", "Password1234");
   HashMap hm2;
   hm2.add("aBoo", "perfect");
   hm2.add("aBryant", "Password1234");
   hm2.add("Bxoo", "perfect");
   hm = hm2;
   ASSERT_EQ(10,hm.bucketCount());
   ASSERT_TRUE(hm.contains("aBoo"));
   ASSERT_TRUE(hm.contains("aBryant"));
   ASSERT_TRUE(hm.contains("Bxoo"));
   
   

   ASSERT_FALSE(hm.contains("Bryant"));
   ASSERT_FALSE(hm.contains("Baoo"));
   ASSERT_FALSE(hm.contains("Baryant"));
   ASSERT_FALSE(hm.contains("Booa"));
   ASSERT_FALSE(hm.contains("Bryaant"));
}
unsigned int default_f(const std::string& key){
    int f = 39;
    int hash = 0; 
    for (unsigned int i = 0 ; i < key.length() ; i++){
        hash = f * hash + int(key.at(i));
    }
   return hash;

}
TEST(HashMApTests, canArbHashFunction){
   HashMap::HashFunction newnew = default_f;
   HashMap hm(newnew);
   ASSERT_EQ(10, hm.bucketCount());
   hm.add("Bryant", "Password1234");
   ASSERT_TRUE(hm.contains("Bryant"));
}
TEST(HashMapTests, rightvalues)
{
    HashMap hm;
    hm.add("thornton@ics.uci.edu", "abcdefg");
    hm.add("boo@thornton.com", "sleeping");
    hm.add("boo@thornton.com", "playing");
    ASSERT_TRUE(hm.contains("thornton@ics.uci.edu"));
    ASSERT_TRUE(hm.contains("boo@thornton.com"));

}
