#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<char> > graf; // graf amb pesos


bool pos_ok(graf &g,int i, int j){
	
	return i<g.size() and i>= 0 and j < g[0].size() and j>=0 and g[i][j] != 'X';
	
}

int bfs(graf &g,int i, int j){
	
	int n = g.size();
	queue<int> d;
	d.push(0);
	vector<vector<bool> > vis(n,vector<bool> (g[0].size(),false));
	
	queue<pair<int,int> > q;
	
	q.push(make_pair(i,j));
	
	vis[i][j] = true;
	while(!q.empty()){
		
		pair<int,int> actual = q.front(); q.pop();
		int dist = d.front() +1; d.pop();
		int i = actual.first;
		int j = actual.second;
		
	
		if (pos_ok(g,i+1,j) and !vis[i+1][j]){
			
			if (g[i+1][j] == 't') return dist;
			vis[i+1][j] = true;
			q.push(make_pair(i+1,j));
			d.push(dist); 			
		}
		
		if (pos_ok(g,i-1,j) and !vis[i-1][j]){
			
			if (g[i-1][j] == 't') return dist;
			vis[i-1][j] = true;
			q.push(make_pair(i-1,j));
			d.push(dist); 			
		}
		
		if (pos_ok(g,i,j+1) and !vis[i][j+1]){
			
			if (g[i][j+1] == 't') return dist;
			vis[i][j+1] = true;
			q.push(make_pair(i,j+1));
			d.push(dist); 			
		}
		
		if (pos_ok(g,i,j-1) and !vis[i][j-1]){
			
			if (g[i][j-1] == 't') return dist;
			vis[i][j-1] = true;
			q.push(make_pair(i,j-1));
			d.push(dist); 			
		}
		
	}
	
	return -1;
}

void read_graph(graf &g,int f,int c){
	
	for (int i = 0 ; i< f ; ++i){
		
		for (int j = 0 ; j< c ; ++j){
			cin >> g[i][j];
		}
	}
}


int main(){
	
	int f,c;
	cin >>f >>c;
	
	graf g(f,vector<char> (c));
	
	read_graph(g,f,c);
	int i,j;
	cin >>i >> j;
	
	int dist = bfs(g,i-1,j-1);
	
	if (dist != -1) cout << "distancia minima: " <<dist <<endl;
	else cout <<"no es pot arribar a cap tresor"<<endl;
	
	
}
