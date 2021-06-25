#include <bits/stdc++.h>
using namespace std;

const int N = 100;

// adjacency matrix

bool adjMatrixRelation[N][N]; // relation graph
int adjMatrix[N][N]; // weighted graph

vector<int> adjMatrixAll[N][N]; // to keep all edges between nodes

map<pair<int, int>, int> adjMatrixMap; // for sparse graphs 


// adjacency list

vector<vector<int>> adjListRelation; //boolean relation
vector< vector<pair<int, int>> >adjList; // cost relation (node, cost): select 1 of multiple edges

// Edges List

struct edge {
    int from, to, w;

    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (const edge& e) const {
        return e.w < w; // sort with smaller weights first
    }

};

vector<edge> edges;

int main() {

    int n;

    // Matrix

    /**
     * INPUT: zero based [0, n-1]
     * Fill in the following graphs
     * */

    /**
     * boolean graph
     * 3
     * 0 1 0
     * 1 1 0
     * 0 1 1
     * 
     * */

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val; cin >> val; adjMatrix[i][j] = val;
        }    
    }

    /**
     * weighted graph
     * 3
     * 0 10 5
     * 2 07 9
     * 3 02 0
     * 
     * */

    cin >> n;

    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val; cin >> val; adjMatrix[i][j] = val; //keep the minimum cost edge only
        }    
    }

    int edges;

    /**
     * 3 5 (nodes, edges)
     * 0 3 10   from to w
     * 1 5 2
     * 3 7 -2
     * 0 3 2
     * 2 4 6
     **/

    /**
     * 
     * Only keep the minimum cost
     * Matrix should be initiated to INFINITY
     * 
     * */

    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        int from, to, cost;
        bool directed = true;
        if(directed) { // if the graph is directed
            adjMatrix[from][to] = min(adjMatrix[from][to], cost);
        } else { // if the graph is undirected
            adjMatrix[from][to] = min(adjMatrix[from][to], cost);
            adjMatrix[from][to] = adjMatrix[to][from];
        }
    }


    // List

    // keep edge with min cost

    /**
     * 3
     * node 0: 2 1 2   (number of edges, [to])
     * node 1: 1 2
     * node 2: 2 0 1
     * */

    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int to; cin >> to; adjList[i].emplace_back(to);
        }
    }

    /**
     * 3
     * node 0: 2   1 13   2 4 (number of edges, [{to, cost}])
     * node 1: 1   2 9 
     * node 3: 2   0 -7   1 8
     * */

    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int to, cost; cin >> to >> cost;
            adjList[i].emplace_back(make_pair(to, cost));
        }
        
    }
    
    
    
}


