#pragma once
#include "../utils/template.h"

/**
 * @brief Suffix Automaton
 * @docs docs/suffix_automaton.md
 */

// TODO: add code to rebuild suffix link tree

struct suffix_automaton{
	struct st{
		int len, par;
		ll cnt;
		map<char, int> ch;
	};
	vector<st> v;
	int sz, last;
	
	void init(int n){
		v.resize(n*2);
		v[0].len = 0; //0 is the root
		v[0].par = -1;
		sz = 1;
		last = 0;
	}
	
	void extend(char c){
		int cur = sz++;
		v[cur].len = v[last].len+1;
		int p = last;
		while(p != -1 && !v[p].ch.count(c)){
			v[p].ch[c] = cur;
			p = v[p].par;
		}
		if(p == -1){
			v[cur].par = 0;
		}
		else{
			int o = v[p].ch[c]; //"other"
			if(v[p].len+1 == v[o].len){
				v[cur].par = o;
			}
			else{
				int clone = sz++; //clone
				v[clone].ch = v[o].ch;
				v[clone].par = v[o].par;
				v[clone].len = v[p].len+1;
				while(p != -1 && v[p].ch[c] == o){
					//redirect all these to clone
					v[p].ch[c] = clone;
					p = v[p].par;
				}
				v[o].par = v[cur].par = clone;
			}
		}
		last = cur;
	}
	
	ll getsz(int x){
		if(v[x].cnt)
			return v[x].cnt;
		for(auto i: v[x].ch)
			v[x].cnt += getsz(i.second);
		return ++v[x].cnt;
	}
	
	// k-th lexographically least substring (empty string counts as the 0-th one)
	string kth(int cur, int k){
		assert(k < v[cur].cnt);
		if(!k) return "";
		k--;
		for(auto i: v[cur].ch){
			if(k < v[i.second].cnt)
				return i.first+kth(i.second, k);
			k -= v[i.second].cnt;
		}
		abort();
	}
};
