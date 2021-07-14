---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: content/string/z_algorithm.h
    title: Z Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"tests/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"content/string/z_algorithm.h\"\
    \n\n/**\n * @brief Z Algorithm\n * @docs docs/z_algorithm.md\n */\n\nvector<int>\
    \ zed(string s){\n\tint n = (int)size(s);\n\tvector<int> z(n);\n\tfor(int i =\
    \ 1, l = 0, r = 0; i < n; i++){\n\t\tif(i <= r)\n\t\t\tz[i] = min(r-i+1, z[i-l]);\n\
    \t\twhile(i+z[i] < n and s[z[i]] == s[i+z[i]])\n\t\t\tz[i]++;\n\t\tif(i+z[i]-1\
    \ > r)\n\t\t\tl = i, r = i+z[i]-1;\n\t}\n\treturn z;\n}\n#line 3 \"tests/z_algorithm.test.cpp\"\
    \n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tstring s;\n\tcin>>s;\n\tauto v = zed(s);\n\tv[0] = size(s);\n\tfor(int i:\
    \ v)\n\t\tcout<<i<<' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../content/string/z_algorithm.h\"\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tstring s;\n\tcin>>s;\n\t\
    auto v = zed(s);\n\tv[0] = size(s);\n\tfor(int i: v)\n\t\tcout<<i<<' ';\n}"
  dependsOn:
  - content/string/z_algorithm.h
  - content/utils/template.h
  isVerificationFile: true
  path: tests/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-07-13 15:53:41-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/tests/z_algorithm.test.cpp
- /verify/tests/z_algorithm.test.cpp.html
title: tests/z_algorithm.test.cpp
---
