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
void print_int128(__int128 x);
int msb(int x); 
ll power(ll base, ll exp);
template <typename T>
inline void vecin(vector<T> &a);
template <typename T>
inline void print(const vector<T> &a);
//_________________________________________________________________________________________________________________________________________ 
 
void solve() {
    ll x, y, i, j; cin >> x >> y >> i >> j;
    cout << 1 << ' ' << 1 << ' ' << x << ' ' << y << endl;
} 
int main() {  
    AHMED;
    int t = 1; cin >> t;
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
 
int msb(int x){
    if(x==0) return -1;
    return 31 - __builtin_clz(x);
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