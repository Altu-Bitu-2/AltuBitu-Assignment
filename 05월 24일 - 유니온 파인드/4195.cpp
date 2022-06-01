#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAX = 200002;
int parent[MAX], setSize[MAX];

int findParent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findParent(parent[node]);
}

void merge(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);

	if (n1 != n2) { // 같은 집합이 아니면 합치기
		if (setSize[n1] < setSize[n2])
			swap(n1, n2); // 크기가 작은쪽으로 합치기
		parent[n2] = n1; // n2의 부모가 n1
		setSize[n1] += setSize[n2];
		setSize[n2] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n; // 친구 관계의 숫자
		string user1, user2;

		// 초기화
		for (int i = 0; i < MAX; i++) {
			parent[i] = i; // 자기 자신 부모로 가리킴
			setSize[i] = 1; // 친구 관계의 수 1로 초기화
		}

		map<string, int> name; // 이름-고유 인덱스 매핑
		int idx = 1;

		for(int i =0 ; i<n ; i++){
			cin >> user1 >> user2;
			if (name.count(user1) == 0)
				name[user1] = idx++; // 새로 나온 이름이면 인덱스 부여
			if (name.count(user2) == 0)
				name[user2] = idx++;

			// 루트 찾기
			int user1Parent = findParent(name[user1]);
			int user2Parent = findParent(name[user2]);

			if (user1Parent == user2Parent)
				cout << max(setSize[user1Parent], setSize[user1Parent]) << '\n';
			else {
				merge(user1Parent, user2Parent);
				cout << max(setSize[user1Parent], setSize[user2Parent]) << '\n';
			}
		}
	
	}

	return 0;
}