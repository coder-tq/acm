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
pair<int,int> pos[100010];
void input()
{
	scanf("%d",&n);
}

void solve()
{
	ll ans;
	int x,y;
	pair<int,int> last1,last2;
	last1=MP(-1,-1);
	last2=MP(-1,-1);
	REP(i,1,n) {
		scanf("%d%d",&x,&y);
		if(x == 1)
		{
			if(last1.second < y) last1 = MP(x,y);
		}
		if(x == 2)
		{
			if(last2.second < y) last2 = MP(x,y);
		}
	}
	if(last1.S == -1)
	{
		ans = last2.S+2;
	}
	else if(last2.S == -1)
	{
		ans = last1.S+1;
	}
	else if(last1.S <= last2.S)
	{
		ans = last2.S+2;
	}
	else if(last1.S == last2.S+1)
	{
		ans = last2.S+3;
	}
	else if(last1.S > last2.S+1)
	{
		ans = last1.S+1;
	}
	printf("%lld\n",ans);
}

int main()
{
	//ios::sync_with_stdio(false);
	int t = 1;
	scanf("%d",&t); 
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
