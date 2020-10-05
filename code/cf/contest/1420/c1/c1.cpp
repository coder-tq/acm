/*
*	Author: coder_tq1
*	Time: 2020-09-24 22:35:03
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

int n,q;
int arr[300010];
void input()
{
	scanf("%d%d",&n,&q);
	REP(i,1,n){
		scanf("%d",&arr[i]);
	}
}

ll dp[300010]; 
void solve()
{
	ll ans = 0;
	int la = 0;
	int flag = 1;
	REP(i,1,n){
		if(flag) {
			if(arr[i] >= la) la = arr[i];
			else {
				//cout << la << endl;
				ans+=la;
				flag = 0;
				la = arr[i];
				i--;
			}
		}
		else {
			if(arr[i] <= la) la = arr[i];
			else {
				//cout << la << endl;
				ans-=la;
				flag = 1;
				la = arr[i];
				i--;
			}
		}
	}
	if(flag) ans+=la;
	cout << ans << endl;
}

int main()
{
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
