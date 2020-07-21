/*
*	Author: coder_tq
*	Time: 2020-04-03 22:35:01
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
int vis1[200010];
int vis2[200010]; 
void input()
{
	cin >> n;
	for(int i = 0; i < n+10; i++) vis1[i] = 0;
	for(int i = 0; i < n+10; i++) vis2[i] = 0;
	for(int i = 0; i < n; i++) cin >> arr[i];		
}

void solve()
{
	int mx = -1;
	set<int> ans;
	for(int i = 0; i < n; i++) 
	{
		if(vis1[arr[i]] == 0)
		{
			mx = max(mx,arr[i]);
			if(mx == i+1) ans.insert(i+1);
			vis1[arr[i]] = 1;
			continue;
		}
		else
		{
			break;
		}
	}
	set<int> ans2;
	mx = -1;
	for(int i = n-1; i >= 0; i--) 
	{
		if(vis2[arr[i]] == 0)
		{
			mx = max(mx,arr[i]);
			if(mx == n-i) ans2.insert(i+1);
			vis2[arr[i]] = 1;
			continue;
		}
		else
		{
			break;
		}
	}
	int con = 0;
		//cout << ans.size() << endl;
		for(int i:ans)
		{
			if(ans2.count(i+1))
			{
				con++;
				//cout << i << ' ' << n-i << endl;
			}
		}
	cout << con << endl;
	
		for(int i:ans)
		{
			if(ans2.count(i+1))
			{
				//con++;
				cout << i << ' ' << n-i << endl;
			}
		}
	//cout << mxf << ' ' << mxe << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
