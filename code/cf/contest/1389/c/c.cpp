/*
*	Author: coder_tq1
*	Time: 2020-07-29 22:35:02
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

string s; 
int num[10];
int numla[10];
void input()
{
	cin >> s;
	MEM(num);
	REP(i,0,9) numla[i] = -999;
}

void solve()
{
	//printf("%s\n",&s);
	//cout << s.length() << endl;
	REP(i,0,s.length()-1)
	{
		//cout << i << endl;
		if(i-numla[s[i]-'0'] > 1) num[s[i]-'0']++,numla[s[i]-'0'] = i;
	}
	REP(i,0,9) cout << i << ' ' << num[i] << endl;
	sort(num,num+10);
	int ans = s.length()-min(num[9],num[8])*2;
	MEM(num);
	REP(i,0,s.length()-1)
	{
		//cout << i << endl;
		num[s[i]-'0']++;
	}
	sort(num,num+10);
	ans = min(ans,(int)(s.length()-num[9]) );
	printf("%d\n",ans);
}

int main()
{
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
