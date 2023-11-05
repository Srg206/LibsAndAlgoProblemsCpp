#include<iostream>
#include<cmath>
#include <sstream>
#include <string>

class Complex {

public:
	Complex() {};
	Complex(double re, double img) { real = re; imaginary = img; };
	Complex(double re) { real = re; imaginary = 0; };
	Complex(const Complex& a) { real = a.real; imaginary = a.imaginary; };


	double real=0.0;
	double imaginary=0.0;

	static const char Start_Symbol = '{';
	static const char Middle_Division = ';';
	static const char Complex_Symbol = 'i';
	static const char Finish_Symbol = '}';

	const Complex operator=(const Complex& rhs) { real = rhs.real; imaginary = rhs.imaginary; return *this; };
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	Complex operator+=(double rhs) { Complex a = Complex(rhs); return operator+=(a); };
	Complex operator-=(double rhs) { Complex a = Complex(rhs); return operator-=(a); };
	Complex operator*=(double rhs) { Complex a = Complex(rhs); return operator*=(a); };
	Complex operator/=(double rhs) { Complex a = Complex(rhs); return operator/=(a); };

	double r() {return sqrt(real * real + imaginary * imaginary); };
	double angle_cos() { return real / r(); };


	void print();
};	

	Complex operator+(const Complex& lhs,const Complex& rhs);
	Complex operator-(const Complex& lhs,const Complex& rhs);
	Complex operator*(const Complex& lhs,const Complex& rhs);
	Complex operator/(const Complex& lhs,const Complex& rhs);
	Complex operator+(const Complex& lhs,const double rhs) { Complex a = Complex(rhs); return (lhs+a); };
	Complex operator-(const Complex& lhs,const double rhs) { Complex a = Complex(rhs); return (lhs-a); };
	Complex operator*(const Complex& lhs,const double rhs) { Complex a = Complex(rhs); return (lhs*a); };
	Complex operator/(const Complex& lhs,const double rhs) { Complex a = Complex(rhs); return (lhs/a); };

	bool operator==(const Complex& lhs, const Complex& rhs) { return (lhs.real == rhs.real && lhs.imaginary == rhs.imaginary); };
	bool operator!=(const Complex& lhs, const Complex& rhs) { return !(lhs==rhs); };
	std::ostream& operator<<(std::ostream& out,const Complex& z);
	std::istream& operator>>(std::istream& in, Complex& z);


	//=======================================================MAIN///////////////////////////////////////////////////////////
int main() {
	Complex a(1, 2);
	Complex b(2, 5);
	Complex c(1, 1);
	Complex d(0,0);
	Complex q(0,0);
	std::cin >> q;
	std::cout << q;


	return 0;
}
	//=======================================================MAIN///////////////////////////////////////////////////////////


Complex &Complex::operator+=(const Complex& rhs) {
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}


Complex &Complex::operator-=(const Complex& rhs) {
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}


Complex &Complex::operator*=(const Complex& rhs) {
	double re = real;
	double img =imaginary;
	real = (re * rhs.real) - (img * rhs.imaginary);
	imaginary = (re * rhs.imaginary) + (img * rhs.real);
	return *this;
}


Complex &Complex::operator/=(const Complex& rhs) {
	double del = rhs.real*rhs.real+rhs.imaginary*rhs.imaginary;
	Complex tmp1(real,imaginary);
	Complex tmp2(rhs.real, -rhs.imaginary);
	tmp1 *= tmp2;
	real = tmp1.real / del;
	imaginary = tmp1.imaginary / del;
	return *this;
}

//=============================================WITHOUT_ASSIGMENT==========////////////////////////////////////////
Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex res(lhs.real+rhs.real,lhs.imaginary+rhs.imaginary);
	return res;

}
Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex res(lhs.real - rhs.real, lhs.imaginary - rhs.imaginary);
	return res;

}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex tmp(lhs);
	tmp *= rhs;
	return tmp;

}
Complex operator/(const Complex& lhs,const Complex& rhs) {
	Complex tmp(lhs);
	tmp /= rhs;
	return tmp;

}
std::ostream& operator<<(std::ostream &out, const Complex& z) {
	std::ios_base::fmtflags oldflags = std::cout.flags();
	std::streamsize oldprecision = std::cout.precision();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);

	std::cout << "{" << z.real << ";" << z.imaginary << "i" << "}" << std::endl;
	
	std::cout.flags(oldflags);
	std::cout.precision(oldprecision);


	return out;
}
std::istream& operator>>(std::istream &in, Complex& z) {
	std::string str=" ";
	char left_bar(0);
	char semicolon(0);
	char letter_i(0);
	char right_bar(0);
	double re = 0;
	double im = 0;
	in >> left_bar >> re >> semicolon >> im >> letter_i >> right_bar;
	if (left_bar == z.Start_Symbol && semicolon == z.Middle_Division && letter_i == z.Complex_Symbol && right_bar == z.Finish_Symbol) {
		z.real = re;
		z.imaginary = im;
	}
	else{
		z.real = 0;
		z.imaginary = 0;
	}

	return in;
}


void Complex::print() {
	std::ios_base::fmtflags oldflags = std::cout.flags();
	std::streamsize oldprecision = std::cout.precision();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3); 

	std::cout << "{" << real << ";" << imaginary << "i" << "}" << std::endl;

	std::cout.flags(oldflags);
	std::cout.precision(oldprecision);

}