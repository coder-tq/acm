/*
*	Author: $%U%$
*	Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/ 
#include <bits/stdc++.h>
#define endl "\n"
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

int n;
int b[110];
double c[110]; 
void input()
{
	cin >> n;
	REP(i,1,n) cin >> b[i] >> c[i];
}

void solve()
{
	double ans = 0;
	REP(i,1,n) ans = max(ans,(1-c[i])/(b[i]+1-c[i]) );
	printf("%.5lf\n",ans);
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
