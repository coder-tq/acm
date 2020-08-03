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

int n,m;
int a[110];
void input()
{
	scanf("%d",&n);
	scanf("%d",&m);
	REP(i,1,n)
	{
		int x,y;
		scanf("%d:%d",&x,&y);
		a[i] = x*60+y;
	}
}

void solve()
{
	ll sum = 0;
	REP(i,1,n)
	{
		sum += a[i];
	}
	sum-=(n-1)*m;
	printf("%02d:%02d:%02d\n",sum/3600,sum%3600/60,sum%3600%60);	
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
