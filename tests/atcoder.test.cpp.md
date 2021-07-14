---
data:
  _extendedDependsOn:
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
    PROBLEM: https://atcoder.jp/contests/agc001/tasks/agc001_a
    links:
    - https://atcoder.jp/contests/agc001/tasks/agc001_a
  bundledCode: "#line 1 \"tests/atcoder.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc001/tasks/agc001_a\"\
    \n#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(),\
    \ (x).end()\n\n#ifdef LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\n\
    template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<'\
    \ ',pr(args...);}\n#else\ntemplate<typename... Args> void pr(Args... args){}\n\
    #endif\n\nusing namespace std;\nusing ll = long long;\n#line 3 \"tests/atcoder.test.cpp\"\
    \n\nint main(){\n\tios_base::sync_with_stdio(0);\n\tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\
    \t\n\tint n, l[200];\n\tcin>>n;\n\tfor(int i = 0; i < 2*n; i++)\n\t\tcin>>l[i];\n\
    \tsort(l, l+2*n);\n\tint ans = 0;\n\tfor(int i = 0; i < 2*n; i += 2){\n\t\tans\
    \ += l[i];\n\t}\n\tcout<<ans<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc001/tasks/agc001_a\"\n#include\
    \ \"../content/utils/template.h\"\n\nint main(){\n\tios_base::sync_with_stdio(0);\n\
    \tcin.tie(0);\n\tcin.exceptions(cin.failbit);\n\t\n\tint n, l[200];\n\tcin>>n;\n\
    \tfor(int i = 0; i < 2*n; i++)\n\t\tcin>>l[i];\n\tsort(l, l+2*n);\n\tint ans =\
    \ 0;\n\tfor(int i = 0; i < 2*n; i += 2){\n\t\tans += l[i];\n\t}\n\tcout<<ans<<'\\\
    n';\n}"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: true
  path: tests/atcoder.test.cpp
  requiredBy: []
  timestamp: '2021-07-14 18:14:35-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/atcoder.test.cpp
layout: document
redirect_from:
- /verify/tests/atcoder.test.cpp
- /verify/tests/atcoder.test.cpp.html
title: tests/atcoder.test.cpp
---
