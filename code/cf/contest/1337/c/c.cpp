#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int n,k;
vector<int> v[N];
struct mode
{
	int index;
	int dep;
	int n_num;
	bool f;
}mo[N];
int id[N];
ll ans;
 
void dfs(int x,int pre)
{
	mo[x].dep=mo[pre].dep+1;
	mo[x].index=x;
	for(auto y:v[x])
	{
		if(y==pre)
			continue;
		dfs(y,x);
		mo[x].n_num+=mo[y].n_num;
	}
	mo[x].n_num++;
}

bool cmp(const mode &m1,const mode &m2)
{
	if(m1.n_num==m2.n_num)
		return m1.dep>m2.dep;
	else
		return m1.n_num<m2.n_num;
}
 
void dfs(int x,int pre,int num)
{
	if(mo[id[x]].f)
		ans+=num;
	else
		num++;
	for(auto y:v[x])
	{
		if(y==pre)
			continue;
		dfs(y,x,num);
	}
}
 
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		v[uu].push_back(vv);
		v[vv].push_back(uu);
	}
	dfs(1,0);
	sort(mo+1,mo+n+1,cmp);
 	for(int i=1;i<=n;i++)
 		id[mo[i].index]=i;
	for(int i=1;i<=k;i++)
 		mo[i].f=true;
	dfs(1,0,0);
	printf("%lld\n",ans); 
	return 0;
}

/*

11 6 
1 2
1 3
1 7
2 8
3 4
7 10
8 9
4 5
10 11
5 6 

*/

