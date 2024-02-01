---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tarjan_scc.test.cpp
    title: tests/tarjan_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Tarjan SCC
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\n#line 3 \"content/graph/tarjan_scc.h\"\n\n/**\n\
    \ * @brief Tarjan SCC\n */\n\nstruct tarjan_scc{\n\tvector<vector<int>> adj;\n\
    \tvector<int> dfn, low, id;\n\tvector<bool> ins;\n\tint t;\n\tstack<int> stk;\n\
    \tvector<vector<int>> scc;\n\t\n\ttarjan_scc(int MM) : adj(MM), dfn(MM), low(MM),\
    \ id(MM), ins(MM), t(0) {}\n\t\n\tvoid dfs(int cur){\n\t\tdfn[cur] = low[cur]\
    \ = ++t;\n\t\tstk.push(cur);\n\t\tins[cur] = 1;\n\t\t\n\t\tfor(auto u: adj[cur]){\n\
    \t\t\tif(!dfn[u]){\n\t\t\t\tdfs(u);\n\t\t\t\tlow[cur] = min(low[cur], low[u]);\n\
    \t\t\t}\n\t\t\telse if(ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t\
    }\n\t\t\n\t\tif(dfn[cur] == low[cur]){\n\t\t\tint u = -1;\n\t\t\tscc.emplace_back();\n\
    \t\t\twhile(u != cur){\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\
    \t\t\t\tid[u] = cur;\n\t\t\t\tscc.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t\
    }\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Tarjan SCC\n\
    \ */\n\nstruct tarjan_scc{\n\tvector<vector<int>> adj;\n\tvector<int> dfn, low,\
    \ id;\n\tvector<bool> ins;\n\tint t;\n\tstack<int> stk;\n\tvector<vector<int>>\
    \ scc;\n\t\n\ttarjan_scc(int MM) : adj(MM), dfn(MM), low(MM), id(MM), ins(MM),\
    \ t(0) {}\n\t\n\tvoid dfs(int cur){\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tstk.push(cur);\n\
    \t\tins[cur] = 1;\n\t\t\n\t\tfor(auto u: adj[cur]){\n\t\t\tif(!dfn[u]){\n\t\t\t\
    \tdfs(u);\n\t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t}\n\t\t\telse if(ins[u])\n\
    \t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\t\t\n\t\tif(dfn[cur] == low[cur]){\n\
    \t\t\tint u = -1;\n\t\t\tscc.emplace_back();\n\t\t\twhile(u != cur){\n\t\t\t\t\
    u = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\t\t\t\tid[u] = cur;\n\t\t\t\t\
    scc.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/graph/tarjan_scc.h
  requiredBy: []
  timestamp: '2024-02-01 09:33:50-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tarjan_scc.test.cpp
documentation_of: content/graph/tarjan_scc.h
layout: document
redirect_from:
- /library/content/graph/tarjan_scc.h
- /library/content/graph/tarjan_scc.h.html
title: Tarjan SCC
---
