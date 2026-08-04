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
	int n; cin >> n;
	str a,b; cin >> a >> b;
	if(a==b){cout << "YES" << endl; return;}
	if(n==2){cout << "NO" << endl; return;}
	vi c(8);
	for(int i = 0; i < n; i++){
		if(i%2){
			if(a[i]=='1') c[0]++;
			else c[1]++;
			if(b[i]=='1') c[2]++;
			else c[3]++;
		}
		else{
			if(a[i]=='1') c[4]++;
			else c[5]++;
			if(b[i]=='1') c[6]++;
			else c[7]++;
		}
	}
	if(c[0] == c[2] && c[1]==c[3] && c[4] == c[6] && c[5] == c[7]) cout << "YES" << endl;
	else cout << "NO" << endl;
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