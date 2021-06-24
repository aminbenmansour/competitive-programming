/**
 * 
 * problem link: https://codeforces.com/contest/160/problem/A
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

int n;
int num = 0, sum = 0, cnt = 0;

vector<int> coins;

int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========
    
    cin >> n;
    int i = n;
    while(i--) {
        int val; cin >> val; coins.emplace_back(val);
    }

    sort(coins.begin(), coins.end(), greater<int>());

    for(int c : coins) {
        sum += c;
    }


    auto it = coins.begin();
    if(sum != 0) {
        while(cnt <= (sum / 2)) {
            cnt += *it;
            num++; it++;
        }
    }

    cout << num;
    return 0 ;
}
