---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/bit.h
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: content/data_structures/lazy_segment_tree.h
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: content/data_structures/li_chao_tree.h
    title: Li Chao Tree
  - icon: ':heavy_check_mark:'
    path: content/data_structures/segment_tree.h
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: content/data_structures/sparse_table.h
    title: Sparse Table
  - icon: ':warning:'
    path: content/geometry/point.h
    title: Point
  - icon: ':warning:'
    path: content/geometry/polygon.h
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: content/string/manacher.h
    title: Manacher's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit.test.cpp
    title: tests/bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lazy_segment_tree.test.cpp
    title: tests/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_tree.test.cpp
    title: tests/li_chao_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/manacher.test.cpp
    title: tests/manacher.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/segment_tree.test.cpp
    title: tests/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_table.test.cpp
    title: tests/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/template.md
    document_title: My starter code
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\n"
  code: "/**\n * @brief My starter code\n * @docs docs/template.md\n */\n\n#include\
    \ <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef LOCAL\ntemplate<typename\
    \ T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename T, typename...\
    \ Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n#else\ntemplate<typename...\
    \ Args> void pr(Args... args){}\n#endif\n\nusing namespace std;\n"
  dependsOn: []
  isVerificationFile: false
  path: content/utils/template.h
  requiredBy:
  - content/geometry/point.h
  - content/geometry/polygon.h
  - content/data_structures/segment_tree.h
  - content/data_structures/lazy_segment_tree.h
  - content/data_structures/li_chao_tree.h
  - content/data_structures/bit.h
  - content/data_structures/sparse_table.h
  - content/string/manacher.h
  timestamp: '2021-07-04 14:49:31-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/li_chao_tree.test.cpp
  - tests/manacher.test.cpp
  - tests/segment_tree.test.cpp
  - tests/lazy_segment_tree.test.cpp
  - tests/bit.test.cpp
  - tests/sparse_table.test.cpp
documentation_of: content/utils/template.h
layout: document
redirect_from:
- /library/content/utils/template.h
- /library/content/utils/template.h.html
title: My starter code
---