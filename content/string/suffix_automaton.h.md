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
    _deprecated_at_docs: docs/suffix_automaton.md
    document_title: Suffix Automaton
    links: []
  bundledCode: "#line 1 \"content/utils/template.h\"\n/**\n * @brief My starter code\n\
    \ */\n\n#include <bits/stdc++.h>\n#define all(x) (x).begin(), (x).end()\n#define\
    \ makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());\n\n#ifdef\
    \ LOCAL\ntemplate<typename T> void pr(T a){std::cerr<<a<<std::endl;}\ntemplate<typename\
    \ T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}\n\
    #else\ntemplate<typename... Args> void pr(Args... args){}\n#endif\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing pii = pair<int, int>;\n#line 3 \"content/string/suffix_automaton.h\"\
    \n\n/**\n * @brief Suffix Automaton\n * @docs docs/suffix_automaton.md\n */\n\n\
    struct suffix_automaton{\n\tstruct st{\n\t\tint len, par;\n\t\tll cnt;\n\t\tmap<char,\
    \ int> ch;\n\t};\n\tvector<st> v;\n\tint sz, last;\n\t\n\tvoid init(int n){\n\t\
    \tv.resize(n*2);\n\t\tv[0].len = 0; //0 is the root\n\t\tv[0].par = -1;\n\t\t\
    sz = 1;\n\t\tlast = 0;\n\t}\n\t\n\tvoid extend(char c){\n\t\tint cur = sz++;\n\
    \t\tv[cur].len = v[last].len+1;\n\t\tint p = last;\n\t\twhile(p != -1 && !v[p].ch.count(c)){\n\
    \t\t\tv[p].ch[c] = cur;\n\t\t\tp = v[p].par;\n\t\t}\n\t\tif(p == -1){\n\t\t\t\
    v[cur].par = 0;\n\t\t}\n\t\telse{\n\t\t\tint o = v[p].ch[c]; //\"other\"\n\t\t\
    \tif(v[p].len+1 == v[o].len){\n\t\t\t\tv[cur].par = o;\n\t\t\t}\n\t\t\telse{\n\
    \t\t\t\tint clone = sz++; //clone\n\t\t\t\tv[clone].ch = v[o].ch;\n\t\t\t\tv[clone].par\
    \ = v[o].par;\n\t\t\t\tv[clone].len = v[p].len+1;\n\t\t\t\twhile(p != -1 && v[p].ch[c]\
    \ == o){\n\t\t\t\t\t//redirect all these to clone\n\t\t\t\t\tv[p].ch[c] = clone;\n\
    \t\t\t\t\tp = v[p].par;\n\t\t\t\t}\n\t\t\t\tv[o].par = v[cur].par = clone;\n\t\
    \t\t}\n\t\t}\n\t\tlast = cur;\n\t}\n\t\n\tll getsz(int x){\n\t\tif(v[x].cnt)\n\
    \t\t\treturn v[x].cnt;\n\t\tfor(auto i: v[x].ch)\n\t\t\tv[x].cnt += getsz(i.second);\n\
    \t\treturn ++v[x].cnt;\n\t}\n\t\n\t// k-th lexographically least substring (empty\
    \ string counts as the 0-th one)\n\tstring kth(int cur, int k){\n\t\tassert(k\
    \ < v[cur].cnt);\n\t\tif(!k) return \"\";\n\t\tk--;\n\t\tfor(auto i: v[cur].ch){\n\
    \t\t\tif(k < v[i.second].cnt)\n\t\t\t\treturn i.first+kth(i.second, k);\n\t\t\t\
    k -= v[i.second].cnt;\n\t\t}\n\t\tabort();\n\t}\n};\n"
  code: "#pragma once\n#include \"../utils/template.h\"\n\n/**\n * @brief Suffix Automaton\n\
    \ * @docs docs/suffix_automaton.md\n */\n\nstruct suffix_automaton{\n\tstruct\
    \ st{\n\t\tint len, par;\n\t\tll cnt;\n\t\tmap<char, int> ch;\n\t};\n\tvector<st>\
    \ v;\n\tint sz, last;\n\t\n\tvoid init(int n){\n\t\tv.resize(n*2);\n\t\tv[0].len\
    \ = 0; //0 is the root\n\t\tv[0].par = -1;\n\t\tsz = 1;\n\t\tlast = 0;\n\t}\n\t\
    \n\tvoid extend(char c){\n\t\tint cur = sz++;\n\t\tv[cur].len = v[last].len+1;\n\
    \t\tint p = last;\n\t\twhile(p != -1 && !v[p].ch.count(c)){\n\t\t\tv[p].ch[c]\
    \ = cur;\n\t\t\tp = v[p].par;\n\t\t}\n\t\tif(p == -1){\n\t\t\tv[cur].par = 0;\n\
    \t\t}\n\t\telse{\n\t\t\tint o = v[p].ch[c]; //\"other\"\n\t\t\tif(v[p].len+1 ==\
    \ v[o].len){\n\t\t\t\tv[cur].par = o;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tint clone\
    \ = sz++; //clone\n\t\t\t\tv[clone].ch = v[o].ch;\n\t\t\t\tv[clone].par = v[o].par;\n\
    \t\t\t\tv[clone].len = v[p].len+1;\n\t\t\t\twhile(p != -1 && v[p].ch[c] == o){\n\
    \t\t\t\t\t//redirect all these to clone\n\t\t\t\t\tv[p].ch[c] = clone;\n\t\t\t\
    \t\tp = v[p].par;\n\t\t\t\t}\n\t\t\t\tv[o].par = v[cur].par = clone;\n\t\t\t}\n\
    \t\t}\n\t\tlast = cur;\n\t}\n\t\n\tll getsz(int x){\n\t\tif(v[x].cnt)\n\t\t\t\
    return v[x].cnt;\n\t\tfor(auto i: v[x].ch)\n\t\t\tv[x].cnt += getsz(i.second);\n\
    \t\treturn ++v[x].cnt;\n\t}\n\t\n\t// k-th lexographically least substring (empty\
    \ string counts as the 0-th one)\n\tstring kth(int cur, int k){\n\t\tassert(k\
    \ < v[cur].cnt);\n\t\tif(!k) return \"\";\n\t\tk--;\n\t\tfor(auto i: v[cur].ch){\n\
    \t\t\tif(k < v[i.second].cnt)\n\t\t\t\treturn i.first+kth(i.second, k);\n\t\t\t\
    k -= v[i.second].cnt;\n\t\t}\n\t\tabort();\n\t}\n};"
  dependsOn:
  - content/utils/template.h
  isVerificationFile: false
  path: content/string/suffix_automaton.h
  requiredBy: []
  timestamp: '2024-02-01 17:09:56-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: content/string/suffix_automaton.h
layout: document
redirect_from:
- /library/content/string/suffix_automaton.h
- /library/content/string/suffix_automaton.h.html
title: Suffix Automaton
---
(Incomplete list of) Useful things to know about SAM:
- The suffix link tree (SLT) is a suffix trie that has its paths compressed (i.e. a path with no branches will get compressed to one edge).
- To find number of distinct substrings of multiple strings, just reset `SAM.last` to `0` in between strings.
