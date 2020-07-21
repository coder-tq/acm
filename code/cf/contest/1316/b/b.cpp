/*
*	Author: coder_tq
*	Time: 2020-03-04 22:35:01
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

string reverse(string a,int s,int e)
{
	string ans = "";
	for(int i = 0; i < s; i++) ans+=a[i];
	for(int i = e; i >= s; i--) ans+=a[i];
	for(int i = e+1; i < a.length(); i++) ans+=a[i];
	return ans;
}

string tem;
string ans;
int con; 
int n;
void input()
{
	con = 0;
	tem.clear();
	cin >> n;
	cin >> tem;
}

void solve()
{
	ans = "";
	string te = "";
	int con = 0;
	for(int k = 1; k <= n; k++)
	{
		te = tem;
		if((n-k)%2 == 1)
		{
			string ans1 = "";
			for(int j = k-1; j < n; j++) ans1+=te[j];
			for(int j = 0; j < k-1; j++) ans1+=te[j];
			te = ans1;
		}
		else
		{
			string ans1 = "";
			for(int j = k-1; j < n; j++) ans1+=te[j];
			for(int j = k-2; j >=0; j--) ans1+=te[j];
			te = ans1;
		}
		//cout << k << endl << te << endl;
		if(ans == "")
		{
			ans = te;
			con = k;
		}
		else if(ans > te)
		{
			ans = te;
			con = k;
		}
	}
	cout << ans << endl;
	cout << con << endl;
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
