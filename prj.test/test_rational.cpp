#include<iostream>

class Rational {
public:
	Rational() = default;
	Rational(int64_t n,int64_t d);
	Rational(const Rational & R) = default;
	~Rational() = default;
	Rational& operator=(const Rational& R) = default;	
	int64_t get_num() const;
	int64_t get_den() const;

	void set_num(int64_t n);
	void set_den(int64_t d);


	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	static const char div = '/';

	void shorten_the_fraction();

private:

	int64_t greatest_common_divisor(int64_t a, int64_t b); 
	int64_t least_common_multiple(int64_t a, int64_t b);
	
	int64_t num = 0; //сверху
	int64_t den = 1; //снизу

};
	std::ostream& operator<<(std::ostream &out, Rational& r);
	std::istream& operator>>(std::istream &in, Rational& r);



/////////////////////////////////////////////////////////////TEST///////////////////////////////////////////

int main() {

	Rational r1(2,3);
	Rational r2(3,4);
	Rational r3(r1);
	Rational r4;
	

	r1 += r2;
	std::cout << r1;
	r1 = r3;
	
	r1 -= r2;
	std::cout << r1;
	r1 = r3;
	
	r1 *= r2;
	std::cout << r1;
	r1 = r3;
	
	r1 /= r2;
	std::cout << r1;
	r1 = r3;


	return 0;
}

/////////////////////////////////////////////////////////////TEST///////////////////////////////////////////
int64_t Rational::get_den() const {
	return den;
}
int64_t Rational::get_num() const{
	return num;
}

void Rational::set_den(int64_t d) {
	den = d;
}

void Rational::set_num(int64_t n) {
	num = n;
}

int64_t Rational::greatest_common_divisor(int64_t a, int64_t b) {
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return greatest_common_divisor(a % b, b);
	return greatest_common_divisor(a, b % a);
}

int64_t Rational::least_common_multiple(int64_t a, int64_t b) {
	return (a * b) / greatest_common_divisor(a, b);
}
void Rational::shorten_the_fraction() {
	int64_t tmp_div = greatest_common_divisor(num, den);
	num /= tmp_div;
	den /= tmp_div;

}
Rational::Rational(int64_t n, int64_t d) {
	if (d == 0) {
		throw  std::exception("   ERORR: DENOMINATOR CAN`T BE EQUAL ZERO !!!!  ");
	}
	num = n;
	den = d;
}

Rational& Rational::operator+=(const Rational& rhs) {
	int64_t tmp_den= least_common_multiple(den, rhs.get_den());
	num = num*(tmp_den/den) + rhs.get_num()*(tmp_den/rhs.get_den());
	den = tmp_den;
	return *this;
}


Rational& Rational::operator-=(const Rational& rhs) {
	int64_t tmp_den= least_common_multiple(den, rhs.get_den());
	num = num*(tmp_den/den) - rhs.get_num()*(tmp_den/rhs.get_den());
	den = tmp_den;
	return *this;
}


Rational& Rational::operator*=(const Rational& rhs) {
	num = num * rhs.get_num();
	den = den * rhs.get_den();
	return *this;
}


Rational& Rational::operator/=(const Rational& rhs) {
	num = num * rhs.get_den();
	den = den * rhs.get_num();
	return *this;
}

std::istream& operator>>(std::istream& in, Rational& r) {
	
	int64_t n=0;
	int64_t d=0;
	char bar = ' ';
	in >> n >> bar >> d;
	if (bar == r.div) {
		r.set_num(n);
		r.set_den(d);
	}
	else{
		std::cout<< "Format is incorrect" << std::endl;
	}
	return in;

}


std::ostream& operator<<(std::ostream& out,  Rational& r) {
	r.shorten_the_fraction();
	std::cout << r.get_num() << r.div << r.get_den()<<std::endl;
	return out;
}



