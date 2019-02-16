#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > matrix;


void read_graph(matrix &g, int f, int &c){
	
	for (int i=0 ; i<f ;++i){
		for (int j = 0; j<c ; ++j){
			cin >> g[i][j];
		}
	}
}


bool mi_tesoro(matrix &g,int i,int j,vector<vector<bool> > &vis){
	
	bool encontrado = false;
	
	if (not vis[i][j]){
		
		vis[i][j] = true;
		
		if (g[i][j]!= 'X'){
			
			if (g[i][j] == 't') return true;
			
			if (i!= 0) {
				
				encontrado = encontrado or mi_tesoro(g,i-1,j,vis);
					if (encontrado) return true;
				
			}
			
			if (i!= g.size()-1){
				encontrado = encontrado or mi_tesoro(g,i+1,j,vis);
				if (encontrado) return true;
			}
			
			if (j!=0){
				encontrado = encontrado or mi_tesoro(g,i,j-1,vis);
				if (encontrado) return true;
			}
			
			if (j != g[0].size() -1 ){
				encontrado = encontrado or mi_tesoro(g,i,j+1,vis);
				if (encontrado) return true;
			}
			
			
		}
		
	}
	return encontrado;
	
}

int main(){
	
	int f,c,i,j;
	
	cin >>f >> c;
	
	matrix g(f,vector<char> (c));
	
	read_graph(g,f,c);
		
	vector<vector<bool> > vis(f,vector<bool> (c, false));
	
	cin >> i >> j;
	
	if (mi_tesoro(g,i-1,j-1,vis)) cout << "yes"<<endl;
	else cout <<"no" <<endl;
}

