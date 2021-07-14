#define PROBLEM "https://atcoder.jp/contests/agc001/tasks/agc001_a"
#include "../content/utils/template.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, l[200];
	cin>>n;
	for(int i = 0; i < 2*n; i++)
		cin>>l[i];
	sort(l, l+2*n);
	int ans = 0;
	for(int i = 0; i < 2*n; i += 2){
		ans += l[i];
	}
	cout<<ans<<'\n';
}