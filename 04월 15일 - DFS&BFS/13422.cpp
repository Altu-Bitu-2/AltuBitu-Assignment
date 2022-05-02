#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++) { // m개 만큼
        money += house[i]; // 돈 훔치기
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; // 가짓 수 리턴
    }
    for (int i = m; i < n + m - 1; i++) {
        money -= house[i - m]; // 한 칸 이동
        money += house[i % n]; // 한 칸 이동
        if (money < k) { // 훔칠 수 있는 경우
            ans++; // 가짓 수 1 더하기
        }
    }
    return ans; // 가짓 수 리턴
}


int main() {
    int t, n, m, k; // 테스트 케이스, 집 개수, 도둑이 훔칠 연속된 집 개수, 방범 장치 작동하는 최소 돈의 양

    cin >> t; // t 입력받기
    while (t--) { // 각 테스트 케이스에 대해
        cin >> n >> m >> k; // 입력받기
        vector<int> house(n, 0); // 각 집의 돈 저장할 벡터 선언
        for (int i = 0; i < n; i++) {
            cin >> house[i]; // 돈 입력받기
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}