#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;


int search_pico(const vector<int>& v,int i, int j){
	
	if (i == j) return i;
	
	int m = (i+j)/2;
	if (m == 0) {
		
		if (v[0] > v[1]) return 0;
		else return 1;
	}
	
	if (v[m] > v[m-1] and v[m] > v[m+1]) return m;
	
	if (v[m] > v[m+1]) return search_pico(v,i,m-1);
	else return search_pico(v,m+1,j);
}	

bool asc(int x,const vector<int>& v,int i, int j){
	
	if (i>j) return false;
	
	int m = (i+j)/2;
	if (v[m] == x) return true;
	
	if (x>v[m]) asc(x,v,m+1,j);
	else if (x<v[m]) asc(x,v,i,m-1);
	
	
}

bool desc(int x,const vector<int>& v,int i, int j){
	
	if (i>j) return false;

	int m = (i+j)/2;
	if (v[m] == x) return true;
	
	if (x<v[m]) desc(x,v,m+1,j);
	else if (x>v[m]) desc(x,v,i,m-1);
	
	
}

bool search(int x, const vector<int>& v){
	
	int pico = search_pico(v,0,v.size()-1);	
	if (v[pico] == x) return true;	
	if (x > v[pico]) return false;	
	return asc(x,v,0,pico-1) or desc(x,v,pico+1,v.size()-1);
	
}
int main(){
	
	int n;
	while (cin >>n){
	
	
	vector<int> v(n);
	
	for (int i = 0 ; i<n ; ++i){
		
		cin >> v[i];
		
	}
	int x;
	while (cin >> x and x!=0){
		if (search(x,v)) cout << "encontrado"<<endl;
		else cout << "no esta"<<endl;
	}
}
}
