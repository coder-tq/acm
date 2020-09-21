/*
*	Author: coder_tq1
*	Time: 2020-09-10 20:49:05
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
string str; 
void input()
{
	cin >> n >> str;
}

int cur1;
int cur0;
int ans[200010];
void solve()
{
	int mx = 0;
	int sum = 0;
	cur1 = 1;
	cur0 = 1;
	REP(i,0,n-1){
		if(str[i] == '1'){
			if(cur0 > 1){
				cur0--;
				if(cur0 == 1) cur1++;
				ans[i] = cur0;
			}
			else {
				ans[i] = cur1;
				cur1++;
			}
		}
		else {
			if(cur1 > 1){
				cur1--;
				if(cur1 == 1) cur0++;
				ans[i] = cur1;
			}
			else {
				ans[i] = cur0;
				cur0++;
			}
		}
		mx = max(mx,ans[i]);
	}
	cout << mx << endl;
	REP(i,0,n-1) cout << ans[i] << ' ';
	cout << endl;
}
//11100000111111
//12332145
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
