/*
*    Author: $%U%$
*    Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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

int m,p;
int n;
void input()
{
    cin >> n >> m >> p;
}

void solve()
{
    int cost,prise;
    cost = m;
    prise = (int)m*(1-p*1.0/100);
    int ans = 0;
    int cur = 0;
    //cout << ceil(m*p*0.01) << endl;
    while(n >= cost)
    {
        ans+=1;
        n=n-cost+prise;
    }
    cout << ans << endl;
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
