/*
*	Author: coder_tq
*	Time: 2020-02-23 17:05:00
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
int arr[3];
void input()
{
	cin >> arr[0] >> arr[1] >> arr[2];
}

void solve()
{
	sort(arr,arr+3);
	int sum = 0;
	if(arr[0] > 0)
	{
		arr[0]--;
		sum++;
	}
	if(arr[1] > 0)
	{
		arr[1]--;
		sum++;
	}
	if(arr[2] > 0)
	{
		arr[2]--;
		sum++;
	}
	if(arr[2] > 0&&arr[0] > 0)
	{
		arr[2]--;
		arr[0]--;
		sum++;
	}
	if(arr[2] > 0&&arr[1] > 0)
	{
		arr[2]--;
		arr[1]--;
		sum++;
	}
	if(arr[1] > 0&&arr[0] > 0)
	{
		arr[1]--;
		arr[0]--;
		sum++;
	}
	if(arr[2] > 0&&arr[1] > 0&&arr[0] > 0)
	{
		arr[2]--;
		arr[1]--;
		arr[0]--;
		sum++;
	}
	cout << sum << endl;
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
