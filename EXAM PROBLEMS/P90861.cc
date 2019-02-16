#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){
	
	int n;
	cin >>n;
	
	vector<queue<string> > v(n);
	queue<string> mevoy;
	string c,name;
	int cua;
	
	
		
		int i = 0;
	/*	while (getline(cin,s) and i<n){
			
			istringstream ss(s);
			while (ss >>name){
				v[i-1].push(name);
				cout << "he insertado " << name << i<<endl;
			}
			i++;
		}
		
	*/
	
	for (int i = -1 ; i<n ; ++i){
			string s;
			getline(cin,s);			
			istringstream ss(s);
			while (ss >>name){
				v[i].push(name);
			
			
		
			}
	}
	
	while (cin >> c and c!= "end"){
		
		if (c == "SURT"){
			cin >> cua;
			
			if (cua>0 and cua<=n and !v[cua-1].empty()) {
				mevoy.push( v[cua-1].front());	
				v[cua-1].pop();
			}	
			
		}
		
		if (c== "ENTRA"){
			cin >>name >> cua;
			
			if (cua>0 and cua<=n) v[cua-1].push(name);
		}
		
	}
	cout << "SORTIDES" <<endl <<"--------"<<endl;
	while (!mevoy.empty()){
		cout <<mevoy.front()<<endl;
		mevoy.pop();
	}
	cout <<endl;
	
	cout << "CONTINGUTS FINALS"<<endl << "-----------------"<<endl;
	
	for (int i = 1 ; i <=n ; ++i){
		cout << "cua "<<i << ":";
		while (!v[i-1].empty()) {
			cout <<' '<< v[i-1].front() ;
			v[i-1].pop();
		}
		cout <<endl;
	}
	
	
}
