#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;
	cin >> n;

	map<string, int> m;

	while (n--) {
		cin >> s;
		int loc = s.find('.');
		string result = s.substr(loc + 1);
		m[result]++;
	}

	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->first << " " << i->second << "\n";
	return 0;
}
