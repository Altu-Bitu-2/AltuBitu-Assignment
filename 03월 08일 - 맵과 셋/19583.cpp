#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int answer=0;
	string s, e, q, time, name;

	cin >> s >> e >> q; 

	set <string> before_list, after_list;
	
	while (!cin.eof()){ 
		cin >> time >> name;
		if (time <= s)
			before_list.insert(name);
		else if (time >= e && time <= q) 
			after_list.insert(name); 
	}

	for (auto i: after_list) 
		if (before_list.find(i) != before_list.end())
			answer++;
	
	cout << answer << "\n";

	return 0;
}