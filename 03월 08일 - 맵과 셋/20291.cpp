#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

vector <string> split(string str, char delimiter) {
	istringstream iss(str); 
	string buffer; 

	vector<string> result;

	while (getline(iss, buffer, delimiter))
		result.push_back(buffer);

	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;
	cin >> n;

	map<string, int> m;

	while (n--) {
		cin >> s;
		vector<string> result = split(s, '.');
		m[result[1]]++;
	}

	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->first << " " << i->second << "\n";
        
	return 0;
}