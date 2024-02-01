#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "../content/graph/tarjan.h"

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	blockcut t(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		if (a != b) {
			t.addedge(a, b);
			t.addedge(b, a);
		}
	}
	t.run();
	cout << size(t.comps) << '\n';
	for (auto &&v : t.comps) {
		cout << size(v);
		for (auto i : v)
			cout << ' ' << i;
		cout << '\n';
	}
}
