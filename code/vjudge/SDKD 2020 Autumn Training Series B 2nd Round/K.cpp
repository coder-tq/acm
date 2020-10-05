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

string str;
void input()
{
	cin >> str;
}
// enun
int la[30];
int a[100010];//上一个字母出现的位置 
int cnt[100010];//重复出现的字母个数 
int vis[30];
void solve()
{
	MEM(vis);
	MEM(cnt);
	memset(la,-1,sizeof(la));
	int len = str.length();
	for(int i = 0; i < len; i++){
		a[i] = la[str[i]-'a'];
		la[str[i]-'a'] = i;
		printf("a[%d]: %d\n",i,a[i]);
	} 
	for(int i = 0; i < len; i++){
		if(i == 0){
			vis[str[i] - 'a'] = 1;
			continue;
		}
		if(a[i]!=-1)
			cnt[i] += max(0,cnt[i-1]-cnt[a[i]]);
		else cnt[i] += cnt[i-1];
		if( vis[str[i]-'a'] == 1) {
			cnt[i+1]++;
		}
		vis[str[i] - 'a'] = 1;
		printf("cnt[%d]: %d\n",i,cnt[i]);
	} 
	ll sum = 0;
	for(int i = 1; i < len; i++){
		printf("ans[%d]: %d\n",i,i-a[i]-1-cnt[i]);
		sum += max(0,i-a[i]-1-cnt[i]);
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
