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
void print_int128(__int128 x);
int msb(int x);
int gcd(int a, int b);
ll lcm(int a, int b);
template <typename T>
inline void vecin(vector<T> &a);
template <typename T>
inline void vecout(const vector<T> &a);
//_________________________________________________________________________________________________________________________________________
 
void solve() {
  ll n, m;
  cin >> n >> m;
  vi v(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> v[i];
  }
  vector<vi> a(n, vi(m));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> a[i][j];
    }
  }
  vi mark(n, 0);
  const ll inf = 1e18;
  ll lst = inf;
  for(int i = 0 ; i < n ; i++) {
    if(v[i] < lst) {
      mark[i] = 1;
      lst = v[i];
    }
  }
  ll ans = m;
  priority_queue<ll> unused;
  priority_queue<ll, vi, greater<ll>> used;
  ll s = 0;
  for(int i = n - 1 ; i >= 0 ; i--) {
    for(int j = 0 ; j < m ; j++) {
      unused.push(a[i][j]);
    }
    while(!used.empty() && !unused.empty() && used.top() < unused.top()) {
      unused.push(used.top());
      s -= used.top();
      used.pop();
    }
    if(mark[i]) {
      while(!unused.empty() && s < v[i]) {
        s += unused.top();
        used.push(unused.top());
        unused.pop();
      }
      if(s >= v[i]) {
        ans = min(ans, ll(used.size()));
      }
    }
  }
  cout << ans << '
';
} 
 
int main() {
    AHMED;
    // freopen("breedflip.in","r",stdin);
    // freopen("breedflip.out","w",stdout);
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
 
template <typename T>
inline void vecin(vector<T> &a)
{
    for (auto &x : a)
        cin >> x;
}
 
template <typename T>
inline void vecout(const vector<T> &a)
{
    for (const auto &x : a)
        cout << x << ' ';
    cout << '
';
}