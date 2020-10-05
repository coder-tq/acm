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
double arr[110];
void input()
{
	cin >> n;
	REP(i,1,n) cin >> arr[i];
}

double dfs(int k,int i,int cur){ // 剩余通过数，当前 
	if(k == 0){
		return 0;
	}
	if(cur == 0) return 0;
	if(i > n) return 0;
	
	cur--;
	
	double ans = 0;
	k--;
	ans += arr[i]/100.0*dfs(k,i+1,cur);
	k++;
	ans += (1-arr[i]/100.0)*dfs(k,i+1,cur);
	return ans;
};

void solve()
{
	double ans = 0;
	sort(arr+1,arr+n+1, greater<double> () );
	dp[i][j] = dp[i-1]y 
	REP(i,1,n){ // 提交i篇  
		double cur = 0;
		REP(j,1,i){ // 通过j篇 
			cur += dfs(j,1,i);
			ans = max(ans,cur);
		}
		//ans = max(ans,pow(ex*n,ex*n/n));
		//cout << dfs(i,1) << endl;
	}
	cout << ans << endl;
}
// abcdeb
// abbcde
// abccde
// abcccde
// abcdde
// abcddde
// abcdddde


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
