#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../content/data_structures/lazy_segment_tree.h"

using ll = long long;
using pll = pair<ll, ll>;
constexpr ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, q;
	cin>>n>>q;
	
	lazy_segment_tree<ll, pll> ST;
	ST.init(n+5, 0, pll(1, 0),
		[](auto x, auto y){ return (x+y) % mod; },
		[](auto x, auto y, int l, int r){ return (x*y.first + (r-l+1)*y.second) % mod; },
		[](auto x, auto y){ return pll(x.first*y.first % mod, (y.first*x.second + y.second) % mod); }
		);
	
	for(int i = 0; i < n; i++){
		ll a;
		cin>>a;
		ST.update(i, i, {0, a});
	}
	while(q--){
		int op;
		cin>>op;
		if(op == 0){
			int l, r; ll b, c;
			cin>>l>>r>>b>>c;
			ST.update(l, r-1, {b, c});
		}
		else{
			int l, r;
			cin>>l>>r;
			auto a = ST.query(l, r-1);
			cout<<a<<'\n';
		}
	}
}