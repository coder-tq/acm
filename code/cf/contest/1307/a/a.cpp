/*
*	Author: coder_tq
*	Time: 2020-02-17 23:35:02
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
int n,d;
int arr[150]; 
void input()
{
	memset(arr,0,sizeof(arr));
	cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	while(d--)
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i+1]!=0) 
			{
				arr[i]++,arr[i+1]--;
				break;
			}
		}
	}
	cout << arr[0] << endl;
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
