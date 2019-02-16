#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos



void read_graph(GrafP &g,int arcs,int vertexs,vector<int> &pesovertices){	
	int x,y,c;
	int peso;
	for (int i = 0 ; i< vertexs ; ++i){
		
		cin >> peso;
		pesovertices[i] = peso; 
		
	}
		
	for (int i = 0 ; i< arcs ; ++i){		
		cin >> x >> y >> c;		
		g[x].push_back(ArcP(c,y));
		g[y].push_back(ArcP(c,x));	
		
	}
}

void dijkstra(const GrafP &g, int inici, vector<int> &p, vector<int> &d,vector<int> &pesovertices){
	
	int n = g.size();
	p = vector<int>(n,-1);
	d = vector<int>(n,numeric_limits<int>::max());
	d[inici] = 0;
		
	vector<bool> vis(n,false);
	
	priority_queue<ArcP, vector<ArcP>, greater<ArcP> > pq;
	
	pq.push(ArcP(0,inici));
	
	while(!pq.empty()){
		
		int u = pq.top().second;pq.pop();
		
		if(!vis[u]){
			
			vis[u] = true;
			
			for (int i = 0 ; i< g[u].size() ; ++i){
				
				int c = g[u][i].first;
				int nextnode = g[u][i].second;
				
				if (d[nextnode] > d[u]+c + pesovertices[nextnode]){
					d[nextnode] = d[u] +c + pesovertices[nextnode];
					p[nextnode] = u;
				
					pq.push(ArcP(d[nextnode],nextnode));
					
				}								
			}			
		}		
	}	
}


int main(){
	
	int n ,arcs;
	
	cin >> n >> arcs;
		
	GrafP g(n);
	vector<int> v(n);
	read_graph(g,arcs,n,v);
		
	vector<int> p;
	vector<int> d;
		
		int x,y;
		
	while (cin >> x>>y){
		
		dijkstra(g,x,p,d,v);
		
		if (d[y] == numeric_limits<int>::max()) cout << "c(" <<x <<','<<y<<") = +oo"<<endl;
		else if (x == y) cout << "c(" <<x <<','<<y<<") = "<<0<<endl;
		else cout << "c(" <<x <<','<<y<<") = "<<d[y] - v[y]<<endl;
			
	}		
}
	
	
	

