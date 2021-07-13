#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../content/data_structures/bit.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, q;
	cin>>n>>q;
	
	bit<ll> t;
	t.init(n+1, 0, [](auto x, auto y){ return x+y;});
	
	for(int i = 1,a; i <= n; i++){
		cin>>a;
		t.update(i, a);
	}
	
	while(q--){
		int op;
		cin>>op;
		if(op == 0){
			int i, x;
			cin>>i>>x;
			t.update(i+1, x);
		}
		else{
			int l, r;
			cin>>l>>r;
			cout<<t.query(r)-t.query(l)<<'\n';
		}
	}
}