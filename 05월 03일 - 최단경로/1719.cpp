#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e7; 
typedef pair<int, int> ci;

void floydWarshall(int n, vector<vector<ci>>& graph) { 
	for (int k = 1; k <= n; k++) { // k: 중간 정점
		for (int i = 1; i <= n; i++) { // i: 출발 정점
			for (int j = 1; j <= n; j++) { // j: 도착 정점
				// 중간에 k를 거쳐서 i에서 j로 갈 때의 비용
				int cost = graph[i][k].first + graph[k][j].first;
				if (graph[i][j].first > cost) {
					graph[i][j].first = cost; // 최소 비용 갱신		
					if (i != k) graph[i][j].second = graph[i][k].second; // 거쳐갈 정점 갱신
				}
			}
		}
	}
}

int main() {
	int n, m, a, b, c;

	cin >> n >> m;
	vector<vector<ci>> graph(n + 1, vector<ci>(n + 1, {INF, 0})); // first: 거리, second: 제일 먼저 이동해야 하는 집하장 번호

	for (int i = 1; i <= n; i++) {
		graph[i][i] = { 0, 0 }; // 자기 자신과의 거리
	}

	while (m--) {
		cin >> a >> b >> c;
		graph[a][b] = {c, b};
		graph[b][a] = {c, a};
	}

	floydWarshall(n, graph);

	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) {
			if (graph[i][j].second == 0) cout << "- ";
			else cout << graph[i][j].second << ' ';
		}
		cout << '\n';
	}


	return 0;
}