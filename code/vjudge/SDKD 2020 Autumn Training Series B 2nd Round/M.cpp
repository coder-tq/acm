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

double w,g,h,r;
void input()
{
	cin >> w >> g >> h >> r;
}

void solve()
{
	double w1 = (g-r) * 1.0 / ((g-r) + (h-r)) * w;
	double w2 = (h-r) * 1.0 / ((g-r) + (h-r)) * w;
	printf("%.8lf %.8lf\n",sqrt( abs(g-h)*abs(g-h)+w*w ) , sqrt( (g-r)*(g-r)+w1*w1 ) + sqrt( (h-r)*(h-r)+w2*w2 ) );
	//cout << sqrt( abs(g-h)*abs(g-h)+w*w ) << ' ' << sqrt( ((h-r)+(g-r))*((h-r)+(g-r))+w*w ) << endl; 
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
