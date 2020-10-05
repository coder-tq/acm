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

int n,x; 
int odd,even;
void input()
{
	cin >> n >> x;
	int t;
	REP(i,1,n) {
		cin >> t;
		if(t&1) odd++;
		else even++;
	}
}

void solve()
{
	if(odd!=0&&!(n == x&&(odd%2==0))&&!(odd==n&&(x%2==0))){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

int main()
{
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		odd = 0;
		even = 0;
		input();
		solve();
	}
	return 0;
}