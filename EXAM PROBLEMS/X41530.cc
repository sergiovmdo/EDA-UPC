#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

typedef vector<vector<int> > graph;
/*
bool pos_ok(graph &g, int i, int j){
	
	return i>= 0 and i< g.size() and j >= 0 and j< g[0].size() and g[i][j]!= 'X';
	
}*/

void read(graph &g,int &arcs){
	int x,y;
	for (int i = 0 ; i< arcs;++i){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		
	}
	
}

bool es_arbre(graph &g,vector<bool> &vis,int u,int padre){
	bool found = true;
	if (!vis[u]){
		vis[u] = true;
		
		for (int i = 0; i< g[u].size();++i){
			
			if (g[u][i] != padre) found = found and es_arbre(g,vis,g[u][i],u);
			
		}
		return found;
	}
	
	else return false;
	
	
}



int main(){
	
	int n,arcs;
	
	while (cin >> n>> arcs){
		
		graph g(n);
		read(g,arcs);
		
		int arbres = 0;
		vector<bool> vis(n,false);
		bool stop = false;
		for (int i = 0 ; i< n and !stop ; ++i){
			
			if (!vis[i]){
				if (es_arbre(g,vis,i,i)) arbres++;
				else stop = true;
			}
			
			
		}
		
		if (!stop) cout <<arbres<<endl;
		else cout << "no" <<endl;
		
	}


}
