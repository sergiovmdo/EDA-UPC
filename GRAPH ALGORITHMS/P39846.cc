#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef vector<vector<char> > graph;

bool pos_ok(graph &g, int i, int j){
	
	return i>= 0 and i< g.size() and j >= 0 and j< g[0].size() and g[i][j]!= 'X';
	
}

void read(graph &g){
	for (int i = 0 ; i< g.size();++i){
		for (int j = 0 ; j<g[0].size() ; ++j){
			cin >> g[i][j];			
		}
	}	
}

void bfs( graph &g,int i, int j,vector<int> &trobats){
	
	int n = g.size();
	vector<vector<bool> > vis(n,vector<bool> (g[0].size(),false));
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	queue<int> d;
	d.push(0);
	
	while(!q.empty()){
		
		pair<int,int> pos= q.front() ; q.pop();
		int i = pos.first;int j = pos.second;
		
		int dist = d.front() ; d.pop();
		
		if (g[i][j] == 't'){
			
			trobats.push_back(dist);
		}
		
		
		if (pos_ok(g,i+1,j) and !vis[i+1][j]){
			
			vis[i+1][j]=true;
			q.push(make_pair(i+1,j));
			d.push(dist+1);
		}
		if (pos_ok(g,i-1,j) and !vis[i-1][j]){
			
			vis[i-1][j]=true;
			q.push(make_pair(i-1,j));
			d.push(dist+1);
		}
		
		if (pos_ok(g,i,j+1) and !vis[i][j+1]){
			
			vis[i][j+1]=true;
			q.push(make_pair(i,j+1));
			d.push(dist+1);
		}
		
		if (pos_ok(g,i,j-1) and !vis[i][j-1]){
			
			vis[i][j-1]=true;
			q.push(make_pair(i,j-1));
			d.push(dist+1);
		}
	}
	
	
	
}



int main(){
	
	int n,m;
	cin >> n >> m;
	graph g(n,vector<char> (m));
	read(g);
	int i,j;
	
	vector<int> trobats;
	cin >> i >> j;
	bfs(g,i-1,j-1,trobats);
	

	
	if (trobats.size() != 0) {
			int max = trobats[0];
	
		for (int i = 1 ; i< trobats.size();++i){
			if (trobats[i]>max) max = trobats[i];
		
		}
	cout << "maximum distance: "<< max <<endl;	
	}
	else cout << "no treasure can be reached"<<endl;

}
