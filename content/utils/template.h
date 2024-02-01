/**
 * @brief My starter code
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define makeunique(x) (x).erase(unique((x).begin(), (x).end()), (x).end());

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;
