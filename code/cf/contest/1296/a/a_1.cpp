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
int arr[2010];

void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	int oflag = 0;
	int eflag = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i]%2) oflag = 1;
		else eflag = 1;
	}
	//cout << oflag << ' ' << eflag << endl;
	int flag = 1;
	if(oflag == 0) flag = 0;
	if(n%2 == 0&&eflag == 0) flag = 0;
	if(flag) cout << "YES" << endl;
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