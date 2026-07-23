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
	int n,m; cin >> n >> m;
	vi a(1000003), d(1000003);
	for(int i=1; i<=n; i++) cin >> a[i];
	a[++n]=m;
	for(int i=n; i--;) d[i]=a[i+1]-a[i]+d[i+2];
	int ans = d[0];
	d[0] = 0;
    for(int i = 0; i < n; ++i,d[i]=d[i-1]+(i%2?a[i]-a[i-1]:0)) 
		if(a[i]+1<a[i+1]) 
			ans = max(ans,d[i]+a[i+1]-a[i]-1+d[i+1+(i%2)]);
	cout << ans << endl;
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