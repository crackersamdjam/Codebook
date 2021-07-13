#pragma once
#include "../utils/template.h"

/**
 * @brief Knuth-Morris-Pratt Algorithm
 * @docs docs/kmp.md
 */

vector<int> kmp(string s){
	vector<int> pi(size(s));
	pi[0] = 0;
	for(int i = 1, j = 0; i < size(s); i++){
		while(j and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}