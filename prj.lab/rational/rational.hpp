#include<iostream>

class Rational {
public:
	Rational() = default;
	Rational(int64_t n, int64_t d);
	Rational(int64_t n);
	Rational(const Rational& R) = default;
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
	int64_t num = 0; //сверху
	int64_t den = 1; //снизу

};

	int64_t greatest_common_divisor(int64_t a, int64_t b);
	int64_t least_common_multiple(int64_t a, int64_t b);
std::ostream& operator<<(std::ostream& out, Rational& r);
std::istream& operator>>(std::istream& in, Rational& r);

bool operator==(Rational& a, Rational& b);
bool operator!=(Rational& a, Rational& b);
bool operator<(Rational& a, Rational& b);
bool operator>(Rational& a, Rational& b);
bool operator<=(Rational& a, Rational& b);
bool operator>=(Rational& a, Rational& b);


Rational operator+(Rational& a, Rational& b);
Rational operator-(Rational& a, Rational& b);
Rational operator*(Rational& a, Rational& b);
Rational operator/(Rational& a, Rational& b);


Rational operator+(Rational& a, int64_t b);
Rational operator-(Rational& a, int64_t b);
Rational operator*(Rational& a, int64_t b);
Rational operator/(Rational& a, int64_t b);

Rational operator+(int64_t b, Rational& a);
Rational operator-(int64_t b, Rational& a);
Rational operator*(int64_t b, Rational& a);
Rational operator/(int64_t b, Rational& a);

