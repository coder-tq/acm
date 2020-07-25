#include<string>
#include<string.h>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define met(a) memset(a, 0, sizeof(a))
typedef long long LL;
const int M = 5e6 + 5;
int n, x, y;

int main()
{
    ios::sync_with_stdio(false);
    int k = 0, T = 1;
//    cin >> T;
    while(T--){
        double r; cin >> r;
        double sinf = sin(75.0/180*3.1415926);
        cout << fixed << setprecision(5) << (4*r*sinf+2*r) * (4*r*sinf+2*r) << endl;
    }
    return 0;
}
/*

*/

