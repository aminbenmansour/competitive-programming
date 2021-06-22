/**
 * 
 * Problem link: https://codeforces.com/problemset/problem/580/A
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

int protect, n;
vector<long long> stewards;

int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========

    cin >> n;

    int i = n;
    while(i--) {
        long long val; cin >> val; stewards.emplace_back(val);
    }

    if(n <= 2) {
        protect = 0;
    } else {
        long long mn, mx, tmp = 0;
        sort(stewards.begin(), stewards.end());
        mn = stewards[0]; mx = stewards[n-1];
        i = 0;
        while(stewards[i++] == mn && i != n+1) {
            tmp++;
        }
        if( i != (n+1)) {
        i = n-1;
        while(stewards[i--] == mx) {
            tmp++;
        }

        protect = n - tmp;
        }
        
    }

    cout << protect;
    
    return 0;
}
