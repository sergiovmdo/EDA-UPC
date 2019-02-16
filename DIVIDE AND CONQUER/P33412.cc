#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>

using namespace std;



 bool resistant_search(double x, const vector<double>& v){
 	
 	if (v.size() == 0) return false;
 	
 	int r = v.size()-1;
 	int m,l=0;
 	
 	while (l+1 < r){
 		m = (l+r)/2;
 		
 		if(v[m] == x or v[m-1] == x or v[m+1] == x) return true;
 		else if (v[m] < x) {
 			l=m;
		 }
		 else r=m;
 		
	 }
 	
 	return ((x==v[l]) or (x==v[r]));
 	
 	
 }





int main(){
	
	double x;
	cin>>x;
	double y;
	vector<double> a;
	while (cin>> y and y!=0){
		a.push_back(y);
	}
	
	if (resistant_search(x,a)) cout <<"yes"<<endl;
	else cout <<"no" <<endl;
	 
}
