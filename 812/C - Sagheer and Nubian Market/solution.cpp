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
	ll n, s; cin >> n >> s;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	auto can = [&](ll k){
		vector<ll> b(n+1);
		for(int i = 1; i <= n;i ++){
			b[i] = 1LL * a[i] + i * k;
		}
		sort(all(b));
		ll res = 0;
		for(int i = 1; i <= k; i++){
			res += b[i];
			if(res > s) return s+1;
		}
		return res;
	};
	ll l = 0, r = n;
	pair<ll,ll> ans;
	ans.first = 0, ans.second = 0;
	while(l <= r){
		ll mid = l + (r - l) / 2;
		ll b = can(mid);
		if(b <= s) {
			ans.first = mid;
			ans.second = b;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans.first << ' ' << ans.second << endl;
}
 
 
int main() {
    AHMED;
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