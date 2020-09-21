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
string s; 
void input()
{
	cin >> n >> s; 
}

string fun(int n){
	string str = "2";
	string strt = "";
	while(n--){
		strt = "";
		for(int i = 0; i < str.length(); i++)
		{
			strt += to_string( 1 << (str[i]-'0') );
		}
		str = strt;
	}
	return str;
}



string str[10];
int dp[100010][10];//1 2 4 6
int def[4] = {1,2,4,6};
void solve()
{
	REP(i,0,9) str[i] = fun(i);
	REP(i,0,9) {
		REP(j,0,3){
			int sum = 0;
			for(char k : str[i])
			{
				if(k - '0' == def[j]) sum++;
			}
			dp[i][def[j]] = sum;
		}
	}
	REP(i,9,n) {
		REP(j,0,3){
			dp[i][def[j]] = (dp[i-3][def[j]]+dp[i-2][def[j]]+dp[i-1][def[j]]-dp[i-4][def[j]])%998244353;
		}
	}
	if(s.length() > 1) exit(-1);
	else printf("%d\n",dp[n-1][s[0]-'0']);
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
