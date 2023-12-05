// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>
#include<cmath>
#include <sstream>
#include <string>
#include<iostream>

std::string BoolToStr(bool a) {
	return a == 0 ? "False" : "True";
}
//=======================================================TEST///////////////////////////////////////////////////////////
Complex test_Prase(const std::string& s) {
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
	Complex a(1.2, 2.7);
	Complex zero(0, 0);
	Complex b(2.33, 3.16);
	Complex c(4.2, 5.11);
	double d = 2;
	Complex e(1.33, 2.44);

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
	a += 0.33355555555555555;
	a -= 0.33355555555555555;
	e += 0.33355555555555555;
	e -= 0.33355555555555555;

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