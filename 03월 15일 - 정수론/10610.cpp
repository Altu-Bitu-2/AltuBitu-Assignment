#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int flag = 0, sum = 0;
	string s; 
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') flag = 1; 
		sum += (s[i] - '0');
		arr[i] = (s[i] - '0');
	}
    
	if (flag == 0)
		cout << "-1\n";
	else {
		if (sum % 3 == 0) { // 3의 배수, 정렬
			sort(arr, arr + s.length(), greater<>());
			for (int i = 0; i < s.length(); i++)
				cout << arr[i];
		}
		else cout << "-1\n";
	}

	return 0;
}