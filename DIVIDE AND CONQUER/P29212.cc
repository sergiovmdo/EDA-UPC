#include <iostream>
#include <vector>

using namespace std;

int potencia(int x,int n,int m){
	if (n == 0) return 1;
	else {
		int y = potencia(x,n/2,m)%m;
		if (n%2==0) return (y*y)%m;
		else return ((y*y)%m*x)%m;
	}
}

int main(){
	int k;
	int n,m;
	
	while (cin >>n >> k >>m){
		n=potencia(n,k,m);
		cout <<n<<endl;
	}
}
