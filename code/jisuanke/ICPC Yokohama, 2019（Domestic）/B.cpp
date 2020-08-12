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
	
	int n,m;
	char key[100][100];
	string str;
	int input()
	{
		MEM(key);
		scanf("%d%d",&n,&m);
		REP(i,1,n)
		{
			getchar();
			REP(j,1,m)
			{
				scanf("%c",&key[i][j]);
			}
		}
		cin >> str;
		return n;
	}
	
	void solve()
	{
		int curx = 1;
		int cury = 1;
		int sum = 0;
		REP(i,0,str.length()-1)
		{
			int flag = 0;
			REP(j,1,n)
			{
				REP(k,1,m)
				{
					if(key[j][k] == str[i])
					{
						//cout << i << ' ' << j << ' ' << curx << ' ' << cury << endl;
						sum+=abs(j-curx)+abs(k-cury)+1;
						curx = j;
						cury = k;
						flag = 1;
						
					}
					if(flag) break;
				}
				if(flag) break;
			}
		}
		printf("%d\n",sum);
	}
	
	int main()
	{
		int t = 1;
		//scanf("%d",&t);
		while(input())
		{
			;
			solve();
		}
		return 0;
	}
