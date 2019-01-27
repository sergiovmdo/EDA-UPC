#include <map>
#include <iostream>

using namespace std;

int main() {
	
	int x,y,n;
	
	
	while (cin >> x >> y >> n and  x<=1000 and y<=1000 and n<= 100000000){
		map<int,int> victor;
		int i=1;
		while (victor.find(n)== victor.end() and n<= 100000000){
			victor.insert(make_pair(n,i));
			if (n %2 == 0) {
				n= (n/2) + x;
			}
			else {
				n = (3*n) + y;
			}
			++i;
		}
		
		int size=i;
		if (n> 100000000 ) size=n;
		else {
		map<int,int>::const_iterator it=victor.find(n);
		if (it!= victor.end()){
			size-=it->second;
			
		}
	}
		
		cout <<size<<endl;
		
	
	}
}
		
			