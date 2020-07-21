/*
*	Author: fairy_girl
*	Time: 2020-04-08 22:35:00
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
//aj = 2ai+aj
int n;
int arr1[100010];
int arr2[100010];
int dif[100010];
int tag[100010][2];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr1[i];
	for(int i = 0; i < n; i++) cin >> arr2[i];
}

void solve()
{
	int flag = 1;
	int temflagz = 0;
	int temflagf = 0;
	for(int i = 0; i < n; i++)
	{
		tag[i][0] = temflagz;
		tag[i][1] = temflagf;
		dif[i] = arr2[i]-arr1[i];
		if(arr1[i]>0) temflagz = 1;
		if(arr1[i]<0) temflagf = 1;
	}
	for(int i = n-1; i >= 0; i--)
	{
		if(dif[i] == 0) continue;
		if(dif[i] > 0&&tag[i][0] == 1) continue;
		if(dif[i] < 0&&tag[i][1] == 1) continue;
		flag = 0;
	}
	if(flag)
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
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
