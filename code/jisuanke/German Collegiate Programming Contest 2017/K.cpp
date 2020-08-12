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

struct worker{
	string name;
	int money;
};

bool cmp(worker o1,worker o2)
{
	if(o1.money == o2.money) return o1.name > o2.name;
	return o1.money > o2.money;
}

int n,d,k;
worker wor[10010];
void input()
{
	scanf("%d%d%d",&n,&d,&k);
	REP(i,1,n)
	{
		cin >> wor[i].name >> wor[i].money;
	}
}

void solve()
{
	sort(wor+1,wor+n+1,cmp);
	ll sum = 0;
	int num = 0;
	REP(i,1,k)
	{
		num++;
		sum+=wor[i].money;
		if(sum >= d) break;
	}
//	REP(i,1,n)
//	{
//		cout << wor[i].money << ' ' << wor[i].name << endl;
//	}
	if(sum < d) 
	{
		printf("impossible\n");
		return;
	}
	printf("%d\n",num);
	REP(i,1,num)
	{
		cout << wor[i].name << ", YOU ARE FIRED!\n";
	}
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
