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
    path: content/data_structures/segment_tree.h
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: content/data_structures/sparse_table.h
    title: Sparse Table
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit.test.cpp
    title: tests/bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lazy_segment_tree.test.cpp
    title: tests/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/segment_tree.test.cpp
    title: tests/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/staticrmq.test.cpp
    title: tests/staticrmq.test.cpp
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
  - content/data_structures/segment_tree.h
  - content/data_structures/lazy_segment_tree.h
  - content/data_structures/bit.h
  - content/data_structures/sparse_table.h
  timestamp: '2021-07-04 14:49:31-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segment_tree.test.cpp
  - tests/lazy_segment_tree.test.cpp
  - tests/bit.test.cpp
  - tests/staticrmq.test.cpp
documentation_of: content/utils/template.h
layout: document
redirect_from:
- /library/content/utils/template.h
- /library/content/utils/template.h.html
title: My starter code
---
