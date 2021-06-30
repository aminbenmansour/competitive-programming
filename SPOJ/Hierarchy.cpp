/**
 * 
 *  Problem link: https://codeforces.com/contest/216/problem/B
 *  
 *  Topological sort (Directed graph)
 *  
 * */

#include <bits/stdc++.h>
using namespace std;
 
 #define fast               cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		    for(int i=0;i<sz(v);++i)
#define lp(i, n)		    for(int i=0; i<(int)(n); i++)

int n, k, w;
vector<vector<int> > graph;
vector<bool> seen;
vector<int> init_result, parent;
 
void top_sort(int student) {
	seen[student] = true;
	for (int i = 0; i < (int) graph[student].size(); i++) {
		int child = graph[student][i];
		if (!seen[child])
			top_sort(child);
	}
	init_result.push_back(student);
}
 
int main() {
 
 
	cin >> n >> k;
 
	graph.resize(n + 1);
    seen.resize(n);
    parent.resize(n);
 
	for (int i = 1; i <= k; i++) {
		cin >> w;
		for (int j = 0; j < w; j++) {
			int val; cin >> val;
			graph[i].push_back(val);
		}
	}
 
	for (int i = 1; i <= n; i++) {
		if (!seen[i])
			top_sort(i);
	}
 
    
	int pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		int student = init_result[i];
		parent[student] = pos;
		pos = student;
	}
 
	for (int i = 1; i <= n; i++) {
		cout << parent[i] << '\n';
	}
 
	return 0;
}