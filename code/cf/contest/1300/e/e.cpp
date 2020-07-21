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
int arr[1000010];
int s[1000010];
int e[1000010];
double t[1000010];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i],t[i] = arr[i];
}

void solve()
{
	for(int i = 0; i < n; i++) s[i] = i,e[i] = i;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] < t[i-1])
		{
			t[i] = i-1-s[i-1]
		}
	}
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
