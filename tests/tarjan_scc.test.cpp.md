---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/graph/tarjan.h
    title: Tarjan's algorithm
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"tests/tarjan_scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n */\n\n\
    #include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef LOCAL\n\
    template<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
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
    \tid[u] = cur;\n\t\t\t\tcomps.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t}\n};\n\
    #line 3 \"tests/tarjan_scc.test.cpp\"\n#define all(x) (x).begin(), (x).end()\n\
    \nusing namespace std;\n\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\
    \tcin.exceptions(cin.failbit);\n\t\n\tint n,m;\n\tcin>>n>>m;\n\ttarjan<TARJAN::SCC>\
    \ t(n+5);\n\tfor(int i = 0,a,b; i < m; i++){\n\t\tcin>>a>>b;\n\t\tif(a != b)\n\
    \t\t\tt.adj[a].emplace_back(b);\n\t}\n\tfor(int i = 0; i < n; i++){\n\t\tif(!t.dfn[i])\n\
    \t\t\tt.dfs(i);\n\t}\n\tcout<<size(t.comps)<<'\\n';\n\treverse(all(t.comps));\n\
    \tfor(auto &&v: t.comps){\n\t\tcout<<size(v);\n\t\tfor(auto i: v)\n\t\t\tcout<<'\
    \ '<<i;\n\t\tcout<<'\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../content/graph/tarjan.h\"\
    \n#define all(x) (x).begin(), (x).end()\n\nusing namespace std;\n\n\nint main(){\n\
    \tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tint n,m;\n\tcin>>n>>m;\n\ttarjan<TARJAN::SCC> t(n+5);\n\tfor(int i = 0,a,b;\
    \ i < m; i++){\n\t\tcin>>a>>b;\n\t\tif(a != b)\n\t\t\tt.adj[a].emplace_back(b);\n\
    \t}\n\tfor(int i = 0; i < n; i++){\n\t\tif(!t.dfn[i])\n\t\t\tt.dfs(i);\n\t}\n\t\
    cout<<size(t.comps)<<'\\n';\n\treverse(all(t.comps));\n\tfor(auto &&v: t.comps){\n\
    \t\tcout<<size(v);\n\t\tfor(auto i: v)\n\t\t\tcout<<' '<<i;\n\t\tcout<<'\\n';\n\
    \t}\n}\n"
  dependsOn:
  - content/graph/tarjan.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/tarjan_scc.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 11:09:33-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tarjan_scc.test.cpp
layout: document
redirect_from:
- /verify/tests/tarjan_scc.test.cpp
- /verify/tests/tarjan_scc.test.cpp.html
title: tests/tarjan_scc.test.cpp
---
