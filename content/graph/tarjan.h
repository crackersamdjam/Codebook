#pragma once
#include "../utils/template.h"

/**
 * @brief Tarjan's algorithm
 * @docs docs/tarjan.md
 */

struct tarjan_scc {
	vector<vector<int>> adj;
	vector<int> dfn, low, id;
	vector<bool> ins;
	int t;
	stack<int> stk;
	vector<vector<int>> comps;
	
	tarjan_scc(int mm) : adj(mm), dfn(mm), low(mm), id(mm), ins(mm), t(0) {}
	
	// todo: store the previous edge id instead of previous node in case of multiple edges
	void dfs(int cur, int pre = -1) {
		dfn[cur] = low[cur] = ++t;
		stk.push(cur);
		ins[cur] = 1;
		
		for (int u: adj[cur]) {
			if (!dfn[u]) {
				dfs(u, cur);
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
};

struct tarjan_bcc {
	int n, t, ei, ncomps;
	vector<vector<pair<int, int>>> adj;
	vector<vector<int>> adj2, comps;
	vector<int> dfn, low, id;
	vector<bool> ins;
	stack<pii> st;
	set<int> art;
	
	tarjan_bcc(int nn) : n(nn), adj(nn), adj2(nn), dfn(nn), low(nn), id(nn), ins(nn), t(0), ei(0), ncomps(0) {}
	
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

	void run() {
		for(int i = 0; i < n; i++){
			if(!dfn[i]){
				dfs(i, -1);
				process(-1, -1);
			}
		}
	}

	// new components are numbered [n, n+tt)
	int constructBCT() {
		for(int i = 0; i < ncomps; i++){
			sort(all(comps[i]));
			comps[i].erase(unique(all(comps[i])), comps[i].end());
			for(int u: comps[i]){
				adj2[n+i].push_back(u);
				adj2[u].push_back(n+i);
			}
		}
		return ncomps;
	}
};

