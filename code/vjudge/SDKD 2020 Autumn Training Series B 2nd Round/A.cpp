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

int n;
int mp[30];
stack<char> q;
char c;

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


void input()
{
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> c;
		if(c == 'F') mp[i] = 0;
		else mp[i] = 1;
	}
	while( !q.empty() ) q.pop();
}

void solve()
{
	while( cin >> c ){
		if(c == '*'){
			int c1 = q.top() == 'T' ? 1 : 0; q.pop();
			int c2 = q.top() == 'T' ? 1 : 0; q.pop();
			if(c1 & c2 == 1){
				q.push('T');
			}
			else q.push('F');
		}
		else if(c == '+'){
			int c1 = q.top() == 'T' ? 1 : 0; q.pop();
			int c2 = q.top() == 'T' ? 1 : 0; q.pop();
			if(c1 | c2 == 1){
				q.push('T');
			}
			else q.push('F');
		}
		else if(c == '-'){
			int c1 = q.top() == 'T' ? 1 : 0; q.pop();
			if(!c1){
				q.push('T');
			}
			else q.push('F');
		}
		else{
			if(mp[c-'A'] == 1) q.push('T');
			else q.push('F');
		}
	}
	cout << q.top() << endl;
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
