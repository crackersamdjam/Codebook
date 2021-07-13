---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit.test.cpp
    title: tests/bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/bit.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/data_structures/bit.h\"\
    \n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/bit.md\n */\n\ntemplate<class\
    \ T> struct bit{\n\tint SZ;\n\tvector<T> bit;\n\tfunction<T(T, T)> merge;\n\t\n\
    \tvoid init(int n, T def, function<T(T, T)> f){\n\t\tSZ = n;\n\t\tbit.resize(SZ,\
    \ def);\n\t\tmerge = f;\n\t}\n\tvoid update(int i, T v){\n\t\tfor(; i < SZ; i\
    \ += i&-i)\n\t\t\tbit[i] = merge(bit[i], v);\n\t}\n\tT query(int i){\n\t\tT x\
    \ = bit[0];\n\t\tfor(; i; i -= i&-i)\n\t\t\tx = merge(x, bit[i]);\n\t\treturn\
    \ x;\n\t}\n};\n\ntemplate<class T> struct range_bit{\n\tbit<T> T1, T2;\n\tfunction<T(T,\
    \ T)> unmerge;\n\n\tvoid init(int n, T def, function<T(T, T)> f, function<T(T,\
    \ T)> g){\n\t\tT1.init(n, def, f);\n\t\tT2.init(n, def, f);\n\t\tunmerge = g;\n\
    \t}\n\tT query(int i){\n\t\treturn i*T1.query(i)-T2.query(i);\n\t}\n\tT query(int\
    \ l, int r){\n\t\treturn unmerge(query(r), query(l-1));\n\t}\n\tvoid update(int\
    \ l, int r, T v){\n\t\tT1.update(l, v);\n\t\tT1.update(r+1, -v);\n\t\tT2.update(l,\
    \ v*(l-1));\n\t\tT2.update(r+1, -v*r);\n\t}\n\tvoid update(int l, T v){\n\t\t\
    update(l, l, v);\n\t}\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Binary Indexed\
    \ Tree\n * @docs docs/bit.md\n */\n\ntemplate<class T> struct bit{\n\tint SZ;\n\
    \tvector<T> bit;\n\tfunction<T(T, T)> merge;\n\t\n\tvoid init(int n, T def, function<T(T,\
    \ T)> f){\n\t\tSZ = n;\n\t\tbit.resize(SZ, def);\n\t\tmerge = f;\n\t}\n\tvoid\
    \ update(int i, T v){\n\t\tfor(; i < SZ; i += i&-i)\n\t\t\tbit[i] = merge(bit[i],\
    \ v);\n\t}\n\tT query(int i){\n\t\tT x = bit[0];\n\t\tfor(; i; i -= i&-i)\n\t\t\
    \tx = merge(x, bit[i]);\n\t\treturn x;\n\t}\n};\n\ntemplate<class T> struct range_bit{\n\
    \tbit<T> T1, T2;\n\tfunction<T(T, T)> unmerge;\n\n\tvoid init(int n, T def, function<T(T,\
    \ T)> f, function<T(T, T)> g){\n\t\tT1.init(n, def, f);\n\t\tT2.init(n, def, f);\n\
    \t\tunmerge = g;\n\t}\n\tT query(int i){\n\t\treturn i*T1.query(i)-T2.query(i);\n\
    \t}\n\tT query(int l, int r){\n\t\treturn unmerge(query(r), query(l-1));\n\t}\n\
    \tvoid update(int l, int r, T v){\n\t\tT1.update(l, v);\n\t\tT1.update(r+1, -v);\n\
    \t\tT2.update(l, v*(l-1));\n\t\tT2.update(r+1, -v*r);\n\t}\n\tvoid update(int\
    \ l, T v){\n\t\tupdate(l, l, v);\n\t}\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/data_structures/bit.h
  requiredBy: []
  timestamp: '2021-07-13 15:53:41-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bit.test.cpp
documentation_of: content/data_structures/bit.h
layout: document
redirect_from:
- /library/content/data_structures/bit.h
- /library/content/data_structures/bit.h.html
title: Binary Indexed Tree
---
### Reversable Functions

Standard BIT supports the following for reversable functions:
- point update + point query
- point update + range query
- range update + point query

To do range update + range query, use range_bit.

### Non-reversable Functions

The only operations supported for non-reversable functions are:
- point update + prefix query
- suffix update + point query
