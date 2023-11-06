#include<iostream>
#include<cmath>
#include <sstream>
#include <string>

struct Complex {

	Complex()=default;
	Complex(double re, double img);
	Complex(double re);
	~Complex()=default;

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

	double module();
	double argument();
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
//=======================================================MAIN///////////////////////////////////////////////////////////
int main() {
	Complex a(1, 2);
	Complex b(2, 5);
	Complex c(1, 1);
	Complex d(0, 0);
	Complex q(1, 0);

	d = q + 5;
	std::cout << d;
	d = 5+q;
	std::cout << d;




	return 0;
}
//=======================================================MAIN///////////////////////////////////////////////////////////
Complex::Complex(double re, double img) {
	real = re; 
	imaginary = img;
}
Complex::Complex(double re) {
	real = re; 
	imaginary = 0;
}


Complex& Complex::operator+=(const Complex& rhs) {
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}

Complex& Complex::operator+=(double rhs) { 
	Complex a = Complex(rhs); 
	return operator+=(a); 
}


Complex& Complex::operator-=(const Complex& rhs) {
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}
Complex& Complex::operator-=(double rhs) {
	Complex a = Complex(rhs);
	return operator-=(a);
}


Complex& Complex::operator*=(const Complex& rhs) {
	double re = real;
	double img = imaginary;
	real = (re * rhs.real) - (img * rhs.imaginary);
	imaginary = (re * rhs.imaginary) + (img * rhs.real);
	return *this;
}

Complex& Complex::operator*=(double rhs) {
	Complex a = Complex(rhs);
	return operator*=(a);
}


Complex& Complex::operator/=(const Complex& rhs) {
	double del = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
	Complex tmp1(real, imaginary);
	Complex tmp2(rhs.real, -rhs.imaginary);
	tmp1 *= tmp2;
	real = tmp1.real / del;
	imaginary = tmp1.imaginary / del;
	return *this;
}

Complex& Complex::operator/=(double rhs) {
	Complex a = Complex(rhs);
	return operator/=(a);
}


//=============================================WITHOUT_ASSIGMENT==========////////////////////////////////////////
Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex res(lhs.real + rhs.real, lhs.imaginary + rhs.imaginary);
	return res;
}
Complex operator+(const Complex& lhs, const double rhs) { 
	Complex a(rhs); 
	return (lhs + a); 
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex res(lhs.real - rhs.real, lhs.imaginary - rhs.imaginary);
	return res;

}
Complex operator-(const Complex& lhs, const double rhs) {
	Complex a(rhs);
	return (lhs - a);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex tmp(lhs);
	tmp *= rhs;
	return tmp;
}
Complex operator*(const Complex& lhs, const double rhs) {
	Complex a(rhs);
	return (lhs * a);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex tmp(lhs);
	tmp /= rhs;
	return tmp;
}
Complex operator/(const Complex& lhs, const double rhs) {
	Complex a(rhs);
	return (lhs / a);
}


std::ostream& operator<<(std::ostream& out, const Complex& z) {
	std::ios_base::fmtflags oldflags = std::cout.flags();
	std::streamsize oldprecision = std::cout.precision();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);

	std::cout << "{" << z.real << ";" << z.imaginary << "}" << std::endl;

	std::cout.flags(oldflags);
	std::cout.precision(oldprecision);


	return out;
}
std::istream& operator>>(std::istream& in, Complex& z) {
	std::string str = " ";
	char left_bar(0);
	char semicolon(0);
	char letter_i(0);
	char right_bar(0);
	double re = 0;
	double im = 0;
	in >> left_bar >> re >> semicolon >> im >> right_bar;
	if (left_bar == z.Start_Symbol && semicolon == z.Middle_Division && right_bar == z.Finish_Symbol) {
		z.real = re;
		z.imaginary = im;
	}
	else {
		z.real = 0;
		z.imaginary = 0;
	}

	return in;
}


bool operator==(const Complex& lhs, const Complex& rhs) { 
	return (lhs.real == rhs.real && lhs.imaginary == rhs.imaginary); 
}

bool operator!=(const Complex& lhs, const Complex& rhs) { 
	return !(lhs == rhs);
}



double Complex::module() { 
	return sqrt(real * real + imaginary * imaginary); 
}
double Complex::argument() { 
	return acos(real / module()); 
}


