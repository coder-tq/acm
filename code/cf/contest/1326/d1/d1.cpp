/*
*	Author: coder_tq
*	Time: 2020-03-19 22:35:03
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
string tem; 
void input()
{
	tem.clear();
	cin >> tem;
}

void solve()
{
	int len = tem.length();
	if(len == 1)
	{
		cout << tem << endl;
		return;
	}
	int pos = len-1;
	int con = 0;
	for(int i = 0; i < len; i++)
	{
		if(tem[pos--]==tem[i])
			con++;
		else break;
	}
	int mx1 = 0;
	for(int i = 0; i < len-con*2; i++)
	{
		pos = con;
		int k = con+i;
		int flag = 0;
		while(tem[pos] == tem[k])
		{
			pos++;
			k--;
			if(k <= pos) flag = 1;
		}
		if(flag == 1) mx1 = i;
	}
	int mx2 = 0;
	for(int i = 0; i < len-con*2; i++)
	{
		pos = len-con-1;
		int k = pos-i;
		int flag = 0;
		while(tem[pos] == tem[k])
		{
			pos--;
			k++;
			if(k >= pos) flag = 1;
		}
		if(flag == 1) mx2 = i;
	}
	if(con == len)
	{
		cout << tem << endl;
		return;
	}
	for(int i = 0; i < con; i++) cout << tem[i];
	if(mx1 > mx2)
	{
		for(int i = con, num = 0; num <= mx1; num++,i++) cout << tem[i];
	}
	else for(int i = len-con-mx2-1, num = 0; num <= mx2; num++,i++) cout << tem[i];
	for(int i = len-con; i < len; i++) cout << tem[i];
	cout << endl;
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
