/*
*	Author: coder_tq
*	Time: 2020-04-01 22:35:18
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
int n;
int arr[6];
int ans[6]; 
void input()
{
	cin >> n;
}
//twofa ctors
void solve()
{
	int pos = 0;
	while(n)
	{
		if(n%2) arr[pos] = 1;
		else arr[pos] = 0;
		pos++;
		n/=2;
	}
	for(int i = 0; i < 6; i++) ans[i] = arr[i];
	int t;
	{
		t = ans[0];
		ans[0] = ans[4];
		ans[4] = t;
	}
	{
		t = ans[2];
		ans[2] = ans[3];
		ans[3] = t;
	}
	int ans1 = 0;
	for(int i = 0; i < 6; i++)
	{
		ans1+=ans[i]*pow(2,i);
	}
	cout << ans1 << endl;
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
