#include <iostream>
#include <map>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	string clothes_name, clothes_type;
	cin >> t;
	while (t--) {
		int answer = 1;
		map<string, int> m;
		cin >> n;
		for (int i = 0; i < n ; i++) {
			cin >> clothes_name >> clothes_type;
			m[clothes_type]++;
		}
		for (auto i = m.begin(); i != m.end(); i++) 
			answer *= (i -> second + 1 ); 
		
		cout << answer-1 << "\n";
	}

	return 0;
}