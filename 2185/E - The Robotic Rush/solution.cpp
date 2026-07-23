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
 
int next(const vi&a, int tar){
	int l = 0, r = a.size()-1;
	int res = -1;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(a[mid] > tar){
			res = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return res;
}
 
int prev(const vi&a, int tar){
	int l = 0, r = a.size()-1;
	int res = -1;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(a[mid] < tar){
			res = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return res;
}
 
void solve() {
	int n,m,k; cin >> n >> m >> k;
	vi robots(n), lava(m);
	for(int&i:robots) cin >> i;
	for(int&i:lava) cin >> i;
	str s; cin >> s;
	vi l(n),r(n);
	sort(all(lava));
	for(int i = 0; i < n; i++){
		l[i] = prev(lava, robots[i]);
		r[i] = next(lava, robots[i]);
		if(r[i]==-1) r[i] = k+1;
		else r[i] = lava[r[i]] - robots[i];
		if(l[i]==-1) l[i] = k+1;
		else l[i] = robots[i] - lava[l[i]];
	}
	vector<vi> willDie(2*k+1);
	for(int i = 0; i < n; i++){
		if(l[i] <= k) {
			willDie[-l[i] + k].pb(i);
		}
		if(r[i] <= k){
			willDie[k+r[i]].pb(i);
		}
	}
	int delta = 0;
	vi taken(n);
	int alive = n;
	for(int i =0; i < k; i++){
		if(s[i] == 'L') {delta--;}
		else {delta++;}
		for(int j:willDie[delta+k]){
			if(taken[j] == 0){
				taken[j] = 1;
				alive--;
			}
		}
		willDie[delta+k].clear();
		cout << alive << ' ';
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