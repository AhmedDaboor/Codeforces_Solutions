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
	int n, k; cin >> n >> k;
	if(k+1==n) {cout << -1 << endl; return;}
	int c0 = (n + 1) / 2;
    int c1 = n / 2;
    int blocks = n - k;
    int sz0 = 1 + c0 - (blocks + 1) / 2;
    int sz1 = (blocks > 1 ? (1 + c1 - blocks / 2) : 0);
    for (int i = 0; i < blocks; i++) {
        int len = 1;
        if (i == 0) len = sz0;
        else if (i == 1) len = sz1;
        char ch = (i % 2 == 0) ? '0' : '1';
        while (len--) cout << ch;
    }
    cout << endl;
}
 
 
int main() {
    AHMED;
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