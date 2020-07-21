/*
*	Author: coder_tq
*	Time: 2020-03-14 22:34:59
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
int arr[100010]; 
set<int> st;
void input()
{
	st.clear();
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
}

void solve()
{
	for(int i = 0; i < n; i++) st.insert(arr[i]);
	cout << st.size() << endl;
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
