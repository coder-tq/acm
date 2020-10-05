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
double arr[1000010];
double sum1[1000010];
double sum2[1000010];
void input()
{
	scanf("%d",&n);
	MEM(arr);
	MEM(sum1);
	MEM(sum2);
	REP(i,1,n){
		scanf("%lf",&arr[i]);
		sum1[i]+=sum1[i-1]+arr[i];
	}
}

void solve()
{
	PER(i,n,1){
		sum2[i]+=sum2[i+1]+arr[i];
	}
	double mx1 = 0;
	double mx2 = 0;
	REP(i,0,n+1){
		mx1 = max(mx1,sum1[i]/i);
		mx2 = max(mx2,sum2[i]/(n-i+1));
	}
	printf("%.9lf",max(mx1,mx2));
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
