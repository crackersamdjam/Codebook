---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/string/manacher.h
    title: Manacher's Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"tests/manacher.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n */\n\n\
    #include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define makeunique(x)\
    \ (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef LOCAL\ntemplate<typename\
    \ T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename T, typename...\
    \ Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n#else\ntemplate<typename...\
    \ Args> void pr(Args... args){}\n#endif\n\nusing namespace std;\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\n#line 3 \"content/string/manacher.h\"\n\n\
    /**\n * @brief Manacher's Algorithm\n * @docs docs/manacher.md\n */\n \npair<vector<int>,\
    \ vector<int>> manacher(string s){\n\ts = \"@\"+s+\"#\";\n\tint n = (int)size(s);\n\
    \tvector<int> p1(n), p2(n); //radii of palindromes (1 odd, 2 even length)\n\t\n\
    \tfor(int i = 1, mx = 0, p = 0; i < n-1; i++){\n\t\tp1[i] = (i >= mx) ? 1 : min(mx-i,\
    \ p1[p*2-i]);\n\t\twhile(s[i-p1[i]] == s[i+p1[i]])\n\t\t\tp1[i]++;\n\t\tif(i+p1[i]\
    \ > mx)\n\t\t\tmx = i+p1[i], p = i;\n\t}\n\tfor(int i = 1, mx = 0, p = 0; i <\
    \ n-1; i++){\n\t\tp2[i] = (i >= mx) ? 0 : min(mx-i, p2[p*2-i+2]);\n\t\twhile(s[i-p2[i]-1]\
    \ == s[i+p2[i]])\n\t\t\tp2[i]++;\n\t\tif(i+p2[i] > mx)\n\t\t\tmx = i+p2[i], p\
    \ = i-1;\n\t}\n\tp1.erase(p1.begin()); p2.erase(p2.begin());\n\tp1.pop_back();\
    \ p2.pop_back();\n\treturn {p1, p2};\n}\n#line 3 \"tests/manacher.test.cpp\"\n\
    \nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tstring s;\n\tcin>>s;\n\tauto [a, b] = manacher(s);\n\tfor(int i = 0; i <\
    \ (int)size(s)-1; i++){\n\t\tcout<<a[i]*2-1<<' '<<b[i+1]*2<<' ';\n\t}\n\tcout<<a.back()<<'\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../content/string/manacher.h\"\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tstring s;\n\tcin>>s;\n\t\
    auto [a, b] = manacher(s);\n\tfor(int i = 0; i < (int)size(s)-1; i++){\n\t\tcout<<a[i]*2-1<<'\
    \ '<<b[i+1]*2<<' ';\n\t}\n\tcout<<a.back()<<'\\n';\n}"
  dependsOn:
  - content/string/manacher.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/manacher.test.cpp
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/manacher.test.cpp
layout: document
redirect_from:
- /verify/tests/manacher.test.cpp
- /verify/tests/manacher.test.cpp.html
title: tests/manacher.test.cpp
---
