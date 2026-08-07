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
	ll n; cin >> n;
	vi a(n);
	vecin(a);
	map<int, int> p;
	ll cnt = 1;
	for(int i = 1; i < n; i++){
		if(a[i]!=a[i-1]) p[i-1] = cnt, cnt = 1;
		else cnt++;
	}
	p[n-1]=cnt;
	vector<pair<ll,ll>> b(all(p));
	ll L = b.size();
	if(L == 1) {cout << 1 << endl; return;}
	for(int i = 1; i < L; i++){
		if(b[i].second >= 2 && b[i-1].second >= 2){
			cout << L + 2 << endl; return;
		}
	}
	for(int i = 0; i < L; i++){
		if(b[i].second >= 2){
			ll col = a[b[i].first];
			bool can = false;
			if (i - 1 >= 0) {
				if (i - 2 < 0 || a[b[i-2].first] != col) {
					can = true;
				}
			}
			if (i + 1 < L) {
				if (i + 2 >= L || a[b[i+2].first] != col) {
					can = true;
				}
			}
			if (can) {
				cout << L + 1 << endl;
				return;
			}
		}
	}
	cout << L << endl;
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