#pragma once
#include "../utils/template.h"

/**
 * @brief Binary Indexed Tree
 * @docs docs/bit.md
 */

template<class T> struct bit{
	int SZ;
	vector<T> bit;
	function<T(T, T)> merge;
	
	void init(int n, T def, function<T(T, T)> f){
		SZ = n;
		bit.resize(SZ, def);
		merge = f;
	}
	void update(int i, T v){
		for(; i < SZ; i += i&-i)
			bit[i] = merge(bit[i], v);
	}
	T query(int i){
		T x = bit[0];
		for(; i; i -= i&-i)
			x = merge(x, bit[i]);
		return x;
	}
};

template<class T> struct range_bit{
	bit<T> T1, T2;
	function<T(T, T)> unmerge;

	void init(int n, T def, function<T(T, T)> f, function<T(T, T)> g){
		T1.init(n, def, f);
		T2.init(n, def, f);
		unmerge = g;
	}
	T query(int i){
		return i*T1.query(i)-T2.query(i);
	}
	T query(int l, int r){
		return unmerge(query(r), query(l-1));
	}
	void update(int l, int r, T v){
		T1.update(l, v);
		T1.update(r+1, -v);
		T2.update(l, v*(l-1));
		T2.update(r+1, -v*r);
	}
	void update(int l, T v){
		update(l, l, v);
	}
};