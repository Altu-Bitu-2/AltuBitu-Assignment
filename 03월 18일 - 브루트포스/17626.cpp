#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt=0;
	int arr[250];
	cin >> n;

	for (int i = 0; i * i <= 50000; i++)
		arr[i] = i * i;

	// 수를 한 개 더해서 n 되나 체크
	for (int i = 1; i * i <= n; i++)
		if (arr[i] == n) {
			cout << "1\n"; return 0;
		}
	// 수 두 개 더해서 n되나 체크
	for (int i = 1; i * i <= n ; i++) 
		for (int j = i ; j * j <= n; j++) 
			if (arr[i] + arr[j] == n) {
				cout << "2\n"; return 0;
			}

	// 수 세 개 더해서 n되나 체크
	for (int i = 1; i * i <= n ; i++) 
		for (int j = i ; j * j <= n ; j++) 
			for (int k = j ; k * k <= n; k++) 
				if (arr[i] + arr[j] + arr[k] == n) {
					cout << "3\n"; return 0;
				}
	
	// 수 네 개 더해서 n되나 체크
	for (int i = 1; i * i <= n ; i++) 
		for (int j = i ; j * j <= n ; j++) 
			for (int k = j  ; k * k <= n ; k++) 
				for (int l = k ; l * l <= n ; l++) 
					if (arr[i] + arr[j] + arr[k] + arr[l] == n) {
						cout << "4\n"; return 0;
					}
	return 0;
}