---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/segment_tree.h
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"tests/segment_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/data_structures/segment_tree.h\"\
    \n\n/**\n * @brief Segment Tree\n * @docs docs/segment_tree.md\n */\n\ntemplate<class\
    \ T, class L> struct segment_tree{\n\tint SZ;\n\tvector<T> val;\n\tfunction<T(T,\
    \ T)> merge;\n\tfunction<T(T, L)> apply;\n\t\n\tvoid init(int n, T def, function<T(T,\
    \ T)> f, function<T(T, L)> g){\n\t\tSZ = n;\n\t\twhile(n&(n-1)) n++; // next largest\
    \ power of 2\n\t\tval.resize(2*n, def);\n\t\tmerge = f;\n\t\tapply = g;\n\t}\n\
    \n\t#define lc (rt<<1)\n\t#define rc (rt<<1|1)\n\t#define nm ((nl+nr)/2)\n\t\n\
    \tT _query(int l, int r, int nl, int nr, int rt){\n\t\tif(r < nl or nr < l) return\
    \ val[0];\n\t\tif(l <= nl and nr <= r) return val[rt];\n\t\treturn merge(_query(l,\
    \ r, nl, nm, lc), _query(l, r, nm+1, nr, rc));\n\t}\n\tT query(int l, int r){\
    \ return _query(l, r, 0, SZ-1, 1); }\n\t\n\tvoid _update(int i, L x, int nl, int\
    \ nr, int rt){\n\t\tif(nl == nr){\n\t\t\tval[rt] = apply(val[rt], x);\n\t\t\t\
    return;\n\t\t}\n\t\ti <= nm ? _update(i, x, nl, nm, lc) : _update(i, x, nm+1,\
    \ nr, rc);\n\t\tval[rt] = merge(val[lc], val[rc]);\n\t}\n\tvoid update(int i,\
    \ L x){ _update(i, x, 0, SZ-1, 1); };\n\n\t#undef lc\n\t#undef rc\n\t#undef nm\n\
    };\n#line 3 \"tests/segment_tree.test.cpp\"\n\nusing p = pair<ll, ll>;\nconstexpr\
    \ ll mod = 998244353;\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\
    \tcin.exceptions(cin.failbit);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\t\n\tsegment_tree<p,\
    \ p> ST;\n\tST.init(n+5, {1, 0},\n\t\t[](auto x, auto y){ return p(x.first*y.first\
    \ % mod, (y.first*x.second + y.second) % mod); },\n\t\t[](auto x, auto y){ return\
    \ y; });\n\t\n\tfor(int i = 0; i < n; i++){\n\t\tll a, b;\n\t\tcin>>a>>b;\n\t\t\
    ST.update(i, {a, b});\n\t}\n\twhile(q--){\n\t\tint op;\n\t\tcin>>op;\n\t\tif(op\
    \ == 0){\n\t\t\tint i; ll a, b;\n\t\t\tcin>>i>>a>>b;\n\t\t\tST.update(i, {a, b});\n\
    \t\t}\n\t\telse{\n\t\t\tint l, r; ll x;\n\t\t\tcin>>l>>r>>x;\n\t\t\tauto [a, b]\
    \ = ST.query(l, r-1);\n\t\t\tcout<<(a*x+b)%mod<<'\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../content/data_structures/segment_tree.h\"\n\nusing p = pair<ll,\
    \ ll>;\nconstexpr ll mod = 998244353;\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\
    \t\n\tsegment_tree<p, p> ST;\n\tST.init(n+5, {1, 0},\n\t\t[](auto x, auto y){\
    \ return p(x.first*y.first % mod, (y.first*x.second + y.second) % mod); },\n\t\
    \t[](auto x, auto y){ return y; });\n\t\n\tfor(int i = 0; i < n; i++){\n\t\tll\
    \ a, b;\n\t\tcin>>a>>b;\n\t\tST.update(i, {a, b});\n\t}\n\twhile(q--){\n\t\tint\
    \ op;\n\t\tcin>>op;\n\t\tif(op == 0){\n\t\t\tint i; ll a, b;\n\t\t\tcin>>i>>a>>b;\n\
    \t\t\tST.update(i, {a, b});\n\t\t}\n\t\telse{\n\t\t\tint l, r; ll x;\n\t\t\tcin>>l>>r>>x;\n\
    \t\t\tauto [a, b] = ST.query(l, r-1);\n\t\t\tcout<<(a*x+b)%mod<<'\\n';\n\t\t}\n\
    \t}\n}"
  dependsOn:
  - content/data_structures/segment_tree.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-14 16:06:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/segment_tree.test.cpp
- /verify/tests/segment_tree.test.cpp.html
title: tests/segment_tree.test.cpp
---
