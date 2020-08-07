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

int road[] = {1,8,2,7,3,6,4,5};
int vis[10];

void solve()
{
	if(n == 16)
	{
		printf("a1 b1 c1 h1 h2 a2 a3 h3 h4 a4 a5 h5 h6 a6 a7 h7 h8\n");
		return;
	}
	if(n == 24)
	{
		printf("a1 b1 c1 d1 e1 f1 g1 h1 h2 e2 d2 c2 b2 a2 a3 h3 h4 a4 a5 h5 h6 a6 a7 h7 h8\n");
		return;
	}
	if(n == 32)
	{
		printf("a1 c1 d1 e1 f1 g1 h1 b1 b2 c2 d2 e2 f2 g2 h2 a2 a3 c3 d3 e3 f3 g3 h3 b3 b4 c4 d4 e4 f4 g4 a4 a8 h8\n");
		return;
	}
	if(n == 40)
	{
		printf("a1 c1 d1 e1 f1 g1 h1 b1 b2 c2 d2 e2 f2 g2 h2 a2 a3 c3 d3 e3 f3 g3 h3 b3 b4 c4 d4 e4 f4 g4 h4 a4 a5 c5 d5 e5 f5 g5 b5 b8 h8\n");
		return;
	}
	if(n == 48)
	{
		printf("a1 c1 d1 e1 f1 g1 h1 b1 b2 c2 d2 e2 f2 g2 h2 a2 a3 c3 d3 e3 f3 g3 h3 b3 b4 c4 d4 e4 f4 g4 h4 a4 a5 c5 d5 e5 f5 g5 h5 b5 b6 c6 d6 e6 f6 g6 a6 a8 h8\n");
		return;
	}
	if(n == 56)
	{
		printf("a1 c1 d1 e1 f1 g1 h1 b1 b2 c2 d2 e2 f2 g2 h2 a2 a3 c3 d3 e3 f3 g3 h3 b3 b4 c4 d4 e4 f4 g4 h4 a4 a5 c5 d5 e5 f5 g5 h5 b5 b6 c6 d6 e6 f6 g6 h6 a6 a7 c7 d7 e7 f7 g7 b7 b8 h8\n");
		return;
	}
	MEM(vis);
	int curx = 1;
	int cury = 1;
	
	int line = n/8;
	if(n%8 == 0) line--;
	n=n%8;
	if(n == 0) n+=8;
	n-=1;
	printf("a1");
	REP(i,1,line)
	{
		if(i == 1) 
		{
			REP(j,1,7) printf(" %c%d",i+'a'-1,road[j]),curx = road[j];
		}
		else if(i%2 == 0) PER(j,7,0) printf(" %c%d",i+'a'-1,road[j]),curx = road[j];
		else REP(j,0,7) printf(" %c%d",i+'a'-1,road[j]),curx = road[j];
		//printf("\n");
	}
	printf(" h%d",curx);
	vis[curx] = 1;
	//if(curx!=1) n++;
	int i = 0;
	while(n--)
	{
		i++;
		if(vis[i] == 1) {
			if(line > 0) n++;
			continue;
		}
		printf(" h%d",i);
		
	}
	printf(" h8\n");
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
