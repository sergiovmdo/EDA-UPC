#include <queue>
#include <iostream>

using namespace std;

int main() {
	
	priority_queue<int> numbers;
	char key;
	int x;
	
	while (cin >> key){
		if (key == 'S'){
			cin >> x;
			numbers.push(x);
		}
		else if (key == 'A'){
			if (numbers.empty()) cout << "error!"<<endl;
			else{
			cout << numbers.top()<<endl;
			}
		}
		else if (key == 'R'){
			if (numbers.empty()) cout << "error!"<<endl;
			else{
			numbers.pop();
			}
		}
		else if (key == 'I'){
			if (numbers.empty()) cout << "error!"<<endl;
			else{
			cin >> x;
			int k = numbers.top();
			k+=x;
			numbers.pop();
			numbers.push(k);
			}
		} 
		else if (key == 'D'){
			if (numbers.empty()) cout << "error!"<<endl;
			else{
			cin >>x;
			int k = numbers.top();
			k-=x;
			numbers.pop();
			numbers.push(k);
			}
		}
		
		
	}
	
}