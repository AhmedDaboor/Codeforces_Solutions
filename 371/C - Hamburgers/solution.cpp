#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
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
	str st; cin >> st;
	ll nb,ns,nc; cin >> nb >> ns >> nc ;
	ll pb,ps,pc; cin >> pb >> ps >> pc;
	ll rr; cin >> rr;
	ll b = 0, s = 0, c = 0;
	for(char&ch:st){
		if(ch == 'B') b ++;
		else if(ch == 'S') s ++;
		else c++;
	}
	auto can = [&](ll m){
		return (max(0LL,b*m-nb)*pb + max(0LL,s*m-ns)*ps + max(0LL,c*m-nc)*pc <= rr);
	};
	ll l = 0, r = 1e13, ans = 0;
	while(l <= r){
		ll mid = l + (r - l) / 2;
		if(can(mid)){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans << endl;
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