#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,string> p1,pair<int,string> p2){

	if (p1.first == p2.first){
		return p1.second <=p2.second;
		
	}
	
	return p1.first > p2.first;

}

int main(){

	map<string,pair<int,bool> > players;
	map<string,pair<int,bool> >::iterator it;
	map<string,pair<int,bool> >::iterator it2;		
	string comanda,name,name2;
	
	while (cin >> comanda) {
		
		if (comanda == "LOGIN"){
			cin >> name;
			it = players.find(name);
			if (it == players.end()){
				
				players.insert(make_pair(name,make_pair(1200,true)));
			}
			else it->second.second= true;
		}
		else if(comanda == "LOGOUT"){
			cin >>name;
			it = players.find(name);
			
			if (it != players.end()){
				it->second.second = false;
			}
		}
		
		else if(comanda == "PLAY"){
			
			cin >>name >> name2;
			it = players.find(name);
			it2 = players.find(name2);
			
			if(name!=name2 and it != players.end() and it2 != players.end() and it->second.second and it2->second.second){
				it->second.first+=10;
				it2->second.first-=10;
				if (it2->second.first < 1200) it2->second.first = 1200;
				
			}
			else cout << "jugador(s) no connectat(s)"<<endl;
		}
		else if (comanda == "GET_ELO"){
			cin >>name;
			it = players.find(name);
			if (it != players.end()){
				cout << it->first <<' ' << it->second.first <<endl;
			}
		}
	}
	
	cout <<endl << "RANKING"<<endl;
	
	vector<pair<int,string> > ORDENJODER;
	it= players.begin();
	
	for (int i = 0; i < players.size(); ++i){
		ORDENJODER.push_back(make_pair(it->second.first,it->first));
		++it;
	}
	
	sort(ORDENJODER.begin(),ORDENJODER.end(),comp);	
	
	for(int i = 0; i<ORDENJODER.size();++i){
		cout << ORDENJODER[i].second <<' ' <<ORDENJODER[i].first <<endl;
	}

}
