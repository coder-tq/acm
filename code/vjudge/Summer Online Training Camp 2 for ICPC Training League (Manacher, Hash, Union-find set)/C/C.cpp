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

string s; 
void input()
{
}
ll hasha[1000100];
ll p=1e6+7;
void solve()
{
	memset(hasha,0,sizeof(hasha));
	int ans = 0;
	for(int i = 1; i <= s.length(); i++)
	{
		hasha[i] = (hasha[i-1]*p+s[i-1]-'a'+1)%mod;
	}
	cout << "------------------------" << endl;
	for(int i = 1; i <= s.length(); i++)
	{
		int cur = 0;
		ll totalhash=hasha[s.length()];
		while(totalhash%hasha[i]*q_pow(p,i) == 0)
		{
			cur++;
			totalhash/=hasha[i]*q_pow(p,i);
		}
		if(totalhash == 1) ans = max(ans,cur);
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(cin >> s)
	{
		if(s == ".") return 0;
		input();
		solve();
	}
	return 0;
}
