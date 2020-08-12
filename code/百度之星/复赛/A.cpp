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
ll Mod = 998244353;

ll ksm(ll x,ll y){
    int ans1=1;while (y){
        if (y&1) ans1=1ll*ans1*x%Mod;
        y>>=1;x=1ll*x*x%Mod;
    }return ans1;
}

ll m,p,q; 
void input()
{
	scanf("%lld%lld%lld",&m,&p,&q);
}


void solve()
{	
	ll dif = ((m*p-m*q+q*p/100)*Mod / p+1) % Mod ;
	printf("%lld\n",abs(dif));
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
