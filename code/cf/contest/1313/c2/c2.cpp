/*
*	Author: coder_tq
*	Time: 2020-02-24 12:06:10
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
ll arr[500010];
stack<pair<ll,ll> > st1;
stack<pair<ll,ll> > st2;
ll pre[500010];
ll suf[500010];
ll ans[500010];
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
	for(int i = 0; i <= n; i++)
	{
	    //cout << i << ' ';
		if(i == 0)
		{
			pre[i] = 0;
		}
		else {
            if (st1.size() == 0 || arr[i-1] >= st1.top().first) {
                st1.push(make_pair(arr[i-1], i));
                pre[i] = pre[i - 1] + arr[i-1];
            } else {
                while (st1.size() != 0&&st1.top().first >= arr[i-1]) {
                    st1.pop();
                }
                if(st1.size() == 0) pre[i] = arr[i-1]*(i);
                else pre[i] = pre[st1.top().second] + arr[i-1] * (i - st1.top().second);
                st1.push(make_pair(arr[i-1], i));
            }
        }
	}

	for(int i = n; i >= 0; i--)
    {
	    //cout << st2.size() << endl;
	    //cout << i << endl;
	    if(i == n)
        {
	        suf[n-i] = 0;
	        //st2.push(make_pair(arr[i],i));
        }
	    else{
	        if(st2.size() == 0 || arr[i] >= st2.top().first){
	            st2.push(make_pair(arr[i] , i));
	            suf[n-i] = suf[n-i-1]+arr[i];
	        }
	        else{
	            while(st2.size() != 0 && st2.top().first >= arr[i])
                {
	                st2.pop();
                }
	            if(st2.size() == 0) suf[n-i] = arr[i]*(n-i);
	            else suf[n-i] = suf[n-st2.top().second] + arr[i] * (st2.top().second - i);
	            st2.push(make_pair(arr[i],i));
	        }
	    }
    }

//    for(int i = 0; i <= n; i++)
//    {
//        cout << pre[i] << ' ';
//    }
//    cout << endl;
//    for(int i = 0; i <= n; i++)
//    {
//        cout << suf[i] << ' ';
//    }
//    cout << endl;

	ll mxans = -1;
	int pos = -1;
	for(int i = 0; i <= n; i++)
    {
	    if(pre[i]+suf[n-i] >= mxans)
        {
	        mxans = pre[i]+suf[n-i];
	        pos = i-1;
        }
    }
    //cout << mxans << ' ' << pos << endl;
	ll mi = 1e18;
    for(int i = pos; i >= 0; i--)
    {
        mi = min(arr[i],mi);
        ans[i] = mi;
    }
    mi = 1e18;
    for(int i = pos; i < n; i++)
    {
        mi = min(arr[i],mi);
        ans[i] = mi;
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
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
//347407913 807251700 961118891 36855898 222367400 403475770 349054129 611443727 103165319 936253189 710799600 33000434 188942798 58789127 197436908 189735874 671210523 347607462 422267645 19494446 783463968 641946110 67544654 979177180 191183394 945039837 27233502 778751715 307833852 168471622 784925698 636897488 856883610 837913327 433225057 13746853 708854015 889202114 218729847 746537173 708589375 720333280 578589330 125753162 893520005 683999129 411680600 944963424 159609102 128875637 371570112