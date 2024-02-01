---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_tree.test.cpp
    title: tests/li_chao_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/li_chao_tree.md
    document_title: Li Chao Tree
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/data_structures/li_chao_tree.h\"\
    \n\n/**\n * @brief Li Chao Tree\n * @docs docs/li_chao_tree.md\n */\n\ntemplate<typename\
    \ T> struct line{\n\tT m, b;\n\tT eval(T x){ return m*x + b;}\n};\n\ntemplate<typename\
    \ T> struct sparse_li_chao_tree{\n\tint LS, RS;\n\tT def;\n\tfunction<T(T, T)>\
    \ merge;\n\t\n\tstruct node{\n\t\tnode *lc, *rc;\n\t\tline<T> val;\n\t\tnode(line<T>\
    \ _val){\n\t\t\tlc = rc = nullptr;\n\t\t\tval = _val;\n\t\t}\n\t};\n\tnode *rt\
    \ = nullptr;\n\t\n\t// merge() should be min or max\n\tvoid init(int _LS, int\
    \ _RS, T _def, function<T(T, T)> _merge){\n\t\tLS = _LS;\n\t\tRS = _RS;\n\t\t\
    def = _def;\n\t\tmerge = _merge;\n\t}\n\n\t#define nm (nl+(nr-nl)/2)\n\t// this\
    \ works for negative indices too, unlike (nl+nr)/2\n\t\n\tvoid _add(line<T> ln,\
    \ int nl, int nr, node *&cur){\n\t\tassert(nl <= nr);\n\t\tif(!cur){\n\t\t\tcur\
    \ = new node(ln);\n\t\t\treturn;\n\t\t}\n\t\tbool bl = ln.eval(nl) < cur->val.eval(nl);\n\
    \t\tbool bm = ln.eval(nm) < cur->val.eval(nm);\n\t\tif(bm) swap(cur->val, ln);\n\
    \t\tif(nl == nr) return;\n\t\tbl != bm ? _add(ln, nl, nm, cur->lc) : _add(ln,\
    \ nm+1, nr, cur->rc);\n\t}\n\tvoid add(line<T> ln){ _add(ln, LS, RS, rt); }\n\t\
    \n\tT _get(T x, int nl, int nr, node *cur){\n\t\tif(!cur) return def;\n\t\tif(nl\
    \ == nr) return cur->val.eval(x);\n\t\tif(x <= nm) return merge(cur->val.eval(x),\
    \ _get(x, nl, nm, cur->lc));\n\t\treturn merge(cur->val.eval(x), _get(x, nm+1,\
    \ nr, cur->rc));\n\t}\n\tT get(T x){ return _get(x, LS, RS, rt); }\n\n\t#undef\
    \ nm\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Li Chao\
    \ Tree\n * @docs docs/li_chao_tree.md\n */\n\ntemplate<typename T> struct line{\n\
    \tT m, b;\n\tT eval(T x){ return m*x + b;}\n};\n\ntemplate<typename T> struct\
    \ sparse_li_chao_tree{\n\tint LS, RS;\n\tT def;\n\tfunction<T(T, T)> merge;\n\t\
    \n\tstruct node{\n\t\tnode *lc, *rc;\n\t\tline<T> val;\n\t\tnode(line<T> _val){\n\
    \t\t\tlc = rc = nullptr;\n\t\t\tval = _val;\n\t\t}\n\t};\n\tnode *rt = nullptr;\n\
    \t\n\t// merge() should be min or max\n\tvoid init(int _LS, int _RS, T _def, function<T(T,\
    \ T)> _merge){\n\t\tLS = _LS;\n\t\tRS = _RS;\n\t\tdef = _def;\n\t\tmerge = _merge;\n\
    \t}\n\n\t#define nm (nl+(nr-nl)/2)\n\t// this works for negative indices too,\
    \ unlike (nl+nr)/2\n\t\n\tvoid _add(line<T> ln, int nl, int nr, node *&cur){\n\
    \t\tassert(nl <= nr);\n\t\tif(!cur){\n\t\t\tcur = new node(ln);\n\t\t\treturn;\n\
    \t\t}\n\t\tbool bl = ln.eval(nl) < cur->val.eval(nl);\n\t\tbool bm = ln.eval(nm)\
    \ < cur->val.eval(nm);\n\t\tif(bm) swap(cur->val, ln);\n\t\tif(nl == nr) return;\n\
    \t\tbl != bm ? _add(ln, nl, nm, cur->lc) : _add(ln, nm+1, nr, cur->rc);\n\t}\n\
    \tvoid add(line<T> ln){ _add(ln, LS, RS, rt); }\n\t\n\tT _get(T x, int nl, int\
    \ nr, node *cur){\n\t\tif(!cur) return def;\n\t\tif(nl == nr) return cur->val.eval(x);\n\
    \t\tif(x <= nm) return merge(cur->val.eval(x), _get(x, nl, nm, cur->lc));\n\t\t\
    return merge(cur->val.eval(x), _get(x, nm+1, nr, cur->rc));\n\t}\n\tT get(T x){\
    \ return _get(x, LS, RS, rt); }\n\n\t#undef nm\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/data_structures/li_chao_tree.h
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/li_chao_tree.test.cpp
documentation_of: content/data_structures/li_chao_tree.h
layout: document
redirect_from:
- /library/content/data_structures/li_chao_tree.h
- /library/content/data_structures/li_chao_tree.h.html
title: Li Chao Tree
---
This is a sparse Li Chao Tree.