---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/lazy_segment_tree.test.cpp
    title: tests/lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lazy_segment_tree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\n#line 3 \"content/data_structures/lazy_segment_tree.h\"\
    \n\n/**\n * @brief Lazy Segment Tree\n * @docs docs/lazy_segment_tree.md\n * @info\n\
    \ *\n * todo: make \"find first in range\" (from cp algorthms) function\n * to\
    \ do that, I need a function to check if f(x, current) is good enough, and I also\
    \ need combine(current, val[rt])\n *\n */\n\ntemplate<class T, class L> struct\
    \ lazy_segment_tree{\n\tint SZ;\n\tvector<T> val;\n\tvector<L> lp;\n\tfunction<T(T,\
    \ T)> merge;\n\tfunction<T(T, L, int, int)> apply;\n\tfunction<L(L, L)> merge_lazy;\n\
    \t\n\tvoid init(int n, T def, L ldef, function<T(T, T)> f, function<T(T, L, int,\
    \ int)> g, function<L(L, L)> h){\n\t\tSZ = n;\n\t\tval.resize(__builtin_popcount(n)\
    \ == 1 ? 2*n : 4*n, def);\n\t\tlp.resize(size(val), ldef);\n\t\t// If n is a power\
    \ of 2, only 2n is needed. Otherwise 4n.\n\t\tmerge = f;\n\t\tapply = g;\n\t\t\
    merge_lazy = h;\n\t}\n\n\t#define lc (rt<<1)\n\t#define rc (rt<<1|1)\n\t#define\
    \ nm ((nl+nr)/2)\n\n\tvoid push(int nl, int nr, int rt){\n\t\tL &x = lp[rt];\n\
    \t\tval[lc] = apply(val[lc], x, nl, nm);\n\t\tlp[lc] = merge_lazy(lp[lc], x);\n\
    \t\tval[rc] = apply(val[rc], x, nm+1, nr);\n\t\tlp[rc] = merge_lazy(lp[rc], x);\n\
    \t\tx = lp[0];\n\t}\n\t\n\tT _query(int l, int r, int nl, int nr, int rt){\n\t\
    \tif(r < nl or nr < l) return val[0];\n\t\tif(l <= nl and nr <= r) return val[rt];\n\
    \t\tpush(nl, nr, rt);\n\t\treturn merge(_query(l, r, nl, nm, lc), _query(l, r,\
    \ nm+1, nr, rc));\n\t}\n\tT query(int l, int r){ return _query(l, r, 0, SZ-1,\
    \ 1); }\n\t\n\tvoid _update(int l, int r, L x, int nl, int nr, int rt){\n\t\t\
    if(r < nl or nr < l) return;\n\t\tif(l <= nl and nr <= r){\n\t\t\tval[rt] = apply(val[rt],\
    \ x, nl, nr);\n\t\t\tlp[rt] = merge_lazy(lp[rt], x);\n\t\t\treturn;\n\t\t}\n\t\
    \tpush(nl, nr, rt);\n\t\t_update(l, r, x, nl, nm, lc);\n\t\t_update(l, r, x, nm+1,\
    \ nr, rc);\n\t\tval[rt] = merge(val[lc], val[rc]);\n\t}\n\tvoid update(int l,\
    \ int r, L x){ _update(l, r, x, 0, SZ-1, 1); };\n\n\t#undef lc\n\t#undef rc\n\t\
    #undef nm\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Lazy Segment\
    \ Tree\n * @docs docs/lazy_segment_tree.md\n * @info\n *\n * todo: make \"find\
    \ first in range\" (from cp algorthms) function\n * to do that, I need a function\
    \ to check if f(x, current) is good enough, and I also need combine(current, val[rt])\n\
    \ *\n */\n\ntemplate<class T, class L> struct lazy_segment_tree{\n\tint SZ;\n\t\
    vector<T> val;\n\tvector<L> lp;\n\tfunction<T(T, T)> merge;\n\tfunction<T(T, L,\
    \ int, int)> apply;\n\tfunction<L(L, L)> merge_lazy;\n\t\n\tvoid init(int n, T\
    \ def, L ldef, function<T(T, T)> f, function<T(T, L, int, int)> g, function<L(L,\
    \ L)> h){\n\t\tSZ = n;\n\t\tval.resize(__builtin_popcount(n) == 1 ? 2*n : 4*n,\
    \ def);\n\t\tlp.resize(size(val), ldef);\n\t\t// If n is a power of 2, only 2n\
    \ is needed. Otherwise 4n.\n\t\tmerge = f;\n\t\tapply = g;\n\t\tmerge_lazy = h;\n\
    \t}\n\n\t#define lc (rt<<1)\n\t#define rc (rt<<1|1)\n\t#define nm ((nl+nr)/2)\n\
    \n\tvoid push(int nl, int nr, int rt){\n\t\tL &x = lp[rt];\n\t\tval[lc] = apply(val[lc],\
    \ x, nl, nm);\n\t\tlp[lc] = merge_lazy(lp[lc], x);\n\t\tval[rc] = apply(val[rc],\
    \ x, nm+1, nr);\n\t\tlp[rc] = merge_lazy(lp[rc], x);\n\t\tx = lp[0];\n\t}\n\t\n\
    \tT _query(int l, int r, int nl, int nr, int rt){\n\t\tif(r < nl or nr < l) return\
    \ val[0];\n\t\tif(l <= nl and nr <= r) return val[rt];\n\t\tpush(nl, nr, rt);\n\
    \t\treturn merge(_query(l, r, nl, nm, lc), _query(l, r, nm+1, nr, rc));\n\t}\n\
    \tT query(int l, int r){ return _query(l, r, 0, SZ-1, 1); }\n\t\n\tvoid _update(int\
    \ l, int r, L x, int nl, int nr, int rt){\n\t\tif(r < nl or nr < l) return;\n\t\
    \tif(l <= nl and nr <= r){\n\t\t\tval[rt] = apply(val[rt], x, nl, nr);\n\t\t\t\
    lp[rt] = merge_lazy(lp[rt], x);\n\t\t\treturn;\n\t\t}\n\t\tpush(nl, nr, rt);\n\
    \t\t_update(l, r, x, nl, nm, lc);\n\t\t_update(l, r, x, nm+1, nr, rc);\n\t\tval[rt]\
    \ = merge(val[lc], val[rc]);\n\t}\n\tvoid update(int l, int r, L x){ _update(l,\
    \ r, x, 0, SZ-1, 1); };\n\n\t#undef lc\n\t#undef rc\n\t#undef nm\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/data_structures/lazy_segment_tree.h
  requiredBy: []
  timestamp: '2021-07-05 21:49:47-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lazy_segment_tree.test.cpp
documentation_of: content/data_structures/lazy_segment_tree.h
layout: document
redirect_from:
- /library/content/data_structures/lazy_segment_tree.h
- /library/content/data_structures/lazy_segment_tree.h.html
title: Lazy Segment Tree
---
