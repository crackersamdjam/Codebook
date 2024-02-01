---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/string/suffix_array.h
    title: Suffix Array (in O(n log n))
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
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"tests/suffix_array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n */\n\n\
    #include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define makeunique(x)\
    \ (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef LOCAL\ntemplate<typename\
    \ T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename T, typename...\
    \ Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n#else\ntemplate<typename...\
    \ Args> void pr(Args... args){}\n#endif\n\nusing namespace std;\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\n#line 3 \"content/string/suffix_array.h\"\
    \n\n/**\n * @brief Suffix Array (in O(n log n))\n */\n\nvector<int> sort_cyclic_shifts(string\
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
    \ = k;\n\t\tif(k) k--;\n\t}\n\treturn lcp;\n}\n#line 3 \"tests/suffix_array.test.cpp\"\
    \n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tstring s;\n\tcin>>s;\n\tauto v = suffix_array_construction(s, 'z'+1);\n\t\
    for(int i: v)\n\t\tcout<<i<<' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"../content/string/suffix_array.h\"\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tstring s;\n\tcin>>s;\n\t\
    auto v = suffix_array_construction(s, 'z'+1);\n\tfor(int i: v)\n\t\tcout<<i<<'\
    \ ';\n}"
  dependsOn:
  - content/string/suffix_array.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/tests/suffix_array.test.cpp
- /verify/tests/suffix_array.test.cpp.html
title: tests/suffix_array.test.cpp
---