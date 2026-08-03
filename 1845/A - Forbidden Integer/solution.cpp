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
template <typename T>
inline void vecin(vector<T> &a);
template <typename T>
inline void vecout(const vector<T> &a);
//_________________________________________________________________________________________________________________________________________
 
void solve() {
	ll n, k, x; cin >> n >>  k >> x;
	if(x!=1){
		cout << "YES" << endl;
		cout << n << endl;
		for(int i = 1; i <= n; i++){
			cout << '1' << ' ';
		}
		cout << endl; return;
	}
	if(k==1 || (k==2 && n%2)) {cout << "NO" << endl; return;}
	if(n%2==0){
		cout << "YES" << endl << n/2 << endl;
		int c = n/2;
		while(c--) cout << 2 << ' ';
		cout << endl;
	}
	else {
		cout << "YES" << endl << (n-3)/2+1 << endl;
		cout << 3 << ' ';
		int c = (n-3)/2;
		while(c--) cout << "2 ";
		cout << endl;
	}
	
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