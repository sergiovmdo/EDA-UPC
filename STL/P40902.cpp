#include <map>
#include <iostream>

using namespace std;

int main() {
	map<string,int> players;
	string name,comando;
	int x;
	while (cin >> name >> comando){
		if (comando == "enters"){
			if (players.find(name) != players.end()) {
				cout << name << " is already in the casino"<<endl;
			} else {
				players.insert(make_pair(name,0));
			}
		}
		else if (comando == "wins"){
			cin >> x;
			map<string,int>::iterator it =players.find(name);
			if (it != players.end()) {
				it->second +=x;
			}
			else cout << name<< " is not in the casino" << endl;
		}
		
		else if (comando == "leaves"){
			map<string,int>::iterator it =players.find(name);
			if (it != players.end()) {
				cout << it->first << " has won "<<it->second<<endl;	
				players.erase(name);
			}
			else cout << name << " is not in the casino" << endl;
		}
		
	}
	
	cout << "----------"<<endl;
	for (map<string,int>::const_iterator it=players.begin();it != players.end();++it){
		cout << it->first << " is winning " << it->second << endl;
	}
		
}
		
			