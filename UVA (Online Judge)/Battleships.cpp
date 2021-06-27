/**
 * 
 * Problem: UVA 10452
 * 
 * Category: Graph, DFS
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

int tests, n;

vector<vector<char>> grid;
vector<vector<bool>> seen;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void dfs(int i, int j) {
    if(!seen[i][j]) {
        seen[i][j] = true;
        if(grid[i][j]=='x' || grid[i][j]=='@') {
            lp(k, 8) {
                int ii = i + dx[k], jj = j + dy[k];
                if(valid(ii, jj)) {
                    dfs(ii, jj);
                }
            }
        }
    }
}



int main(int argc, char **argv) {
    fast;

    cin >> tests;

    int num = 0;
    while(tests--) {

        int cnt = 0;

        cin >> n;
        grid.resize(n); seen.resize(n);
        lp(i, n) {
            seen[i].resize(n);
            lp(j,n) {
                char val; cin >> val; 
                grid[i].emplace_back(val);
            }
            
            
        }

        lp(i, n) {
            lp(j, n) {
                if(!seen[i][j] && grid[i][j] == 'x') {
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout << "Case " << ++num <<": " << cnt << '\n';
        seen.resize(0); grid.resize(0);
        

    }
    return 0 ;
}
