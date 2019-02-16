#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef vector<vector<int> > graph;

void read_graph(graph &g,int arcs){
	
	int x,y;
	for (int i = 0 ; i<arcs ; ++i){		
		cin >> x >> y;		
		g[x].push_back(y);		
	}	
}
	

list<int> topol(graph &g){
	
	int n = g.size();
	vector<int> ge(n,0);
	priority_queue<int, vector<int>, greater<int> > s;
	for (int i = 0 ; i<n ; ++i){
		for (int j = 0; j<g[i].size();++j){
			++ge[g[i][j]];			
		}				
	}
	
	for (int i = 0 ; i<ge.size();++i){
		
		if (ge[i] == 0) s.push(i);
	}
	
	list<int> l;
	
	while (!s.empty()){
		
		int u = s.top(); s.pop();
		
		l.push_back(u);
		
		for (int i = 0; i<g[u].size();++i){
			
			int v = g[u][i];
			
			if(--ge[v] == 0){
				s.push(v);
				
			}
		}
		
	}
	return l;
	
}

int main(){
	
	int n,arcs;
	
	while (cin >> n >> arcs){
		
		graph g(n);
		
		read_graph(g,arcs);
		list<int> hostia;
		
		hostia = topol(g);
		
		list<int>::const_iterator it = hostia.begin();
		list<int>::const_iterator it2 = hostia.end();
		it2--;
		for (;it != it2; ++it){
			
			cout <<*it <<' ';
		}
		cout<<*it2 <<endl;
	}
	
}
