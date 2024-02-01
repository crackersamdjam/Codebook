#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../content/graph/tarjan.h"

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	tarjan<TARJAN::SCC> t(n+5);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		if (a != b)
			t.adj[a].emplace_back(b);
	}
	for (int i = 0; i < n; i++) {
		if (!t.dfn[i])
			t.dfs(i);
	}
	cout << size(t.comps) << '\n';
	reverse(all(t.comps));
	for (auto &&v : t.comps) {
		cout << size(v);
		for (auto i : v)
			cout << ' ' << i;
		cout << '\n';
	}
}
