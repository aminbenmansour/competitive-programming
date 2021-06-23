/**
 * 
 * problem link: https://codeforces.com/contest/520/problem/A
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

int n;
bool seen[26];
string str, pan = "NO";

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> str;
    if(n < 26) {
        //DO NOTHING !!
    } else {
        int i = 26;
        while(i--) {
            seen[i] = true;
        }

        int count = 0;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        i = 0;
        while(count < 26 && i < n) {
            char c = str[i];
            if(seen[c-97]) {
                count++;
                seen[c-97] = false;
            }
            i++;
        }
        if(count == 26) {
            pan = "YES";
        }
    }

    cout << pan;
    
    

    return 0 ;
}
