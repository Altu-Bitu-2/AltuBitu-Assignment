#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> ci; // 편의상 pair<int,int>를 ci로 이름 붙여서 사용

// 필요 강의실 수를 구하는 함수
int arrayRoom(int n, vector<ci> lec) {
	priority_queue<int, vector<int>, greater<>> pq; // 종료 시간을 저장하는 우선순위 큐
	pq.push(-1); // 처음 인덱스 에러 피하기 위해 음수 값 삽입 (첫번째 강의 때 갱신될 값)

	for (int i = 0; i < n;i++) {
		if (lec[i].first >= pq.top()) { // 현재 강의의 시작 시간이 가장 빨리 끝나는 강의실의 종료시간보다 크다면 (늦게 시작한다면) 같은 강의실 쓸 수 있음
			pq.pop(); // 종료시간 갱신해주기 위해 pop하기
		}
		pq.push(lec[i].second); // 기존 강의실 정보 갱신 or 새로운 강의실 정보 저장
	}
	return pq.size(); // 강의실 개수 반환
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 강의실 수를 최소로 하기 위해서 현재 사용하는 강의실 중 가장 빨리 끝나는 강의실에
	// 가장 먼저 시작하는 강의실을 배치해야 함
	int n; // 강의 개수

	cin >> n; // 강의 개수 입력 받기
	vector<ci> lec(n, ci(0, 0)); // n개 pair<0,0>으로 초기화

	for (int i = 0; i < n; i++) {
		cin >> lec[i].first >> lec[i].second; // 시작시간, 종료시간
	}
	sort(lec.begin(), lec.end()); // 먼저 시작하는 순으로 정렬

	cout << arrayRoom(n, lec) << '\n'; // 출력
	return 0;
}