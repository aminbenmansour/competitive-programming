/**
 * 
 * problem link: https://codeforces.com/problemset/problem/767/A
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;

map<int, int, greater<>> snacks;
vector<int> tail;


int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        snacks.insert({val, i});
    }

    auto ptr = snacks.begin();
    int current = 0;

     while (ptr != snacks.end()) {
        int fir, sec;
        do { 
            fir = ptr->first; sec = ptr->second;
            tail.emplace_back(fir);
            
            if (sec != current)
                cout<<'\n';
            
            ++ptr;

        } while(sec != current);
        current += tail.size();
        
        for(int it: tail) {
            cout << it << " ";
        }
        cout <<'\n';
        tail.clear();
        
     }

    return 0 ;
}
