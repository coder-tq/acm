#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e5+5;
int nr,ng,nb;
ll r[N],g[N],b[N];
ll mi=0x3f3f3f3f3f3f3f3f;

void check(ll x,ll y,ll z)
{
	ll ans=(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
	if(ans<mi)
	{
		mi=ans;
//		cout<<x<<" "<<y<<" "<<z<<endl;
	}
		
}

void sl(int nr,int ng,int nb,ll *r,ll *g,ll *b)
{
	for(int i=1;i<=nr;i++)
	{
		int id_g=lower_bound(g+1,g+ng+1,r[i])-g;
		if(id_g<=ng)
		{
			int id_b=lower_bound(b+1,b+nb+1,g[id_g])-b;
			if(id_b<=nb)
				check(r[i],g[id_g],b[id_b]);
			if(id_b>1)
				check(r[i],g[id_g],b[id_b-1]);
		}
		if(id_g>1)
		{
			id_g--;
			int id_b=lower_bound(b+1,b+nb+1,g[id_g])-b;
			if(id_b<=nb)
				check(r[i],g[id_g],b[id_b]);
			if(id_b>1)
				check(r[i],g[id_g],b[id_b-1]);
		}
	}	
}

void solve()
{
	mi=0x3f3f3f3f3f3f3f3f;
	scanf("%d%d%d",&nr,&ng,&nb);
	for(int i=1;i<=nr;i++)
		scanf("%lld",r+i);
	for(int i=1;i<=ng;i++)
		scanf("%lld",g+i);
	for(int i=1;i<=nb;i++)
		scanf("%lld",b+i);
	sort(r+1,r+nr+1);
	sort(g+1,g+ng+1);
	sort(b+1,b+nb+1);
	sl(nr,ng,nb,r,g,b);
	sl(nr,nb,ng,r,b,g);
	sl(ng,nr,nb,g,r,b);
	sl(ng,nb,nr,g,b,r);
	sl(nb,nr,ng,b,r,g);
	sl(nb,ng,nr,b,g,r);
	printf("%lld\n",mi);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
 	return 0;
}

