/*
*	Author: coder_tq
*	Time: 2020-03-09 22:35:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll mod = 998244353;
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
ll qpow(int i,int j)
{
	return j == 1?i:j&1?(qpow((i*i)%mod,j>>1)*i)%mod:qpow((i*i)%mod,j>>1);
}
int n,m;
ll jc[200010];
void input()
{
	cin >> n >> m;
}
void solve()
{
	ll sum = 1;
	jc[0] = 1;
	for(int i = 1; i < 200010; i++)
	{
		sum*=i;
		sum%=mod;
		jc[i] = sum;
	}
	ll mx = m-(n-1);
	mx%=mod;
	sum = 0;
	ll c;
	if(jc[n-2]%jc[n-2-((n-2)/2)] == 0)
	{
		c = jc[n-2]/jc[n-2-((n-2)/2)];
	}
	else c = (mod+jc[n-2])/jc[n-2-((n-2)/2)];
	c%=mod;
	c*=jc[(n-2)/2];
	c%=mod;
	for(int i = n-1; i <= m; i++)
	{
		ll ans;
		//Cn-2 (n-2)/2//n-2个数分配种类 
		//可选i-1，选n-2个数;
		//Ci-1 n-2//挑选n-2个数 
		if(jc[i-1]%jc[i-1-n+2] == 0)
		{
			ans = jc[i-1]/jc[i-1-n+2];
		}
		else ans = (jc[i-1]+mod)/jc[i-1-n+2];
		ans%=mod;
		ans*=jc[n-2];
		ans%=mod;
		ans%=mod;
		ans*=c;
		ans%=mod;
		sum+=ans;
		sum%=mod;
	}
	cout << sum << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
//3 3 3
//3 4 6
//3 5 10
//3 6 15
//4 4  
