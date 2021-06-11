/**
 * 
 * problem link: https://codeforces.com/contest/567/problem/A
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;
vector<long long> ox;
long n;

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i < n; i++) {
        long long val;
        cin >> val;
        ox.push_back(val);
    }

    vector<long long>::iterator f = ox.begin();
    vector<long long>::iterator l = ox.end(); --l;

    long long mn, mx;

    for(vector<long long>::iterator city = ox.begin(); city != ox.end(); city++) {
        long long d1, d2;
        d1 = *city - *f; d2 = *l - *city;

        mx = max(d1, d2); 

        if (*city == *f) {
            mn = abs(*city - *(++f));
            --f;
        } else if (*city == *l){ 
            mn = abs (*city - *(--l));
            ++l;
        } else {
            mn = min((*(city+1) - *city), (*city - *(city-1)));
        }

        cout << mn << " " << mx << endl;

    }

    

    return 0 ;
}
