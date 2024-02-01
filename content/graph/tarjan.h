#pragma once
#include "../utils/template.h"

/**
 * @brief Tarjan's algorithm
 * @docs docs/tarjan.md
 */

enum class TARJAN { SCC, BCC };

template <const TARJAN T>
struct tarjan {
	static constexpr bool isBCC = (T == TARJAN::BCC);
	int n, t, ii;
	vector<vector<pii>> adj;
	vector<int> dfn, low, id;
	vector<bool> ins;
	stack<int> stk;
	vector<vector<int>> comps;
	
	tarjan(int mm) : n(mm), t(0), ii(0), adj(mm), dfn(mm), low(mm), id(mm), ins(mm) {}
	
	void addedge(int a, int b) {
		if constexpr (!isBCC) {
			adj[a].emplace_back(b, 0);
		}
		else {
			adj[a].emplace_back(b, ii);
			adj[b].emplace_back(a, ii);
			ii++;
		}
	}

	void dfs(int cur, int pid) {
		dfn[cur] = low[cur] = ++t;
		stk.push(cur);
		ins[cur] = 1;

		for (auto [u, i]: adj[cur]) {
			if (isBCC and i == pid)
				continue;

			if (!dfn[u]) {
				dfs(u, i);
				low[cur] = min(low[cur], low[u]);
			}
			else if (!isBCC and ins[u])
				low[cur] = min(low[cur], dfn[u]);
		}
		
		if (dfn[cur] == low[cur]) {
			int u = -1;
			comps.emplace_back();
			while (u != cur) {
				u = stk.top(); stk.pop();
				ins[u] = 0;
				id[u] = cur;
				comps.back().emplace_back(u);
			}
		}
	}

	void run() {
		for (int i = 0; i < n; i++) {
			if (!dfn[i]) {
				dfs(i, -1);
			}
		}
	}
};

// https://en.wikipedia.org/wiki/Biconnected_component
// Any connected graph decomposes into a tree of biconnected components called the block-cut tree of the graph
// wait, shouldn't blockcut be the same then??

struct blockcut {
	int n, t, ei, ncomps;
	vector<vector<pii>> adj;
	vector<vector<int>> adj2, comps;
	vector<int> dfn, low, id;
	vector<bool> ins;
	stack<pii> st;
	set<int> art;
	
	blockcut(int mm) : n(mm), t(0), ei(0), ncomps(0), adj(mm), comps(mm), dfn(mm), low(mm), id(mm), ins(mm) {}
	
	void addedge(int a, int b) {
		adj[a].emplace_back(b, ei);
		adj[b].emplace_back(a, ei);
		ei++;
	}

	void process(int u, int v){
		if (st.empty()) return;
		while (st.size()) {
			pii e = st.top(); st.pop();
			comps[ncomps].push_back(e.first);
			comps[ncomps].push_back(e.second);
			if (e == pii(u, v))
				break;
		}
		ncomps++;
	}

	void dfs(int cur, int pi = -1) {
		dfn[cur] = low[cur] = ++t;
		int ch = 0;
		for (auto [u, i]: adj[cur]) {
			if (i == pi) continue;
			if (!dfn[u]) {
				ch++;
				st.emplace(cur, u);
				dfs(u, i);
				
				low[cur] = min(low[cur], low[u]);
				
				if ((pi == -1 and ch > 1) or (pi != -1 and low[u] >= dfn[cur])) {
					art.insert(cur);
					process(cur, u);
				}
			}
			else
				low[cur] = min(low[cur], dfn[u]);
		}
	}

	// Block leaders are numbered [n, n + ncomps)
	int run() {
		for (int i = 0; i < n; i++) {
			if (!dfn[i]) {
				st.emplace(i, i); // for components with only one vertex?
				dfs(i, -1);
				process(-1, -1);
			}
		}
		comps.resize(ncomps);
		adj2.resize(n+ncomps);
		for (int i = 0; i < ncomps; i++) {
			sort(all(comps[i]));
			makeunique(comps[i]);
			for (int u: comps[i]) {
				adj2[n+i].push_back(u);
				adj2[u].push_back(n+i);
			}
		}
		return n + ncomps;
	}
};

