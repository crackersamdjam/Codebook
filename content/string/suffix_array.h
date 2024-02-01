#pragma once
#include "../utils/template.h"

/**
 * @brief Suffix Array (in O(n log n))
 */

vector<int> sort_cyclic_shifts(string const &s, int const alphabet){
	int n = (int)size(s);
	vector<int> p(n), c(n), cnt(max(alphabet, n));
	for(int i = 0; i < n; i++)
		cnt[s[i]]++;
	for(int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i-1];
	for(int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for(int i = 1; i < n; i++){
		if(s[p[i]] != s[p[i-1]])
			classes++;
		c[p[i]] = classes-1;
	}
	vector<int> pn(n), cn(n);
	for(int h = 0; (1<<h) < n; h++){
		for(int i = 0; i < n; i++){
			pn[i] = p[i] - (1<<h);
			if(pn[i] < 0)
				pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin()+classes, 0);
		for(int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for(int i = 1; i < classes; i++)
			cnt[i] += cnt[i-1];
		for(int i = n-1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i = 1; i < n; i++){
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1<<h)) % n]};
			pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h)) % n]};
			if(cur != prev)
				classes++;
			cn[p[i]] = classes-1;
		}
		c.swap(cn);
	}
	return p;
}

vector<int> suffix_array_construction(string s, int const alphabet = 256){
	s += "$";
	vector<int> sorted_shifts = sort_cyclic_shifts(s, alphabet);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

// p should be suffix_array_construction(s)
vector<int> lcp_construction(string const &s, vector<int> const &p){
	int n = (int)size(s);
	vector<int> rank(n);
	for (int i = 0; i < n; i++)
		rank[p[i]] = i;
	
	int k = 0;
	vector<int> lcp(n-1);
	for(int i = 0; i < n; i++){
		if(rank[i] == n-1){
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while(i+k < n and j+k < n and s[i+k] == s[j+k])
			k++;
		lcp[rank[i]] = k;
		if(k) k--;
	}
	return lcp;
}
