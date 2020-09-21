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
string t;
void input()
{
	cin >> n;
}

int cou[30] = {0};
void solve()
{
	REP(i,1,n) {
		MEM(cou);
		cin >> t;
		REP(j,0,t.size()-1) cou[t[j]-'a']++;
		int ans = 0;
		REP(j,0,26) ans = max(ans,cou[j]); 
		printf("Case #%d: %d\n",i,ans);
	}
}

//00 00 
//00 01
//01 00
//01 01
//01 10
//10 11
//11 10
//11 11


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
