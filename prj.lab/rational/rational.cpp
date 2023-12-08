#include"rational.hpp"


Rational::Rational(int64_t n) {
	num = n;
	den = 1;
}
int64_t Rational::get_den() const {
	return den;
}
int64_t Rational::get_num() const{
	return num;
}

void Rational::set_den(int64_t d) {
	if (d == 0) {
		throw std::exception(" Erorr determinator can`t be equal zero !!!! ");
	}
	else if (d < 0) {
		num *= -1;
		d *= -1;
	}
	den = d;
}

void Rational::set_num(int64_t n) {
	num = n;
}

int64_t greatest_common_divisor(int64_t a, int64_t b) {
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return greatest_common_divisor(a % b, b);
	return greatest_common_divisor(a, b % a);
}

int64_t least_common_multiple(int64_t a, int64_t b) {
	return (a * b) / greatest_common_divisor(a, b);
}
void Rational::shorten_the_fraction() {
	int64_t tmp_div = abs(greatest_common_divisor(num, den));
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
	if (rhs.get_num() == 0) {
		throw std::exception("Erorr division by zero !!!");
	}
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
	out << r.get_num() << r.div << r.get_den();
	return out;
}
bool operator==( Rational& a, Rational& b) {
	a.shorten_the_fraction();
	b.shorten_the_fraction();
	if (a.get_den() == b.get_den() && a.get_num() == b.get_num()) {
		return true;
	}
	else{
		return false;
	}
}
bool operator!=( Rational& a, Rational& b) {
	return !(a == b);
}
bool operator<( Rational& a, Rational& b) {
	int64_t tmp_den = least_common_multiple(a.get_den(),b.get_den());
	a.set_num((tmp_den / a.get_den()) * a.get_num());
	b.set_num((tmp_den / b.get_den()) * b.get_num());
	a.set_den(tmp_den);
	b.set_den(tmp_den);

	if (a.get_num() < b.get_num()) {
		return true;
	}
	else {
		return false;
	}
}
bool operator>( Rational& a, Rational& b) {
	int64_t tmp_den = least_common_multiple(a.get_den(),b.get_den());
	a.set_num((tmp_den / a.get_den()) * a.get_num());
	b.set_num((tmp_den / b.get_den()) * b.get_num());
	a.set_den(tmp_den);
	b.set_den(tmp_den);

	if (a.get_num() < b.get_num()) {
		return true;
	}
	else {
		return false;
	}
}

Rational operator+(Rational& a, Rational& b) {
	Rational c(a);
	c += b;
	return c;
}
Rational operator-(Rational& a, Rational& b) {
	Rational c(a);
	c -= b;
	return c;
}
Rational operator*(Rational& a, Rational& b) {
	Rational c(a);
	c *= b;
	return c;
}
Rational operator/(Rational& a, Rational& b) {
	Rational c(a);
	c /= b;
	return c;
}



Rational operator+(Rational& a,int64_t b) {
	Rational c(a);
	Rational d(b);
	c += d;
	return c;
}
Rational operator-(Rational& a, int64_t b) {
	Rational c(a);
	Rational d(b);

	c -= d;
	return c;
}
Rational operator*(Rational& a, int64_t b) {
	Rational c(a);
	Rational d(b);

	c *= d;
	return c;
}
Rational operator/(Rational& a, int64_t b) {
	Rational c(a);
	Rational d(b);

	c /= d;
	return c;
}



Rational operator+(int64_t b ,Rational &a) {
	Rational c(a);
	Rational d(b);
	c += d;
	return c;
}
Rational operator-(int64_t b, Rational& a) {
	Rational c(a);
	Rational d(b);

	c -= d;
	return c;
}
Rational operator*(int64_t b, Rational& a) {
	Rational c(a);
	Rational d(b);

	c *= d;
	return c;
}
Rational operator/(int64_t b, Rational& a) {
	Rational c(a);
	Rational d(b);

	c /= d;
	return c;
}










