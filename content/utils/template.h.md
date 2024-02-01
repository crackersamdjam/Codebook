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
    path: content/graph/flow/hopcroft_karp.h
    title: Hopcroft Karp
  - icon: ':heavy_check_mark:'
    path: content/graph/tarjan.h
    title: Tarjan's algorithm
  - icon: ':warning:'
    path: content/math/fraction.h
    title: Fraction Class
  - icon: ':warning:'
    path: content/string/kmp.h
    title: Knuth-Morris-Pratt Algorithm
  - icon: ':heavy_check_mark:'
    path: content/string/manacher.h
    title: Manacher's Algorithm
  - icon: ':heavy_check_mark:'
    path: content/string/suffix_array.h
    title: Suffix Array (in O(n log n))
  - icon: ':warning:'
    path: content/string/suffix_automaton.h
    title: Suffix Automaton
  - icon: ':heavy_check_mark:'
    path: content/string/z_algorithm.h
    title: Z Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aplusb.test.cpp
    title: tests/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/atcoder.test.cpp
    title: tests/atcoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bit.test.cpp
    title: tests/bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hopcroft_karp.test.cpp
    title: tests/hopcroft_karp.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array.test.cpp
    title: tests/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tarjan_bcc.test.cpp
    title: tests/tarjan_bcc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tarjan_scc.test.cpp
    title: tests/tarjan_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/z_algorithm.test.cpp
    title: tests/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: My starter code
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n"
  code: "/**\n * @brief My starter code\n */\n\n#include <bits/stdc++.h>\n#define\
    \ all(x) (x).begin(), (x).end()\n#define makeunique(x) (x).erase(unique((x).begin(),\
    \ (x).end()), (x).end());\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\nusing pii = pair<int, int>;\n"
  dependsOn: []
  isVerificationFile: false
  path: content/utils/template.h
  requiredBy:
  - content/graph/tarjan.h
  - content/graph/flow/hopcroft_karp.h
  - content/geometry/point.h
  - content/geometry/polygon.h
  - content/data_structures/li_chao_tree.h
  - content/data_structures/bit.h
  - content/data_structures/lazy_segment_tree.h
  - content/data_structures/segment_tree.h
  - content/data_structures/sparse_table.h
  - content/string/z_algorithm.h
  - content/string/suffix_array.h
  - content/string/manacher.h
  - content/string/suffix_automaton.h
  - content/string/kmp.h
  - content/math/fraction.h
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lazy_segment_tree.test.cpp
  - tests/li_chao_tree.test.cpp
  - tests/z_algorithm.test.cpp
  - tests/manacher.test.cpp
  - tests/tarjan_bcc.test.cpp
  - tests/bit.test.cpp
  - tests/atcoder.test.cpp
  - tests/aplusb.test.cpp
  - tests/hopcroft_karp.test.cpp
  - tests/tarjan_scc.test.cpp
  - tests/segment_tree.test.cpp
  - tests/sparse_table.test.cpp
  - tests/suffix_array.test.cpp
documentation_of: content/utils/template.h
layout: document
redirect_from:
- /library/content/utils/template.h
- /library/content/utils/template.h.html
title: My starter code
---
