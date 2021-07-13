#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../content/string/manacher.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	string s;
	cin>>s;
	auto [a, b] = manacher(s);
	for(int i = 0; i < (int)size(s)-1; i++){
		cout<<a[i]*2-1<<' '<<b[i+1]*2<<' ';
	}
	cout<<a.back()<<'\n';
}