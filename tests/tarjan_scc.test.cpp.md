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
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/graph/tarjan.h\"\
    \n\n/**\n * @brief Tarjan's algorithm\n * @docs docs/tarjan.md\n */\n\nstruct\
    \ tarjan_scc {\n\tvector<vector<int>> adj;\n\tvector<int> dfn, low, id;\n\tvector<bool>\
    \ ins;\n\tint t;\n\tstack<int> stk;\n\tvector<vector<int>> comps;\n\t\n\ttarjan_scc(int\
    \ mm) : adj(mm), dfn(mm), low(mm), id(mm), ins(mm), t(0) {}\n\t\n\t// todo: store\
    \ the previous edge id instead of previous node in case of multiple edges\n\t\
    void dfs(int cur, int pre = -1) {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tstk.push(cur);\n\
    \t\tins[cur] = 1;\n\t\t\n\t\tfor (int u: adj[cur]) {\n\t\t\tif (!dfn[u]) {\n\t\
    \t\t\tdfs(u, cur);\n\t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t}\n\t\t\t\
    else if (ins[u])\n\t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\t\t\n\t\t\
    if (dfn[cur] == low[cur]) {\n\t\t\tint u = -1;\n\t\t\tcomps.emplace_back();\n\t\
    \t\twhile (u != cur) {\n\t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\
    \t\t\t\tid[u] = cur;\n\t\t\t\tcomps.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t\
    }\n};\n\nstruct tarjan_bcc {\n\tint n, t, ei, ncomps;\n\tvector<vector<pair<int,\
    \ int>>> adj;\n\tvector<vector<int>> adj2, comps;\n\tvector<int> dfn, low, id;\n\
    \tvector<bool> ins;\n\tstack<pii> st;\n\tset<int> art;\n\t\n\ttarjan_bcc(int nn)\
    \ : n(nn), adj(nn), adj2(nn), dfn(nn), low(nn), id(nn), ins(nn), t(0), ei(0),\
    \ ncomps(0) {}\n\t\n\tvoid addedge(int a, int b) {\n\t\tadj[a].emplace_back(b,\
    \ ei);\n\t\tadj[b].emplace_back(a, ei);\n\t\tei++;\n\t}\n\n\tvoid process(int\
    \ u, int v){\n\t\tif (st.empty()) return;\n\t\twhile (st.size()) {\n\t\t\tpii\
    \ e = st.top(); st.pop();\n\t\t\tcomps[ncomps].push_back(e.first);\n\t\t\tcomps[ncomps].push_back(e.second);\n\
    \t\t\tif (e == pii(u, v))\n\t\t\t\tbreak;\n\t\t}\n\t\tncomps++;\n\t}\n\n\tvoid\
    \ dfs(int cur, int pi = -1) {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tint ch = 0;\n\
    \t\tfor (auto [u, i]: adj[cur]) {\n\t\t\tif (i == pi) continue;\n\t\t\tif (!dfn[u])\
    \ {\n\t\t\t\tch++;\n\t\t\t\tst.emplace(cur, u);\n\t\t\t\tdfs(u, i);\n\t\t\t\t\n\
    \t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t\t\n\t\t\t\tif ((pi == -1 and\
    \ ch > 1) or (pi != -1 and low[u] >= dfn[cur])) {\n\t\t\t\t\tart.insert(cur);\n\
    \t\t\t\t\tprocess(cur, u);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse\n\t\t\t\tlow[cur] =\
    \ min(low[cur], dfn[u]);\n\t\t}\n\t}\n\n\tvoid run() {\n\t\tfor(int i = 0; i <\
    \ n; i++){\n\t\t\tif(!dfn[i]){\n\t\t\t\tdfs(i, -1);\n\t\t\t\tprocess(-1, -1);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\t// new components are numbered [n, n+tt)\n\tint constructBCT()\
    \ {\n\t\tfor(int i = 0; i < ncomps; i++){\n\t\t\tsort(all(comps[i]));\n\t\t\t\
    comps[i].erase(unique(all(comps[i])), comps[i].end());\n\t\t\tfor(int u: comps[i]){\n\
    \t\t\t\tadj2[n+i].push_back(u);\n\t\t\t\tadj2[u].push_back(n+i);\n\t\t\t}\n\t\t\
    }\n\t\treturn ncomps;\n\t}\n};\n\n#line 3 \"tests/tarjan_scc.test.cpp\"\n\nint\
    \ main() {\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \n\tint n, m;\n\tcin >> n >> m;\n\ttarjan_scc t(n+5);\n\tfor (int i = 0, a, b;\
    \ i < m; i++) {\n\t\tcin >> a >> b;\n\t\tif (a != b)\n\t\t\tt.adj[a].emplace_back(b);\n\
    \t}\n\tfor (int i = 0; i < n; i++) {\n\t\tif (!t.dfn[i])\n\t\t\tt.dfs(i);\n\t\
    }\n\tcout << size(t.comps) << '\\n';\n\treverse(all(t.comps));\n\tfor (auto &&v\
    \ : t.comps) {\n\t\tcout << size(v);\n\t\tfor (auto i : v)\n\t\t\tcout << ' '\
    \ << i;\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../content/graph/tarjan.h\"\
    \n\nint main() {\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \n\tint n, m;\n\tcin >> n >> m;\n\ttarjan_scc t(n+5);\n\tfor (int i = 0, a, b;\
    \ i < m; i++) {\n\t\tcin >> a >> b;\n\t\tif (a != b)\n\t\t\tt.adj[a].emplace_back(b);\n\
    \t}\n\tfor (int i = 0; i < n; i++) {\n\t\tif (!t.dfn[i])\n\t\t\tt.dfs(i);\n\t\
    }\n\tcout << size(t.comps) << '\\n';\n\treverse(all(t.comps));\n\tfor (auto &&v\
    \ : t.comps) {\n\t\tcout << size(v);\n\t\tfor (auto i : v)\n\t\t\tcout << ' '\
    \ << i;\n\t\tcout << '\\n';\n\t}\n}\n"
  dependsOn:
  - content/graph/tarjan.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/tarjan_scc.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 15:45:45-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tarjan_scc.test.cpp
layout: document
redirect_from:
- /verify/tests/tarjan_scc.test.cpp
- /verify/tests/tarjan_scc.test.cpp.html
title: tests/tarjan_scc.test.cpp
---
