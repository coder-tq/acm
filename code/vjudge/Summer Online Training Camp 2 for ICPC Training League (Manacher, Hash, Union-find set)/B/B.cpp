#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int p[1010000]; 

int Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    t+="@"; 
    // Process t
    //vector<int> p(t.size(), 0);
    int mxlen = 0;
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        mxlen = max(p[i],mxlen);
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
//    return s.substr((resCenter - resLen) / 2, resLen - 1); //最长子回文串
	return mxlen-1;
}

long long sum[1010000];
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(sum,0,sizeof(sum));
		int val[30];
		for(int i = 1; i <= 26; i++) cin >> val[i];
		string s;
		cin >> s;
		Manacher(s);
		for(int i = 1; i <= s.length(); i++)
		{
			sum[i] = sum[i-1]+val[s[i-1]-'a'+1];
			//cout << i << ' ' << sum[i] << endl;
		}
		//for(int i = 0; i < s.length()*2+2; i++) cout << i << ' ' << p[i] << endl;
		long long ans = 0;
		for(int i = 1; i <= s.length()/2; i++)
		{
			//cout << i << endl;
			long long cur = 0;
			//cout << p[(s.length()+i*2)] << endl;
			if(p[i*2]-1 == i*2-1) cur+=sum[i*2-1];
			if(p[(s.length()+i*2)]-1 == s.length()-i*2+1) cur+=sum[s.length()]-sum[i*2-1];
			ans = max(ans,cur);
		}
		cout << ans << endl;
	}
}
//123456
//acacac
//012345678901234
//$#a#c#a#c#a#c#@
//012141616141210
