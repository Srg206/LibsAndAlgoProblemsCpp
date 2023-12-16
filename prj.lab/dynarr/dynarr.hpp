#ifndef DYNARR_HPP
#define DYNARR_HPP
#include<iostream>


class DynArr {
public:
	DynArr()=default;
	DynArr( const DynArr &arr);
	DynArr(size_t s);
	~DynArr();

	DynArr& operator=(const DynArr& arr);
	
	size_t size();
	size_t capacity();
	void Resize(size_t s);
	const float& operator[](size_t idx) const;
	float& operator[](size_t idx);

private:
	size_t size_ = 0;
	size_t capacity_ = 0;
	float* data_ = nullptr;

};

bool operator==(DynArr& a, DynArr& b);


#endif // !DYNARR_HPP
