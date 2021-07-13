#pragma once
#include "../utils/template.h"

/**
 * @brief Li Chao Tree
 * @docs docs/li_chao_tree.md
 */

template<typename T> struct line{
	T m, b;
	T eval(T x){ return m*x + b;}
};

template<typename T> struct sparse_li_chao_tree{
	int LS, RS;
	T def;
	function<T(T, T)> merge;
	
	struct node{
		node *lc, *rc;
		line<T> val;
		node(line<T> _val){
			lc = rc = nullptr;
			val = _val;
		}
	};
	node *rt = nullptr;
	
	// merge() should be min or max
	void init(int _LS, int _RS, T _def, function<T(T, T)> _merge){
		LS = _LS;
		RS = _RS;
		def = _def;
		merge = _merge;
	}

	#define nm (nl+(nr-nl)/2)
	// this works for negative indices too, unlike (nl+nr)/2
	
	void _add(line<T> ln, int nl, int nr, node *&cur){
		assert(nl <= nr);
		if(!cur){
			cur = new node(ln);
			return;
		}
		bool bl = ln.eval(nl) < cur->val.eval(nl);
		bool bm = ln.eval(nm) < cur->val.eval(nm);
		if(bm) swap(cur->val, ln);
		if(nl == nr) return;
		bl != bm ? _add(ln, nl, nm, cur->lc) : _add(ln, nm+1, nr, cur->rc);
	}
	void add(line<T> ln){ _add(ln, LS, RS, rt); }
	
	T _get(T x, int nl, int nr, node *cur){
		if(!cur) return def;
		if(nl == nr) return cur->val.eval(x);
		if(x <= nm) return merge(cur->val.eval(x), _get(x, nl, nm, cur->lc));
		return merge(cur->val.eval(x), _get(x, nm+1, nr, cur->rc));
	}
	T get(T x){ return _get(x, LS, RS, rt); }

	#undef nm
};