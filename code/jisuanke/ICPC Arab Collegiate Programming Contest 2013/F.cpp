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
	cin >> s;
}

int num;
void solve()
{
	int curx = 0;
	int cury = 0;
	num = 0;
	for(auto i:s)
	{
		if(i == 'R') curx++;
		if(i == 'L') curx--;
		if(i == 'U') cury++;
		if(i == 'D') cury--;
		if(i == '?') num++;
	}
	cout << curx-num << ' ' << cury-num << ' ' << curx+num << ' ' << cury+num << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
