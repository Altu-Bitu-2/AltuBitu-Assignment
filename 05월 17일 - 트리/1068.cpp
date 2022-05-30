#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // 2차원 tree 벡터

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int& erase_node) { 
    if (node == erase_node) { // 현재 노드가 지울 노드라면 
        return 0; // 더이상 탐색하지 않고 0 리턴
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1; // 비어있거나 size가 1인데 지울 노드가 들어있다면 리프 노드이므로 1 리턴
    }
    int cnt = 0; // 초기화
    for (int i = 0; i < tree[node].size(); i++) { // 모든 자식들에 대해 
        cnt += eraseLeafCnt(tree[node][i], erase_node); // dfs 방식으로 탐색하기 
    }
    return cnt; // 총 리프 노드의 개수 리턴
}

int main() {
    int n, par, root, erase_node; // 노드 개수, 입력 받을 때 사용하는 부모 노드, 루트, 지울 노드

    //입력
    cin >> n; // n 입력 받기
    tree.assign(n, vector<int>(0)); // tree 벡터 0으로 초기화하기
    for (int i = 0; i < n; i++) { // n 만큼 반복하면서 par 입력받기
        cin >> par; // i번째 노드의 부모 노드 입력 받기
        if (par == -1) { // par가 -1이라면
            root = i; // i는 루트 노드
            continue; // 다음으로 넘어가기
        }
        tree[par].push_back(i); // 부모 벡터에 i(자식) 추가하기
    }
    cin >> erase_node; // 지울 노드 입력받기

    cout << eraseLeafCnt(root, erase_node); // 연산 & 출력
    return 0;
}