/**
 * 
 * We are using tabulation to avoid the problems caused by memoization
 * 
 * */


/**
 * 
 * INPUT: Knapsack weight - Number of items
 * INPUT: Weights of items
 * INPUT: Profits
 * 
 * 
 * OUTPUT: Best possible profit
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;

vector<int> wt, profit;
vector<vector<int>> dp;
int items, w;


int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========

    cin >> w >> items;

    int n = items;

    while(n--) {
        int val; cin >> val; wt.emplace_back(val);
    }

    n = items;

    while(n--) {
        int val; cin >> val; profit.emplace_back(val);
    }

    
    int i = items + 1 , j = w + 1;
   
    dp.resize(i);
    while(i-- > -1)
        dp[i].resize(w + 1);


    for(int i = 0; i <= items; i++) {
        for (int j = 0; j <= w; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(wt[i-1] > w) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i][w-wt[i-1]]);
            }
        }
        
    }

    cout << dp[items][w];

    return 0;
}
