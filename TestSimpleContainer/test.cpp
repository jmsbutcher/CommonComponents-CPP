#include "pch.h"

#include "../SimpleContainer/SimpleContainer.h"

using namespace std;



TEST(TestIntContainer, ReturnsOneItemByNameAndID) {
	SimpleContainer<int> c;
	c.Add(make_shared<int>(4), "Four");

	auto returnedByID = c.Get(0);
	EXPECT_EQ(*(returnedByID.get()), 4);

	auto returnedByName = c.Get("Four");
	EXPECT_EQ(*(returnedByID.get()), 4);
}


TEST(TestIntContainer, ReturnsTwoItemsByNameAndDefaultID) {
	SimpleContainer<int> c;
	c.Add(make_shared<int>(4), "Four");
	c.Add(make_shared<int>(99), "Ninety nine");

	auto returned99ByID = c.Get(1);
	EXPECT_EQ(*(returned99ByID.get()), 99);

	auto returned99ByName = c.Get("Ninety nine");
	EXPECT_EQ(*(returned99ByID.get()), 99);

	auto returned4ByID = c.Get(0);
	EXPECT_EQ(*(returned4ByID.get()), 4);

	auto returned4ByName = c.Get("Four");
	EXPECT_EQ(*(returned4ByID.get()), 4);
	
}


TEST(TestIntContainer, ReturnsTwoItemsBySpecifiedID) {
	SimpleContainer<int> c;
	c.Add(make_shared<int>(4), "Four", 5);
	c.Add(make_shared<int>(99), "Ninety nine", 6);

	auto returned99ByID = c.Get(6);
	EXPECT_EQ(*(returned99ByID.get()), 99);

	auto returned4ByID = c.Get(5);
	EXPECT_EQ(*(returned4ByID.get()), 4);
}


TEST(TestIntContainer, GetByInvalidIDThrowsException) {
	SimpleContainer<int> c;
	c.Add(make_shared<int>(4), "Four", 5);
	EXPECT_THROW(c.Get(0), std::out_of_range);
}

TEST(TestIntContainer, GetByInvalidNameThrowsException) {
	SimpleContainer<int> c;
	c.Add(make_shared<int>(4), "Four", 5);
	EXPECT_THROW(c.Get("five"), std::out_of_range);
}
