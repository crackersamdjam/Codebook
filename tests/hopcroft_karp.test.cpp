#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../content/graph/flow/hopcroft_karp.h"

int main(){
	hopcroft_karp h;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int ls, rs, m;
	cin>>ls>>rs>>m;
	h.adj.resize(ls+1);
	h.btoa.resize(rs+1, -1);
	
	while(m--){
		int a, b;
		cin>>a>>b;
		h.adj[a].emplace_back(b);
	}
	auto ans = h.run();
	cout<<size(ans)<<'\n';
	for(auto [a, b]: ans){
		cout<<a<<' '<<b<<'\n';
	}
}