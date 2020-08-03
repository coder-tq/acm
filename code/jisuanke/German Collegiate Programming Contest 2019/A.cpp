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
int n;
string s1[55]; 
string s2[55];
void input()
{
	scanf("%d",&n);
	REP(i,1,n)
	{
		cin >> s1[i];
		
		transform(s1[i].begin(), s1[i].end(), s1[i].begin(), ::toupper);
		//printf("%s\n",s1[i]);
		//cout << s1[i] << endl;
	}
	REP(i,1,n)
	{
		cin >> s2[i];
		transform(s2[i].begin(), s2[i].end(), s2[i].begin(), ::toupper);
	}
}

bool isok(int lon, const string & s)
{
    string c = "";
    int i, len;
    for(i=0, len=s.size(); i<len; ++i){
        c += s[i];
    }
    for(int j=1 ; j*lon < len; ++j){
        for(int k=0; j*lon+k<len && k<lon; ++k ){
            if(s[j*lon+k] != c[k]){
                return false;
            }
        }
    }
    return true;
}

int getScore(string s)
{
    int len1 = s.size();
	for(int lon=1, len=len1/2; lon <= len; ++lon){
        if(len1 % lon == 0 && isok(lon, s)){
            return lon;
        }
	}
	return s.size();
}



int a1[55];
int a2[55];
void solve()
{
	REP(i,1,n)
	{
		a1[i] = getScore(s1[i]);
	}
	REP(i,1,n)
	{
		a2[i] = getScore(s2[i]);
	}
	sort(a1+1,a1+n+1);
	sort(a2+1,a2+n+1);
	ll ans = 0;
	REP(i,1,n)
	{
		ans+=(a1[i]-a2[i])*(a1[i]-a2[i]);
	}
	cout << ans << endl;
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
