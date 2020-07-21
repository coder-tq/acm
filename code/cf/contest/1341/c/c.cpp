/*
*	Author: fairy_girl
*	Time: 2020-04-23 22:45:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff-1
#define llinf 9223372036854775807LL

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
int arr[100010];
int mp[100010];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) mp[i] = 0;
	for(int i = 0; i < n; i++) cin >> arr[i],mp[arr[i]] = i;
}

void solve()
{
	int flag = 1;
	int num = 1;
	int mxpos = n;
	while(num!=n)
	{
		int pos = mp[num];
		//cout << pos << ' ' << mxpos << endl;
		for(int i = pos; i < mxpos; i++)
		{
			//cout << num << endl;
			if(num!=arr[i]) flag = 0;
			num++;
			if(num == n) break;
		}
		if(pos > mxpos)
		{
			flag = 0;
			break;
		}
		mxpos = pos;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main()
{
//	ios::sync_with_stdio(false); 
//	cin.tie(0);
	//freopen("out.txt","r",stdin);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
