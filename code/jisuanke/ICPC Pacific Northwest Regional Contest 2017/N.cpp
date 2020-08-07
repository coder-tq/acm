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
void input()
{
	scanf("%d",&n);
}
char mp[50][50];
int vis1[50][500];
int vis2[50][500];

bool check()
{
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			if(vis1[i][mp[i][j]]) return 0;
			vis1[i][mp[i][j]] = 1;
		}
	}
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			if(vis2[j][mp[i][j]]) return 0;
			vis2[j][mp[i][j]] = 1;
		}
	}
	return 1;
}
bool check2()
{
	REP(i,2,n)
	{
		if(mp[1][i] > mp[1][i-1]) continue;
		else return 0;
	}
	REP(i,2,n)
	{
		if(mp[i][1] > mp[i-1][1]) continue;
		else return 0;
	}
	return 1;
}

void solve()
{
	MEM(vis1);
	MEM(vis2);
	REP(i,1,n)
	{
		getchar();
		REP(j,1,n)
		{
			scanf("%c",&mp[i][j]);
			if(mp[i][j] >= 'A'&&mp[i][j] <= 'Z') mp[i][j]=mp[i][j]-'A'+'9'+1;
		}
	}
	if(!check())
	{
		printf("No\n");
		return;
	}
	if(check2())
	{
		printf("Reduced\n");
		return;
	}
	printf("Not Reduced\n");
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
