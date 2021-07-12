#pragma once
#include "../utils/template.h"

/**
 * @brief Point
 * @docs docs/point.md
 * @info
 */


//using T = long double; constexpr T eps = 1e-9;
using T = long long; constexpr T eps = 0;
// all numbers that can be represented by long long can also be
// accurately represented by long double, it's just slower

using pt = complex<T>;
#define x real()
#define y imag()

istream &operator >> (istream &stream, pt &p){
	T X, Y; stream>>X>>Y; p = pt(X, Y); return stream;}
ostream &operator << (ostream &stream, const pt &p){
	return stream<<p.x<<' '<<p.y;}

namespace std{
	bool operator<(const pt &a, const pt &b){
		return a.x < b.x or (a.x-eps <= b.x and a.y < b.y-eps);}
	bool operator==(const pt &a, const pt &b){
		return !(a < b) and !(b < a);}
	bool operator<=(const pt &a, const pt &b){
		return !(b < a);}
}

T dot(pt a, pt b){ return a.x*b.x + a.y*b.y;}
T norm(pt a){ return dot(a, a);} // norm is distance squared. Don't use std::norm because of inaccuracy
T cross(pt a, pt b){ return a.x*b.y - a.y*b.x;} // right hand rule: a-index, b-middle, cross-thumb. Result is > 0 if ccw, < 0 if cw, 0 if collinear.
T ccw(pt origin, pt a, pt b){ return cross(a-origin, b-origin);}

// intersection of the (infinite) lines a1-a2 and b1-b2
pt intersect(pt a1, pt a2, pt b1, pt b2){
	pt d1 = a2-a1, d2 = b2-b1;
	return a1 + cross(b1-a1, d2)/cross(d1, d2) * d1;
}

// intersection of the line segments a1-a2 and b1-b2
// make this look nicer (and easier to code up)
bool has_intersect(pt a1, pt a2, pt b1, pt b2){
	if(max(a1.x, a2.x) >= min(b1.x, b2.x) && max(b1.x, b2.x) >= min(a1.x, a2.x) &&
	   max(a1.y, a2.y) >= min(b1.y, b2.y) && max(b1.y, b2.y) >= min(a1.y, a2.y)
	   && ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0
	   && ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0)
		return 1;
	return 0;
}

// monotone chain algorithm
vector<pt> convex_hull(vector<pt> pts){
	sort(all(pts));
	vector<pt> hull;
	for(int h = 0; h < 2; h++){
		int last = (int)size(hull);
		for(int i = 0; i < (int)size(pts); i++){
			while((int)size(hull) >= last+2 and ccw(*(hull.end()-2), pts[i], hull.back()) >= 0)
				hull.pop_back();
			hull.push_back(pts[i]);
		}
		hull.pop_back();
		reverse(all(pts));
	}
	if(size(hull) == 2 and hull[0] == hull[1])
		hull.pop_back();
	if(!size(hull) and size(pts))
		hull.push_back(pts[0]);
	return hull;
}


#undef x
#undef y