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
    document_title: Tarjan's algorithm
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\n#line 3 \"content/graph/tarjan.h\"\n\n/**\n * @brief\
    \ Tarjan's algorithm\n */\n\nenum class TARJAN { SCC, BCC };\n// add a flag for\
    \ if we want articulationn points\n\ntemplate <TARJAN arg = TARJAN::SCC>\nstruct\
    \ tarjan {\n\tvector<vector<int>> adj;\n\tvector<int> dfn, low, id;\n\tvector<bool>\
    \ ins;\n\tint t;\n\tstack<int> stk;\n\tvector<vector<int>> comps;\n\t\n\ttarjan(int\
    \ MM) : adj(MM), dfn(MM), low(MM), id(MM), ins(MM), t(0) {}\n\t\n\tvoid dfs(int\
    \ cur) {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tstk.push(cur);\n\t\tins[cur] = 1;\n\
    \t\t\n\t\tfor(auto u: adj[cur]){\n\t\t\tif constexpr (arg == TARJAN::BCC) {\n\t\
    \t\t\t// don't take same edge back\n\t\t\t}\n\t\t\tif (!dfn[u]) {\n\t\t\t\tdfs(u);\n\
    \t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t}\n\t\t\telse if (arg == TARJAN::BCC\
    \ or ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\t\t\n\t\tif (dfn[cur]\
    \ == low[cur]) {\n\t\t\tint u = -1;\n\t\t\tcomps.emplace_back();\n\t\t\twhile\
    \ (u != cur) {\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\t\t\t\
    \tid[u] = cur;\n\t\t\t\tcomps.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Tarjan's\
    \ algorithm\n */\n\nenum class TARJAN { SCC, BCC };\n// add a flag for if we want\
    \ articulationn points\n\ntemplate <TARJAN arg = TARJAN::SCC>\nstruct tarjan {\n\
    \tvector<vector<int>> adj;\n\tvector<int> dfn, low, id;\n\tvector<bool> ins;\n\
    \tint t;\n\tstack<int> stk;\n\tvector<vector<int>> comps;\n\t\n\ttarjan(int MM)\
    \ : adj(MM), dfn(MM), low(MM), id(MM), ins(MM), t(0) {}\n\t\n\tvoid dfs(int cur)\
    \ {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tstk.push(cur);\n\t\tins[cur] = 1;\n\t\
    \t\n\t\tfor(auto u: adj[cur]){\n\t\t\tif constexpr (arg == TARJAN::BCC) {\n\t\t\
    \t\t// don't take same edge back\n\t\t\t}\n\t\t\tif (!dfn[u]) {\n\t\t\t\tdfs(u);\n\
    \t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t}\n\t\t\telse if (arg == TARJAN::BCC\
    \ or ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\t\t\n\t\tif (dfn[cur]\
    \ == low[cur]) {\n\t\t\tint u = -1;\n\t\t\tcomps.emplace_back();\n\t\t\twhile\
    \ (u != cur) {\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\t\t\t\
    \tid[u] = cur;\n\t\t\t\tcomps.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/graph/tarjan.h
  requiredBy: []
  timestamp: '2024-02-01 11:09:33-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tarjan_scc.test.cpp
documentation_of: content/graph/tarjan.h
layout: document
redirect_from:
- /library/content/graph/tarjan.h
- /library/content/graph/tarjan.h.html
title: Tarjan's algorithm
---
