/**
 * 
 * problem link: https://codeforces.com/contest/770/problem/A
 * 
 * */

#include <bits/stdc++.h>
 
using namespace std;
 
unordered_set<char> us;
 string out = "";
  
int randomize() {
    return (1 + (rand() % 26)) + 96;
}
 
void generate(int n, int k) {
    out = "";
    int i = 0;
    while(out.length() < n) {
        char c;
        int distinct;
        do {
            c = randomize();
            us.insert(c);
            distinct = us.size();
        } while ((i != 0 && out[i-1] == c) || distinct != k);
        // cond1: not first letter AND two consecutive letters are distinct || cond2: N° of distincts is as required
        
        if (distinct == k) {
            auto it = us.begin();
            while (out.length() < n) {
                c = *it;
                string str(1, c);
                out.append(str);
                it++;
                if(it == us.end())
                    it = us.begin();
            }
        } else {
            string str(1, c);
            out.append(str);
        }
        i++;
    }
}
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    srand(time(0));
    //input 
    int n, k;
    cin >> n >> k;
    
    //logic
    generate(n, k);
    //output
    cout << out;
    return 0;
}