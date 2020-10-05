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
vector<int> node[100010];
int du[100010];
void input()
{
	MEM(du);
	int x,y;
	cin >> n;
	REP(i,1,n) node[i].clear();
	REP(i,1,n-1){
		cin >> x >> y;
		du[x]++;
		du[y]++;
		node[x].push_back(y);
		node[y].push_back(x);
	}
}

int flag = 0;
int dis[100010];
int ans;
void dfs(int x,int fa){
	int cnt = 0;
	for(auto v:node[x]){
		
		dis[v] = dis[x]+1;
		if(du[v] == 1&&dis[v]&1) flag = 1;
		if(du[v] == 1) cnt++;
		if(v == fa) continue;
		if(du[v] > 1) dfs(v,x);
	}
	//cout << x << ' ' << cnt << endl;
	ans-=max(0,cnt-1);
}

void solve()
{
	int root;
	REP(i,1,n){
		if(du[i] == 1) {
			root = i;
			break;
		}
	}
	//cout << root << endl;
	ans = n-1;
	dfs(root,0);
	if(flag) cout << 3 << endl;
	else cout << 1 << endl; 
	cout << ans << endl;
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
