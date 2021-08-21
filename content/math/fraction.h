#pragma once
#include "../utils/template.h"

/**
 * @brief Fraction Class
 * @docs docs/fraction.md
 */

struct fraction{
	ll n, d;
	fraction(ll num = 0, ll den = 1){
		n = num, d = den;
		reduce();
	}
	void reduce(){
		if(d < 0) d *= -1, n *= -1;
		if(n == 0)d = 1;
		else if (d == 0)n = 0;
		else {
			ll gc = __gcd((n < 0 ? -n : n), d);
			n /= gc, d /= gc;
		}
	}
	ll toLL() const { return n / d; }
	double toDouble() const { return double((long double) (n) / (long double) (d)); }
	long double toLD() const { return (long double) (n) / (long double) (d); }
	fraction operator+(const fraction &a) const { return fraction(n * a.d + a.n * d, d * a.d); }
	fraction operator-(const fraction &a) const { return fraction(n * a.d - a.n * d, d * a.d); }
	fraction operator*(const fraction &a) const { return fraction(n * a.n, d * a.d); }
	fraction operator/(const fraction &a) const { return fraction(n * a.d, d * a.n); }
	bool operator<(const fraction &a) const { return __int128(n) * __int128(a.d) < __int128(a.n) * __int128(d); }
	bool operator==(const fraction &a) const { return !(*this < a) && !(a < *this); }
	bool operator>=(const fraction &a) const { return !(*this < a); }
	bool operator<=(const fraction &a) const { return !(a < *this); }
	bool operator>(const fraction &a) const { return a < *this; }
	bool operator!=(const fraction &a) const { return (*this < a) || (a < *this); }
	friend ostream& operator<<(ostream& os, fraction const &a) { return os<<a.n<<'/'<<a.d; }
	friend istream& operator>>(istream& is, fraction &a) { char _; is>>a.n>>_>>a.d;assert(_ == '/');  a.reduce(); return is; }
};