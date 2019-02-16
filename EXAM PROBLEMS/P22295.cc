#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef vector<vector<char> > graph;

void read_graph(graph &g){

	for (int i = 0 ; i<g.size() ; ++i){		
		for (int j = 0 ; j< g[0].size(); ++j){			
			cin >> g[i][j];
		}	
	}	
}

bool pos_ok(graph &g, int i, int j){
	
	return i< g.size() and i>= 0 and j< g[0].size() and j>= 0;
	
}

void dfs(graph &g,vector<vector<bool> > &vis,int i,int j, int fi,int fj, vector<char> &prev,int it){
	
	if (i == fi and j ==fj){	
		for (int k = 0 ; k< it ; ++k){
			
			cout << prev[k] ;
		}
		cout << g[fi][fj] <<endl;	
		return;	
	}
	
	prev[it] = g[i][j];
	
	if (!vis[i][j]) vis[i][j] = true;
	
	if (pos_ok(g,i+1,j) and !vis[i+1][j]){
		
		vis[i+1][j] = true;
		dfs(g,vis,i+1,j,fi,fj,prev,it+1);
		vis[i+1][j] = false;
	}
			
	if (pos_ok(g,i-1,j) and !vis[i-1][j]){
		
		vis[i-1][j] = true;
		dfs(g,vis,i-1,j,fi,fj,prev,it+1);
		vis[i-1][j] = false;
		
	}
	
	if (pos_ok(g,i,j+1) and !vis[i][j+1]){
		
		vis[i][j+1] = true;
		dfs(g,vis,i,j+1,fi,fj,prev,it+1);
		vis[i][j+1] = false;
		
	}
		
	if (pos_ok(g,i,j-1) and !vis[i][j-1]){
		
		vis[i][j-1] = true;
		dfs(g,vis,i,j-1,fi,fj,prev,it+1);
		vis[i][j-1] = false;
		
	}
	
}

int main(){
	
	int n,arcs;
	cin >> n >> arcs;
	
	graph g(n,vector<char> (arcs));
	
	int i,j,fi,fj;
	
	read_graph(g);
	
	cin >> i >> j >> fi >> fj;
	vector<char> prev(n*arcs);
	vector<vector<bool> > vis(n,vector<bool> (arcs,false));
	
	dfs(g,vis,i,j,fi,fj,prev,0);
}
