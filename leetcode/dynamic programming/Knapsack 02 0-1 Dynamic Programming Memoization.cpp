/**
 * 
 * Problem description: knapsack is a widely known problem with a lot of variation like 0/1, bounded, unbounded, fractional and non fractional knapsacks 
 * this problem could be categorized under combinatorial & optimization and we will work later on others variations without forgetting our main goal
 * which is to optimize recursive problems with dynamic programming
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

/**
 * 
 * Complexity of this recursive algorithm is equal to O(n*w) // n is number of items, w is bag's weight
 * 
 * */
int knapsack(const vector<int> &wt, const vector<int> &profit, int w, int n) {
    int result;

    if (w == 0 || n == 0)
        return 0;

    if (dp[w][n] != -1) 
        return dp[w][n];
    
    if (wt[n] > w) {
        result = knapsack(wt, profit, w, n-1);
    } else {
        result = max(knapsack(wt, profit, w, n-1), profit[n] + knapsack(wt, profit, w-wt[n], n-1));
    }
    return dp[w][n] = result;

}

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

    int dp[w][items];

    for (int i = 0; i < items; i++) {
        for (int j = 0; j < w; j++) {
            dp[i][j] = -1;
        }
        
    }
    

    cout << knapsack(wt, profit, w, items);

    return 0 ;
}
