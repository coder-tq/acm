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
int a[200100]; 
void input()
{
	cin >> n;
	int t;
	REP(i,1,n+10) a[i] = 0;
	REP(i,1,n){
		scanf("%d",&t);
		if(t > n) continue;
		a[t]++;
	}
}

void solve()
{
	int cur = 1;
	int vcur = 1;
	REP(i,1,n){
		vcur += a[i];
		if(i <= cur)
			cur += a[i];
		if(i < vcur) cur = vcur;
	}
	//if(n < vcur) cur = vcur; 
	cout << cur << endl;
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
