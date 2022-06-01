#include <iostream>
using namespace std;

int parent[500001];
#define MAX 1000001

int findParent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findParent(parent[node]);
}

int merge(int n1, int n2) { // 합치고 사이클 여부 리턴하는 함수
	n1 = findParent(n1);
	n2 = findParent(n2);

	if (n1 != n2) { // 부모가 다르면 작은쪽으로 합치기
		if (n1 > n2)
			swap(n1, n2); 
		parent[n2] = n1; 
		return 0; // 사이클 없으면 0
	}
	return 1; // 사이클 있으면 1 리턴
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, ans = MAX, result = 0, cnt=0;
	cin >> n >> m;
	int d1, d2; // 점1, 점2

	for (int i = 0; i < n; i++)
		parent[i] = i; // 자기 자신을 부모로 가리키도록 초기화

	for(int i =1 ; i<=m ; i++) { // i: 인덱스
		cin >> d1 >> d2;
		d1 = findParent(d1);
		d2 = findParent(d2);
		result = merge(d1, d2);
		if (result == 1) ans = min(ans, i); // min 값으로 갱신해서 최초 사이클 만들어진 시점 기록
		
		else cnt++;
	}

	// m번 다 0 나오면 종료 안 된 상태
	if (cnt == m) cout << "0\n";
	else cout << ans << '\n';

	return 0;
}