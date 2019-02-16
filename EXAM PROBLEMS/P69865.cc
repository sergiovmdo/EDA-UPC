#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<char> > tauler;
typedef vector<vector<bool> > vis;

void leer_grafo(tauler &g){
	
	for (int i = 0 ; i<g.size() ; ++i){
		for (int j = 0; j<g[0].size() ; ++j){
			cin >> g[i][j];			
		}
	}
	
}


bool ok (tauler &g,int i,int j){
	
	return i>= 0 and i<g.size() and j>=0 and j<g[0].size();
}


int como_se_pasan_los_de_eda(tauler &g,vector<vector<bool> >  &colected, char ficha,int i , int j,vector<vector<bool> > &vis){
	int monedos = 0;
	
	
	if (g[i][j] == 'T') return 0;
	
	if (g[i][j] != '.' and g[i][j] != 'B' and g[i][j] != 'K' and !colected[i][j]) {
		
		colected[i][j] = true;
		monedos+=(g[i][j] - '0');
		
	}
	
	if (ficha == 'B'){
		
		if (i>0 and j>0 and !vis[i-1][j-1]){
			vis[i-1][j-1] = true;
			monedos = monedos + como_se_pasan_los_de_eda(g,colected,ficha,i-1,j-1,vis);
			
		}
		
		if (i>0 and j<g[0].size()-1 and !vis[i-1][j+1] ){	
		
			vis[i-1][j+1] = true;
			monedos = monedos + como_se_pasan_los_de_eda(g,colected,ficha,i-1,j+1,vis);
		
		}
		
		if (i<g.size()-1 and j<g[0].size()-1 and !vis[i+1][j+1]){	
			vis[i+1][j+1] = true;
			monedos = monedos + como_se_pasan_los_de_eda(g,colected,ficha,i+1,j+1,vis);
		
		}
		
		if (i<g.size()-1 and j>0  and !vis[i+1][j-1]){	
			vis[i+1][j-1] = true;
			monedos = monedos + como_se_pasan_los_de_eda(g,colected,ficha,i+1,j-1,vis);
			
		}
	}
	
	else if (ficha == 'K'){
		
		int fini,jfini;
		fini = i-2;
		jfini = j +1;
	
		if (fini >=0 and jfini <= g[0].size()-1 and !vis[fini][jfini] and ok){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
			
		}	
		
		fini = i-2;
		jfini = j -1;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
		
		}
		
		fini = i+2;
		jfini = j -1;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
			
		}
		
		fini = i+2;
		jfini = j +1;
	
	
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
			
		}
		
		fini = i+1;
		jfini = j +2;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
		
		}
		
		fini = i-1;
		jfini = j +2;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
			
		}
		
		fini = i-1;
		jfini = j-2;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
		;
		}
		
		fini = i+1;
		jfini = j-2;
		
		if (ok(g,fini,jfini) and !vis[fini][jfini]){
			vis[fini][jfini]=true;
			monedos +=como_se_pasan_los_de_eda(g,colected,ficha,fini,jfini,vis);
		
		}
		
	}
	
	return monedos;
}



int encuentra_mis_fichas(tauler &g){
	vis colected(g.size(),vector<bool> (g[0].size(),false));

	int mismonedos=0;
	vector<vector<bool> > vis(g.size(),vector<bool> (g[0].size(),false));
	vector<vector<bool> > visk(g.size(),vector<bool> (g[0].size(),false));
	for (int i = 0 ; i < g.size() ; ++i){
		for (int j = 0 ; j< g[0].size() ;++j){
			if (g[i][j] == 'B' or g[i][j] == 'K') {
				
				if (g[i][j] == 'B'){
				
					mismonedos+= como_se_pasan_los_de_eda(g,colected,g[i][j],i,j,vis);
				}
				else 	mismonedos+= como_se_pasan_los_de_eda(g,colected,g[i][j],i,j,visk);
			}
		}
	}	
	return mismonedos;
}


int main(){
	
	int f,c,mismonedos;
	
	while (cin>> f >> c){
	
		tauler g(f,vector<char> (c));
	
		leer_grafo(g);
	
		mismonedos= encuentra_mis_fichas(g);
		cout <<mismonedos <<endl;
	}
	
	
}


