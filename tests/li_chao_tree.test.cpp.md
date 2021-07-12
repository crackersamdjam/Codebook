---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/data_structures/li_chao_tree.h
    title: Li Chao Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"tests/li_chao_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\n#line 3 \"content/data_structures/li_chao_tree.h\"\
    \n\n/**\n * @brief Li Chao Tree\n * @docs docs/li_chao_tree.md\n * @info Sparse\
    \ Li Chao Tree\n */\n\ntemplate<typename T> struct line{\n\tT m, b;\n\tT eval(T\
    \ x){ return m*x + b;}\n};\n\ntemplate<typename T> struct sparse_li_chao_tree{\n\
    \tint LS, RS;\n\tT def;\n\tfunction<T(T, T)> merge;\n\t\n\tstruct node{\n\t\t\
    node *lc, *rc;\n\t\tline<T> val;\n\t\tnode(line<T> _val){\n\t\t\tlc = rc = nullptr;\n\
    \t\t\tval = _val;\n\t\t}\n\t};\n\tnode *rt = nullptr;\n\t\n\t// merge() should\
    \ be min or max\n\tvoid init(int _LS, int _RS, T _def, function<T(T, T)> _merge){\n\
    \t\tLS = _LS;\n\t\tRS = _RS;\n\t\tdef = _def;\n\t\tmerge = _merge;\n\t}\n\n\t\
    #define nm (nl+(nr-nl)/2)\n\t// this works for negative indices too, unlike (nl+nr)/2\n\
    \t\n\tvoid _add(line<T> ln, int nl, int nr, node *&cur){\n\t\tassert(nl <= nr);\n\
    \t\tif(!cur){\n\t\t\tcur = new node(ln);\n\t\t\treturn;\n\t\t}\n\t\tbool bl =\
    \ ln.eval(nl) < cur->val.eval(nl);\n\t\tbool bm = ln.eval(nm) < cur->val.eval(nm);\n\
    \t\tif(bm) swap(cur->val, ln);\n\t\tif(nl == nr) return;\n\t\tbl != bm ? _add(ln,\
    \ nl, nm, cur->lc) : _add(ln, nm+1, nr, cur->rc);\n\t}\n\tvoid add(line<T> ln){\
    \ _add(ln, LS, RS, rt); }\n\t\n\tT _get(T x, int nl, int nr, node *cur){\n\t\t\
    if(!cur) return def;\n\t\tif(nl == nr) return cur->val.eval(x);\n\t\tif(x <= nm)\
    \ return merge(cur->val.eval(x), _get(x, nl, nm, cur->lc));\n\t\treturn merge(cur->val.eval(x),\
    \ _get(x, nm+1, nr, cur->rc));\n\t}\n\tT get(T x){ return _get(x, LS, RS, rt);\
    \ }\n\n\t#undef nm\n};\n#line 3 \"tests/li_chao_tree.test.cpp\"\n\nusing ll =\
    \ long long;\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\t\
    cin.exceptions(cin.failbit);\n\t\n\tint n, q;\n\tcin>>n>>q;\n\t\n\tsparse_li_chao_tree<ll>\
    \ st;\n\tst.init(-1e9, 1e9, LLONG_MAX, [](auto x, auto y){ return min(x, y); });\n\
    \twhile(n--){\n\t\tll a, b;\n\t\tcin>>a>>b;\n\t\tst.add({a, b});\n\t}\n\twhile(q--){\n\
    \t\tint op;\n\t\tcin>>op;\n\t\tif(op == 0){\n\t\t\tll a, b;\n\t\t\tcin>>a>>b;\n\
    \t\t\tst.add({a, b});\n\t\t}\n\t\telse{\n\t\t\tll x;\n\t\t\tcin>>x;\n\t\t\tcout<<st.get(x)<<'\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../content/data_structures/li_chao_tree.h\"\n\nusing ll = long long;\n\nint\
    \ main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tint n, q;\n\tcin>>n>>q;\n\t\n\tsparse_li_chao_tree<ll> st;\n\tst.init(-1e9,\
    \ 1e9, LLONG_MAX, [](auto x, auto y){ return min(x, y); });\n\twhile(n--){\n\t\
    \tll a, b;\n\t\tcin>>a>>b;\n\t\tst.add({a, b});\n\t}\n\twhile(q--){\n\t\tint op;\n\
    \t\tcin>>op;\n\t\tif(op == 0){\n\t\t\tll a, b;\n\t\t\tcin>>a>>b;\n\t\t\tst.add({a,\
    \ b});\n\t\t}\n\t\telse{\n\t\t\tll x;\n\t\t\tcin>>x;\n\t\t\tcout<<st.get(x)<<'\\\
    n';\n\t\t}\n\t}\n}"
  dependsOn:
  - content/data_structures/li_chao_tree.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/li_chao_tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-12 16:34:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/li_chao_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/li_chao_tree.test.cpp
- /verify/tests/li_chao_tree.test.cpp.html
title: tests/li_chao_tree.test.cpp
---
