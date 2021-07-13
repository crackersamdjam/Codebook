#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../content/string/suffix_array.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	string s;
	cin>>s;
	auto v = suffix_array_construction(s, 'z'+1);
	for(int i: v)
		cout<<i<<' ';
}