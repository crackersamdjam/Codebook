#pragma once
#include "../../utils/template.h"

/**
 * @brief Hopcroft Karp
 * @docs docs/hopcroft_karp.md
 */

struct hopcroft_karp{
	vector<vector<int>> adj;
	vector<int> btoa;
	
	bool dfs(int cur, int L, vector<int>& A, vector<int>& B){
		if(A[cur] != L)
			return 0;
		A[cur] = -1;
		for(int u: adj[cur]){
			if(B[u] == L+1){
				B[u] = 0;
				if(btoa[u] == -1 or dfs(btoa[u], L+1, A, B))
					return btoa[u] = cur, 1;
			}
		}
		return 0;
	}
	
	vector<pair<int, int>> run(){
		vector<int> A(adj.size()), B(btoa.size()), cur, nx;
		while(1){
			fill(all(A), 0);
			fill(all(B), 0);
			/// Find the starting nodes for BFS (i.e. layer 0).
			cur.clear();
			for(int i: btoa){
				if(~i){
					A[i] = -1;
				}
			}
			
			for(int i = 0; i < size(adj); i++){
				if(A[i] == 0){
					cur.push_back(i);
				}
			}
			/// Find all layers using bfs.
			for(int lay = 1;; lay++){
				bool islast = 0;
				nx.clear();
				for(int i: cur){
					for(int j: adj[i]){
						if(btoa[j] == -1){
							B[j] = lay;
							islast = 1;
						}
						else if(btoa[j] != i and !B[j]){
							B[j] = lay;
							nx.push_back(btoa[j]);
						}
					}
				}
				if(islast) break;
				if(nx.empty()) goto out;
				for(int i: nx){
					A[i] = lay;
				}
				swap(cur, nx);
			}
			/// Use DFS to scan for augmenting paths.
			for(int i = 0; i < size(adj); i++)
				dfs(i, 0, A, B);
		}
		out:;
		vector<pair<int, int>> matching;
		for(int i = 0; i < size(btoa); i++){
			if(~btoa[i]){
				matching.emplace_back(btoa[i], i);
			}
		}
		return matching;
	}
};