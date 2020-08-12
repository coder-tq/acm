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

map<string,int> countrymp;
int mp[200][200];
int n,m; 

int cur = 1;
int getid(string country)
{
	if(countrymp[country] != 0) return countrymp[country];
	return countrymp[country] = cur++;
}

void input()
{
	cin >> n >> m;
}

int edge[500][500];
void solve()
{
	string str;
	REP(i,1,n)
	{
		int x,y;
		cin >> str;
		x = getid(str);
		//cout << x << endl;
		cin >> str >> str >> str;
		cin >> str;
		y = getid(str);
		//cout << y << endl;
		edge[x][y] = 1;
	}
	REP(i,1,cur-1)
	{
		REP(j,1,cur-1)
		{
			REP(k,1,cur-1)
			{
				edge[i][k] = max(edge[i][k],edge[i][j]&edge[j][k]);
			}
		}
	}
	REP(i,1,m)
	{
		int x,y;
		cin >> str;
		x = getid(str);
		cin >> str >> str >> str;
		cin >> str;
		y = getid(str);
		if(edge[x][y] == 1)	cout << "Fact" << endl;
		else if(edge[y][x] == 1) cout << "Alternative Fact" << endl;
		else cout << "Pants on Fire" << endl;
	}
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
