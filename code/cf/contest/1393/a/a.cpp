/*
*	Author: coder_tq1
*	Time: 2020-08-07 22:35:02
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
void input()
{
	scanf("%d",&n);
}

void solve()
{
	printf("%d\n",n/2+1);
}
/*
 1 1
 2 2
 3 2
 4 3
 5 3
 6 4
 7 4
 1 2 1 2 1 2
 2 3 2 3 2 1
 1 2 3 4 3 2
 2 3 4 3 2 1
 1 2 3 2 3 2
 2 1 2 1 2 1
*/
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
