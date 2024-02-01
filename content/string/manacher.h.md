---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/utils/template.h
    title: My starter code
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/manacher.test.cpp
    title: tests/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/manacher.md
    document_title: Manacher's Algorithm
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/string/manacher.h\"\
    \n\n/**\n * @brief Manacher's Algorithm\n * @docs docs/manacher.md\n */\n \npair<vector<int>,\
    \ vector<int>> manacher(string s){\n\ts = \"@\"+s+\"#\";\n\tint n = (int)size(s);\n\
    \tvector<int> p1(n), p2(n); //radii of palindromes (1 odd, 2 even length)\n\t\n\
    \tfor(int i = 1, mx = 0, p = 0; i < n-1; i++){\n\t\tp1[i] = (i >= mx) ? 1 : min(mx-i,\
    \ p1[p*2-i]);\n\t\twhile(s[i-p1[i]] == s[i+p1[i]])\n\t\t\tp1[i]++;\n\t\tif(i+p1[i]\
    \ > mx)\n\t\t\tmx = i+p1[i], p = i;\n\t}\n\tfor(int i = 1, mx = 0, p = 0; i <\
    \ n-1; i++){\n\t\tp2[i] = (i >= mx) ? 0 : min(mx-i, p2[p*2-i+2]);\n\t\twhile(s[i-p2[i]-1]\
    \ == s[i+p2[i]])\n\t\t\tp2[i]++;\n\t\tif(i+p2[i] > mx)\n\t\t\tmx = i+p2[i], p\
    \ = i-1;\n\t}\n\tp1.erase(p1.begin()); p2.erase(p2.begin());\n\tp1.pop_back();\
    \ p2.pop_back();\n\treturn {p1, p2};\n}\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Manacher's\
    \ Algorithm\n * @docs docs/manacher.md\n */\n \npair<vector<int>, vector<int>>\
    \ manacher(string s){\n\ts = \"@\"+s+\"#\";\n\tint n = (int)size(s);\n\tvector<int>\
    \ p1(n), p2(n); //radii of palindromes (1 odd, 2 even length)\n\t\n\tfor(int i\
    \ = 1, mx = 0, p = 0; i < n-1; i++){\n\t\tp1[i] = (i >= mx) ? 1 : min(mx-i, p1[p*2-i]);\n\
    \t\twhile(s[i-p1[i]] == s[i+p1[i]])\n\t\t\tp1[i]++;\n\t\tif(i+p1[i] > mx)\n\t\t\
    \tmx = i+p1[i], p = i;\n\t}\n\tfor(int i = 1, mx = 0, p = 0; i < n-1; i++){\n\t\
    \tp2[i] = (i >= mx) ? 0 : min(mx-i, p2[p*2-i+2]);\n\t\twhile(s[i-p2[i]-1] == s[i+p2[i]])\n\
    \t\t\tp2[i]++;\n\t\tif(i+p2[i] > mx)\n\t\t\tmx = i+p2[i], p = i-1;\n\t}\n\tp1.erase(p1.begin());\
    \ p2.erase(p2.begin());\n\tp1.pop_back(); p2.pop_back();\n\treturn {p1, p2};\n\
    }"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/string/manacher.h
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/manacher.test.cpp
documentation_of: content/string/manacher.h
layout: document
redirect_from:
- /library/content/string/manacher.h
- /library/content/string/manacher.h.html
title: Manacher's Algorithm
---
Returns two vectors `p1` and `p2`. `p1[i]*2-1` is the length of the palindrome centered at index `i` of the string.
`p2[i]*2` is the length of the palindrome centered around the midpoint between indices `i-1` and `i` in the string. This means that `p2[0]` is a dummy. 
