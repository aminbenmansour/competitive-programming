/**
 * 
 * We are using memoization which relies on recursive calls and a data structure to store 
 * encountred subproblems
 * 
 *  * Disadvantages are the following
 *          * Consuming more memory
 *          * May cause a stack overflow if recursive calls are too much
 *  * Solution
 *          * Using iterative DP
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

    // -1 in order to avoid segmentation error (similar to out of bound error) 
    if (dp[n-1][w-1] != -1) 
        return dp[n][w];
    
    if (wt[n-1] > w) {
        result = knapsack(wt, profit, w, n-1);
    } else {
        result = max(knapsack(wt, profit, w, n-1), profit[n-1] + knapsack(wt, profit, w-wt[n-1], n-1));
    }
    
    dp[n-1][w-1] = result;
    return dp[n-1][w-1];

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


    for (int i = 0; i < items; i++) {
        
        vector<int> tmp;
        for (int j = 0; j < w; j++) {
            tmp.emplace_back(-1);
        }
        dp.emplace_back(tmp);
        
    }
    
    cout << knapsack(wt, profit, w, items);

    return 0 ;
}
