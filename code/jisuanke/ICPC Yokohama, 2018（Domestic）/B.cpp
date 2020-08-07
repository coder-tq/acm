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

int n,m,p,t;
ll fold[500][500];
int input()
{
	scanf("%d%d%d%d",&m,&n,&t,&p);
	return m;
}

void solve()
{
	int curx = 0;
	int cury = 0;
	int d,x;
	MEM(fold);
	REP(i,0,n-1)//初始化 
	{
		REP(j,0,m-1)
		{
			fold[i][j] = 1;
		}
	}
	REP(i,1,t)//模拟折纸 
	{
		scanf("%d%d",&d,&x);
		if(d == 1)//从左向右折叠 x个格子 
		{
			REP(k,cury,300)//从下到上 
			{
				REP(j,curx,curx+x-1)//从左到右
				{
					fold[k][j+2*(curx+x-j)-1]+=fold[k][j];
				}
			}
			
			
			curx+=x;
		}
		if(d == 2)//从下向上折叠 x个格子 
		{
			REP(k,curx,300)//从左到右 
			{
				REP(j,cury,cury+x-1)//从下到上 
				{
					fold[j+2*(cury+x-j)-1][k]+=fold[j][k];
				}
			}
			
			
			cury+=x;
		}
//        REP(i,0,10)//test 
//        {
//            REP(j,0,10)
//            {
//                printf("%d ",fold[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
	}
	
    //printf("curx: %d cury: %d\n",curx,cury);
	REP(i,1,p)//查询 
	{
		int xa,ya;
		scanf("%d%d",&xa,&ya);
		printf("%lld\n",fold[cury+ya][curx+xa]);
	}
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
