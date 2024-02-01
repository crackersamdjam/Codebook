#pragma once
#include "../utils/template.h"

/**
 * @brief Tarjan's algorithm
 */

enum class TARJAN { SCC, BCC };
// add a flag for if we want articulation points

template <TARJAN arg = TARJAN::SCC>
struct tarjan {
	vector<vector<int>> adj;
	vector<int> dfn, low, id;
	vector<bool> ins;
	int t;
	stack<int> stk;
	vector<vector<int>> comps;
	
	tarjan(int MM) : adj(MM), dfn(MM), low(MM), id(MM), ins(MM), t(0) {}
	
	void dfs(int cur) {
		dfn[cur] = low[cur] = ++t;
		stk.push(cur);
		ins[cur] = 1;
		
		for(auto u: adj[cur]){
			if constexpr (arg == TARJAN::BCC) {
				// don't take same edge back
			}
			if (!dfn[u]) {
				dfs(u);
				low[cur] = min(low[cur], low[u]);
			}
			else if (arg == TARJAN::BCC or ins[u])
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
