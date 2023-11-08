#include<iostream>
#include<cmath>
#include <sstream>
#include <string>

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

std::string BoolToStr(bool a) {
	return a == 0 ? "False": "True";
}
//=======================================================TEST///////////////////////////////////////////////////////////
Complex test_Prase(const std::string &s) {
	std::istringstream istrm(s);

	Complex a;
	char leftbrace = ' ';
	char comma = ' ';
	char rightbrace = ' ';
	istrm >> leftbrace >> a.real >> comma >> a.imaginary >> rightbrace;
	std::cout << s << "=> ";
	if (leftbrace != a.Start_Symbol || comma != a.Middle_Division || rightbrace != a.Finish_Symbol) {
		throw std::exception("  Incorrect Format of input data !!!! ");
	}
	std::cout << a << " correct parsing" << std::endl;
	return a;
}

void test() {
	Complex a(1, 2);
	Complex zero(0, 0);
	Complex b(2, 3);
	Complex c(4, 5);
	double d = 2;
	Complex e(1, 2);

	//======================Without assigment operations START///
	std::cout << "Without assigment operations START" << std::endl;
	std::cout << "a " << a << " + " << " b" << b << " = " << a + b << std::endl;
	std::cout << "a " << a << " - " << " b" << b << " = " << a - b << std::endl;
	std::cout << "a " << a << " * " << " b" << b << " = " << a * b << std::endl;
	std::cout << "a " << a << " / " << " b" << b;
	try {
		std::cout << " = " << a / b << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "a " << a << " / " << " b" << zero;
	try {
		std::cout << " = " << a / zero << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "a " << a << " / " << 0;
	try {
		std::cout << " = " << a / 0 << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "\nWithout assigment operations FINISH\n" << std::endl;
	//======================Without assigment operations FINISH///

	//======================Assigment operations START///
	std::cout << "Assigment operations START\n" << std::endl;

	std::cout << "a " << a << " = " << " b" << b << " => " << " a= ";
	a = b;
	std::cout << a << std::endl;

	std::cout << "a " << a << " += " << " b" << b << " => " << " a= ";
	a += b;
	std::cout << a << std::endl;
	std::cout << "a " << a << " -= " << " b" << b << " => " << " a= ";
	a -= b;
	std::cout << a << std::endl;

	std::cout << "a " << a << " *= " << " b" << b << " => " << " a= ";
	a *= b;
	std::cout << a << std::endl;


	std::cout << "a " << a << " /= " << " b" << b;
	try {
		a /= b;
		std::cout << " => " << " a= " << a << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


	std::cout << "a " << a << " /= " << " zero" << zero;
	try {
		a /= zero;
		std::cout << " => " << " a= " << a << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "\nAssigment operations FINISH\n" << std::endl;
	//======================Assigment operations FINISH///
	
	//======================Comparison operations START///
	std::cout << "Comparison operations START\n" << std::endl;

	std::cout << "a " << a << " == " << " b" << b << " - " << BoolToStr(a == b) << std::endl;
	std::cout << "a " << a << " == " << " b" << e << " - " << BoolToStr(a == e) << std::endl;
	std::cout << "a " << a << " != " << " b" << b << " - " << BoolToStr(a != b) << std::endl;
	std::cout << "a " << a << " != " << " b" << e << " - " << BoolToStr(a != e) << std::endl;

	std::cout << "\nComparison operations Finish\n" << std::endl;
	//======================Comparison operations FINISH///
	
	
	//==============================================================PARSING TEST START///
	//system("cls");
	std::cout << "Parsing test START\n" << std::endl;
	Complex parsed_num(0, 0);
	std::string test_string_1 = "{2.23,3.0}";
	std::string test_string_2 = "{   2.23, 3.0  }";
	std::string test_string_3 = "{2.23 3.0}";
	std::string test_string_4 = "2.23,3.0}";
	
	
	try {
		parsed_num = test_Prase(test_string_1);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	try {
		parsed_num = test_Prase(test_string_2);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	try {
		parsed_num = test_Prase(test_string_3);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	try {
		parsed_num = test_Prase(test_string_4);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "Parsing test Finish\n" << std::endl;

	//==============================================================PARSING TEST FINISH///

}
//=======================================================TEST///////////////////////////////////////////////////////////

//=======================================================MAIN///////////////////////////////////////////////////////////
int main() {

	test();

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
	if (del == 0) {
		throw std::exception("   ERORR DIVISON BY ZERO!!!!  ");
	}
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

	std::cout << "{" << z.real << "," << z.imaginary << "}";

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
		std::cout << "Format is incorrect" << std::endl;
	}

	return in;
}


bool operator==(const Complex& lhs, const Complex& rhs) {
	return (lhs.real == rhs.real && lhs.imaginary == rhs.imaginary);
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
	return !(lhs == rhs);
}


//
//double Complex::module() {
//	return sqrt(real * real + imaginary * imaginary);
//}
//double Complex::argument() {
//	return acos(real / module());
//}


