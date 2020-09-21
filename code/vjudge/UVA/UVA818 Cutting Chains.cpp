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
int mp[20][20];

int input()
{
	MEM(mp);
	cin >> n;
	if(n == 0) return 0;
	int x,y;
	while(1){
		cin >> x >> y;
		if(x == -1 && y == -1) break;
		mp[x][y] = mp[y][x] = 1;
	}
	return 1;
}

bool check1(ll x) // 是否有度数大于2的点 
{
	REP(i,1,n){
		int cnt = 0;
		if(x >> (i-1) & 1) continue;
		REP(j,1,n){
			if(x >> (j-1)&1) continue;
			if(mp[i][j]) cnt++; 
		}
		if(cnt > 2) return 0;
	}
	return 1;
}


int vis[20]; 
int vis2[20];
int flag = 1;
int con = 0;
void dfs(int x,ll p,int fa)
{
	if(p >> (x-1) & 1) return; 
	if(vis[x] == 1){
		flag = 0;
		return;
	}
	vis[x] = 1;
	REP(i,1,n){
		if(i == x) continue;
		if(i == fa) continue;
		if(p >> (i-1) & 1) continue;
		if(mp[x][i]) dfs(i,p,x);
	}
}

ll count(ll x){
	ll ans = 0;
	while(x){
		if(x&1) ans++;
		x = x>>1; 
	}
	return ans;
}
int kase = 0;
void solve()
{
	
	ll ans = 0x3f3f3f3f;
	ll s = (1 << n);
	for(auto i = 0; i < s; i++)
	{
		ll tem = i;
		//while(tem) printf("%d",tem&1),tem >>= 1;
		//cout << endl;
		con = 0;
		MEM(vis);
		if(!check1(i)) continue; //度数检查不通过
		//cout << "passed check1!" << endl;
		flag = 1;
		REP(j,1,n) {
			if(vis[j]|| i >> (j-1) & 1) {
				continue;
			}
			con++;
			dfs(j,i,-1);
		}
		if(!flag) continue; //有环 
		//cout << "passed check2!" << endl;
		
		//cout << con << endl;
		if (count(i) >= con - 1)
			ans = min(count(i),ans);
	}
	printf("Set %d: Minimum links to open is %d\n",++kase,ans);
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	//printf("%d",count(15)); 
	while(input())
	{
		solve();
	}
	return 0;
}
