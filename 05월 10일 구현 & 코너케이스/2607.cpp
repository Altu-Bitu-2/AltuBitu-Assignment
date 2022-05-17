#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26; // 알파벳 개수


// 알파벳별 등장 횟수 저장
vector <int> alphaMap(string str) {
	vector<int> result(SIZE, 0); // 알파벳 등장 횟수 저장해서 결과로 반환할 벡터
	for (int i = 0; i < str.size(); i++)
		result[str[i] - 'A']++; // 문자열 돌면서 나오는 알파벳 개수 기록함

	return result; // 결과 벡터 반환
}


int main() {

	int n, ans = 0; // 단어 개수, 정답
	string source, target; // 기준 문자열, 비교할 문자열

	cin >> n >> source; // 입력

	vector <int> source_alpha = alphaMap(source); // 첫 번째 단어에서 등장하는 알파벳 개수 세기
	while (--n) { // n개 비교하면서
		cin >> target; // target 입력받고

		int diff = 0; // 다른 문자의 개수
		vector<int> target_alpha = alphaMap(target); // 타겟 단어에서 등장하는 알파벳 개수

		for (int i = 0; i < SIZE; i++) // 두 단어의 차이
			diff += abs(source_alpha[i] - target_alpha[i]); // diff에 저장
		if (diff <= 1 || (diff == 2 && source.size() == target.size())) // 문자를 더하거나 빼거나 바꾸거나
			ans++; // 정답 개수 증가
	}

	cout << ans;

	return 0;
}