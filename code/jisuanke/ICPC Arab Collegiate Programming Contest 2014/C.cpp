#include<string>
#include<string.h>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define met(a) memset(a, 0, sizeof(a))
#define MP(x,y) make_pair(x, y)
typedef long long LL;
const int M = 30 + 5;
long long n, ans;
//map<string, int> mp;

int l;
int mp[6][1000000];

int gtn(string s)
{
	int tem = 0;
	for(char i : s)
	{
		tem = tem*10+(i-'0');
	}
	return tem;
}
int gtl(string s)
{
	return s.length();
}

void init()
{
    scanf("%lld",&n);
    ans = 0;
    met(mp);
}

void dfs(string s, int der, int  pos)
{
    if(pos >= s.size()){
        mp[gtl(s)][gtn(s)] = 1;
        return ;
    }

    string c;
    if( s[pos] + der <= '9' ){
        c = s;
        c[pos] += der;
        dfs(c, der, pos+1);
    }

    if( s[pos] - der >= '0' ){
        c = s;
        c[pos] -= der;
        dfs(c, der, pos+1);
    }
}

void solve(int k)
{
    char s[10];
    for(int i=0; i<n; ++i){
        met(s);
        //getchar();
        scanf("%s",s);
        //cout << s << endl;
        if(mp[gtl(s)][gtn(s)] == 1) continue;
        ++ans;
        mp[gtl(s)][gtn(s)] = 1;
        for(int j=1; j<=9; ++j){
            dfs(s, j, 0);
        }
    }
    printf("Case %d: %d\n",k,ans);
    //cout << "Case " << k << ": " << ans << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
//    cout << copys("22222", 3, 3) << endl;
    int k = 0, T = 1;
    scanf("%d",&T);
    while(T--){
        init();
        solve(k+1);
        ++k;
    }
    return 0;
}
/*
2
1 1 1
1 2 3
*/

