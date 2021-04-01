#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
#include "../content/data_structures/sparse_table.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin>>n>>q;
	vector<int> v(n);
	for(auto &i: v)
		cin>>i;
	
	sparse_table<int> sp;
	sp.build(v);
	
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<sp.query(l, r-1)<<'\n';
	}
}