#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int arr[21], s, e;
	for (int i = 0; i < 20; i++)
		arr[i] = i+1;

	for (int i = 0; i < 10; i++) {
		cin >> s >> e;
		reverse(arr + s -1 , arr + e);
	}

	for (int i = 0; i < 20; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}