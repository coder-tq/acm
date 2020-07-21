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
string t; 
void input()
{
	cin >> n >> t;
}

void solve()
{
	int ans = n;
	for(int pos = 25;pos > 0;pos--)
	{
		//cout << t << endl;
		//cout << (char)(pos+'a'-1) << endl;
		for(int con = 0; con < 200; con++)
		{
			for(int i = 0; i < n; i++)
			{
				if(t[i]-'a' == pos)
				{
	//				cout << i << endl;
	//				for(int k = 0; k < n; k++) cout << t[k];
	//				cout << endl;
					if(i == 0)
					{
						if(i+1<n&&t[i+1]-'a' == pos-1) 
						{
							for(int j = i; j < n; j++)
							{
								t[j] = t[j+1];
							}
							t[n-1] = 0;
							n--;
							i--;
						}
						continue;
					}
					if(i == n-1)
					{
						if(i-1>=0&&t[i-1]-'a' == pos-1) t[n-1] = 0,n--,i--;
						continue;
					}
					if(t[i-1]-'a' == pos-1||t[i+1]-'a' == pos-1)
					{
						for(int j = i; j < n; j++)
						{
							t[j] = t[j+1];
						}
						t[n-1] = 0;
						n--;
						i--;
					}
				}
			}
		}
		//cout << t << endl;
	}
	cout << ans-n << endl;
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
//0 1 2 3
//1 2 1 2
