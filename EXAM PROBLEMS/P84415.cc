#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	
	string comanda,palabra;
	map<string,int> hola;

	
	while (cin >> comanda){
	
		if (comanda == "store"){
			cin >> palabra;
				
				if (hola.find(palabra) != hola.end()){
					hola[palabra]+= 1; 
				}
				else {
					hola.insert(make_pair(palabra,1));
				}		
				
		}
	
		else if (comanda == "delete"){
			cin >> palabra;
			
			if (hola.find(palabra) != hola.end()){
				
				if (hola[palabra] > 1) {
					--hola[palabra];
					
				}
				else hola.erase(palabra);
			}
			
		}
		
		else if (comanda == "maximum?"){
			map<string,int>::iterator it = hola.end();
			if (hola.empty()){
				cout << "indefinite maximum" <<endl;
				
			}
			
			else {
				it--;
				cout << "maximum: "<<(it->first) << ", "<< (it->second) << " time(s)" <<endl;
			}
			
		}
		
		else if (comanda == "minimum?"){
			if (hola.empty()){
				cout << "indefinite minimum" <<endl;
				
			}
			else {
				map<string,int>::iterator it = hola.begin();
				cout << "minimum: "<<(it->first) << ", " << (it->second) << " time(s)" <<endl;
			}
		}
		
		
	}
}
