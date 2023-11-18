// 2022 by Polevoi Dmitry under Unlicense
#ifndef COMPLEX_COMPLEX_HPP_20231113
#define COMPLEX_COMPLEX_HPP_20231113
#include<iostream>

struct Complex {

	Complex() = default;
	Complex(double re, double img);
	Complex(double re);
	~Complex() = default;

	double real{ 0 };
	double imaginary{ 0.0 };

	static const char Start_Symbol = '{';
	static const char Middle_Division = ',';
	static const char Finish_Symbol = '}';

	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	Complex& operator+=(double rhs);
	Complex& operator-=(double rhs);
	Complex& operator*=(double rhs);
	Complex& operator/=(double rhs);

	/*double module();
	double argument();*/
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
std::ostream& operator<<(std::ostream& out, const Complex& z);
std::istream& operator>>(std::istream& in, Complex& z);
#endif // !COMPLEX_COMPLEX_HPP_20231113
