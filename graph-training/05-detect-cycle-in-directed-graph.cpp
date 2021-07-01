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
vector<int> seen;

/**
 * recursive method
 * */

bool cyclic = false;

void dfs(int i, bool &cyclic) {
    if(seen[i]) {
        cyclic = true; return;
    } else if (!cyclic) {
        seen[i] = true;
        int adj = graph[i].size();
        lp(j, adj) {
            int node = graph[i][j];
            dfs(node, cyclic);
        }
        seen[i] = false;
    }
}

/**
 * end of the recursive method
 * */


int main(int argc, char **argv) {
    fast;
	cin >> nodes >> edges;

    // count starts from zero !!
    graph.resize(nodes); 
    seen.resize(nodes); 

    lp(i, edges) {
        //direction is from node to adjacent
        int node, adjacent; 
        cin >> node >> adjacent;
        graph[node].emplace_back(adjacent);
    }
 
    lp(i, nodes) {
        dfs(i, cyclic);
    }

    string result = cyclic ? "cyclic" : "not cyclic";
	cout << "the graph is " << result << '\n';
    return 0 ;
}
