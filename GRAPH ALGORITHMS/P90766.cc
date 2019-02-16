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


int mi_tesoro(matrix &g,int i,int j,vector<vector<bool> > &vis){
	
	int encontrado = 0;
	
	if (not vis[i][j]){
		
		vis[i][j] = true;
		
		if (g[i][j]!= 'X'){
			
			if (g[i][j] == 't') encontrado++;
			
			if (i!= 0) {
				
				encontrado += mi_tesoro(g,i-1,j,vis);
					
				
			}
			
			if (i!= g.size()-1){
				encontrado += mi_tesoro(g,i+1,j,vis);
				
			}
			
			if (j!=0){
				encontrado += mi_tesoro(g,i,j-1,vis);
				
			}
			
			if (j != g[0].size() -1 ){
				encontrado += mi_tesoro(g,i,j+1,vis);
				
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
	
	 cout << mi_tesoro(g,i-1,j-1,vis)<<endl;
	
}

