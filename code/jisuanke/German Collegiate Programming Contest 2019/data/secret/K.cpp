/*
*   Author: $%U%$
*   Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
 
ll xa,ya,da;
ll xb,yb,db;
void input()
{
    cin >> xa >> ya >> da >> xb >> yb >> db;
}
 
void solve()
{
    if(abs(xa-xb)+abs(ya-yb) > da+db)
    {
        cout << "impossible" << endl;
        return ;
    }
    int y = (ya-yb)==0?1:(ya-yb)/abs(ya-yb); // 1为下 -1为上 0为相等 
    int x = (xa-xb)==0?1:(xa-xb)/abs(xa-xb); // 1为左 -1为右 0为相等 
    //cout << y << ' ' << x << endl; 
    ll derx = abs(xa-xb);
    ll dery = abs(ya-yb);
    if((derx+dery)%2!=(da+db)%2)
    {
        cout << "impossible" << endl;
        return ;
    }
    
//    if(m1 >= ax){
//            x1 = x2;
//            m1 -= ax;
//            if(m1 >= ay){
//                y1 = y2;
//                m1 -= ay;
//                if(m1&1)++y1;
//            } else {
//                y1 += m1 * (ay / dy);
//            }
//        } else {
//            x1 += m1 * (ax / dx);
//        }
//        cout << x1 << " " << y1 << endl;
    
    if(da <= derx)
    {
        cout << xa-x*(da) << ' ' << ya << endl;
    }
    if(da > derx)
    {
    	da-=derx;
    	if(da>dery)
    	{
	        cout << xb << ' ' <<( (da&1)?ya-y*da+1:ya-y*da )<< endl;
		}
        else cout << xb << ' ' << ya-y*da << endl;
        //cout << y*(da-derx) << endl;
        //y*(da-derx)
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
