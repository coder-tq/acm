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

int w,p;
void input()
{
	cin >> w >> p;
}
int v[1010];
int ans[1010];
void solve()
{
	REP(i,1,w)
	{
		REP(j,1,p)
		{
			scanf("%d",&v[j]);
		}
		sort(v+2,v+p+1);
		
		ll cur = 0;
		ll tem;
		PER(j,p,2)
		{
			if(v[1] < v[j])
			{
				//printf("j:%d v[j]:%d v[1]:%d\n",j,v[j],v[1]);
				tem = v[1];
//				cur += ceil((v[j]-v[1])/2.0);
//				v[1] += ceil((v[j]-v[1])/2.0);
//				v[j] -= ceil((v[j]-v[1])/2.0);
				v[1] = ceil((v[j]+v[1])/2.0);
				cur += v[1]-tem;
				v[j] -= v[1]-tem;
				//printf("j:%d v[j]:%d v[1]:%d\n",j,v[j],v[1]);
			}
		}
		int f = 0;
		PER(j,p,2)
		{
			if(v[1] == v[j])
			{
				f = 1;
			}
		}
		cur+=f;
		//cout << cur << endl;
		ans[i] = cur;
	}
	sort(ans+1,ans+w+1);
	ll sum = 0;
	REP(i,1,w/2+1)
	{
		sum+=ans[i];
	}
	cout << sum << endl;
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
