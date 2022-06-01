#include <iostream>
#include <vector>
using namespace std;

vector <int> parent;

int findParent(int node) {
	if (parent[node] < 0)
		return node; // 루트 노드인 경우 리턴
	return parent[node] = findParent(parent[node]); // 부모 재귀 호출
}

void unionInput(int x, int y) {
	int xp = findParent(x); // 부모 찾기
	int yp = findParent(y); // 부모 찾기

	if (xp == yp) return; // 같은 집합에 속해 있으므로 리턴
	if (parent[xp] < parent[yp]) { // 부모 숫자가 작은쪽으로 합치기
		parent[xp] += parent[yp];
		parent[yp] = xp; // yp의 부모에 xp 넣기
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int liarParty(vector<int>& parties) {
	int cnt = 0; // 거짓말 할 수 있는 파티 숫자
	for (int i = 0; i < parties.size(); i++) {
		if (findParent(parties[i] != findParent(0))) // 각 파티에서 한 사람만 저장해 둔 뒤 마지막에 거짓말 여부 한 번에 판단함
			cnt++; // 진실 아는 사람 루트가 0이므로, 해당 사람의 루트가 0이 아니면 거짓말 할 수 있음
	}
	return cnt;
}


int main() {
	int n, m;
	cin >> n >> m; // 사람의 수, 파티의 수
	
	parent.assign(n + 1, -1); 

	int init, p;
	cin >> init;
	while (init--) { // 진실을 아는 사람들
		cin >> p;
		unionInput(0, p); // p를 루트 정점이 0인 집합으로 합치기
	}

	int cnt, first_person, person; 
	vector<int> parties; // 첫 번째 사람만 기록
	while (m--) {
		cin >> cnt >> first_person; // 파티 사람 숫자, 첫번째 사람 입력받기

		// 연산
		parties.push_back(first_person); // 파티 정보로 각 파티의 첫번째 사람만 저장
		while (--cnt) { // 앞에서 한 명 입력받았으므로 --cnt
			cin >> person; // 입력
			unionInput(first_person, person); // 첫번째 사람이랑 입력받은 사람 한 집합으로 합치기
		}
	}

	// 연산&출력
	cout << liarParty(parties);

	return 0;
}