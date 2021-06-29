/**
 * 
 * Problem link: https://codeforces.com/contest/216/problem/B
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

#define fast                cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)


typedef long long ll;
 
vector<vector<int>> graph;
vector<int> seen;

enum status {PATH = 0, CYCLE = 1};


//  path (chain) or cycle
// We can use Find-Union Data structure to do that too
status dfs(int cur_node, int par_node, int &nodes_cnt) {
	if(seen[cur_node])
		return CYCLE;
 
	seen[cur_node] = 1;
 
	for(auto child_node : graph[cur_node]) if(child_node != par_node) {
		++nodes_cnt;
 
		if(dfs(child_node, cur_node, nodes_cnt) == CYCLE)
			return CYCLE;
	}
	return PATH;
}


int main(int argc, char **argv) {
    fast;
    
    int n, m;
 
	cin >> n >> m;
 
	graph = vector<vector<int>>(n);
	seen = vector<int>(n);
 
	lp(i, m) {
		int x, y;
		cin>>x>>y;
		--x, --y;
 
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
 
	int remove = 0;
 
	lp(i, n) 
	if(!seen[i]) {
		int cnt = 0;
 
		status solve = dfs(i, -1, cnt);
 
		if(solve == CYCLE)	// if odd cycle, remove 1
			remove += (cnt % 2 == 1);
	}
    
	// teams must be same size...if total odd, remove 1
	if( (n - remove) % 2 == 1)
		remove++;
 
	cout << remove;
    return 0 ;
}
