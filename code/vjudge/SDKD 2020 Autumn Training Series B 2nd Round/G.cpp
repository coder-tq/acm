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

int pro[105];
int sum;

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


void input()
{
	cin >> sum;
	for(int i=1; i<=sum; ++i){
		cin >> pro[i];
	}
}

void solve()
{
	sort(pro+1, pro+sum+1, greater<int>() );
	/*	
	for(int i=1; i<=sum; ++i){
		cout << pro[i] << endl;
	}
	*/
	double ans = -1;
	for(int s=1; s<=sum; ++s){
		double sum = 0;
		for(int a=1; a<=s; ++a){
			double p = 1;
			for(int i=1; i<=a; ++i){
				p *= pro[i]*1.0/100.0;
			}
			for(int i=a+1; i<=s; ++i){
				p *= (100 - pro[i])*1.0/100.0;
			}
			//cout << p << endl;
			sum += p * pow(a*1.0, a*1.0/s);
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

int main()
{
	cout << sqrt(2500+28*28) + sqrt(2500+18*18);
	int t = 1;
	//scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
