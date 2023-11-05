#include<iostream>
#include<cmath>
#include <sstream>

class Complex {

public:
	Complex() {};
	Complex(double re, double img) { real = re; imaginary = img; };
	Complex(double re) { real = re; imaginary = 0; };
	Complex(const Complex& a) { real = a.real; imaginary = a.imaginary; };


	double real=0.0;
	double imaginary=0.0;
	const Complex& operator=(const Complex& rhs) { real = rhs.real; imaginary = rhs.imaginary; return *this; };
	Complex operator+=(Complex& rhs);
	Complex operator-=(Complex& rhs);
	Complex operator*=(Complex& rhs);
	Complex operator/=(Complex& rhs);

	Complex operator+=(double rhs) { Complex a = Complex(rhs); return operator+=(a); };
	Complex operator-=(double rhs) { Complex a = Complex(rhs); return operator-=(a); };
	Complex operator*=(double rhs) { Complex a = Complex(rhs); return operator*=(a); };
	Complex operator/=(double rhs) { Complex a = Complex(rhs); return operator/=(a); };

	double r() {return sqrt(real * real + imaginary * imaginary); };
	double angle_cos() { return real / r(); };


	void print();
};	

	Complex operator+(Complex& lhs, Complex& rhs);
	Complex operator-(Complex& lhs, Complex& rhs);
	Complex operator*(Complex& lhs, Complex& rhs);
	Complex operator/(Complex& lhs, Complex& rhs);
	Complex operator+(Complex& lhs, double rhs) { Complex a = Complex(rhs); return (lhs+a); };
	Complex operator-(Complex& lhs, double rhs) { Complex a = Complex(rhs); return (lhs-a); };
	Complex operator*(Complex& lhs, double rhs) { Complex a = Complex(rhs); return (lhs*a); };
	Complex operator/(Complex& lhs, double rhs) { Complex a = Complex(rhs); return (lhs/a); };

	bool operator==(Complex& lhs, Complex& rhs) { return (lhs.real == rhs.real && lhs.imaginary == rhs.imaginary); };
	bool operator!=(Complex& lhs, Complex& rhs) { return !(lhs==rhs); };



	//=======================================================MAIN///////////////////////////////////////////////////////////
int main() {
	Complex a(2, 2);
	Complex b(2, 0);
	
	return 0;
}
	//=======================================================MAIN///////////////////////////////////////////////////////////


Complex Complex::operator+=(Complex& rhs) {
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}


Complex Complex::operator-=(Complex& rhs) {
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}


Complex Complex::operator*=(Complex& rhs) {
	double re = real;
	double img =imaginary;
	real = (re * rhs.real) - (img * rhs.imaginary);
	imaginary = (re * rhs.imaginary) + (img * rhs.real);
	return *this;
}


Complex Complex::operator/=(Complex& rhs) {
	double del = rhs.real*rhs.real+rhs.imaginary*rhs.imaginary;
	Complex tmp1(real,imaginary);
	Complex tmp2(rhs.real, -rhs.imaginary);
	tmp1 *= tmp2;
	real = tmp1.real / del;
	imaginary = tmp1.imaginary / del;
	return *this;
}

//=============================================WITHOUT_ASSIGMENT==========////////////////////////////////////////
Complex operator+(Complex& lhs, Complex& rhs) {
	Complex res(lhs.real+rhs.real,lhs.imaginary+rhs.imaginary);
	return res;

}
Complex operator-(Complex& lhs, Complex& rhs) {
	Complex res(lhs.real - rhs.real, lhs.imaginary - rhs.imaginary);
	return res;

}

Complex operator*(Complex& lhs, Complex& rhs) {
	Complex tmp(lhs);
	tmp *= rhs;
	return tmp;

}
Complex operator/(Complex& lhs, Complex& rhs) {
	Complex tmp(lhs);
	tmp /= rhs;
	return tmp;

}


void Complex::print() {
	std::ios_base::fmtflags oldflags = std::cout.flags();
	std::streamsize oldprecision = std::cout.precision();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);
	if (imaginary > 0) {
		std::cout << "{" << real << " +" << imaginary << "i" << "}" << std::endl;
	}
	else {
		std::cout << "{" << real <<  " " << imaginary << "i" << "}" << std::endl;
	}
	std::cout.flags(oldflags);
	std::cout.precision(oldprecision);

}