#include"../prj.lab/dynarr/dynarr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"



TEST_CASE("Testing constructors + destructor + operator=") {
	SUBCASE("Testing Default Constructor") {
		DynArr mas;
		CHECK(mas.size()==0);
		CHECK(mas.capacity()==0);
	}
	SUBCASE("Testing Copy Constructor") {
		DynArr mas;
		/// <summary>
		/// ADD OPERATIONS WITH RESIZE 
		/// </summary>
		DynArr mas_2(mas);
		CHECK(mas.size() == mas_2.size());
		CHECK(mas.capacity() == mas_2.capacity());
		CHECK(mas==mas_2);
	}


	SUBCASE("Testing Constructor with argument") {
		DynArr mas(10);
		CHECK(mas.capacity() == 10);
		CHECK(mas.size() == 10);
		for (size_t i = 0; i < mas.capacity(); i++){
			CHECK(mas[i]==0);
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
}



