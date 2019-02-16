#include <iostream>
#include  <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct comp{
	bool operator()(const string &a, const string &b){
		
		if (a.size() == b.size()) return a<b;
		return a.size() < b.size();
	}
};


int main(){
	
	
	string word;
	int cont = 1;
		
	while (word!= "QUIT"){
		
		set<string> sa;
		set<string,comp> so;
				
		while (cin >> word and (word != "END") and (word != "QUIT")){
		
			if(sa.find(word) == sa.end()){
				if (so.find(word)!=so.end()) so.erase(word);
				sa.insert(word);
			}
			else{
				so.insert(word);
				sa.erase(word);
			}
		
		}
		if (cont >1) cout <<endl;
		cout <<"GAME #" << cont<<endl;
		cout << "HAS:" <<endl;
		for(set<string>::const_iterator it= sa.begin() ; it != sa.end() ;++it){
			cout << *it <<endl;
		}
		
		cout <<endl;
		
		cout << "HAD:" <<endl;
		for(set<string>::const_iterator it= so.begin(); it!= so.end();++it){
			
			
			cout << *it <<endl;
		}
		
		++cont;
	
	}
	
	
	
}
