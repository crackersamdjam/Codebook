---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/lazy_segment_tree.h
    title: Lazy Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"tests/lazy_segment_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n */\n\n\
    #include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef LOCAL\n\
    template<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\n#line 3 \"content/data_structures/lazy_segment_tree.h\"\
    \n\n/**\n * @brief Lazy Segment Tree\n *\n * todo: make \"find first in range\"\
    \ (from cp algorthms) function\n * to do that, I need a function to check if f(x,\
    \ current) is good enough, and I also need combine(current, val[rt])\n *\n */\n\
    \ntemplate<class T, class L> struct lazy_segment_tree{\n\tint SZ;\n\tvector<T>\
    \ val;\n\tvector<L> lp;\n\tfunction<T(T, T)> merge;\n\tfunction<T(T, L, int, int)>\
    \ apply;\n\tfunction<L(L, L)> merge_lazy;\n\t\n\tvoid init(int n, T def, L ldef,\
    \ function<T(T, T)> f, function<T(T, L, int, int)> g, function<L(L, L)> h){\n\t\
    \tSZ = n;\n\t\twhile(n&(n-1)) n++; // next largest power of 2\n\t\tval.resize(2*n,\
    \ def);\n\t\tlp.resize(size(val), ldef);\n\t\tmerge = f;\n\t\tapply = g;\n\t\t\
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
    #undef nm\n};\n#line 3 \"tests/lazy_segment_tree.test.cpp\"\n\nusing pll = pair<ll,\
    \ ll>;\nconstexpr ll mod = 998244353;\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\
    \t\n\tlazy_segment_tree<ll, pll> ST;\n\tST.init(n+5, 0, pll(1, 0),\n\t\t[](auto\
    \ x, auto y){ return (x+y) % mod; },\n\t\t[](auto x, auto y, int l, int r){ return\
    \ (x*y.first + (r-l+1)*y.second) % mod; },\n\t\t[](auto x, auto y){ return pll(x.first*y.first\
    \ % mod, (y.first*x.second + y.second) % mod); }\n\t\t);\n\t\n\tfor(int i = 0;\
    \ i < n; i++){\n\t\tll a;\n\t\tcin>>a;\n\t\tST.update(i, i, {0, a});\n\t}\n\t\
    while(q--){\n\t\tint op;\n\t\tcin>>op;\n\t\tif(op == 0){\n\t\t\tint l, r; ll b,\
    \ c;\n\t\t\tcin>>l>>r>>b>>c;\n\t\t\tST.update(l, r-1, {b, c});\n\t\t}\n\t\telse{\n\
    \t\t\tint l, r;\n\t\t\tcin>>l>>r;\n\t\t\tauto a = ST.query(l, r-1);\n\t\t\tcout<<a<<'\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../content/data_structures/lazy_segment_tree.h\"\n\nusing pll = pair<ll,\
    \ ll>;\nconstexpr ll mod = 998244353;\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\
    \t\n\tlazy_segment_tree<ll, pll> ST;\n\tST.init(n+5, 0, pll(1, 0),\n\t\t[](auto\
    \ x, auto y){ return (x+y) % mod; },\n\t\t[](auto x, auto y, int l, int r){ return\
    \ (x*y.first + (r-l+1)*y.second) % mod; },\n\t\t[](auto x, auto y){ return pll(x.first*y.first\
    \ % mod, (y.first*x.second + y.second) % mod); }\n\t\t);\n\t\n\tfor(int i = 0;\
    \ i < n; i++){\n\t\tll a;\n\t\tcin>>a;\n\t\tST.update(i, i, {0, a});\n\t}\n\t\
    while(q--){\n\t\tint op;\n\t\tcin>>op;\n\t\tif(op == 0){\n\t\t\tint l, r; ll b,\
    \ c;\n\t\t\tcin>>l>>r>>b>>c;\n\t\t\tST.update(l, r-1, {b, c});\n\t\t}\n\t\telse{\n\
    \t\t\tint l, r;\n\t\t\tcin>>l>>r;\n\t\t\tauto a = ST.query(l, r-1);\n\t\t\tcout<<a<<'\\\
    n';\n\t\t}\n\t}\n}"
  dependsOn:
  - content/data_structures/lazy_segment_tree.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 09:33:50-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/lazy_segment_tree.test.cpp
- /verify/tests/lazy_segment_tree.test.cpp.html
title: tests/lazy_segment_tree.test.cpp
---
