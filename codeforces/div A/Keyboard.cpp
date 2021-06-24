/**
 * 
 * problem link: https://codeforces.com/contest/474/problem/A
 * 
 * */

#include <bits/stdc++.h>
using namespace std;
char keyboard[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
char shift;
string str;
int gap;
int main(int argc, char **argv) {
    // Fast input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ==========

    cin >> shift;
    cin >> str;

    gap = shift == 'R' ? -1 : 1;

    auto it = str.begin();
    while(it != str.end()) {
        auto index = find(keyboard, keyboard+30, *it);
        int i = distance(keyboard, index) + gap;
        *it = keyboard[i];
        it++;
    }

    cout << str;
    return 0 ;
}
