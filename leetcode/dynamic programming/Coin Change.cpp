/**
 * 
 * problem link: https://leetcode.com/problems/coin-change/ #322
 * Dynamic Programming
 * */

#include <bits/stdc++.h>
 
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n+1][amount+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < amount+1; j++) {
            
            if( i==0 ) { // Boundaries block
                if (j == 0) { // coins NULL, amount NULL
                    dp[i][j] = 0;
                } else { // coins NULL, amount > 0
                    dp[i][j] = 1e5;
                }
            } else if(coins[i-1] > j) { // Exclusion case :: Current denomenation > amount
                dp[i][j] = dp[i-1][j];
            } else { // Inclusion case :: Taking the minimum of inclusion-exclusion case
                dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
            }

        }
    }
    return dp[n][amount] > 1e4 ? -1 : dp[n][amount];  
}



int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========

    int change, amount;
    vector<int> coins;

    cin >> amount >> change;

    while(change--) {
        int val; cin >> val; coins.emplace_back(val);
    }

    cout << coinChange(coins, amount);

    return 0 ;
}
