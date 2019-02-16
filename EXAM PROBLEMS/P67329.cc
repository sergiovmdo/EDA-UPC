#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<char> adn(4);

void backtracking(int n,int j,vector<char> &v){
	
	if (j == n) {
		
		for (int k= 0 ; k<n; ++k){
			cout <<v[k];
		}
		cout <<endl; 
	}
	else {
	
	for (int i = 0 ; i < 4 ; ++i){
			
		v[j] = adn[i];
		backtracking(n,j+1,v);
	}
}
}

int main(){
	
	int n;
	cin >>n;
	vector<char> v(n);
	adn[0] = 'A';
	adn[1] = 'C';
	adn[2] = 'G';
	adn[3] = 'T';
	backtracking(n,0,v);

}


