#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int i_first_occurrence(int i, int j, double x, const vector<double> &v);


int first_occurrence(double x, const vector<double>& v){
	
	return i_first_occurrence(0,v.size()-1,x,v);
	
}


int i_first_occurrence(int i, int j, double x, const vector<double> &v){
	
	if (i<=j){
	
	int m = (i+j)/2;
	
	if (v[m]<x) return i_first_occurrence(m+1,j,x,v);
	else if(v[m] > x) return i_first_occurrence(i,m-1,x,v);
	
	else{
		
		int pos = 0;
		
		if (m!=0){
			
			pos = i_first_occurrence(i,m-1,x,v);
			
			if (pos == -1) pos = m;
			
		}
		
		return pos;
		
	}		
}
	return -1;
}


int main(){
	
	double x;
	
	int n;
	cin >>n;
	
	vector<double> v(n);
	for (int i =0;i<n;++i) cin >> v[i];
	
	cin >> x;
	
	int k =first_occurrence(x,v);
	cout <<k <<endl;
}
