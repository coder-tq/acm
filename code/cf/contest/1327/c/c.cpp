/*
*	Author: coder_tq
*	Time: 2020-03-23 22:35:01
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
int n,m,k;
pair<int,int> spos[210];
pair<int,int> epos[210];
pair<int,int> road[210];
void input()
{
	cin >> n >> m >> k;
	int t1,t2;
	for(int i = 0; i < k; i++)
	{
		cin >> t1 >> t2;
		spos[i] = make_pair(t1,t2);
	}
	for(int i = 0; i < k; i++)
	{
		cin >> t1 >> t2;
		epos[i] = make_pair(t1,t2);
	}
}
void solve()
{
	cout << n-1+m-1+n*m-1 << endl;
	for(int i = 0; i < n-1; i++) cout << "U";
	for(int i = 0; i < m-1; i++) cout << "L";
	int posx = 1;
	int posy = 1;
	while(posx != n+1)
	{
		for(int i = 0; i < m-1; i++)
		{
			if(posx%2 == 1) cout << "R";
			else cout << "L";
		}
		if(posx!=n)
		cout << "D";
		posx++;
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
