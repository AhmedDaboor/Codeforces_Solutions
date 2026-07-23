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
 
vector<ll> v;
const ll X = 1e12;
void cube(){
	for(ll i = 1; i*i*i <= X; i++){
		v.pb(i);
	}
}
 
void solve() {
    ll x; cin >> x;
  	for(ll i = 1; i*i*i <= x; i++){
  		ll target = x - i*i*i;
  		ll l = 0, r = v.size() - 1;
  		while(l <= r){
  			ll mid = (l + r) / 2;
  			ll cube = v[mid]*v[mid]*v[mid];
  			if(cube == target){cout << "YES" << endl;return;}
  			else if(cube < target) l = mid + 1;
  			else r = mid - 1;
  		}
  	}
	cout << "NO" << endl;
}
 
int main() {
    AHMED;
    // freopen("outofplace.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);
    cube();
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