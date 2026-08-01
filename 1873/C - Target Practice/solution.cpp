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
	int ans = 0;
	int g[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,2,2,2,2,2,2,2,2,1},
		{1,2,3,3,3,3,3,3,2,1},
		{1,2,3,4,4,4,4,3,2,1},
		{1,2,3,4,5,5,4,3,2,1},
		{1,2,3,4,5,5,4,3,2,1},
		{1,2,3,4,4,4,4,3,2,1},
		{1,2,3,3,3,3,3,3,2,1},
		{1,2,2,2,2,2,2,2,2,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			char c; cin >> c;
			if(c=='X') ans += g[i][j];
		}
	}
	cout << ans << endl;
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