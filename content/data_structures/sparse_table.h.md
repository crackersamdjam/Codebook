---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/staticrmq.test.cpp
    title: tests/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"content/data_structures/sparse_table.h\"\n/**\n * @brief\
    \ Sparse Table\n * @docs docs/sparse_table.md\n * @info todo: let this do operations\
    \ other than just range max\n */\n\ntemplate<class T> struct sparse_table{\n\t\
    int n; vector<vector<T>> sp;\n\tT query(int l, int r){\n\t\tint k = __lg(r-l+1);\n\
    \t\treturn min(sp[k][l], sp[k][r-(1<<k)+1]);\n\t}\n\tvoid build(vector<T> v){\n\
    \t\tn = size(v);\n\t\tsp.resize(__lg(n)+1);\n\t\tsp[0] = v;\n\t\tfor(int i = 1;\
    \ i <= __lg(n); i++){\n\t\t\tsp[i].resize(n, -1);\n\t\t\tfor(int j = 0; j+(1<<i)-1\
    \ < n; j++){\n\t\t\t\tsp[i][j] = min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);\n\t\t\
    \t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n/**\n * @brief Sparse Table\n * @docs docs/sparse_table.md\n\
    \ * @info todo: let this do operations other than just range max\n */\n\ntemplate<class\
    \ T> struct sparse_table{\n\tint n; vector<vector<T>> sp;\n\tT query(int l, int\
    \ r){\n\t\tint k = __lg(r-l+1);\n\t\treturn min(sp[k][l], sp[k][r-(1<<k)+1]);\n\
    \t}\n\tvoid build(vector<T> v){\n\t\tn = size(v);\n\t\tsp.resize(__lg(n)+1);\n\
    \t\tsp[0] = v;\n\t\tfor(int i = 1; i <= __lg(n); i++){\n\t\t\tsp[i].resize(n,\
    \ -1);\n\t\t\tfor(int j = 0; j+(1<<i)-1 < n; j++){\n\t\t\t\tsp[i][j] = min(sp[i-1][j],\
    \ sp[i-1][j+(1<<(i-1))]);\n\t\t\t}\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: content/data_structures/sparse_table.h
  requiredBy: []
  timestamp: '2021-04-01 17:37:37-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/staticrmq.test.cpp
documentation_of: content/data_structures/sparse_table.h
layout: document
redirect_from:
- /library/content/data_structures/sparse_table.h
- /library/content/data_structures/sparse_table.h.html
title: Sparse Table
---
nothing yet
