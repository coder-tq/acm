#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int N=2e5; 
ll a[N+5];
ll sum[N+5];
ll n;
set<ll> st;
map<ll,int> mp;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll ans=0;
	int now=0; 
	for(int i=1;i<=n;i++)
	{
		if(!st.count(sum[i]))
		{
			ans+=i-now;
			if(!(sum[i]-sum[now]))
			{
				now=max(now,1);
				ans--;
			}
		}
		else
		{
			if(i-max(mp[sum[i]]+1,now)>0)
			{
				ans+=i-max(mp[sum[i]]+1,now);
			}
			
			now=max(now,mp[sum[i]]);
		}
		if(!a[i])
			now=i;
		mp[sum[i]]=i;
		st.insert(sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 
 
 /*
 5
 1 1 0 1 1
 
 
3
1 0 -1


6
1 1 0 0 -1 -1
 */

