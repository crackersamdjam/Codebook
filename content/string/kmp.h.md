---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/kmp.md
    document_title: Knuth-Morris-Pratt Algorithm
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\n#line 3 \"content/string/kmp.h\"\n\n/**\n * @brief\
    \ Knuth-Morris-Pratt Algorithm\n * @docs docs/kmp.md\n */\n\nvector<int> kmp(string\
    \ s){\n\tvector<int> pi(size(s));\n\tpi[0] = 0;\n\tfor(int i = 1, j = 0; i < size(s);\
    \ i++){\n\t\twhile(j and s[i] != s[j])\n\t\t\tj = pi[j-1];\n\t\tif(s[i] == s[j])\n\
    \t\t\tj++;\n\t\tpi[i] = j;\n\t}\n\treturn pi;\n}\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Knuth-Morris-Pratt\
    \ Algorithm\n * @docs docs/kmp.md\n */\n\nvector<int> kmp(string s){\n\tvector<int>\
    \ pi(size(s));\n\tpi[0] = 0;\n\tfor(int i = 1, j = 0; i < size(s); i++){\n\t\t\
    while(j and s[i] != s[j])\n\t\t\tj = pi[j-1];\n\t\tif(s[i] == s[j])\n\t\t\tj++;\n\
    \t\tpi[i] = j;\n\t}\n\treturn pi;\n}"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/string/kmp.h
  requiredBy: []
  timestamp: '2024-02-01 09:33:50-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: content/string/kmp.h
layout: document
redirect_from:
- /library/content/string/kmp.h
- /library/content/string/kmp.h.html
title: Knuth-Morris-Pratt Algorithm
---
`pi[i]` = the length of the longest proper prefix of `s` (i.e. `s[0, i-1]`) that is also a suffix of `s[0, i-1]`.

To check if `t` contains `s`, do kmp on `s+'#'+t` and check whether any `pi[i] = len(s)`.
