#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../content/data_structures/li_chao_tree.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, q;
	cin>>n>>q;
	
	sparse_li_chao_tree<ll> st;
	st.init(-1e9, 1e9, LLONG_MAX, [](auto x, auto y){ return min(x, y); });
	while(n--){
		ll a, b;
		cin>>a>>b;
		st.add({a, b});
	}
	while(q--){
		int op;
		cin>>op;
		if(op == 0){
			ll a, b;
			cin>>a>>b;
			st.add({a, b});
		}
		else{
			ll x;
			cin>>x;
			cout<<st.get(x)<<'\n';
		}
	}
}