#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    str s; cin >> s;
    int l = 0, r = 0;
    int ansA = 0, ansB = 0, c = 0;
    l = 0; c = 0;
    for(r = 0; r < n; r++){
        if(s[r] != 'a') c++;
        while(c > k){
            if(s[l] != 'a') c--;
            l++;
        }
        ansA = max(ansA, r - l + 1);
    }
    l = 0; c = 0;
    for(r = 0; r < n; r++){
        if(s[r] != 'b') c++;
        while(c > k){
            if(s[l] != 'b') c--;
            l++;
        }
        ansB = max(ansB, r - l + 1);
    }
    cout << max(ansA, ansB) << endl;
}
 
int main() {
    AHMED;
    // freopen("outofplace.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);
    int t = 1;
	//cin >> t;
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