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

int n,x;
int d[200010];
void input()
{
	scanf("%d%d",&n,&x);
	REP(i,0,n-1) scanf("%d",&d[i]);
}

ll dp[200010];
void solve()
{
	int mx = 0;
	REP(i,0,n-1) mx = max(mx,d[i]);
	if(x <= mx) {
		cout << (mx+(mx-x+1))*x/2 << endl;
		return;
	}
	else{
		ll ans = 0;
		ll cur = 0;
		int tem = 0;
		ll day = 0; 
		while(cur < x){
			//cout << cur << endl;//
			cur += d[tem%n];
			day += (1+d[tem%n])*d[tem%n]/2;
			if(cur >= x) {
				cur -= d[tem%n];
				day -= (1+d[tem%n])*d[tem%n]/2;
				break;
			}
			tem++;
		}
		REP(i,0,n-1){
			//cout << i << ' ';//
			int la = x-cur;
			//cout << "la: " << la << ' ' << "cur: " << cur << ' ' << "x: " << x << ' ';//
			day += (d[(i-1+n)%n] + d[(i-1+n)%n]-la+1) * la/2;
			//cout << day << ' ';//
			ans = max(ans,day); 
			day -= (d[(i-1+n)%n] + d[(i-1+n)%n]-la+1) * la/2;
			
			
			day += (1+la) * la/2;
			//cout << day << ' ';//
			ans = max(ans,day); 
			day -= (1+la) * la/2;
			
			
			day -= (1+d[i%n])*d[i%n]/2;
			cur -= d[i%n];
			
			while(cur < x){
				cur += d[tem%n];
				day += (1+d[tem%n])*d[tem%n]/2;
				if(cur >= x) {
					cur-=d[tem%n];
					day -= (1+d[tem%n])*d[tem%n]/2;
					break;
				}
				tem++;
			}
			//cout << endl;//
		}
		cout << ans << endl;
	}
}
// 10 8
// 1 1 1 5 1 1 1 4 4 4


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
