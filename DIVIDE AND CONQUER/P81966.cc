#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right){

	
	if (left>right) return -1;
	
	int m = (left+right)/2;
	if (v[m] == x) return m;
	
	if (x>v[m]) position(x,v,m+1,right);
	else if (x<v[m]) position(x,v,left,m-1);
	
	
}