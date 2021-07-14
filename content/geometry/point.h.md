---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy:
  - icon: ':warning:'
    path: content/geometry/polygon.h
    title: Polygon
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/point.md
    document_title: Point
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/geometry/point.h\"\
    \n\n/**\n * @brief Point\n * @docs docs/point.md\n */\n\n\n//using T = long double;\
    \ constexpr T eps = 1e-9;\nusing T = long long; constexpr T eps = 0;\n// all numbers\
    \ that can be represented by long long can also be\n// accurately represented\
    \ by long double, it's just slower\n\nusing pt = complex<T>;\n#define x real()\n\
    #define y imag()\n\nistream &operator >> (istream &stream, pt &p){\n\tT X, Y;\
    \ stream>>X>>Y; p = pt(X, Y); return stream;}\nostream &operator << (ostream &stream,\
    \ const pt &p){\n\treturn stream<<p.x<<' '<<p.y;}\n\nnamespace std{\n\tbool operator<(const\
    \ pt &a, const pt &b){\n\t\treturn a.x < b.x or (a.x-eps <= b.x and a.y < b.y-eps);}\n\
    \tbool operator==(const pt &a, const pt &b){\n\t\treturn !(a < b) and !(b < a);}\n\
    \tbool operator<=(const pt &a, const pt &b){\n\t\treturn !(b < a);}\n}\n\nT dot(pt\
    \ a, pt b){ return a.x*b.x + a.y*b.y;}\nT norm(pt a){ return dot(a, a);} // norm\
    \ is distance squared. Don't use std::norm because of inaccuracy\nT cross(pt a,\
    \ pt b){ return a.x*b.y - a.y*b.x;} // right hand rule: a-index, b-middle, cross-thumb.\
    \ Result is > 0 if ccw, < 0 if cw, 0 if collinear.\nT ccw(pt origin, pt a, pt\
    \ b){ return cross(a-origin, b-origin);}\n\n// intersection of the (infinite)\
    \ lines a1-a2 and b1-b2\npt intersect(pt a1, pt a2, pt b1, pt b2){\n\tpt d1 =\
    \ a2-a1, d2 = b2-b1;\n\treturn a1 + cross(b1-a1, d2)/cross(d1, d2) * d1;\n}\n\n\
    // intersection of the line segments a1-a2 and b1-b2\n// make this look nicer\
    \ (and easier to code up)\nbool has_intersect(pt a1, pt a2, pt b1, pt b2){\n\t\
    if(max(a1.x, a2.x) >= min(b1.x, b2.x) && max(b1.x, b2.x) >= min(a1.x, a2.x) &&\n\
    \t   max(a1.y, a2.y) >= min(b1.y, b2.y) && max(b1.y, b2.y) >= min(a1.y, a2.y)\n\
    \t   && ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0\n\t   && ccw(b1, b2, a1) * ccw(b1,\
    \ b2, a2) <= 0)\n\t\treturn 1;\n\treturn 0;\n}\n\n// monotone chain algorithm\n\
    vector<pt> convex_hull(vector<pt> pts){\n\tsort(all(pts));\n\tvector<pt> hull;\n\
    \tfor(int h = 0; h < 2; h++){\n\t\tint last = (int)size(hull);\n\t\tfor(int i\
    \ = 0; i < (int)size(pts); i++){\n\t\t\twhile((int)size(hull) >= last+2 and ccw(*(hull.end()-2),\
    \ pts[i], hull.back()) >= 0)\n\t\t\t\thull.pop_back();\n\t\t\thull.push_back(pts[i]);\n\
    \t\t}\n\t\thull.pop_back();\n\t\treverse(all(pts));\n\t}\n\tif(size(hull) == 2\
    \ and hull[0] == hull[1])\n\t\thull.pop_back();\n\tif(!size(hull) and size(pts))\n\
    \t\thull.push_back(pts[0]);\n\treturn hull;\n}\n\n\n#undef x\n#undef y\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Point\n\
    \ * @docs docs/point.md\n */\n\n\n//using T = long double; constexpr T eps = 1e-9;\n\
    using T = long long; constexpr T eps = 0;\n// all numbers that can be represented\
    \ by long long can also be\n// accurately represented by long double, it's just\
    \ slower\n\nusing pt = complex<T>;\n#define x real()\n#define y imag()\n\nistream\
    \ &operator >> (istream &stream, pt &p){\n\tT X, Y; stream>>X>>Y; p = pt(X, Y);\
    \ return stream;}\nostream &operator << (ostream &stream, const pt &p){\n\treturn\
    \ stream<<p.x<<' '<<p.y;}\n\nnamespace std{\n\tbool operator<(const pt &a, const\
    \ pt &b){\n\t\treturn a.x < b.x or (a.x-eps <= b.x and a.y < b.y-eps);}\n\tbool\
    \ operator==(const pt &a, const pt &b){\n\t\treturn !(a < b) and !(b < a);}\n\t\
    bool operator<=(const pt &a, const pt &b){\n\t\treturn !(b < a);}\n}\n\nT dot(pt\
    \ a, pt b){ return a.x*b.x + a.y*b.y;}\nT norm(pt a){ return dot(a, a);} // norm\
    \ is distance squared. Don't use std::norm because of inaccuracy\nT cross(pt a,\
    \ pt b){ return a.x*b.y - a.y*b.x;} // right hand rule: a-index, b-middle, cross-thumb.\
    \ Result is > 0 if ccw, < 0 if cw, 0 if collinear.\nT ccw(pt origin, pt a, pt\
    \ b){ return cross(a-origin, b-origin);}\n\n// intersection of the (infinite)\
    \ lines a1-a2 and b1-b2\npt intersect(pt a1, pt a2, pt b1, pt b2){\n\tpt d1 =\
    \ a2-a1, d2 = b2-b1;\n\treturn a1 + cross(b1-a1, d2)/cross(d1, d2) * d1;\n}\n\n\
    // intersection of the line segments a1-a2 and b1-b2\n// make this look nicer\
    \ (and easier to code up)\nbool has_intersect(pt a1, pt a2, pt b1, pt b2){\n\t\
    if(max(a1.x, a2.x) >= min(b1.x, b2.x) && max(b1.x, b2.x) >= min(a1.x, a2.x) &&\n\
    \t   max(a1.y, a2.y) >= min(b1.y, b2.y) && max(b1.y, b2.y) >= min(a1.y, a2.y)\n\
    \t   && ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0\n\t   && ccw(b1, b2, a1) * ccw(b1,\
    \ b2, a2) <= 0)\n\t\treturn 1;\n\treturn 0;\n}\n\n// monotone chain algorithm\n\
    vector<pt> convex_hull(vector<pt> pts){\n\tsort(all(pts));\n\tvector<pt> hull;\n\
    \tfor(int h = 0; h < 2; h++){\n\t\tint last = (int)size(hull);\n\t\tfor(int i\
    \ = 0; i < (int)size(pts); i++){\n\t\t\twhile((int)size(hull) >= last+2 and ccw(*(hull.end()-2),\
    \ pts[i], hull.back()) >= 0)\n\t\t\t\thull.pop_back();\n\t\t\thull.push_back(pts[i]);\n\
    \t\t}\n\t\thull.pop_back();\n\t\treverse(all(pts));\n\t}\n\tif(size(hull) == 2\
    \ and hull[0] == hull[1])\n\t\thull.pop_back();\n\tif(!size(hull) and size(pts))\n\
    \t\thull.push_back(pts[0]);\n\treturn hull;\n}\n\n\n#undef x\n#undef y"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/geometry/point.h
  requiredBy:
  - content/geometry/polygon.h
  timestamp: '2021-07-13 15:53:41-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: content/geometry/point.h
layout: document
redirect_from:
- /library/content/geometry/point.h
- /library/content/geometry/point.h.html
title: Point
---
