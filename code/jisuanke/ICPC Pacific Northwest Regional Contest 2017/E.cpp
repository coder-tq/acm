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

double n,x;
double vx; 
bool input()
{
	return (scanf("%lf%lf%lf",&n,&x,&vx)==EOF)?0:1;
}

void solve()
{
	double l,r,vy,v;
	double sum=0;
    while(n--)
    {
        cin>>l>>r>>vy;
        sum+=(r-l)*vy;
    }
    sum=sum/x;
    if(fabs(sum)>vx)
    {
        cout<<"Too hard"<<endl;
        return;
    }
    v=sqrt(vx*vx-sum*sum);
    if(v<vx/2)
        cout<<"Too hard"<<endl;
    else
    {
        v=x/v;
        cout<<fixed<<setprecision(3)<<v<<endl;
    }

}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(input())
	{
		;
		solve();
	}
	return 0;
}
