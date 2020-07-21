/*
*	Author: coder_tq
*	Time: 2020-02-09 22:05:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"

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

double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int n;
long double x[100010];
long double y[100010];
void input()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
}

void solve()
{
	x[0] = x[n];
	y[0] = y[n];
	x[n+1] = x[1];
	y[n+1] = y[1];
	long double ans[n+10];
	for(int i = 1; i <= n; i++) ans[i] = ((x[i-1]-x[i])*(x[i+1]-x[i])+(y[i-1]-y[i])*(y[i+1]-y[i]))/(fabs(dist(x[i-1],y[i-1],x[i],y[i]))*fabs(dist(x[i+1],y[i+1],x[i],y[i])));
	int flag = 1;
	long double sum = 0;
	vector<int> vec;
	//for(int i = 1; i <= n; i++) printf("%lf\n",ans[i]);
	if(n%2)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		for(int i = 1; i <= n/2; i++) if(ans[i] != ans[i+n/2]) flag = 0;
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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
