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
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"tests/tarjan_blockcut_bccs.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/biconnected_components\"\n#line 1 \"content/utils/template.h\"\
    \n/**\n * @brief My starter code\n */\n\n#include <bits/stdc++.h>\n#define all(x)\
    \ (x).begin(), (x).end()\n#define makeunique(x) (x).erase(unique((x).begin(),\
    \ (x).end()), (x).end());\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    #line 3 \"content/graph/tarjan.h\"\n\n/**\n * @brief Tarjan's algorithm\n * @docs\
    \ docs/tarjan.md\n */\n\nstruct SCC {\n\tint n, t, ii;\n\tvector<vector<int>>\
    \ adj;\n\tvector<int> dfn, low, id;\n\tvector<bool> ins;\n\tstack<int> stk;\n\t\
    vector<vector<int>> comps;\n\t\n\tSCC(int mm) : n(mm), t(0), ii(0), adj(mm), dfn(mm),\
    \ low(mm), id(mm), ins(mm) {}\n\t\n\tvoid addedge(int a, int b) {\n\t\tadj[a].emplace_back(b);\n\
    \t}\n\n\tvoid dfs(int cur) {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tstk.push(cur);\n\
    \t\tins[cur] = 1;\n\n\t\tfor (int u: adj[cur]) {\n\t\t\tif (!dfn[u]) {\n\t\t\t\
    \tdfs(u);\n\t\t\t\tlow[cur] = min(low[cur], low[u]);\n\t\t\t}\n\t\t\telse if (ins[u])\n\
    \t\t\t\tlow[cur] = min(low[cur], dfn[u]);\n\t\t}\n\t\t\n\t\tif (dfn[cur] == low[cur])\
    \ {\n\t\t\tint u = -1;\n\t\t\tcomps.emplace_back();\n\t\t\twhile (u != cur) {\n\
    \t\t\t\tu = stk.top(); stk.pop();\n\t\t\t\tins[u] = 0;\n\t\t\t\tid[u] = cur;\n\
    \t\t\t\tcomps.back().emplace_back(u);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid run() {\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (!dfn[i]) {\n\t\t\t\tdfs(i);\n\t\t\
    \t}\n\t\t}\n\t}\n};\n\n// Any connected graph decomposes into a tree of **biconnected\
    \ components (BCCs)** called the **block-cut** tree of the graph\nstruct blockcut\
    \ {\n\tint n, t, ei, ncomps;\n\tvector<vector<pii>> adj;\n\tvector<vector<int>>\
    \ adj2, comps;\n\tvector<int> dfn, low, id;\n\tvector<bool> ins;\n\tstack<int>\
    \ st;\n\tset<int> art;\n\t\n\tblockcut(int mm) : n(mm), t(0), ei(0), ncomps(0),\
    \ adj(mm), comps(mm), dfn(mm), low(mm), id(mm), ins(mm) {}\n\t\n\tvoid addedge(int\
    \ a, int b) {\n\t\tadj[a].emplace_back(b, ei);\n\t\tadj[b].emplace_back(a, ei);\n\
    \t\tei++;\n\t}\n\n\tvoid process(int cur){\n\t\tif (st.empty()) return;\n\t\t\
    while (st.size()) {\n\t\t\tint u = st.top(); st.pop();\n\t\t\tcomps[ncomps].push_back(u);\n\
    \t\t\tif (u == cur)\n\t\t\t\tbreak;\n\t\t}\n\t\tncomps++;\n\t}\n\n\tvoid dfs(int\
    \ cur, int pi = -1) {\n\t\tdfn[cur] = low[cur] = ++t;\n\t\tst.push(cur);\n\t\t\
    int ch = 0;\n\t\tfor (auto [u, i]: adj[cur]) {\n\t\t\tif (i == pi) continue;\n\
    \t\t\tif (!dfn[u]) {\n\t\t\t\tch++;\n\t\t\t\tdfs(u, i);\n\t\t\t\tlow[cur] = min(low[cur],\
    \ low[u]);\n\t\t\t\t\n\t\t\t\tif ((pi == -1 and ch > 1) or (pi != -1 and low[u]\
    \ >= dfn[cur])) {\n\t\t\t\t\tart.insert(cur);\n\t\t\t\t\tst.push(cur);\n\t\t\t\
    \t\tprocess(u);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse\n\t\t\t\tlow[cur] = min(low[cur],\
    \ dfn[u]);\n\t\t}\n\t}\n\n\t// Block leaders are numbered [n, n + ncomps)\n\t\
    int run() {\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (!dfn[i]) {\n\t\t\t\t\
    dfs(i, -1);\n\t\t\t\tst.push(i);\n\t\t\t\tprocess(-1); // pop stack until empty\n\
    \t\t\t}\n\t\t}\n\t\tcomps.resize(ncomps);\n\t\tadj2.resize(n+ncomps);\n\t\tfor\
    \ (int i = 0; i < ncomps; i++) {\n\t\t\tsort(all(comps[i]));\n\t\t\tmakeunique(comps[i]);\n\
    \t\t\tfor (int u: comps[i]) {\n\t\t\t\tadj2[n+i].push_back(u);\n\t\t\t\tadj2[u].push_back(n+i);\n\
    \t\t\t}\n\t\t}\n\t\treturn n + ncomps;\n\t}\n};\n\n#line 3 \"tests/tarjan_blockcut_bccs.test.cpp\"\
    \n\nint main() {\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \n\tint n, m;\n\tcin >> n >> m;\n\tblockcut t(n);\n\tfor (int i = 0, a, b; i <\
    \ m; i++) {\n\t\tcin >> a >> b;\n\t\tif (a != b) {\n\t\t\tt.addedge(a, b);\n\t\
    \t\tt.addedge(b, a);\n\t\t}\n\t}\n\tt.run();\n\tcout << size(t.comps) << '\\n';\n\
    \tfor (auto &&v : t.comps) {\n\t\tcout << size(v);\n\t\tfor (auto i : v)\n\t\t\
    \tcout << ' ' << i;\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#include \"../content/graph/tarjan.h\"\n\nint main() {\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\n\tint n, m;\n\tcin >> n >> m;\n\
    \tblockcut t(n);\n\tfor (int i = 0, a, b; i < m; i++) {\n\t\tcin >> a >> b;\n\t\
    \tif (a != b) {\n\t\t\tt.addedge(a, b);\n\t\t\tt.addedge(b, a);\n\t\t}\n\t}\n\t\
    t.run();\n\tcout << size(t.comps) << '\\n';\n\tfor (auto &&v : t.comps) {\n\t\t\
    cout << size(v);\n\t\tfor (auto i : v)\n\t\t\tcout << ' ' << i;\n\t\tcout << '\\\
    n';\n\t}\n}\n"
  dependsOn:
  - content/graph/tarjan.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/tarjan_blockcut_bccs.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 17:43:59-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tarjan_blockcut_bccs.test.cpp
layout: document
redirect_from:
- /verify/tests/tarjan_blockcut_bccs.test.cpp
- /verify/tests/tarjan_blockcut_bccs.test.cpp.html
title: tests/tarjan_blockcut_bccs.test.cpp
---
