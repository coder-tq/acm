/*
*	Author: coder_tq
*	Time: 2020-03-01 21:15:00
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
int arr1[110],arr2[110];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
}

void solve()
{
	int sum1 = 0;
	int sum2 = 0;
	int flag = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr1[i] == arr2[i]) continue;
		if(arr1[i] == 1&&arr2[i] == 0) flag = 1;
		if(arr1[i] == 1) sum1++;
		if(arr2[i] == 1) sum2++;
	}
	if(flag)
	{
		if(sum1 > sum2) cout << 1 << endl;
		else if(1.0*(sum2+1)/sum1 == (int)((sum2+1)/sum1)) cout << (sum2+1)/sum1 << endl;
		else cout << (sum2+1)/sum1+1 << endl;
	}
	else{
		if(sum1 > sum2) cout << 1 << endl;
		else cout << -1 << endl;
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
