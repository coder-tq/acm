#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    t+="@"; 
    // Process t
    vector<int> p(t.size(), 0);
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

int main() {
	ios::sync_with_stdio(false);
	string s;
	int kase = 1;
    while(cin >> s)
    {
    	if(s=="END") return 0;
    	printf("Case %d: %d\n",kase++,Manacher(s));
	}
}
