#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace FAST_IO
{
	static int sc_ret = 0;
	struct pt_nl {};
	struct sc
	{
	    sc& operator>>(char& v) { sc_ret = scanf(" %c", &v); return *this; }
	    sc& operator>>(int& v) { /*sc_ret = read(v);*/ sc_ret = scanf("%d", &v); return *this; }
	    sc& operator>>(unsigned& v) { sc_ret = scanf("%u", &v); return *this; }
	    sc& operator>>(double& v) { sc_ret = scanf("%lf", &v); return *this; }
	    sc& operator>>(char* v) { sc_ret = scanf("%s", v); return *this; }
	    sc& operator>>(string& v) { sc_ret = (bool)(cin >> v); return *this; }
	    sc& operator>>(ll& v) { sc_ret = read(v); return *this; }
	    sc& ch(char& v) { v = sc_ret = getchar(); return *this; }
	    sc& gets(char* v) { sc_ret = fgets(v, INT_MAX, stdin) != 0; v[strlen(v) - 1] = 0; return *this; }
	    operator bool() const { return sc_ret > 0; }
	    template <typename T>
	    int read(T& v)
	    {
	        T x = 0, k = 1;
	        int c = getchar();
	        while (c < '0' || c > '9')
	        {
	            if (c == '-') k = -1;
	            c = getchar();
	        }
	        while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - 48), c = getchar();
	        v = x * k;
	        return c;
	    }
	}SC;
	struct pr
	{
	    pr& ln() { putchar('\n'); return *this; }
	    pr& operator<<(const pt_nl& nl) { putchar('\n'); return *this; }
	    pr& operator<<(char v) { putchar(v); return *this; }
	    pr& operator<<(int v) { write(v); return *this; }
	    pr& operator<<(double v) { printf("%.2f", v); return *this; }
	    pr& operator()(const char* fmt, double v) { printf(fmt, v); return *this; }
	    pr& operator<<(const char* v) { printf("%s", v); return *this; }
	    pr& operator<<(string v) { printf("%s", v.c_str()); return *this; }
	    pr& operator<<(ll v) { write(v); return *this; }
	    template <typename T>
	    void write(T v)
	    {
	        int cnt = 0; char c[23];
	        if (v == 0)
	        {
	            putchar('0');
	            return;
	        }
	        if (v < 0) putchar('-'), v = -v;
	        while (v) c[++cnt] = (v % 10) + 48, v /= 10;
	        while (cnt > 0) putchar(c[cnt--]);
	    }
	    template <typename T>
	    void ln(T* arr, int size)
	    {
	        if (size > 0)
	        {
	            (*this) << arr[0];
	            for (int i = 1; i < size; ++i)
	            {
	                putchar(' ');
	                (*this) << arr[i];
	            }
	            putchar('\n');
	        }
	    }
	    template <typename T>
	    void muln(T* arr, int size)
	    {
	        for (int i = 0; i < size; ++i)
	        {
	            (*this) << arr[i];
	            putchar('\n');
	        }
	    }
	}PR;
	#define cin SC
	#define cout PR
	#define endl pt_nl()
}
using namespace FAST_IO;

int number[]={0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int n,k;
string dp[2][2005];
char _tmp[10];

bool check(int x,int y)
{
	for(int i=0;i<7;i++)
	{
		if((x>>i)&1)
		{
			if(!((y>>i)&1))
				return false;
		}
	}
	return true;
}

int to_num(char *c)
{
	int ans=0;
	for(int i=0;i<7;i++)
	{
		ans*=2;
		ans+=c[i]-'0';
	}
	return ans;
}

int main()
{
	cin>>n>>k;
	int circle=1; 
	for(int i=1;i<=n;i++)
	{
		for(int i=0;i<=k;i++)
			dp[circle][k]="";
		cin>>_tmp;
		int tmp=to_num(_tmp);
		for(int j=0;j<=9;j++)
		{
			if(check(tmp,number[j]))
			{
				int num=__builtin_popcount(number[j])-__builtin_popcount(tmp);
				if(i==1)
				{
					dp[circle][num]=max(dp[circle][num],string("")+(char)(j+'0'));
				}
				else
				{
					for(int kk=num;kk<=k;kk++)
					{
						if(dp[circle^1][kk-num].length()==i-1)
							dp[circle][kk]=max(dp[circle][kk],dp[circle^1][kk-num]+(char)(j+'0'));
					}	
				}
				
			}
		}
		circle^=1;
	}
	if(dp[circle^1][k].length()==n)
		cout<<dp[circle^1][k]<<endl;
	else
		cout<<-1<<endl;
    return 0;
}

/*
2 4
0010010
0010010
*/ 

