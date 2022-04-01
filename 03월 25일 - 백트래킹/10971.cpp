#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; // 비용 행렬
int n, ans = INF; // 최소 비용 저장 위해 미래 최댓값으로 초기화

// cnt: 순회한 도시 개수
// cur_city: 현재 방문한 도시
// cost: 현재 도시까지 순회하는데 소요된 비용

void backtracking(int cnt, int cur_city, int cost) { 
	if (cost >= ans) // cost가 ans보다 크면 최소비용은 아니므로 더 갈 필요 없어서 종료
		return;
	
	if (cnt == n) { // 종료 조건, n개 도시 순회하면 종료
		// 현재 도시에서 출발 도시(0)으로 다시 돌아올 수 있는지 확인
		if (matrix[cur_city][0] != 0) { // 돌아올 수 있다면
			ans = min(ans, cost + matrix[cur_city][0]); // 최솟값 갱신
		}
		return; // 종료
	}
	for (int i = 0; i < n; i++) { // cur_city에서 도시 i로 이동
		if (matrix[cur_city][i] && !visited[i]) { // cur_city에서 도시 i로 이동할 수 있고, 방문하지 않았다면 방문하기
			visited[i] = true; // 방문 표시
			// 백트래킹, i번째 도시 방문하기 cnt는 순회한 도시 개수니까 cnt+1 전달
			// cur_city: 방문할 도시에 i 넣어줌
			// cost: 지금까지의 cost + cur_city에서 도시 i까지 가는데 드는 비용
			backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
			visited[i] = false; // 되돌리기

		}
	}
}

// 한 사이클을 만들면 어떤 도시에서 시작하든 값은 같으므로 0번 도시에서부터 시작함

int main() {

	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); // 입출력 속도 향상

	cin >> n; // n 입력받기
	visited.assign(n, false); // 방문 배열 초기화
	matrix.assign(n, vector<int>(n, 0)); // matrix 인접행렬 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
			cin >> matrix[i][j]; // matrix 인접행렬 입력받기

	visited[0] = true; // 0번 도시에서 시작하므로 방문 표시
	backtracking(1, 0, 0); // 0번 도시에서 순회 시작
	
	cout << ans; // 값 출력
	return 0; // 종료
}