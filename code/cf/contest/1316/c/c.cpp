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

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

__int64 n,m,p;
__int64 arr1[1000010];
__int64 arr2[1000010];
__int64 ans[1000010];
void input()
{
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++)
	{
		arr1[i] = read();
		arr1[i]%=p;
	}
	for(int i = 0; i < m; i++)
	{
		arr2[i] = read();
		arr2[i]%=p;
	}
}

void solve()
{
	int con = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			ans[i+j]+=arr1[i]*arr2[j];
			ans[i+j]%=p;
		}
		if(ans[i]%p!=0)
		{
			cout << i << endl;
			return;
		}
		else
		{
			cout << 1 << endl;
			return;
		}
	}
}

int main()
{
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
