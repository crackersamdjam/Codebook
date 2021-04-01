---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/template.md
    document_title: My starter code
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ content/utils/template.h: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief My starter code\n * @docs docs/template.md\n */\n\n#pragma\
    \ once\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n\nusing\
    \ namespace std;\n"
  dependsOn: []
  isVerificationFile: false
  path: content/utils/template.h
  requiredBy: []
  timestamp: '2021-04-01 17:21:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: content/utils/template.h
layout: document
redirect_from:
- /library/content/utils/template.h
- /library/content/utils/template.h.html
title: My starter code
---
