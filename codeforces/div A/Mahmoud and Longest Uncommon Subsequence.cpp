/**
 * 
 * problem link: https://codeforces.com/contest/766/problem/A
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

string a, b;
string sht, lng;
int glb = -1;

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count = 0;
    cin >> a;
    cin >> b;

    lng = a.length() >= b.length() ? a : b; sht = a.length() < b.length() ? a : b;

    for(int i=0; i < lng.length(); i++) {

        if(int match = (sht.find(lng[i])!=string::npos)) {

            if(count > glb) 
                glb = count;
                
            count = 0;

            
        } else {
            count++;   
            if(count > glb)
                glb = count;   
        }

    }

    glb == 0 ? cout << -1 : cout << glb;


    return 0 ;
}
