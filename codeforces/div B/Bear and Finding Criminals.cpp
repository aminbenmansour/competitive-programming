/**
 * 
 * problem link: https://codeforces.com/contest/680/problem/B
 * 
 * */
 
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> bcd;
int n, pos;
 
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> pos;
    --pos;
 
    int i = n;
    while(i--) {
        int val;
        cin >> val;
        bcd.emplace_back(val);
    }
 
    int size = n-1;
    int m = min(pos, size-pos);
 
    int beginterval = pos - m;
    int endinterval = pos + m;
 
    int count = 0;
    int adv = 0;
    for (int i = 0; i < n; i++) {
        if(i >= beginterval && i <= endinterval) {
            if(pos == i) {
                count += bcd[i];
                i += m; 
            } else if( bcd[i] && bcd[pos + m  - adv] ) {
                count += 2;
            }
            adv++;
        } else {
            count += bcd[i];
        }
    }
 
    cout << count;
     
 
    return 0 ;
}