#include"../prj.lab/dynarr/dynarr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("dynarr ctor") {
	DynArr arr_def;
	CHECK_EQ(arr_def.size(), 0);
	const int size = 5;
	DynArr arr_s(size);
	CHECK_EQ(arr_s[0], 0);
	CHECK_EQ(arr_s.size(), size);
	CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr op") {
	const int size = 5;
	DynArr arr1(size);
	CHECK_EQ(arr1[0], 0);
	CHECK_EQ(arr1[arr1.size() - 1], 0);
	CHECK_THROWS(arr1[-1]);
	CHECK_THROWS(arr1[arr1.size()]);
}

TEST_CASE("check") {
	DynArr da(4);
	CHECK_EQ(da.size(), 4);
	da.Resize(3);
	CHECK_EQ(da.size(), 3);
	da[2] = 2.2f;
	float x = da[2];
	DynArr da2 = da;
	CHECK_EQ(x, 2.2f);
	CHECK_EQ(da2[2], da[2]);
	CHECK_FALSE(&da2[2] == &da[2]);
	CHECK_THROWS(da.Resize(-1));
//	CHECK_THROWS(da.Resize(0));
	CHECK_THROWS(DynArr(-1));
};




TEST_CASE("Testing constructors + destructor + operator=") {
	SUBCASE("Testing Default Constructor") {
		DynArr mas;
		CHECK(mas.size() == 0);
		CHECK(mas.capacity() == 0);
	}
	SUBCASE("Testing Copy Constructor") {
		DynArr mas;
		mas.Resize(10);
		mas.Resize(15);
		mas.Resize(7);
		DynArr mas_2(mas);
		CHECK(mas.size() == mas_2.size());
		CHECK(mas.capacity() == mas_2.capacity());
		CHECK(mas == mas_2);
	}


	SUBCASE("Testing Constructor with argument") {
		DynArr mas(10);
		CHECK(mas.capacity() == 10);
		CHECK(mas.size() == 10);
		for (size_t i = 0; i < mas.capacity(); i++) {
			CHECK(mas[i] == 0);
		}
	}
}
TEST_CASE("Resize") {
	DynArr a(10);
	for (size_t i = 0; i < 10; i++) {
		a[i] = i;
	}


	a.Resize(15);
	CHECK((a.capacity() == 15 && a.size() == 15));
	for (size_t i = 10; i < 15; i++) {
		CHECK(a[i] == 0);
	}
	a.Resize(8);
	CHECK((a.capacity() == 15 && a.size() == 8));
	a.Resize(10);
	CHECK((a.capacity() == 15 && a.size() == 10));
	CHECK(a[9] == 0);

}

TEST_CASE("operator []") {
	DynArr a(10);
	CHECK_THROWS(a[-1]);
	CHECK_THROWS(a[11]);
};




