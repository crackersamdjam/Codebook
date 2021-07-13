---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array.test.cpp
    title: tests/suffix_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/suffix_array.md
    document_title: Suffix Array (in O(n log n))
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/string/suffix_array.h\"\
    \n\n/**\n * @brief Suffix Array (in O(n log n))\n * @docs docs/suffix_array.md\n\
    \ */\n\nvector<int> sort_cyclic_shifts(string const &s, int const alphabet){\n\
    \tint n = (int)size(s);\n\tvector<int> p(n), c(n), cnt(max(alphabet, n));\n\t\
    for(int i = 0; i < n; i++)\n\t\tcnt[s[i]]++;\n\tfor(int i = 1; i < alphabet; i++)\n\
    \t\tcnt[i] += cnt[i-1];\n\tfor(int i = 0; i < n; i++)\n\t\tp[--cnt[s[i]]] = i;\n\
    \tc[p[0]] = 0;\n\tint classes = 1;\n\tfor(int i = 1; i < n; i++){\n\t\tif(s[p[i]]\
    \ != s[p[i-1]])\n\t\t\tclasses++;\n\t\tc[p[i]] = classes-1;\n\t}\n\tvector<int>\
    \ pn(n), cn(n);\n\tfor(int h = 0; (1<<h) < n; h++){\n\t\tfor(int i = 0; i < n;\
    \ i++){\n\t\t\tpn[i] = p[i] - (1<<h);\n\t\t\tif(pn[i] < 0)\n\t\t\t\tpn[i] += n;\n\
    \t\t}\n\t\tfill(cnt.begin(), cnt.begin()+classes, 0);\n\t\tfor(int i = 0; i <\
    \ n; i++)\n\t\t\tcnt[c[pn[i]]]++;\n\t\tfor(int i = 1; i < classes; i++)\n\t\t\t\
    cnt[i] += cnt[i-1];\n\t\tfor(int i = n-1; i >= 0; i--)\n\t\t\tp[--cnt[c[pn[i]]]]\
    \ = pn[i];\n\t\tcn[p[0]] = 0;\n\t\tclasses = 1;\n\t\tfor(int i = 1; i < n; i++){\n\
    \t\t\tpair<int, int> cur = {c[p[i]], c[(p[i] + (1<<h)) % n]};\n\t\t\tpair<int,\
    \ int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h)) % n]};\n\t\t\tif(cur != prev)\n\t\
    \t\t\tclasses++;\n\t\t\tcn[p[i]] = classes-1;\n\t\t}\n\t\tc.swap(cn);\n\t}\n\t\
    return p;\n}\n\nvector<int> suffix_array_construction(string s, int const alphabet\
    \ = 256){\n\ts += \"$\";\n\tvector<int> sorted_shifts = sort_cyclic_shifts(s,\
    \ alphabet);\n\tsorted_shifts.erase(sorted_shifts.begin());\n\treturn sorted_shifts;\n\
    }\n\n// p should be suffix_array_construction(s)\nvector<int> lcp_construction(string\
    \ const &s, vector<int> const &p){\n\tint n = (int)size(s);\n\tvector<int> rank(n);\n\
    \tfor (int i = 0; i < n; i++)\n\t\trank[p[i]] = i;\n\t\n\tint k = 0;\n\tvector<int>\
    \ lcp(n-1);\n\tfor(int i = 0; i < n; i++){\n\t\tif(rank[i] == n-1){\n\t\t\tk =\
    \ 0;\n\t\t\tcontinue;\n\t\t}\n\t\tint j = p[rank[i] + 1];\n\t\twhile(i+k < n and\
    \ j+k < n and s[i+k] == s[j+k])\n\t\t\tk++;\n\t\tlcp[rank[i]] = k;\n\t\tif(k)\
    \ k--;\n\t}\n\treturn lcp;\n}\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Suffix Array\
    \ (in O(n log n))\n * @docs docs/suffix_array.md\n */\n\nvector<int> sort_cyclic_shifts(string\
    \ const &s, int const alphabet){\n\tint n = (int)size(s);\n\tvector<int> p(n),\
    \ c(n), cnt(max(alphabet, n));\n\tfor(int i = 0; i < n; i++)\n\t\tcnt[s[i]]++;\n\
    \tfor(int i = 1; i < alphabet; i++)\n\t\tcnt[i] += cnt[i-1];\n\tfor(int i = 0;\
    \ i < n; i++)\n\t\tp[--cnt[s[i]]] = i;\n\tc[p[0]] = 0;\n\tint classes = 1;\n\t\
    for(int i = 1; i < n; i++){\n\t\tif(s[p[i]] != s[p[i-1]])\n\t\t\tclasses++;\n\t\
    \tc[p[i]] = classes-1;\n\t}\n\tvector<int> pn(n), cn(n);\n\tfor(int h = 0; (1<<h)\
    \ < n; h++){\n\t\tfor(int i = 0; i < n; i++){\n\t\t\tpn[i] = p[i] - (1<<h);\n\t\
    \t\tif(pn[i] < 0)\n\t\t\t\tpn[i] += n;\n\t\t}\n\t\tfill(cnt.begin(), cnt.begin()+classes,\
    \ 0);\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tcnt[c[pn[i]]]++;\n\t\tfor(int i =\
    \ 1; i < classes; i++)\n\t\t\tcnt[i] += cnt[i-1];\n\t\tfor(int i = n-1; i >= 0;\
    \ i--)\n\t\t\tp[--cnt[c[pn[i]]]] = pn[i];\n\t\tcn[p[0]] = 0;\n\t\tclasses = 1;\n\
    \t\tfor(int i = 1; i < n; i++){\n\t\t\tpair<int, int> cur = {c[p[i]], c[(p[i]\
    \ + (1<<h)) % n]};\n\t\t\tpair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h))\
    \ % n]};\n\t\t\tif(cur != prev)\n\t\t\t\tclasses++;\n\t\t\tcn[p[i]] = classes-1;\n\
    \t\t}\n\t\tc.swap(cn);\n\t}\n\treturn p;\n}\n\nvector<int> suffix_array_construction(string\
    \ s, int const alphabet = 256){\n\ts += \"$\";\n\tvector<int> sorted_shifts =\
    \ sort_cyclic_shifts(s, alphabet);\n\tsorted_shifts.erase(sorted_shifts.begin());\n\
    \treturn sorted_shifts;\n}\n\n// p should be suffix_array_construction(s)\nvector<int>\
    \ lcp_construction(string const &s, vector<int> const &p){\n\tint n = (int)size(s);\n\
    \tvector<int> rank(n);\n\tfor (int i = 0; i < n; i++)\n\t\trank[p[i]] = i;\n\t\
    \n\tint k = 0;\n\tvector<int> lcp(n-1);\n\tfor(int i = 0; i < n; i++){\n\t\tif(rank[i]\
    \ == n-1){\n\t\t\tk = 0;\n\t\t\tcontinue;\n\t\t}\n\t\tint j = p[rank[i] + 1];\n\
    \t\twhile(i+k < n and j+k < n and s[i+k] == s[j+k])\n\t\t\tk++;\n\t\tlcp[rank[i]]\
    \ = k;\n\t\tif(k) k--;\n\t}\n\treturn lcp;\n}"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/string/suffix_array.h
  requiredBy: []
  timestamp: '2021-07-13 15:53:41-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/suffix_array.test.cpp
documentation_of: content/string/suffix_array.h
layout: document
redirect_from:
- /library/content/string/suffix_array.h
- /library/content/string/suffix_array.h.html
title: Suffix Array (in O(n log n))
---
