#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<vector<char> > tauler;

void read_graph(tauler &g, int f, int &c){
	
	for (int i=0 ; i<f ;++i){
		for (int j = 0; j<c ; ++j){
			cin >> g[i][j];
		}
	}
}


bool ok(tauler &g, int i, int j){
	return i>=0 and i<g.size() and j>=0 and j < g[0].size();
}

bool fantasma(tauler &g,int i, int j){
	
	if (ok(g,i-1,j) and g[i-1][j]== 'F') return true;
	if (ok(g,i+1,j) and g[i+1][j]== 'F') return true;
	if (ok(g,i,j+1) and g[i][j+1]== 'F') return true;
	if (ok(g,i,j-1) and g[i][j-1]== 'F') return true;


	if (ok(g,i-1,j+1) and g[i-1][j+1] == 'F') return true;
	if (ok(g,i-1,j-1)and g[i-1][j-1] == 'F') return true;
	if(ok(g,i+1,j+1)and g[i+1][j+1] == 'F') return true;
	if(ok(g,i+1,j-1)and g[i+1][j-1] == 'F') return true;
	return false;
	
}

pair<int,int> encuentra(tauler &g){
	pair<int,int> pos;
	
	for (int i = 0 ; i < g.size(); ++i){
		for (int j = 0 ; j< g[0].size();++j){
			if (g[i][j] == 'P') {
				pos.first=i;
				pos.second = j;
			}
		}
	}
	return pos;
}

bool dfs(tauler &g,vector<vector<bool> > &vis,int i,int j){
	
	bool resultado = false;
	
	vis[i][j] = true;
	
	if (g[i][j] == 'B') return true;
	
	if (ok(g,i-1,j) and g[i-1][j] !='X' and !vis[i-1][j]){
		
		if (!fantasma(g,i-1,j)) resultado = resultado or dfs(g,vis,i-1,j);
		if (resultado) return true;
		
	}
		
	if (ok(g,i+1,j) and g[i+1][j] != 'X' and  !vis[i+1][j]){
		
		if (!fantasma(g,i+1,j)) resultado = resultado or dfs(g,vis,i+1,j);
		if (resultado) return true;
	}
	
	if (ok(g,i,j+1) and g[i][j+1] != 'X' and !vis[i][j+1] ){
		
		if (!fantasma(g,i,j+1)) resultado = resultado or dfs(g,vis,i,j+1);
		if (resultado) return true;
	}

	if (ok(g,i,j-1) and g[i][j-1] != 'X' and !vis[i][j-1] ){
		
		if (!fantasma(g,i,j-1)) resultado = resultado or dfs(g,vis,i,j-1);
		
	}
	
	return resultado;
	
}


int main(){
	
	int n,m;
	
	while (cin>>n >>m){
		
		tauler g(n,vector<char> (m));
		read_graph(g,n,m);
		
		pair<int,int> pos = encuentra(g);
		vector<vector<bool> > vis(n,vector<bool> (m,false));
		
		if (!fantasma(g,pos.first,pos.second)){
			if (dfs(g,vis,pos.first,pos.second)) cout <<"yes"<<endl;
		
			else cout << "no" <<endl;
		}
		else cout <<"no" <<endl;
		

	}

}


