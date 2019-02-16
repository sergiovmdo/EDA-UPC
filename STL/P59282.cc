#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	cout.setf(ios::fixed);
     cout.precision(4);
	
	map<int,int> m;
	int x;
	string com;
	double med=0 ,cont=0;
	
		map<int,int>::iterator it= m.begin();
		map<int,int>::iterator itf= m.end();

	
	while (cin >> com and com != "end"){
				
		if (com == "number"){
		
			cin >> x;
			++m[x];
	
			it = m.begin();
			itf= m.end();
			--itf;
			cont++;	
			med+=x;
			cout << "minimum: "<<it->first <<", maximum: " <<itf->first << ", average: "<<med/cont<<endl;
			
			
		}
		else if (com == "delete"){
		
			if (m.empty()) cout << "no elements"<<endl;
			
			else{
				
				it = m.begin();
				--cont;
				med-=it->first;
				--m[it->first];
				if (m[it->first] == 0) m.erase(it->first);
				
				if (not m.empty()){
				
					it = m.begin();
					itf= m.end();
					itf--;
					cout << "minimum: "<<it->first <<", maximum: " <<itf->first << ", average: "<<med/cont<<endl;
				
				}
				else cout << "no elements"<<endl;
			}
		}
		
		
		
	}
	

}
