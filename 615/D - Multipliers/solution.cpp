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
    ll n; cin >> n;
    map<ll,ll> m;
    for(int i = 0; i < n; i++){
        ll p; cin >> p;
        m[p]++;
    }
    ll N = 1;
    for(auto&[p,e]:m){
        for(ll i= 1; i<= e; i++){
            N = (N * p) % MOD;
        }
    }
    ll S = 1;
    for(auto&[p,e]:m){
        if(e % 2 == 1) { S = -1; break; }
        for(ll i= 1; i<= e/2; i++){
            S = (S * p) % MOD;
        }
    }
    ll cnt = 1;
    bool isHalf = false;
    for(auto&[p,e]:m){
        ll terms = e + 1;
        if(!isHalf && terms % 2 == 0){
            terms /= 2;
            isHalf = true;
        }
        cnt = (cnt * (terms % (MOD - 1))) % (MOD - 1);
    }
    if(S == -1){
        cout << power(N, cnt) << endl;
    }
    else {
        cout << power(S, cnt) << endl;
    }
} 
int main() {  
    AHMED;
    int t = 1; //cin >> t;
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