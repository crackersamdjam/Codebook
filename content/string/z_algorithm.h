#pragma once
#include "../utils/template.h"

/**
 * @brief Z Algorithm
 * @docs docs/z_algorithm.md
 */

vector<int> zed(string s){
	int n = (int)size(s);
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(i <= r)
			z[i] = min(r-i+1, z[i-l]);
		while(i+z[i] < n and s[z[i]] == s[i+z[i]])
			z[i]++;
		if(i+z[i]-1 > r)
			l = i, r = i+z[i]-1;
	}
	return z;
}