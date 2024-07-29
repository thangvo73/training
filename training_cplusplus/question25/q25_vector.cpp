#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> vt){
	for (int i=0; i<vt.size(); i++){
		cout << " " << vt[i];
	}
	cout << endl;
}

int main(){
	vector<int> vector1;
	vector<int> vector2(5);
	vector<int> vector3 = {1,2,3,4,5,6};

	display(vector1);
	display(vector2);
	display(vector3);
	return 0;
}