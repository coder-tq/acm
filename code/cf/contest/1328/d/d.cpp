/*
*	Author: coder_tq
*	Time: 2020-03-26 22:35:00
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
int arr[200010]; 
int dp[200010][2];//0ÎªÌî1£¬1ÎªÌî2 
int ans[200010];
set<int> num;
void input()
{
	num.clear();
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i],num.insert(arr[i]);
	arr[0] = arr[n];
}

void solve()
{
	int cur = 1;
	int sflag = 0; 
	for(int i = 1; i <= n; i++)
	{
		if(arr[i] == arr[i-1]) sflag = 1;
	}
	if(sflag == 0&&n%2 == 1)
	{
		cout << 3 << endl;
		for(int i = 1; i < n; i++)
		{
			if(i%2) cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << 3 << endl;
		return;
	}
	if(sflag == 0&&n%2 == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i%2) cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << endl;
		return;
	}
	if(num.size() == 1)
	{
		cout << 1 << endl;
		for(int i = 1; i <= n; i++) cout << 1 << ' ';
		cout << endl;
		return;
	}
	cout << 2 << endl;
	if(n%2 == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i%2) cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << endl;
	}
	
}

int main()
{
//	ios::sync_with_stdio(false); 
//	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
