#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void read_graph (GrafP &g,int arists){
	
	int x,y,c;
	for (int i = 0; i< arists;++i){
		
		cin >> x >> y >>c ;
		
		g[x].push_back(make_pair(c,y));
		
	}
	
}

void dijkstra(const GrafP& g, int s, vector<int>& d, vector<int>& p){
	
	int n = g.size();
	
	d = vector<int>(n,500000);
	d[s] = 0;
	p = vector<int>(n,-1);
	
	vector<bool> vis(n,false);
	
	priority_queue<ArcP, vector<ArcP>, greater<ArcP> > q;
	q.push(ArcP(0,s));
	
	while (!q.empty()){
		
		int actual = q.top().second ; q.pop();
		
		if (!vis[actual]){
			
			vis[actual] = true;
			
			for (int i = 0 ; i < g[actual].size(); ++i){
				
				int nprox = g[actual][i].second;
				int dprox = g[actual][i].first;
				
				if (d[nprox] > d[actual] + dprox ){
					
					d[nprox] = d[actual] +dprox;
					p[nprox] = actual;
					
					q.push(ArcP(d[nprox],nprox));
					
				}
				
			}
		} 
		
	}
	
}


int main(){
	
	int n,arists;
	
	while (cin >> n >> arists) {
		
		GrafP G(n);
		
		read_graph(G,arists);
		
		int i, j ;
		
		cin >> i >> j;
		
		vector<int> d;
		vector<int> p;
		
		dijkstra(G,i,d,p);
		
		if (d[j] == 500000) cout << "no path from " << i << " to " <<j << endl;
		else cout << d[j] <<endl;
		
		
	}
	
}

