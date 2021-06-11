/**
 * 
 * problem link: https://leetcode.com/problems/fibonacci-number/
 * 
 * */

#include <bits/stdc++.h>

using namespace std;
vector<int> lardh;

int n;
int ctn = 0, maxi = 0;


void scan(int curr) {

    bool hbatna = false;
    int previous = -1;
    
    if (!hbatna && previous > -1)
            hbatna = previous > curr;

    if((hbatna && previous >= curr) || (!hbatna && previous <= curr))
        ctn++;
    else {
        ctn = 0;
        hbatna = false;
    }
            
    if(ctn > maxi)
        maxi = ctn;

    previous = curr;

}
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    cin >> n;

    for(int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        lardh.emplace_back(curr);
    }

    bool hbatna = false;
    int previous = -1;

    for(int i = 0; i < n; i++) {
       
        
        if (!hbatna && previous > -1)
                hbatna = previous > lardh[i];

        if((hbatna && previous >= lardh[i]) || (!hbatna && previous <= lardh[i]))
            ctn++;
        else {
            ctn = 0;
            hbatna = false;
        }
                
        if(ctn > maxi)
            maxi = ctn;

        previous = lardh[i];

    }
    ctn = 0;
    hbatna = false;
    previous = -1;
    for(int i = n-1; i >= 0; i--) {
        
        if (!hbatna && previous > -1)
                hbatna = previous > lardh[i];

        if((hbatna && previous >= lardh[i]) || (!hbatna && previous <= lardh[i]))
            ctn++;
        else {
            ctn = 0;
            hbatna = false;
        }
                
        if(ctn > maxi)
            maxi = ctn;

        previous = lardh[i];

    }

    cout << maxi;

    return 0 ;
}
