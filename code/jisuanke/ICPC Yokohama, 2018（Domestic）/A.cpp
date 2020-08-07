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

int n;
int arr[10010]; 
int input()
{
	scanf("%d",&n);
	REP(i,1,n) scanf("%d",&arr[i]);
	
	return n;
}

void solve()
{
	ll sum = 0;
	REP(i,1,n) sum+=arr[i];
	double aver = sum/n;
	ll ans = 0;
	REP(i,1,n) if(arr[i] < aver) ans++;
	printf("%lld\n",ans);
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(input())
	{
		solve();
	}
	return 0;
}
