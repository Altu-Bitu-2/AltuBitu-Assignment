#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 11;  // 수의 개수는 최대 11개
vector<int> num (SIZE + 1); // 숫자 저장
vector<int> expression(4); // 연산자 저장
const int INF_MAX = 1e9; // 가장 큰 값

int n; // 첫째 줄에 입력받는 n
int max_value = -INF_MAX, min_value = INF_MAX; // max는 연산에서 나온 큰 값으로 갱신될 수 있게 가장 작은 것 넣음

void backtracking(int cnt, int sum) { // cnt: 숫자 인덱스, sum: 현재인덱스까지 식 계산 결과
	if (cnt == n - 1) { // 마지막 숫자라면
		min_value = min(min_value, sum); // 최솟값 갱신
		max_value = max(max_value, sum); // 최댓값 갱신
		return; // 
	}
	int new_sum = 0; // 현재 연산자 포함해서 계산할 새로운 결과
	for (int i = 0; i < 4; i++) { // 0: +, 1:-, 2: x, 3: /
		if (expression[i]) { // i번째 연산자가 존재한다면
			expression[i]--; // i번째 연산자 하나 사용하기
			switch (i) { // i 값에 따라 조건 분기
			case 0: // i가 0이라면 + 의미함
				new_sum = sum + num[cnt + 1]; // 현재까지 연산 결과(sum)에 다음 숫자 더하기
				break;
			case 1: // x인 경우
				new_sum = sum - num[cnt + 1]; // 현재 연산 결과에 다음 숫자 빼기
				break;
			case 2: // +인 경우
				new_sum = sum * num[cnt + 1]; // 현재 연산 결과에 다음 숫자 곱하기
				break;
			case 3: // /인 경우
				new_sum = sum / num[cnt + 1]; // 현재 연산 결과에 다음 숫자 나누기
				break;
			
			}
			backtracking(cnt + 1, new_sum); // 다음 숫자로 넘어가기
			expression[i]++; // 백트래킹, 되돌리기
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); // 입출력 속도 향상

	cin >> n; // n 입력받기
	for (int i = 0; i < n; i++) // 숫자는 n개니까 반복문 n까지 돌면서
		cin >> num[i]; // 숫자 입력받기
	for (int i = 0; i < 4; i++) // 연산자는 4개니까 반복문 4번 돌면서
		cin >> expression[i]; // 연산자 입력받기

	backtracking(0, num[0]); // 0번 인덱스의 숫자에서 시작, 초기 식에는 첫 번째 숫자가 들어있음
	cout << max_value << '\n' << min_value; // 결과 출력

	return 0; // 종료
}