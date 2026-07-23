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
	ll m,h1,a1,x1,y1,h2,a2,x2,y2;
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	ll t1=0;
	while(h1!=a1&&t1<=2e6){
		h1=(x1*h1+y1)%m;
		++t1;
	}
	if(t1>2e6){cout << -1;return;}
	ll T1=1;
	h1=(x1*h1+y1)%m;
	while(h1!=a1&&T1<=2e6) {h1=(x1*h1+y1)%m; ++T1;}
	if(T1>2e6) T1=1e9;
	ll t2=0;
	while(h2!=a2&&t2<=2e6){h2=(x2*h2+y2)%m; ++t2; }
	if(t2>2e6) { cout << -1; return; }
	ll T2=1;
	h2=(x2*h2+y2)%m;
	while(h2!=a2&&T2<=2e6) { h2=(x2*h2+y2)%m; ++T2; }
	if(T2>2e6) T2=1e9;
	for(ll i=0;i<=2e6;i++) {
		ll k=t1+T1*i;
		if(k>=t2&&k%T2==t2%T2) { cout << k; return; }
	}
	cout << -1;
}
 
int main() {
    AHMED;
    // freopen("outofplace.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);
    int t = 1;
	//cin >> t;
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