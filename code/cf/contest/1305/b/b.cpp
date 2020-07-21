/*
*	Author: coder_tq
*	Time: 2020-03-03 22:35:02
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
string t; 
int vis[1010];
void input()
{
	cin >> t;
}

void solve()
{
	int pos1,pos2;
	pos1 = 0,pos2 = t.length()-1;
	set<int> road[1010];
	int con = 0;
	memset(vis,0,sizeof(vis));
	for(int z = 0; z < 1000; z++)
	{
		pos1 = 0,pos2 = t.length()-1;
		int flag = 1;
		while(pos1 < pos2)
		{
			while(pos1 < t.length()&&(t[pos1] != '('||vis[pos1] == 1)) pos1++;
			while(pos2 >= 0&&(t[pos2] != ')'||vis[pos2] == 1)) pos2--;
			//cout << pos1 << ' ' << pos2 << endl;
			if(pos1 > pos2) break;
			else 
			{
				flag = 0;
				road[con].insert(pos1+1);
				road[con].insert(pos2+1);
				vis[pos1] = 1;
				vis[pos2] = 1;
			}
		}
		if(!flag)
			con++;
	}
	cout << con << endl;
	for(int i = 0; i < con; i++)
	{
		cout << road[i].size() << endl;
		for(int j:road[i])
		{
			cout << j << ' ';
		}
		cout << endl;
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
