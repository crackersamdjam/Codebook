---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fraction Class
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/math/fraction.h\"\
    \n\n/**\n * @brief Fraction Class\n */\n\nstruct fraction{\n\tll n, d;\n\tfraction(ll\
    \ num = 0, ll den = 1){\n\t\tn = num, d = den;\n\t\treduce();\n\t}\n\tvoid reduce(){\n\
    \t\tif(d < 0) d *= -1, n *= -1;\n\t\tif(n == 0)d = 1;\n\t\telse if (d == 0)n =\
    \ 0;\n\t\telse {\n\t\t\tll gc = __gcd((n < 0 ? -n : n), d);\n\t\t\tn /= gc, d\
    \ /= gc;\n\t\t}\n\t}\n\tll toLL() const { return n / d; }\n\tdouble toDouble()\
    \ const { return double((long double) (n) / (long double) (d)); }\n\tlong double\
    \ toLD() const { return (long double) (n) / (long double) (d); }\n\tfraction operator+(const\
    \ fraction &a) const { return fraction(n * a.d + a.n * d, d * a.d); }\n\tfraction\
    \ operator-(const fraction &a) const { return fraction(n * a.d - a.n * d, d *\
    \ a.d); }\n\tfraction operator*(const fraction &a) const { return fraction(n *\
    \ a.n, d * a.d); }\n\tfraction operator/(const fraction &a) const { return fraction(n\
    \ * a.d, d * a.n); }\n\tbool operator<(const fraction &a) const { return __int128(n)\
    \ * __int128(a.d) < __int128(a.n) * __int128(d); }\n\tbool operator==(const fraction\
    \ &a) const { return !(*this < a) && !(a < *this); }\n\tbool operator>=(const\
    \ fraction &a) const { return !(*this < a); }\n\tbool operator<=(const fraction\
    \ &a) const { return !(a < *this); }\n\tbool operator>(const fraction &a) const\
    \ { return a < *this; }\n\tbool operator!=(const fraction &a) const { return (*this\
    \ < a) || (a < *this); }\n\tfriend ostream& operator<<(ostream& os, fraction const\
    \ &a) { return os<<a.n<<'/'<<a.d; }\n\tfriend istream& operator>>(istream& is,\
    \ fraction &a) { char _; is>>a.n>>_>>a.d;assert(_ == '/');  a.reduce(); return\
    \ is; }\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Fraction\
    \ Class\n */\n\nstruct fraction{\n\tll n, d;\n\tfraction(ll num = 0, ll den =\
    \ 1){\n\t\tn = num, d = den;\n\t\treduce();\n\t}\n\tvoid reduce(){\n\t\tif(d <\
    \ 0) d *= -1, n *= -1;\n\t\tif(n == 0)d = 1;\n\t\telse if (d == 0)n = 0;\n\t\t\
    else {\n\t\t\tll gc = __gcd((n < 0 ? -n : n), d);\n\t\t\tn /= gc, d /= gc;\n\t\
    \t}\n\t}\n\tll toLL() const { return n / d; }\n\tdouble toDouble() const { return\
    \ double((long double) (n) / (long double) (d)); }\n\tlong double toLD() const\
    \ { return (long double) (n) / (long double) (d); }\n\tfraction operator+(const\
    \ fraction &a) const { return fraction(n * a.d + a.n * d, d * a.d); }\n\tfraction\
    \ operator-(const fraction &a) const { return fraction(n * a.d - a.n * d, d *\
    \ a.d); }\n\tfraction operator*(const fraction &a) const { return fraction(n *\
    \ a.n, d * a.d); }\n\tfraction operator/(const fraction &a) const { return fraction(n\
    \ * a.d, d * a.n); }\n\tbool operator<(const fraction &a) const { return __int128(n)\
    \ * __int128(a.d) < __int128(a.n) * __int128(d); }\n\tbool operator==(const fraction\
    \ &a) const { return !(*this < a) && !(a < *this); }\n\tbool operator>=(const\
    \ fraction &a) const { return !(*this < a); }\n\tbool operator<=(const fraction\
    \ &a) const { return !(a < *this); }\n\tbool operator>(const fraction &a) const\
    \ { return a < *this; }\n\tbool operator!=(const fraction &a) const { return (*this\
    \ < a) || (a < *this); }\n\tfriend ostream& operator<<(ostream& os, fraction const\
    \ &a) { return os<<a.n<<'/'<<a.d; }\n\tfriend istream& operator>>(istream& is,\
    \ fraction &a) { char _; is>>a.n>>_>>a.d;assert(_ == '/');  a.reduce(); return\
    \ is; }\n};\n"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/math/fraction.h
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: content/math/fraction.h
layout: document
redirect_from:
- /library/content/math/fraction.h
- /library/content/math/fraction.h.html
title: Fraction Class
---
