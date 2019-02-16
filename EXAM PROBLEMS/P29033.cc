#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > matrix;

void read_graph(matrix &g, int f, int c){
	
	int x,y;
	for (int i=0 ; i<c ;++i){
			
		cin >> x>> y;
		g[x].push_back(y);
		g[y].push_back(x);
		
	}
}


bool se_puede_pintar(matrix &g,vector<pair<bool,int> >&vis,int verticeAVisitar,int padre){
	
	bool pintado = true;
	
	
	if (not vis[verticeAVisitar].first){
		
		vis[verticeAVisitar].first = true;
		int k = vis[padre].second;
		
		if (vis[padre].second == 1) vis[verticeAVisitar].second = 2;
		else  vis[verticeAVisitar].second = 1;
		
		for (int i = 0 ; i<g[verticeAVisitar].size() ; ++i){
			
			if (g[verticeAVisitar][i] != padre) pintado = pintado and se_puede_pintar(g,vis,g[verticeAVisitar][i],verticeAVisitar);
				
				
		}
		return pintado;
			
		}	
	
	else {
		
		if (vis[verticeAVisitar].second == vis[padre].second) return false;
		else return true;
			
	}
		
}



int main(){
	
	int v,a;
	
	while (cin >>v >> a){
		
		matrix g(v);
		bool no = false;
		read_graph(g,v,a);
		
		vector<pair<bool,int> >  vis(v,make_pair(false,0));
		
		for (int i = 0; i<v and not no ; ++i){
		
			if (not vis[i].first){
			
				if (not se_puede_pintar(g,vis,i,i)) no = true;
				
			}
			
		}
		if (no) cout <<"no"<<endl;
		else cout << "yes" <<endl;
	
	}
	 
}

