---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sparse_table.test.cpp
    title: tests/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/data_structures/sparse_table.h\"\
    \n\n/**\n * @brief Sparse Table\n * @docs docs/sparse_table.md\n */\n\ntemplate<class\
    \ T> struct sparse_table{\n\t\n\tint n; vector<vector<T>> sp;\n\tfunction<T(T,\
    \ T)> merge;\n\t\n\tT query(int l, int r){\n\t\tint k = __lg(r-l+1);\n\t\treturn\
    \ merge(sp[k][l], sp[k][r-(1<<k)+1]);\n\t}\n\tvoid build(vector<T> v, function<T(T,\
    \ T)> f){\n\t\tmerge = f;\n\t\tn = size(v);\n\t\tsp.resize(__lg(n)+1);\n\t\tsp[0]\
    \ = v;\n\t\tfor(int i = 1; i <= __lg(n); i++){\n\t\t\tsp[i].resize(n, -1);\n\t\
    \t\tfor(int j = 0; j+(1<<i)-1 < n; j++){\n\t\t\t\tsp[i][j] = merge(sp[i-1][j],\
    \ sp[i-1][j+(1<<(i-1))]);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Sparse Table\n\
    \ * @docs docs/sparse_table.md\n */\n\ntemplate<class T> struct sparse_table{\n\
    \t\n\tint n; vector<vector<T>> sp;\n\tfunction<T(T, T)> merge;\n\t\n\tT query(int\
    \ l, int r){\n\t\tint k = __lg(r-l+1);\n\t\treturn merge(sp[k][l], sp[k][r-(1<<k)+1]);\n\
    \t}\n\tvoid build(vector<T> v, function<T(T, T)> f){\n\t\tmerge = f;\n\t\tn =\
    \ size(v);\n\t\tsp.resize(__lg(n)+1);\n\t\tsp[0] = v;\n\t\tfor(int i = 1; i <=\
    \ __lg(n); i++){\n\t\t\tsp[i].resize(n, -1);\n\t\t\tfor(int j = 0; j+(1<<i)-1\
    \ < n; j++){\n\t\t\t\tsp[i][j] = merge(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);\n\t\
    \t\t}\n\t\t}\n\t}\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/data_structures/sparse_table.h
  requiredBy: []
  timestamp: '2021-07-13 15:53:41-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sparse_table.test.cpp
documentation_of: content/data_structures/sparse_table.h
layout: document
redirect_from:
- /library/content/data_structures/sparse_table.h
- /library/content/data_structures/sparse_table.h.html
title: Sparse Table
---
There is a separate template for binary lifting. This one is just for range queries.
