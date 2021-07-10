/**
 * 
 *  problem link: https://codeforces.com/contest/47/problem/B
 *  
 * */

#include <bits/stdc++.h>
using namespace std;
 
#define fast               cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)
unordered_map<char, int> coins;
char comparators[] = {'<', '>'};
deque<char> value;

int main() {
    coins.insert({'A', 0});
    coins.insert({'B', 0});
    coins.insert({'C', 0});
    lp(i, 3) {
        char op1, op2, comp;
        cin >> op1 >> comp >> op2;
        comp == '>' ? coins[op1]+=1 : coins[op2]+=1;
    }

    char order[3];
    for (auto& it : coins) {
        int index = it.second;
        if (order[index] == 'A' || order[index] == 'B' || order[index] == 'C') {
            cout << "Impossible"; return 0;
        } else {
            order[index] = it.first;
        }
    }

    lp(i, 3) 
        cout << order[i];


	return 0;
}