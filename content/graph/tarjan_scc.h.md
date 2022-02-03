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
    _deprecated_at_docs: docs/tarjan_scc.md
    document_title: Tarjan SCC
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/graph/tarjan_scc.h\"\
    \n\n/**\n * @brief Tarjan SCC\n * @docs docs/tarjan_scc.md\n */\n\nstruct tarjan_scc{\n\
    \tvector<vector<int>> adj;\n\tvector<int> dfn, low, id;\n\tint t;\n\tvector<bool>\
    \ ins;\n\tstack<int> stk;\n\tvector<vector<int>> scc;\n\t\n\ttarjan_scc(int MM){\n\
    \t\tadj.resize(MM);\n\t\tdfn.resize(MM);\n\t\tlow.resize(MM);\n\t\tid.resize(MM);\n\
    \t\tt = 0;\n\t\tins.resize(MM);\n\t}\n\t\n\tvoid dfs(int cur){\n\t\tdfn[cur] =\
    \ low[cur] = ++t;\n\t\tstk.push(cur);\n\t\tins[cur] = 1;\n\t\t\n\t\tfor(auto u:\
    \ adj[cur]){\n\t\t\tif(!dfn[u]){\n\t\t\t\tdfs(u);\n\t\t\t\tlow[cur] = min(low[cur],\
    \ low[u]);\n\t\t\t}\n\t\t\telse if(ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\
    \t\t}\n\t\t\n\t\tif(dfn[cur] == low[cur]){\n\t\t\tint u = -1;\n\t\t\tscc.emplace_back();\n\
    \t\t\twhile(u != cur){\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\
    \t\t\t\tid[u] = cur;\n\t\t\t\tscc.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t\
    }\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Tarjan SCC\n\
    \ * @docs docs/tarjan_scc.md\n */\n\nstruct tarjan_scc{\n\tvector<vector<int>>\
    \ adj;\n\tvector<int> dfn, low, id;\n\tint t;\n\tvector<bool> ins;\n\tstack<int>\
    \ stk;\n\tvector<vector<int>> scc;\n\t\n\ttarjan_scc(int MM){\n\t\tadj.resize(MM);\n\
    \t\tdfn.resize(MM);\n\t\tlow.resize(MM);\n\t\tid.resize(MM);\n\t\tt = 0;\n\t\t\
    ins.resize(MM);\n\t}\n\t\n\tvoid dfs(int cur){\n\t\tdfn[cur] = low[cur] = ++t;\n\
    \t\tstk.push(cur);\n\t\tins[cur] = 1;\n\t\t\n\t\tfor(auto u: adj[cur]){\n\t\t\t\
    if(!dfn[u]){\n\t\t\t\tdfs(u);\n\t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\
    \t}\n\t\t\telse if(ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\
    \t\t\n\t\tif(dfn[cur] == low[cur]){\n\t\t\tint u = -1;\n\t\t\tscc.emplace_back();\n\
    \t\t\twhile(u != cur){\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\
    \t\t\t\tid[u] = cur;\n\t\t\t\tscc.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t\
    }\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/graph/tarjan_scc.h
  requiredBy: []
  timestamp: '2022-02-02 21:01:45-05:00'
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
