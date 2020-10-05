/*
*	Author: $%U%$
*	Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/ 
#include <bits/stdc++.h>
#define inf 0x7fffffff-1
#define llinf 9223372036854775807LL
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define MEM(a) memset(a,0,sizeof(a))

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

char str[100010];
map<int, int> mp;
pair<int, int> a[100010];

void input()
{
	scanf("%s", str+1);
}

void solve()
{
	int sum = 0;
	int f[30] = {0};
	memset(f, -1, sizeof(f));
	int len = strlen(str+1);
	for(int i=1; i <= len; i ++ ) { 
		if(f[str[i] - 'a'] != -1) { 
			mp[f[str[i] - 'a']] = ++sum;
			a[sum].F = f[str[i] - 'a'];
			a[sum].S = i;
		}  
		f[str[i] - 'a'] = i;
	} 
	
	int counts = 0;
	for(int i=1; i <=len; i ++ ) {
		if(mp.count(i)) {
			int num = 0;
			num += a[ mp[i] ].S - i - 1; 
			int j = mp[i]+1; 
			while( a[j].F < a[mp[i]].S  )  {
				if(a[j].F > i && a[j].S < a[ mp[i] ].S)	num -- ;
				j ++ ;
			}
			counts += num;
		} else {
			int num = 0;
			num += len - i; 
			int j = i+1; 
			while(!mp.count(j) && j <= len) j ++ ;
			if(j < len) {
				j = mp[j];
				while( a[j].F < a[mp[i]].S  )  {
					if(a[j].F > i && a[j].S < a[ mp[i] ].S)	num -- ;
					j ++ ;
				}
				counts += num;
			}
		}
	}
	cout << counts << endl;
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
