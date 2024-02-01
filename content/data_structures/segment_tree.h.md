---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segment_tree.test.cpp
    title: tests/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/data_structures/segment_tree.h\"\
    \n\n/**\n * @brief Segment Tree\n */\n\ntemplate<class T, class L> struct segment_tree{\n\
    \tint SZ;\n\tvector<T> val;\n\tfunction<T(T, T)> merge;\n\tfunction<T(T, L)> apply;\n\
    \t\n\tvoid init(int n, T def, function<T(T, T)> f, function<T(T, L)> g){\n\t\t\
    SZ = n;\n\t\twhile(n&(n-1)) n++; // next largest power of 2\n\t\tval.resize(2*n,\
    \ def);\n\t\tmerge = f;\n\t\tapply = g;\n\t}\n\n\t#define lc (rt<<1)\n\t#define\
    \ rc (rt<<1|1)\n\t#define nm ((nl+nr)/2)\n\t\n\tT _query(int l, int r, int nl,\
    \ int nr, int rt){\n\t\tif(r < nl or nr < l) return val[0];\n\t\tif(l <= nl and\
    \ nr <= r) return val[rt];\n\t\treturn merge(_query(l, r, nl, nm, lc), _query(l,\
    \ r, nm+1, nr, rc));\n\t}\n\tT query(int l, int r){ return _query(l, r, 0, SZ-1,\
    \ 1); }\n\t\n\tvoid _update(int i, L x, int nl, int nr, int rt){\n\t\tif(nl ==\
    \ nr){\n\t\t\tval[rt] = apply(val[rt], x);\n\t\t\treturn;\n\t\t}\n\t\ti <= nm\
    \ ? _update(i, x, nl, nm, lc) : _update(i, x, nm+1, nr, rc);\n\t\tval[rt] = merge(val[lc],\
    \ val[rc]);\n\t}\n\tvoid update(int i, L x){ _update(i, x, 0, SZ-1, 1); };\n\n\
    \t#undef lc\n\t#undef rc\n\t#undef nm\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Segment\
    \ Tree\n */\n\ntemplate<class T, class L> struct segment_tree{\n\tint SZ;\n\t\
    vector<T> val;\n\tfunction<T(T, T)> merge;\n\tfunction<T(T, L)> apply;\n\t\n\t\
    void init(int n, T def, function<T(T, T)> f, function<T(T, L)> g){\n\t\tSZ = n;\n\
    \t\twhile(n&(n-1)) n++; // next largest power of 2\n\t\tval.resize(2*n, def);\n\
    \t\tmerge = f;\n\t\tapply = g;\n\t}\n\n\t#define lc (rt<<1)\n\t#define rc (rt<<1|1)\n\
    \t#define nm ((nl+nr)/2)\n\t\n\tT _query(int l, int r, int nl, int nr, int rt){\n\
    \t\tif(r < nl or nr < l) return val[0];\n\t\tif(l <= nl and nr <= r) return val[rt];\n\
    \t\treturn merge(_query(l, r, nl, nm, lc), _query(l, r, nm+1, nr, rc));\n\t}\n\
    \tT query(int l, int r){ return _query(l, r, 0, SZ-1, 1); }\n\t\n\tvoid _update(int\
    \ i, L x, int nl, int nr, int rt){\n\t\tif(nl == nr){\n\t\t\tval[rt] = apply(val[rt],\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\ti <= nm ? _update(i, x, nl, nm, lc) : _update(i,\
    \ x, nm+1, nr, rc);\n\t\tval[rt] = merge(val[lc], val[rc]);\n\t}\n\tvoid update(int\
    \ i, L x){ _update(i, x, 0, SZ-1, 1); };\n\n\t#undef lc\n\t#undef rc\n\t#undef\
    \ nm\n};\n"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/data_structures/segment_tree.h
  requiredBy: []
  timestamp: '2024-02-01 15:45:08-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segment_tree.test.cpp
documentation_of: content/data_structures/segment_tree.h
layout: document
redirect_from:
- /library/content/data_structures/segment_tree.h
- /library/content/data_structures/segment_tree.h.html
title: Segment Tree
---
