/**
 * 
 * problem link: https://codeforces.com/contest/463/problem/B
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> polyns;
int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========

    cin >> n;
    int i = n;
    while(i--) {
        int val; cin >> val; polyns.emplace_back(val);
    }

    int energy = 0, dollars = polyns[0];
    n--;
    for (int i = 0; i < n; i++) {
        int power = energy + polyns[i];
        if(power <= polyns[i+1]) {
            dollars += polyns[i+1] - power;
            energy = 0;
        } else {
            energy += polyns[i] - polyns[i+1];
        }
    }

    cout << dollars;
    
    return 0 ;
}
