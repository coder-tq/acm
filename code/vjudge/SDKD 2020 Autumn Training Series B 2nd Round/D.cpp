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
int n;
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


void input()
{
	scanf("%d", &n);
}

int a[1000] = {0};
void solve()
{
	int num = 0;
	int x;
	int Max = -1;
	for(int i=1; i <=n; i ++ ) {
		scanf("%d", &x);
		a[x] = 1;
		Max = max(x, Max);
	}
	bool flag = false;
	for(int i=1;i <= Max; i ++ ) {
		if(a[i] == 0) printf("%d\n", i);
		if(a[i] == 0) flag = true;
	}
	if(flag == false) puts("good job");
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
