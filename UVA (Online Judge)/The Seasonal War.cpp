/**
 * 
 * Problem: UVA 352
 * 
 * */

#include <bits/stdc++.h>
#define fast                cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)

 
using namespace std;

int n;

char grid[25][25]; // it should be char instead of int because the input does not contain spaces
bool seen[25][25];
vector<pair<int, int>> answers;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

int dfs(int i, int j) {
        if(valid(i, j) && !seen[i][j]) {
            seen[i][j] = true;
            if(grid[i][j] == '1') {
                lp(k, 8) {
                    dfs(i+dx[k], j+dy[k]);
                }
            }
        }

        return 0;
}


int main(int argc, char **argv) {
    fast;

    int img = 0;
    
    while (scanf("%d",&n) != EOF) { // TODO see how to replace it with !cin.eof()
        lp(i, n) {
            cin >> grid[i];
        }

        int eagles = 0;

        lp(i, n) {
            lp(j, n) {
                if(!seen[i][j] && grid[i][j] == '1') {
                    eagles++;
                    dfs(i, j);
                }
            }
        }
        
        answers.push_back({++img, eagles});

        //cout << "Image " << ++img << " contains "<< eagles <<  " war eagles." <<"\n";

        /**
         *  cout did not show anything BUT printf did !!
         * */

        //printf("Image number %d contains %d war eagles.\n",++img, eagles);

        clr(grid, 0);
        clr(seen, false);
    }

    for(auto p : answers)
        cout << "Image " << p.first << " contains "<< p.second <<  " war eagles." <<"\n";

    return 0 ;
}
