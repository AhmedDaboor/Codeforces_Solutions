#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using str = string;
using i128 = __int128_t;
#define AHMED ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl '
'
const ll INF = 1e18;
void print_int128(__int128 x);
int msb(int x);
int gcd(int a, int b);
ll lcm(int a, int b);
//_________________________________________________________________________________________________________________________________________
 
void solve() {
	int m; cin >> m;
	vi a(m+1), b(m+1);
	vi suff(m+2), pref(m+1);
	for(int i = 1; i <= m; i++) {
		int j; cin >> j; 
		a[i] = j;
	}
	for(int i = 1; i <= m; i++) {
		int j; cin >> j; 
		b[i] = j;
	}
	for(int i = 1; i <= m; i++){
		pref[i] = pref[i-1] + b[i];
	}
	for(int i = m; i >= 1; i--){
		suff[i] = suff[i+1] + a[i];
	}
	ll ans = INF; int idx = 1;
	for(int i = 1; i <= m ;i ++){
		ll res = max(suff[i+1],pref[i-1]);
		if(res < ans) {
			ans = res; idx = i;
		}
	}
	cout << max(suff[idx+1], pref[idx-1]) << endl;
}
 
int main() {
    AHMED;
    int t = 1;
	cin >> t;
    while(t--) solve();
    return 0;
}
 
 
//___________________________________________________________________________________________________________________________________________
void print_int128(__int128 x) {
    if (x == 0) { cout << "0"; return; }
    if (x < 0) { cout << '-'; x = -x; }
    string s;
    while (x > 0) {
        int digit = (int)(x % 10);
        s.pb(char('0' + digit));
        x /= 10;
    }
    reverse(all(s));
    cout << s << endl;
}
 
int msb(int x){
    if(x==0) return -1;
    return 31 - __builtin_clz(x);
}
 
int gcd(int a,  int b) {
    while(b != 0) {
        int temp =  b;
        b = a % b;
        a = temp;
    }
    return a;
}
 
ll lcm(int a, int b) {
    return (ll)(a/gcd(a, b))*b;
}