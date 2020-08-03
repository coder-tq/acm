#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t;
char s[200010];
int main() {
    int i, j, k;
    int z;
    cin >> t;
    while(t--) {
        scanf("%s", s);
        int len = strlen(s);
        int ans = 2e7;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                if(j == i) continue;
                int cnt = 0;
                int flag = 0;
                for(int k = 0; s[k]; k++) {
                    if(s[k] == '0'+i) {
                        flag = 1;
                    }
                    if(flag && s[k] == '0'+j) {
                        flag = 0;
                        cnt++;
                    }
                }
                ans = min(ans, len-2*cnt);
            }
            int cnt = 0;
            for(int k = 0; s[k]; k++) {
                if(s[k] == '0'+i) cnt++;
            }
            ans = min(ans, len-cnt);
        }
        printf("%d\n", ans);

    }
    return 0;
}
