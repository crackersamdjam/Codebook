#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
	sp.build(v, [](int x, int y){ return min(x, y);});
	
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<sp.query(l, r-1)<<'\n';
	}
}