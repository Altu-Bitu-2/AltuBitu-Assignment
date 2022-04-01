#include <iostream>
#include <vector>
using namespace std;
const int MAX = 9;

int main() {

	vector <int> v;
	long long arr[51];
	long long n, score, p;
	cin >> n >> score >> p;

	if (n == 0) {
		cout << "1\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		
	}
	
	if (v[n - 1] >= score && n == p) { cout << "-1\n";  return 0; }// 못 들어감
	int rank = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > score) rank++;
		else break;
	
	}

	cout << rank+1 << "\n";
	


	return 0;
}