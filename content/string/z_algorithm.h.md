---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/z_algorithm.test.cpp
    title: tests/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/z_algorithm.md
    document_title: Z Algorithm
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/string/z_algorithm.h\"\
    \n\n/**\n * @brief Z Algorithm\n * @docs docs/z_algorithm.md\n */\n\nvector<int>\
    \ zed(string s){\n\tint n = (int)size(s);\n\tvector<int> z(n);\n\tfor(int i =\
    \ 1, l = 0, r = 0; i < n; i++){\n\t\tif(i <= r)\n\t\t\tz[i] = min(r-i+1, z[i-l]);\n\
    \t\twhile(i+z[i] < n and s[z[i]] == s[i+z[i]])\n\t\t\tz[i]++;\n\t\tif(i+z[i]-1\
    \ > r)\n\t\t\tl = i, r = i+z[i]-1;\n\t}\n\treturn z;\n}\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Z Algorithm\n\
    \ * @docs docs/z_algorithm.md\n */\n\nvector<int> zed(string s){\n\tint n = (int)size(s);\n\
    \tvector<int> z(n);\n\tfor(int i = 1, l = 0, r = 0; i < n; i++){\n\t\tif(i <=\
    \ r)\n\t\t\tz[i] = min(r-i+1, z[i-l]);\n\t\twhile(i+z[i] < n and s[z[i]] == s[i+z[i]])\n\
    \t\t\tz[i]++;\n\t\tif(i+z[i]-1 > r)\n\t\t\tl = i, r = i+z[i]-1;\n\t}\n\treturn\
    \ z;\n}"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/string/z_algorithm.h
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/z_algorithm.test.cpp
documentation_of: content/string/z_algorithm.h
layout: document
redirect_from:
- /library/content/string/z_algorithm.h
- /library/content/string/z_algorithm.h.html
title: Z Algorithm
---
`z[i]` = length of the longest common prefix between `s` and `s[i, end]`. `z[0]` is defined to be `0`.
