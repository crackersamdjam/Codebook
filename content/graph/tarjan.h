#pragma once
#include "../utils/template.h"

/**
 * @brief Tarjan's algorithm
 * @docs docs/tarjan.md
 */

struct SCC {
	int n, t, ii;
	vector<vector<int>> adj;
	vector<int> dfn, low, id;
	vector<bool> ins;
	stack<int> stk;
	vector<vector<int>> comps;
	
	SCC(int mm) : n(mm), t(0), ii(0), adj(mm), dfn(mm), low(mm), id(mm), ins(mm) {}
	
	void addedge(int a, int b) {
		adj[a].emplace_back(b);
	}

	void dfs(int cur) {
		dfn[cur] = low[cur] = ++t;
		stk.push(cur);
		ins[cur] = 1;

		for (int u: adj[cur]) {
			if (!dfn[u]) {
				dfs(u);
				low[cur] = min(low[cur], low[u]);
			}
			else if (ins[u])
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
				dfs(i);
			}
		}
	}
};

// Any connected graph decomposes into a tree of **biconnected components (BCCs)** called the **block-cut** tree of the graph
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
				st.emplace(i, i); // for components with only one vertex? // is there a way to do this with stack<int> instead of the pairs?
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

