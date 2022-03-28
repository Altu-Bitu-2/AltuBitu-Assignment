#include <iostream>
#include <deque>
using namespace std;

deque <int> dodo_deque, suyeon_deque, dodo_ground, suyeon_ground;

void isCard5() {
	if ((!suyeon_ground.empty() && suyeon_ground.front() == 5) || (!dodo_ground.empty() && dodo_ground.front() == 5)) {
		while (!suyeon_ground.empty()) {
			dodo_deque.push_back(suyeon_ground.back());
			suyeon_ground.pop_back();
		}
		while (!dodo_ground.empty()) {
			dodo_deque.push_back(dodo_ground.back());
			dodo_ground.pop_back();
		}
		//cout << "2) dodo deque: " << dodo_deque.size() << "\n";
		//cout << "2) suyeon deque: " << suyeon_deque.size() << "\n";
	}
}

void isCardSum5() {
	if (!suyeon_ground.empty() && !dodo_ground.empty() && (dodo_ground.front() + suyeon_ground.front() == 5)) { // 수연 종 침
		while (!dodo_ground.empty()) {
			suyeon_deque.push_back(dodo_ground.back());
			dodo_ground.pop_back();
		}
		while (!suyeon_ground.empty()) {
			suyeon_deque.push_back(suyeon_ground.back());
			suyeon_ground.pop_back();
		}
		//cout << "1) dodo deque: " << dodo_deque.size() << "\n";
		//cout << "1) suyeon deque: " << suyeon_deque.size() << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, dodo, suyueon;
	cin >> n >> m; // 카드 개수, 게임 진행 횟수

	for (int i = 0; i < n; i++) {
		cin >> dodo >> suyueon;
		dodo_deque.push_front(dodo);
		suyeon_deque.push_front(suyueon);
	}

	// 둘 중에 하나라도 비면 종료
	for(int i =1 ; i <= m ; i++) {
		int flag = 0;

		// 도도 먼저 깜
		if (!dodo_deque.empty()) { // 1장은 들어있어야 함
			dodo = dodo_deque.front(); // 제일 위 카드 하나깜
			dodo_deque.pop_front(); // 카드 한장씩 제거
			dodo_ground.push_front(dodo); // 그라운드에 내려놓을 때 위로 올리기
		}
		if (dodo_deque.empty()) flag = 1;
		if (flag == 1) break;
		isCard5(); // 5 카드 있는지 검사
		isCardSum5(); // 합이 5되는지 검사

		// 수연이 깜
		if (!suyeon_deque.empty()) {
			suyueon = suyeon_deque.front(); // 수연 제일 위 카드
			suyeon_deque.pop_front();
			suyeon_ground.push_front(suyueon);
		}
		if (suyeon_deque.empty()) flag = 1;
		if (flag == 1) break;
		isCard5(); // 5 카드 있는지 검사
		isCardSum5(); // 합이 5되는지 검사
	}
	
	//cout << "dodo deque: " << dodo_deque.size() << "\n";
	//cout << "suyeon deque: " << suyeon_deque.size() << "\n";
	
	if (dodo_deque.size() == suyeon_deque.size()) cout << "dosu\n";
	else dodo_deque.size() > suyeon_deque.size() ? cout << "do\n" : cout << "su\n";

	return 0;
}
