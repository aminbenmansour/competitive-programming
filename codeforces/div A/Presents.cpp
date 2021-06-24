/**
 * 
 * problem link: https://codeforces.com/contest/136/problem/A
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;
map<int, int> m;
 
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int j = i+1;
        
        m.insert({a, j});
    }
 
    for (map<int, int>::iterator  it = m.begin(); it != m.end(); it++){
        cout << it->second << ' ';
    }
    
    
    return 0 ;
}
