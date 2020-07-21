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
int n; 
int arr[100010];
int pos[100010];

void bit(int num,int k)
{
	string ans;
	while(num>=2)
	{
		ans+=num%2+'0';
		num/=2;
	}
	ans+=num+'0';
	
	for(int i = ans.length()-1; i >= 0; i--)
	{
		if(ans[i] == '1'&&pos[i] != -1) pos[i] = -2;
		if(ans[i] == '1'&&pos[i] == -1) pos[i] = k;
	}
}

void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
}

void solve()
{
	memset(pos,-1,sizeof(pos));
	for(int i = 0; i < n; i++)  bit(arr[i],i);
	int fi = -1;
	for(int i = 0; i < 100010; i++) 
	{
		if(pos[i]!=-1&&pos[i]!=-2)
		{
			fi = pos[i];
			//cout << pos[i] << endl;
		}
	}
	if(fi!=-1)
	{
		int t = arr[0];
		arr[0] = arr[fi];
		arr[fi] = t;
	}
	for(int i = 0; i < n; i++) cout << arr[i] << ' ';
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
