#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../content/data_structures/segment_tree.h"

using p = pair<ll, ll>;
constexpr ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, q;
	cin>>n>>q;
	
	segment_tree<p, p> ST;
	ST.init(n+5, {1, 0},
		[](auto x, auto y){ return p(x.first*y.first % mod, (y.first*x.second + y.second) % mod); },
		[](auto x, auto y){ return y; });
	
	for(int i = 0; i < n; i++){
		ll a, b;
		cin>>a>>b;
		ST.update(i, {a, b});
	}
	while(q--){
		int op;
		cin>>op;
		if(op == 0){
			int i; ll a, b;
			cin>>i>>a>>b;
			ST.update(i, {a, b});
		}
		else{
			int l, r; ll x;
			cin>>l>>r>>x;
			auto [a, b] = ST.query(l, r-1);
			cout<<(a*x+b)%mod<<'\n';
		}
	}
}