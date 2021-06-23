#include <bits/stdc++.h>
 
using namespace std;

long long m, n;

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    string n1, n2;

    n1 = to_string(n);
    n2 = to_string(m);

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    int p = 600;
    int res[p];
    int mult = 0, caret = 0, cell;
    
    memset(res, 0, sizeof(res));

    for (int i = 0; i < n1.length(); i++) {
        cell = 0;
        for (int j = 0; j < n2.length(); j++) {

            cell = (n1[i] - '0') * (n2[j] - '0');
            res[i+j] +=  cell % 10;

            caret = cell / 10;
            res[i+j+1]+=caret;

            
            
        }
    }
    
    // int pos = n1.length() + n2.length() - 1;
    // res[pos] = caret;

    //output
    int i = p-1;
    while(i > 0 && res[i] == 0)
        i--;
    
    for (; i >= 0; i--)
        cout << res[i];

    cout << '\n';
    
    return 0 ;
}
