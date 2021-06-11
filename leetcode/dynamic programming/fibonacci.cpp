/**
 * 
 * problem link: https://leetcode.com/problems/fibonacci-number/
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;
vector<long long> F;
long long fibonacci(int n) {
    F.emplace_back(0);
    F.emplace_back(1);

    for (int i = 2; i <= n; i++){
        long long val = F[i-1] + F[i-2];
        F.emplace_back(val);
    }

    return F[n];
    
}   
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fibonacci(50);

    return 0 ;
}
