#include"../prj.lab/dynarr/dynarr.hpp"

DynArr::DynArr(const DynArr& arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_ = new float[capacity_];
	for (size_t i = 0; i < capacity_; i++)
	{
		data_[i] = arr.data_[i];
	}
}

DynArr::DynArr(size_t s) {
	size_ = s;
	capacity_ = s;
	data_ = new float[s];
	for (size_t i = 0; i < s; i++) {
		data_[i] = 0;
	}
}

DynArr::~DynArr() {
	delete[] data_;
	data_ = nullptr;
}

DynArr& DynArr::operator=(const DynArr& arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_ = nullptr;
	data_ = new float[capacity_];
	for (size_t i = 0; i < capacity_; i++)
	{
		data_[i] = arr.data_[i];
	}
	return *this;
}

size_t DynArr::size() {
	return size_;
}

size_t DynArr::capacity() {
	return capacity_;
}

void DynArr::Resize(size_t s) {
	if (s < size_) {
		for (size_t i = s; i < size_; i++) {
			data_[i] = 0;
		}
		size_ = s;
	}
	else if (s <= capacity_) {
		for (size_t i = size_; i < s; i++) {
			data_[i] = 0;
		}
		size_ = s;
	}
	else if (s > capacity_) {
		float* tmp = new float[size_];
		for (size_t i = 0; i < size_; i++) {
			tmp[i] = data_[i];
		}
		data_ = new float[s];
		for (size_t i = 0; i < s; i++) {
			if (i < size_) {
				data_[i] = tmp[i];
			}
			else {
				data_[i] = 0;
			}
		}
		delete[] tmp;
		tmp = nullptr;
		size_ = s;
		capacity_ = s;
	}

}

const float& DynArr::operator[](size_t idx)const {
	if (idx >= size_) {
		throw std::exception("Index is out of Array !!!");
	}
	else {
		return data_[idx];
	}
}
float& DynArr::operator[](size_t idx) {
	if (idx >= size_) {
		throw std::exception("Index is out of Array !!!");
	}
	else {
		return data_[idx];
	}
}

bool operator==(DynArr& a, DynArr& b) {
	bool flag = true;
	if (a.size() != b.size() || a.capacity() != b.capacity()) {
		flag = false;
	}
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			flag = false;
		}
	}

	return flag;
}