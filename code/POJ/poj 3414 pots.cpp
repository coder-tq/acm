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

int a,b,c; 
void input()
{
	scanf("%d%d%d",&a,&b,&c);
}

int vis[110];
string str[] = {"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(2,1)","POUR(1,2)"};//1 2 3 4 5 6
queue<int> qu;
int cura = 0,curb = 0;

void bfs()
{
	if(cura!=a) qu.push(0);
	if(curb!=b) qu.push(1);
	if(cura!=0) qu.push(2);
	if(curb!=0) qu.push(3);
	if(curb!=0) qu.push(4);
	if(cura!=0) qu.push(5);
	
	while(!qu.empty() ){
		
	}
}

void solve()
{
	MEM(vis);
	bfs();
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
