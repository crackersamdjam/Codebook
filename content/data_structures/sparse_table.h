#pragma once
#include "../utils/template.h"

/**
 * @brief Sparse Table
 * @docs docs/sparse_table.md
 */

template<class T> struct sparse_table{
	
	int n; vector<vector<T>> sp;
	function<T(T, T)> merge;
	
	T query(int l, int r){
		int k = __lg(r-l+1);
		return merge(sp[k][l], sp[k][r-(1<<k)+1]);
	}
	void build(vector<T> v, function<T(T, T)> f){
		merge = f;
		n = size(v);
		sp.resize(__lg(n)+1);
		sp[0] = v;
		for(int i = 1; i <= __lg(n); i++){
			sp[i].resize(n);
			for(int j = 0; j+(1<<i)-1 < n; j++){
				sp[i][j] = merge(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
			}
		}
	}
};