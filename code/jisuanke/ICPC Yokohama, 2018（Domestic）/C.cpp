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

int b;
int input()
{
	scanf("%d",&b);
	return b;
}

void solve()
{
	ll l = 1;
	ll sum = 1;
	PER(cnt,50000,0)
	{
		l = (b*2/cnt+1-cnt)/2;
		if(l <= 0) continue;
		sum = (2*l+cnt-1)*cnt/2;
		if(sum == b) 
		{
			printf("%lld %lld\n",l,cnt);
			return;
		}
		
	}
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(input())
	{
		;
		solve();
	}
	return 0;
}
