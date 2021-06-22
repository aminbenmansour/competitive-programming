/**
 * 
 * problem link: http://codeforces.com/contest/16/problem/B
 * 
 * */
 
#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
int m;
multimap<long long, int> containers;

 
int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    int i = m;
    while(i--) {
        int a;
        long long b;

        cin >> a >> b; containers.insert({b, a});
    }

    multimap<long long, int>::iterator it = containers.end();
    --it;

    int ai;
    long long bi;
    
    long long sum = 0;
    bool done = false;
    while(!done) {

        if(it == containers.begin())
            done = true;

        bi = it->first; ai = it->second;

        long long times =  n > ai ? ai : n; 
        n -= ai;
        sum += times * bi;
        
        --it;

        if(n <= 0) {
            done = true;
        }
        
    }
    
    cout << sum;
 
    return 0 ;
}