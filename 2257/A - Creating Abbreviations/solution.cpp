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
#define endl '
'
const ll INF = 1e18;
const ll MOD = 1e18;
void print_int128(__int128 x);
int msb(int x);
int gcd(int a, int b);
ll lcm(int a, int b);
ll power(ll base, ll exp);
template <typename T>
inline void vecin(vector<T> &a);
template <typename T>
inline void print(const vector<T> &a);
//_________________________________________________________________________________________________________________________________________ 
void solve() {
	ll n, m; cin >> n >> m;
    vector<bool> vis(26, false);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vis[toupper(s[0]) - 'A'] = true;
    }
    vector<str> abbr(m);
    for(int i = 0; i < m; i++) cin >> abbr[i];
    vector<bool> used(m, false);
    int ans = 0;
	for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            if (used[i]) continue;
            bool ok = true;
            for (char&c:abbr[i]) {
                if (!vis[toupper(c) - 'A']) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                used[i] = true;
                vis[toupper(abbr[i][0]) - 'A'] = true;
                ans++;
            }
        }
    }
    cout << (ans == m ? "YES" : "NO") << endl; 
}
 
int main() {
    AHMED;
    int t = 1; cin >> t;
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
 
template <typename T>
inline void vecin(vector<T> &a)
{
    for (auto &x : a)
        cin >> x;
}
 
template <typename T>
inline void print(const vector<T> &a)
{
    for (const auto &x : a)
        cout << x << ' ';
    cout << '
';
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