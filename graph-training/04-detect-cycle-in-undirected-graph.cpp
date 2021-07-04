#include <bits/stdc++.h>
using namespace std;

#define fast                cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)

int nodes, edges;
vector<vector<int>> graph;

/**
 *  switch seen
 *          case 1, WHITE: visited 
 *          case 2, GRAY: being processed
 *          case 3, BLACK: the graph is cyclic
 * */
vector<int> seen;

/**
 * recursive method
 * */

/**
 * IMPORTANT: seen vector should be passed by VALUE & should be named diffrently in order to maintain older values while backtracking
 * */

bool dfs(vector<int> visited, int curr) {
     if(visited[curr]==2)
        return true;
    
    visited[curr] = 1;
    bool FLAG = false;
    lp(i, graph[curr].size()) {
        if(visited[graph[curr][i]] == 1)
            visited[graph[curr][i]] = 2;
        else {
            FLAG = dfs(visited, graph[curr][i]);
            if(FLAG==true)
                return true;
        }
    }
    return false;
}

/**
 * end of the recursive method
 * */

int main(int argc, char **argv) {
    fast;
	cin >> nodes >> edges;

    // count starts from zero !!
    graph.resize(nodes); 
    seen = vector<int>(nodes, 0);

    lp(i, edges) {
        int node, adjacent; 
        cin >> node >> adjacent;
        graph[node].emplace_back(adjacent);
        graph[adjacent].emplace_back(node);
    }
 
    bool FLAG = false;
    lp(i, nodes) {
        seen[i] = 1; int n = graph[i].size();
        lp(j, n) { 
            FLAG = dfs(seen, graph[i][j]);
            if(FLAG==true)
                break; 
        }
        seen[i] = 0;
        if(FLAG==true)
            break;
    }

    string result = FLAG ? "cyclic" : "not cyclic";
	cout << "the graph is " << result << '\n';
    return 0 ;
}
