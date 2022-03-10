#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str, sub_str;
	cin >> str;
	 
	set<string> s;
	for (int i = 0; i <= str.size(); i++) {
		sub_str = ""; 
		for (int j = i; j < str.size() ; j++) { 
			sub_str += str[j];
			s.insert(sub_str);
		}
	}
	cout << s.size() << "\n";

	return 0;
}