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

int xa,ya,xb,yb; 
void input()
{
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
}

void solve()
{
	if(xa == 0&&ya == 0)
	{
		if(xa == xb&&ya==yb) printf("1\n");
		else printf("0\n");
		return;
	}
	if(xa == 0||ya == 0)
	{
		int gcd = max(abs(xa),abs(ya));
		if(abs(xa-xb) % gcd == 0 && abs(ya-yb) % gcd == 0 )	printf("1\n");
		else printf("0\n");
		return;
	}
	if(abs(xa-xb) % __gcd(xa,ya) == 0 && abs(ya-yb) % __gcd(xa,ya) == 0 )	printf("1\n");
	else printf("0\n");
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
