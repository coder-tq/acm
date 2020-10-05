/*
*	Author: $%U%$
*	Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/ 
#include <bits/stdc++.h>
#define inf 0x7fffffff-1
#define llinf 9223372036854775807LL
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define MEM(a) memset(a,0,sizeof(a))

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll q_pow(ll a, ll b)
{
    ll ans = 1;
    while(b) {
        if(b&1)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

int n,k;
void input()
{
	scanf("%d%d",&n,&k);
}

int gird[500][500];
void solve()
{
	int ans;
	if(k%n==0) ans = 0;
	else ans = 2;
	MEM(gird);
	ll x = 0;
	ll y = 0;
	int cnt = 0;
	while(k--){
		//cout << x << ' ' << y << endl;
//		if(gird[x][y] == 1){
//			k++;
//		}
		gird[x%n][y] = 1;
		x++;
		y++;
		if(y >= n){
			x = ++cnt;
			y = 0;
		}
	}
	cout << ans << endl;
	REP(i,0,n-1){
		REP(j,0,n-1){
			cout << gird[i][j];
		}
		cout << endl;
	} 
}

int main()
{
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
