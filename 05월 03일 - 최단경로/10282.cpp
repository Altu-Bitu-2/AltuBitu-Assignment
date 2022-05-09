#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e8;

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
	vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장

	priority_queue<ci, vector<ci>, greater<>> pq; // first: 시작점으로부터의 거리, second: 정점

	// 시작 정점 초기화
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int weight = pq.top().first; // 현재 정점까지의 경로값
		int node = pq.top().second; // 현재 탐색하려는 정점
		pq.pop();

		if (weight > dist[node]) { // 이미 작은 값으로 기록되어 있으므로 넘어감
			continue;
		}
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = weight + graph[node][i].second;
			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}	
		}
	}
	return dist;
}
int main() {
	int t, v, e, k, a, b, w;

	cin >> t;

	while (t--) {
		cin >> v >> e >> k;
		vector<vector<ci>> graph(v + 1, vector<ci>(0)); // 인접 리스트

		while (e--) {
			cin >> a >> b >> w;
			graph[b].push_back({ a, w }); // a 노드에서 b 노드까지 w 초
		}

		vector<int> dist = dijkstra(k, v, graph);

		int computer = 0, time = 0;
		for (int i = 1; i <= v; i++) {
			if (dist[i] != INF) {
				computer++;
				time = max(time, dist[i]);
			}
		}
		cout << computer << ' ' << time << '\n';
	}
}