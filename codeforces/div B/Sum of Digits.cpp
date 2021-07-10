/**
 * 
 *  problem link: https://codeforces.com/contest/102/problem/B
 *  
 * */

#include <bits/stdc++.h>
using namespace std;
 
#define fast               cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)


string num;

int main() {
    cin >> num;
    
    if(num.length() == 1) {
        cout << 0;
        return 0;
    }

    long long sum;
    int i = 0;

    while(log10(sum) >= 1) {
        sum = 0;
        lp(i, num.length())
            sum += (num[i] - '0');
        num = to_string(sum);
        i++;
    }

    cout << i;

	return 0;
}