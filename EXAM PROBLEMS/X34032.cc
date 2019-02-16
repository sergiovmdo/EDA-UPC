#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<vector<char> > tauler;
typedef vector<vector<bool> > visitats;

bool ok(tauler &g,int i,int j){
	
	return i>=0 and i<g.size() and j>=0 and j < g[0].size() and g[i][j]!= 'X';
}


void read_graph(tauler &g, int f, int &c){
	
	for (int i=0 ; i<f ;++i){
		for (int j = 0; j<c ; ++j){
			cin >> g[i][j];
		}
	}
}

int bfs(tauler &g,visitats &vis,int ii,int jj){

	queue<pair<int,int> > pos;
	queue<int> dist;
	pos.push(make_pair(ii,jj));
	dist.push(0);
	vis[ii][jj] == true;

	while (!pos.empty()){
	
		pair<int,int> actual = pos.front();
		pos.pop();
		int i= actual.first;
		int j = actual.second;
		
		int d = dist.front()+1;
		dist.pop();
		
		if (ok(g,i-2,j+1) and !vis[i-2][j+1]){		//ARRIBA DERECHA
			if (g[i-2][j+1] == 'p') return d;
			pos.push(make_pair(i-2,j+1));
			dist.push(d);
			vis[i-2][j+1] = true;	
			
		}
		
		if(ok(g,i-2,j-1) and !vis[i-2][j-1]){
			if (g[i-2][j-1] == 'p') return d;
			pos.push(make_pair(i-2,j-1));
			dist.push(d);
			vis[i-2][j-1] = true;
			
		}
		
		if(ok(g,i+2,j-1) and !vis[i+2][j-1]){
			if (g[i+2][j-1] == 'p') return d;
			pos.push(make_pair(i+2,j-1));
			dist.push(d);
			vis[i+2][j-1] = true;
			
		}
		
		if(ok(g,i+2,j+1) and !vis[i+2][j+1]){
			if (g[i+2][j+1] == 'p') return d;
			pos.push(make_pair(i+2,j+1));
			dist.push(d);
			vis[i+2][j+1] = true;
			
		}
		
		if(ok(g,i-1,j+2) and !vis[i-1][j+2]){
			if (g[i-1][j+2] == 'p') return d;
			pos.push(make_pair(i-1,j+2));
			dist.push(d);
			vis[i-1][j+2] = true;		
		}
		
		if(ok(g,i+1,j+2) and !vis[i+1][j+2]){
			if (g[i+1][j+2] == 'p') return d;
			pos.push(make_pair(i+1,j+2));
			dist.push(d);
			vis[i+1][j+2] = true;		
		}
	
		if(ok(g,i+1,j-2) and !vis[i+1][j-2]){
			
			if (g[i+1][j-2] == 'p') return d;
			pos.push(make_pair(i+1,j-2));
			dist.push(d);
			vis[i+1][j-2] = true;		
		}
		
		if(ok(g,i-1,j-2) and !vis[i-1][j-2]){
			if (g[i-1][j-2] == 'p') return d;
			pos.push(make_pair(i-1,j-2));
			dist.push(d);
			vis[i-1][j-2] = true;		
		}
		
	}
	
	return -1;
	
}



int main(){
	
	int f,c,i,j;
	
	while (cin >> f >> c){
		tauler g(f,vector<char> (c));
		read_graph(g,f,c);
		cin >> i >> j;
		visitats vist(f,vector<bool> (c,false));
		int dis = bfs(g,vist,i-1,j-1);
		
		if (dis!=-1) cout <<dis <<endl;
		else cout <<"no"<<endl;
	}


}


