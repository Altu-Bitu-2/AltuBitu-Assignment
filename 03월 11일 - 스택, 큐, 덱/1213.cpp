#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[27] = {0};
	int cnt = 0;
	string name;
	char middle_char = '0';

	cin >> name; // 이름 입력받기
	map<char, int> m; // 알파벳, 출현횟수
	for (int i = 0; i < name.size(); i++) {
		if (arr[name[i] - 'A'] == 0) arr[name[i] - 'A']++;
		else arr[name[i] - 'A'] = 0, m[name[i]]++;
	}

	// 남은게 1개 이상이면
	for (int i = 0; i < 26; i++)
		if (arr[i] == 1) {
			cnt++;
			middle_char = (i +'A');
		}
	
	string sub_str="";
	
	for (auto i : m) // map에 있는거 꺼내오기
		while (i.second--)  
			sub_str += i.first;
		
	if (cnt > 1)
		cout << "I'm Sorry Hansoo";
	else if (cnt == 1){
		cout << sub_str << middle_char;
		reverse(sub_str.begin(), sub_str.end());
		cout << sub_str << "\n";
	}
	else {
		cout << sub_str;
		reverse(sub_str.begin(), sub_str.end());
		cout << sub_str << "\n";
	}
	
	return 0;
}