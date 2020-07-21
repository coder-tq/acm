/*
*	Author: coder_tq
*	Time: 2020-04-03 22:35:01
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
struct node{
	int value;
	int pos;
};

bool cmp(const node &o1,const node &o2)
{
	return o1.value > o2.value;
}

int n,m; 
node arr[100010];
int ans[100010];
void input()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> arr[i].value,arr[i].pos = i;
}

void solve()
{
	int pos = n;
	int flag = 1;
	int mi = 1e9;
	for(int i = 0; i < m; i++)
	{
		ans[arr[i].pos] = pos-arr[i].value+1;
		mi = min(mi,ans[arr[i].pos]);
		pos--;
		if(mi < 1) flag = 0;
	}
	//for(int i = 0; i < m; i++) cout << ans[i] << ' '; cout << endl;
	pos = 1;
	for(int i = m-1; i >= 0; i--)
	{
		if(i == 0&&pos < ans[arr[i].pos]) flag = 0; 
		if(pos >= ans[arr[i].pos]) break;
		ans[arr[i].pos] = pos;
		pos += arr[i].value;
	}
	if(flag == 0) 
	{
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < m; i++) cout << ans[i] << ' ';
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
