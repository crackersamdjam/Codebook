#pragma once
#include "../utils/template.h"

/**
 * @brief Segment Tree
 * @docs docs/segment_tree.md
 * @info
 */

template<class T, class L> struct segment_tree{
	int SZ;
	vector<T> val;
	function<T(T, T)> merge;
	function<T(T, L)> apply;
	
	void init(int n, T def, function<T(T, T)> f, function<T(T, L)> g){
		SZ = n;
		val.resize(__builtin_popcount(n) == 1 ? 2*n : 4*n, def);
		// If n is a power of 2, only 2n is needed. Otherwise 4n.
		merge = f;
		apply = g;
	}

	#define lc (rt<<1)
	#define rc (rt<<1|1)
	#define nm ((nl+nr)/2)
	
	T _query(int l, int r, int nl, int nr, int rt){
		if(r < nl or nr < l) return val[0];
		if(l <= nl and nr <= r) return val[rt];
		return merge(_query(l, r, nl, nm, lc), _query(l, r, nm+1, nr, rc));
	}
	T query(int l, int r){ return _query(l, r, 0, SZ-1, 1); }
	
	void _update(int i, L x, int nl, int nr, int rt){
		if(nl == nr){
			val[rt] = apply(val[rt], x);
			return;
		}
		i <= nm ? _update(i, x, nl, nm, lc) : _update(i, x, nm+1, nr, rc);
		val[rt] = merge(val[lc], val[rc]);
	}
	void update(int i, L x){ _update(i, x, 0, SZ-1, 1); };

	#undef lc
	#undef rc
	#undef nm
};