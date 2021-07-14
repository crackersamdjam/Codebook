#pragma once
#include "../utils/template.h"

/**
 * @brief Lazy Segment Tree
 * @docs docs/lazy_segment_tree.md
 *
 * todo: make "find first in range" (from cp algorthms) function
 * to do that, I need a function to check if f(x, current) is good enough, and I also need combine(current, val[rt])
 *
 */

template<class T, class L> struct lazy_segment_tree{
	int SZ;
	vector<T> val;
	vector<L> lp;
	function<T(T, T)> merge;
	function<T(T, L, int, int)> apply;
	function<L(L, L)> merge_lazy;
	
	void init(int n, T def, L ldef, function<T(T, T)> f, function<T(T, L, int, int)> g, function<L(L, L)> h){
		SZ = n;
		while(n&(n-1)) n++; // next largest power of 2
		val.resize(2*n, def);
		lp.resize(size(val), ldef);
		merge = f;
		apply = g;
		merge_lazy = h;
	}

	#define lc (rt<<1)
	#define rc (rt<<1|1)
	#define nm ((nl+nr)/2)

	void push(int nl, int nr, int rt){
		L &x = lp[rt];
		val[lc] = apply(val[lc], x, nl, nm);
		lp[lc] = merge_lazy(lp[lc], x);
		val[rc] = apply(val[rc], x, nm+1, nr);
		lp[rc] = merge_lazy(lp[rc], x);
		x = lp[0];
	}
	
	T _query(int l, int r, int nl, int nr, int rt){
		if(r < nl or nr < l) return val[0];
		if(l <= nl and nr <= r) return val[rt];
		push(nl, nr, rt);
		return merge(_query(l, r, nl, nm, lc), _query(l, r, nm+1, nr, rc));
	}
	T query(int l, int r){ return _query(l, r, 0, SZ-1, 1); }
	
	void _update(int l, int r, L x, int nl, int nr, int rt){
		if(r < nl or nr < l) return;
		if(l <= nl and nr <= r){
			val[rt] = apply(val[rt], x, nl, nr);
			lp[rt] = merge_lazy(lp[rt], x);
			return;
		}
		push(nl, nr, rt);
		_update(l, r, x, nl, nm, lc);
		_update(l, r, x, nm+1, nr, rc);
		val[rt] = merge(val[lc], val[rc]);
	}
	void update(int l, int r, L x){ _update(l, r, x, 0, SZ-1, 1); };

	#undef lc
	#undef rc
	#undef nm
};