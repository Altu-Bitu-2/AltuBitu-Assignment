#include <iostream>
#include <deque>

using namespace std;

// k개의 수 지워서 큰 수 만드는 함수
string findMaxNumber(string number, int l, int k) {
	deque<char> dq; // k개의 수를 지운 숫자를 저장할 덱

	int cnt = 0; // 지운 수의 개수, 0으로 초기화
	for (int i = 0; i < l; i++) { // number의 길이만큼 for문을 돌면서
		while (cnt < k && !dq.empty() && dq.back() < number[i]) { 
			// 지운 수의 개수가 k보다 작고, 덱이 비어있지 않고 덱에 직전에 입력한 숫자보다 number[i]가 더 큰 경우
			dq.pop_back(); // 덱 뒤에 있는 문자 지우기
			cnt++; // 지웠으니까 cnt 개수 하나 증가시키기
		}
		dq.push_back(number[i]); // 이번 입력 삽입
	
	}
	string answer = ""; // 정답으로 리턴해줄 문자열
	for (int i = 0; i < l - k; i++) // 정답은 l-k개의 자릿수니까 l-k만큼 for문을 돌면서
		answer += dq[i]; // answer에 dq[i]를 붙여주기

	return answer; // 정답 반환

}


int main() {
	int n, k; // n:전체 자릿수, k:지우는 수의 개수
	string number; // n자리 숫자

	cin >> n >> k >> number; // 입력 받기

	cout << findMaxNumber(number, number.length(), k); // 연산 & 출력

	return 0;
}