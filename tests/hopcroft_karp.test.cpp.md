---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/graph/flow/hopcroft_karp.h
    title: Hopcroft Karp
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"tests/hopcroft_karp.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n */\n\n\
    #include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef LOCAL\n\
    template<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\n#line 3 \"content/graph/flow/hopcroft_karp.h\"\n\
    \n/**\n * @brief Hopcroft Karp\n */\n\nstruct hopcroft_karp{\n\tvector<vector<int>>\
    \ adj;\n\tvector<int> btoa;\n\t\n\tbool dfs(int cur, int L, vector<int>& A, vector<int>&\
    \ B){\n\t\tif(A[cur] != L)\n\t\t\treturn 0;\n\t\tA[cur] = -1;\n\t\tfor(int u:\
    \ adj[cur]){\n\t\t\tif(B[u] == L+1){\n\t\t\t\tB[u] = 0;\n\t\t\t\tif(btoa[u] ==\
    \ -1 or dfs(btoa[u], L+1, A, B))\n\t\t\t\t\treturn btoa[u] = cur, 1;\n\t\t\t}\n\
    \t\t}\n\t\treturn 0;\n\t}\n\t\n\tvector<pair<int, int>> run(){\n\t\tvector<int>\
    \ A(adj.size()), B(btoa.size()), cur, nx;\n\t\t// A stores the levels of left\
    \ side nodes, B stores the levels of right side nodes\n\t\twhile(1){\n\t\t\tfill(all(A),\
    \ 0);\n\t\t\tfill(all(B), 0);\n\t\t\tcur.clear();\n\t\t\t// Unmatched A nodes\
    \ are sources of first layer\n\t\t\tfor(int i: btoa)\n\t\t\t\tif(~i) A[i] = -1;\n\
    \t\t\tfor(int i = 0; i < size(adj); i++)\n\t\t\t\tif(A[i] == 0) cur.push_back(i);\n\
    \n\t\t\t/// Find all layers using BFS\n\t\t\tfor(int lay = 1;; lay++){\n\t\t\t\
    \tbool islast = 0;\n\t\t\t\tnx.clear();\n\t\t\t\tfor(int i: cur){\n\t\t\t\t\t\
    for(int j: adj[i]){\n\t\t\t\t\t\tif(btoa[j] == -1){\n\t\t\t\t\t\t\tB[j] = lay;\n\
    \t\t\t\t\t\t\tislast = 1;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse if(btoa[j] != i and\
    \ !B[j]){\n\t\t\t\t\t\t\tB[j] = lay;\n\t\t\t\t\t\t\tnx.push_back(btoa[j]);\n\t\
    \t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif(islast) break;\n\t\t\t\tif(nx.empty())\
    \ goto out;\n\t\t\t\tfor(int i: nx){\n\t\t\t\t\tA[i] = lay;\n\t\t\t\t}\n\t\t\t\
    \tswap(cur, nx);\n\t\t\t}\n\t\t\t/// Use DFS to scan for augmenting paths\n\t\t\
    \tfor(int i = 0; i < size(adj); i++)\n\t\t\t\tdfs(i, 0, A, B);\n\t\t}\n\t\tout:;\n\
    \t\tvector<pair<int, int>> matching;\n\t\tfor(int i = 0; i < size(btoa); i++){\n\
    \t\t\tif(~btoa[i]){\n\t\t\t\tmatching.emplace_back(btoa[i], i);\n\t\t\t}\n\t\t\
    }\n\t\treturn matching;\n\t}\n};\n#line 3 \"tests/hopcroft_karp.test.cpp\"\n\n\
    int main(){\n\thopcroft_karp h;\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\
    \tcin.exceptions(cin.failbit);\n\tint ls, rs, m;\n\tcin>>ls>>rs>>m;\n\th.adj.resize(ls+1);\n\
    \th.btoa.resize(rs+1, -1);\n\t\n\twhile(m--){\n\t\tint a, b;\n\t\tcin>>a>>b;\n\
    \t\th.adj[a].emplace_back(b);\n\t}\n\tauto ans = h.run();\n\tcout<<size(ans)<<'\\\
    n';\n\tfor(auto [a, b]: ans){\n\t\tcout<<a<<' '<<b<<'\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../content/graph/flow/hopcroft_karp.h\"\n\nint main(){\n\thopcroft_karp h;\n\
    \tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \tint ls, rs, m;\n\tcin>>ls>>rs>>m;\n\th.adj.resize(ls+1);\n\th.btoa.resize(rs+1,\
    \ -1);\n\t\n\twhile(m--){\n\t\tint a, b;\n\t\tcin>>a>>b;\n\t\th.adj[a].emplace_back(b);\n\
    \t}\n\tauto ans = h.run();\n\tcout<<size(ans)<<'\\n';\n\tfor(auto [a, b]: ans){\n\
    \t\tcout<<a<<' '<<b<<'\\n';\n\t}\n}"
  dependsOn:
  - content/graph/flow/hopcroft_karp.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/hopcroft_karp.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 09:33:50-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/hopcroft_karp.test.cpp
layout: document
redirect_from:
- /verify/tests/hopcroft_karp.test.cpp
- /verify/tests/hopcroft_karp.test.cpp.html
title: tests/hopcroft_karp.test.cpp
---
