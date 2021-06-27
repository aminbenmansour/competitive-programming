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

int tests, n, m;

char grid[25][8];
bool seen[25][8];

int dx[3] = {-1, 0, 0};
int dy[3] = {0, 1, -1};
string cmds[3] = {"forth", "right", "left"};
char word[] = {'I', 'E', 'H', 'O', 'V', 'A'};


bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < m && j < n;
}

void dfs(int i, int j) {
    lp(k, 3) {
        int new_x = i + dx[k], new_y = j + dy[k];
        if(valid(new_x, new_y) && !seen[new_x][new_y] && ((find(word, word + 6, grid[new_x][new_y])) != (word + 6) || grid[new_x][new_y] == '#') ) {
            seen[new_x][new_y] = true;
            cout << cmds[k] << " ";
            dfs(new_x, new_y); break;
        }
            
    }
}



int main(int argc, char **argv) {
    fast;
    cin >> tests;
    while(tests--) {
        cin >> m >> n;
        
        lp(i, m) {
            cin >> grid[i];
        }

        auto it = find(grid[m-1], grid[m-1] + n, '@');
        int index = distance(grid[m-1], it);
        dfs(m-1, index);
        cout << '\n';
        clr(seen, false); clr(grid, '\000');
        
        
    }
    return 0 ;
}
