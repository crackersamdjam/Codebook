#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../content/string/z_algorithm.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	string s;
	cin>>s;
	auto v = zed(s);
	v[0] = size(s);
	for(int i: v)
		cout<<i<<' ';
}