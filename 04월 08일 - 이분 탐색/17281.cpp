#include <iostream>
#include <vector>

using namespace std;
int n, ans;
vector<vector<int>> innings; // 이닝 결과 2차원 배열
vector<int> order(10, 0); // 타순
vector<bool> check(10, false); // 1-9번 선수 배치 여부 기록

// 각 루타마다 얻는 점수
int hitScore(int hit, vector<bool>& baseman) { // hit: 현재 공격으로 전진하는 칸 수
	int score = 0; // 점수 0으로 초기화
	for (int i = 3; i >= 0; i--) { // 3루부터 0루(홈)까지 반복문 돌면서 점수 계산하기
		if (!baseman[i]) { // 루에 주자가 없다면
			continue; // 다음으로 넘어가기
		}
		if (i + hit >= 4) { // i + hit이 4보다 크다면 1점 얻음
			score++; // 1점 추가
		}
		else { // i+ hit이 4보다 작은 경우 (전진해도 점수는 못 따는 경우)
			baseman[i + hit] = true; // i+hit번째 루에 주자 있다고 표시하기
		}
		baseman[i] = false; // 기존 주자를 이동시켰으므로 false로 바꾸기
	}
	if (hit == 4) { // 홈런 친 경우
		score++; // 1점 올리기
	}
	else {
		baseman[hit] = true; // 새로운 선수들 루에 도착
	}
	return score; // 얻은 점수 리턴
}

// 현재 배치의 점수 구하는 함수
int calcScore() {
	int score = 0; // 총 점수
	int idx = 1; // 타순 저장된 order 인덱스 번호 
	for (int i = 0; i < n; i++) { // i: 이닝
		vector<bool> baseman(4, 0); // 각 루수마다 선수가 있는지
		int out = 0; // 아웃 선수 카운트
		while (out < 3) { // 쓰리아웃이 될 때까지 반복
			int state = innings[i][order[idx++]]; // 현재 선수의 공격 상태
			if (idx == 10) { // 10번 타순이면
				idx = 1; // 처음 1번 타순으로 만들기
			}
			if (state == 0) { // 점수 내지 못하면 
				out++; // 아웃카운트 하나 증가
			}
			else {
				score += hitScore(state, baseman); // 점수를 내는 경우, score에 점수 계산해서 더해주기
				
			}
		}
	
	}
	return score;
}

// 가능한 배치 모두 구하기
void makeArray(int cnt) { // cnt: 타자 순서
	if (cnt == 4) { // 4번 타자는 정해져 있으므로
		makeArray(cnt + 1); // 다음 타자로 넘어가기
		return;
	}
	if (cnt == 10) { // 9번 타자까지 정해짐 (기저조건)
		int score = calcScore(); // 점수 계산
		ans = max(ans, score); // 최댓값으로 갱신
		return; // 종료
	}
	for (int i = 2; i <= 9; i++) { // 2번~9번 타자까지 반복문을 돌면서
		if (!check[i]) { // 만약 배치가 되지 않은 타자라면
			order[cnt] = i; // cnt 타순에 현재 타자 i 기록하기
			check[i] = true; // i번 선수 순서 정해짐
			makeArray(cnt + 1); // 다음 타자
			check[i] = false; // 백트래킹, 되돌리기
		}
	}
}

/*
 구현 + 부르트 포스, 백트래킹 문제
 1. 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (부르트 포스, 백트래킹)
 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
*/

int main() {
	cin >> n;
	innings.assign(n, vector<int>(10, 0)); // n x 10인 벡터를 0으로 초기화함
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++)
			cin >> innings[i][j]; // 이닝 결과 입력 받기
	}

	order[4] = 1; // 4번 타자는 1번 선수
	check[1] = true; // 1번 선수는 순서 정해짐
	makeArray(1); // 1번 선수부터 배치 시작

	cout << ans;
	return 0;
}
