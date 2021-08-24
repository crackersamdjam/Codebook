---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/hopcroft_karp.test.cpp
    title: tests/hopcroft_karp.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/hopcroft_karp.md
    document_title: Hopcroft Karp
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/graph/flow/hopcroft_karp.h\"\
    \n\n/**\n * @brief Hopcroft Karp\n * @docs docs/hopcroft_karp.md\n */\n\nstruct\
    \ hopcroft_karp{\n\tvector<vector<int>> adj;\n\tvector<int> btoa;\n\t\n\tbool\
    \ dfs(int cur, int L, vector<int>& A, vector<int>& B){\n\t\tif(A[cur] != L)\n\t\
    \t\treturn 0;\n\t\tA[cur] = -1;\n\t\tfor(int u: adj[cur]){\n\t\t\tif(B[u] == L+1){\n\
    \t\t\t\tB[u] = 0;\n\t\t\t\tif(btoa[u] == -1 or dfs(btoa[u], L+1, A, B))\n\t\t\t\
    \t\treturn btoa[u] = cur, 1;\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\t\n\tvector<pair<int,\
    \ int>> run(){\n\t\tvector<int> A(adj.size()), B(btoa.size()), cur, nx;\n\t\t\
    while(1){\n\t\t\tfill(all(A), 0);\n\t\t\tfill(all(B), 0);\n\t\t\t/// Find the\
    \ starting nodes for BFS (i.e. layer 0).\n\t\t\tcur.clear();\n\t\t\tfor(int i:\
    \ btoa){\n\t\t\t\tif(~i){\n\t\t\t\t\tA[i] = -1;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\n\t\
    \t\tfor(int i = 0; i < size(adj); i++){\n\t\t\t\tif(A[i] == 0){\n\t\t\t\t\tcur.push_back(i);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\t/// Find all layers using bfs.\n\t\t\tfor(int lay =\
    \ 1;; lay++){\n\t\t\t\tbool islast = 0;\n\t\t\t\tnx.clear();\n\t\t\t\tfor(int\
    \ i: cur){\n\t\t\t\t\tfor(int j: adj[i]){\n\t\t\t\t\t\tif(btoa[j] == -1){\n\t\t\
    \t\t\t\t\tB[j] = lay;\n\t\t\t\t\t\t\tislast = 1;\n\t\t\t\t\t\t}\n\t\t\t\t\t\t\
    else if(btoa[j] != i and !B[j]){\n\t\t\t\t\t\t\tB[j] = lay;\n\t\t\t\t\t\t\tnx.push_back(btoa[j]);\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif(islast) break;\n\t\t\t\tif(nx.empty())\
    \ goto out;\n\t\t\t\tfor(int i: nx){\n\t\t\t\t\tA[i] = lay;\n\t\t\t\t}\n\t\t\t\
    \tswap(cur, nx);\n\t\t\t}\n\t\t\t/// Use DFS to scan for augmenting paths.\n\t\
    \t\tfor(int i = 0; i < size(adj); i++)\n\t\t\t\tdfs(i, 0, A, B);\n\t\t}\n\t\t\
    out:;\n\t\tvector<pair<int, int>> matching;\n\t\tfor(int i = 0; i < size(btoa);\
    \ i++){\n\t\t\tif(~btoa[i]){\n\t\t\t\tmatching.emplace_back(btoa[i], i);\n\t\t\
    \t}\n\t\t}\n\t\treturn matching;\n\t}\n};\n"
  code: "#pragma once\n#include \"../../utils/template.h\"\n\n/**\n * @brief Hopcroft\
    \ Karp\n * @docs docs/hopcroft_karp.md\n */\n\nstruct hopcroft_karp{\n\tvector<vector<int>>\
    \ adj;\n\tvector<int> btoa;\n\t\n\tbool dfs(int cur, int L, vector<int>& A, vector<int>&\
    \ B){\n\t\tif(A[cur] != L)\n\t\t\treturn 0;\n\t\tA[cur] = -1;\n\t\tfor(int u:\
    \ adj[cur]){\n\t\t\tif(B[u] == L+1){\n\t\t\t\tB[u] = 0;\n\t\t\t\tif(btoa[u] ==\
    \ -1 or dfs(btoa[u], L+1, A, B))\n\t\t\t\t\treturn btoa[u] = cur, 1;\n\t\t\t}\n\
    \t\t}\n\t\treturn 0;\n\t}\n\t\n\tvector<pair<int, int>> run(){\n\t\tvector<int>\
    \ A(adj.size()), B(btoa.size()), cur, nx;\n\t\twhile(1){\n\t\t\tfill(all(A), 0);\n\
    \t\t\tfill(all(B), 0);\n\t\t\t/// Find the starting nodes for BFS (i.e. layer\
    \ 0).\n\t\t\tcur.clear();\n\t\t\tfor(int i: btoa){\n\t\t\t\tif(~i){\n\t\t\t\t\t\
    A[i] = -1;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\n\t\t\tfor(int i = 0; i < size(adj); i++){\n\
    \t\t\t\tif(A[i] == 0){\n\t\t\t\t\tcur.push_back(i);\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    /// Find all layers using bfs.\n\t\t\tfor(int lay = 1;; lay++){\n\t\t\t\tbool\
    \ islast = 0;\n\t\t\t\tnx.clear();\n\t\t\t\tfor(int i: cur){\n\t\t\t\t\tfor(int\
    \ j: adj[i]){\n\t\t\t\t\t\tif(btoa[j] == -1){\n\t\t\t\t\t\t\tB[j] = lay;\n\t\t\
    \t\t\t\t\tislast = 1;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse if(btoa[j] != i and !B[j]){\n\
    \t\t\t\t\t\t\tB[j] = lay;\n\t\t\t\t\t\t\tnx.push_back(btoa[j]);\n\t\t\t\t\t\t\
    }\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif(islast) break;\n\t\t\t\tif(nx.empty()) goto\
    \ out;\n\t\t\t\tfor(int i: nx){\n\t\t\t\t\tA[i] = lay;\n\t\t\t\t}\n\t\t\t\tswap(cur,\
    \ nx);\n\t\t\t}\n\t\t\t/// Use DFS to scan for augmenting paths.\n\t\t\tfor(int\
    \ i = 0; i < size(adj); i++)\n\t\t\t\tdfs(i, 0, A, B);\n\t\t}\n\t\tout:;\n\t\t\
    vector<pair<int, int>> matching;\n\t\tfor(int i = 0; i < size(btoa); i++){\n\t\
    \t\tif(~btoa[i]){\n\t\t\t\tmatching.emplace_back(btoa[i], i);\n\t\t\t}\n\t\t}\n\
    \t\treturn matching;\n\t}\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/graph/flow/hopcroft_karp.h
  requiredBy: []
  timestamp: '2021-08-24 16:05:27-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/hopcroft_karp.test.cpp
documentation_of: content/graph/flow/hopcroft_karp.h
layout: document
redirect_from:
- /library/content/graph/flow/hopcroft_karp.h
- /library/content/graph/flow/hopcroft_karp.h.html
title: Hopcroft Karp
---
