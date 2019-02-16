#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void read_graph(GrafP &g,int arcs){	
	int x,y,c;	
	for (int i = 0 ; i< arcs ; ++i){		
		cin >> x >> y >> c;		
		g[x].push_back(ArcP(c,y));	
	}
}

void dijkstra(const GrafP &g, int inici, vector<int> &p, vector<int> &d,vector<int> &ways){
	
	int n = g.size();
	p = vector<int>(n,-1);
	d = vector<int>(n,500000);
	d[inici] = 0;
	
	ways = vector<int> (n,0);
	ways[inici] = 1;
	
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
				
				if (d[nextnode] > d[u]+c){
					ways[nextnode] = ways[u];
					d[nextnode] = d[u] +c ;
					p[nextnode] = u;
				
					pq.push(ArcP(d[nextnode],nextnode));
					
				}	
				
				else if (d[nextnode] == d[u]+c){
					
					ways[nextnode]+=ways[u];
					
				}			
			}			
		}		
	}	
}


int main(){
	
	int n ,arcs;
	
	while (cin >> n >> arcs){
		
		GrafP g(n);
		read_graph(g,arcs);
		
		vector<int> p;
		vector<int> d;
		
		int x,y;
		
		cin >> x>>y;
		
		vector<int> ways;
		dijkstra(g,x,p,d,ways);
		
		if (d[y] == 500000) cout << "no path from " <<x<< " to "<<y<<endl;
		else {
			int prev;
			prev = p[y];
			stack<int> s;
			
			cout << "cost "<< d[y] << ", "<<ways[y] <<" way(s)"<<endl;
		/*	while (!s.empty()){
				
				cout <<s.top() <<' ';
				s.pop(); 
				
			}*/
			
		}
		
		
	}
	
	
	
}
