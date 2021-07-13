---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/bit.h
    title: Binary Indexed Tree
  - icon: ':question:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"tests/bit.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\n#line 3 \"content/data_structures/bit.h\"\n\n\
    /**\n * @brief Binary Indexed Tree\n * @docs docs/bit.md\n * @info\n */\n\ntemplate<class\
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
    update(l, l, v);\n\t}\n};\n#line 3 \"tests/bit.test.cpp\"\n\nusing ll = long long;\n\
    \nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tint n, q;\n\tcin>>n>>q;\n\t\n\tbit<ll> t;\n\tt.init(n+1, 0, [](auto x, auto\
    \ y){ return x+y;});\n\t\n\tfor(int i = 1,a; i <= n; i++){\n\t\tcin>>a;\n\t\t\
    t.update(i, a);\n\t}\n\t\n\twhile(q--){\n\t\tint op;\n\t\tcin>>op;\n\t\tif(op\
    \ == 0){\n\t\t\tint i, x;\n\t\t\tcin>>i>>x;\n\t\t\tt.update(i+1, x);\n\t\t}\n\t\
    \telse{\n\t\t\tint l, r;\n\t\t\tcin>>l>>r;\n\t\t\tcout<<t.query(r)-t.query(l)<<'\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../content/data_structures/bit.h\"\n\nusing ll = long long;\n\nint\
    \ main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tint n, q;\n\tcin>>n>>q;\n\t\n\tbit<ll> t;\n\tt.init(n+1, 0, [](auto x, auto\
    \ y){ return x+y;});\n\t\n\tfor(int i = 1,a; i <= n; i++){\n\t\tcin>>a;\n\t\t\
    t.update(i, a);\n\t}\n\t\n\twhile(q--){\n\t\tint op;\n\t\tcin>>op;\n\t\tif(op\
    \ == 0){\n\t\t\tint i, x;\n\t\t\tcin>>i>>x;\n\t\t\tt.update(i+1, x);\n\t\t}\n\t\
    \telse{\n\t\t\tint l, r;\n\t\t\tcin>>l>>r;\n\t\t\tcout<<t.query(r)-t.query(l)<<'\\\
    n';\n\t\t}\n\t}\n}"
  dependsOn:
  - content/data_structures/bit.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/bit.test.cpp
  requiredBy: []
  timestamp: '2021-07-04 14:49:31-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bit.test.cpp
layout: document
redirect_from:
- /verify/tests/bit.test.cpp
- /verify/tests/bit.test.cpp.html
title: tests/bit.test.cpp
---
