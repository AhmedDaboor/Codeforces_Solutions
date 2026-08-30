#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using str = string;
using i128 = __int128_t;
#define AHMED ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define gcd(a,b) __gcd(a,b)
#define endl '
'
const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll N = 1e6;
void print_int128(__int128 x);
ll power(ll base, ll exp);
vi fact(N + 1), invFact(N + 1);
void factorial();
ll nPr(ll n, ll r);
ll nCr(ll n, ll r);
 
//_________________________________________________________________________________________________________________________________________ 
 
void solve() {
    ll n, x; cin >> n >> x;
    vi a(n);
    for(ll&i:a) cin >> i;
    ll ans = 0;
    pair<ll,ll> prev = {abs(a[0]-x), a[0]+x};
    for(int i = 1; i < n; i++){
    	pair<ll,ll> cur = {(ll)abs(a[i]-x), a[i]+x};
    	if(cur.first > prev.second || cur.second < prev.first){
    		ans ++;
    		prev = cur;
    		continue;
    	}
    	prev = {max(prev.first, cur.first), min(prev.second,cur.second)};
    }
    cout << ans << endl;
} 
int main() {  
    AHMED;
  //  factorial();
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}
 
//___________________________________________________________________________________________________________________________________________
void print_int128(__int128 x) {
    if (x == 0) { cout << "0" << endl; return; }
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
 
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD; 
        exp /= 2;
    }
    return res;
}
void factorial() {
    fact[0] = 1;
 
    for (ll i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;
 
    invFact[N] = power(fact[N], MOD - 2);
 
    for (ll i = N; i >= 1; i--)
        invFact[i - 1] = invFact[i] * i % MOD;
}
 
ll nPr(ll n, ll r) {
    return fact[n] * invFact[n - r] % MOD;
}
 
ll nCr(ll n, ll r) {
    return (nPr(n,r) * invFact[r]) % MOD;
}