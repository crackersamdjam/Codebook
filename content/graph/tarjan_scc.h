#pragma once
#include "../utils/template.h"

/**
 * @brief Tarjan SCC
 * @docs docs/tarjan_scc.md
 */

struct tarjan_scc{
	vector<vector<int>> adj;
	vector<int> dfn, low, id;
	int t;
	vector<bool> ins;
	stack<int> stk;
	vector<vector<int>> scc;
	
	tarjan_scc(int MM){
		adj.resize(MM);
		dfn.resize(MM);
		low.resize(MM);
		id.resize(MM);
		t = 0;
		ins.resize(MM);
	}
	
	void dfs(int cur){
		dfn[cur] = low[cur] = ++t;
		stk.push(cur);
		ins[cur] = 1;
		
		for(auto u: adj[cur]){
			if(!dfn[u]){
				dfs(u);
				low[cur] = min(low[cur], low[u]);
			}
			else if(ins[u])
				low[cur] = min(low[cur], dfn[u]);
		}
		
		if(dfn[cur] == low[cur]){
			int u = -1;
			scc.emplace_back();
			while(u != cur){
				u = stk.top(); stk.pop();
				ins[u] = 0;
				id[u] = cur;
				scc.back().emplace_back(u);
			}
		}
	}
};