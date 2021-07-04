---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/sparse_table.h
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"tests/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\nusing namespace\
    \ std;\n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#line 7 \"content/utils/template.h\"\n#define\
    \ all(x) (x).begin(), (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T\
    \ a){std::cerr<<a<<std::endl;}\ntemplate<typename T, typename... Args> void pr(T\
    \ a, Args... args){std::cerr<<a<<' ',pr(args...);}\n#else\ntemplate<typename...\
    \ Args> void pr(Args... args){}\n#endif\n\nusing namespace std;\n#line 3 \"content/data_structures/sparse_table.h\"\
    \n\n/**\n * @brief Sparse Table\n * @docs docs/sparse_table.md\n * @info todo:\
    \ let this do operations other than just range max\n */\n\ntemplate<class T> struct\
    \ sparse_table{\n\tint n; vector<vector<T>> sp;\n\tT query(int l, int r){\n\t\t\
    int k = __lg(r-l+1);\n\t\treturn min(sp[k][l], sp[k][r-(1<<k)+1]);\n\t}\n\tvoid\
    \ build(vector<T> v){\n\t\tn = size(v);\n\t\tsp.resize(__lg(n)+1);\n\t\tsp[0]\
    \ = v;\n\t\tfor(int i = 1; i <= __lg(n); i++){\n\t\t\tsp[i].resize(n, -1);\n\t\
    \t\tfor(int j = 0; j+(1<<i)-1 < n; j++){\n\t\t\t\tsp[i][j] = min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n#line 6 \"tests/staticrmq.test.cpp\"\n\nint main(){\n\
    \tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\
    \tvector<int> v(n);\n\tfor(auto &i: v)\n\t\tcin>>i;\n\t\n\tsparse_table<int> sp;\n\
    \tsp.build(v);\n\t\n\twhile(q--){\n\t\tint l, r;\n\t\tcin>>l>>r;\n\t\tcout<<sp.query(l,\
    \ r-1)<<'\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    #define all(x) (x).begin(), (x).end()\nusing namespace std;\n#include \"../content/data_structures/sparse_table.h\"\
    \n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\t\n\tint n,\
    \ q;\n\tcin>>n>>q;\n\tvector<int> v(n);\n\tfor(auto &i: v)\n\t\tcin>>i;\n\t\n\t\
    sparse_table<int> sp;\n\tsp.build(v);\n\t\n\twhile(q--){\n\t\tint l, r;\n\t\t\
    cin>>l>>r;\n\t\tcout<<sp.query(l, r-1)<<'\\n';\n\t}\n}"
  dependsOn:
  - content/data_structures/sparse_table.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2021-07-04 14:49:31-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/tests/staticrmq.test.cpp
- /verify/tests/staticrmq.test.cpp.html
title: tests/staticrmq.test.cpp
---
