#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g; // g는 100,000보다 작거나 같은 자연수
	cin >> g;
	vector<ll> v; // 정답 몸무게 저장할 벡터

	// 투 포인터 두 가지 방법 중 같은 쪽에서 시작해서 올라가는 방법 선택
	ll l = 1, r = 2; // r= 현재 몸무게, ㅣ= 이전 몸무게
	int flag = 0;
	while (1) {
		ll tmp = r * r - l * l; 
		if (r - l == 1 && tmp > g) { 
			// r이랑 l이 1 차이 나고, tmp > g라면 그 이후의 수는 모두 tmp > g이므로 더 이상 검사할 필요 없음
			break;
		}
		if (tmp == g) {
			v.push_back(r); // 현재 몸무게 넣기
			if (r - l == 1) { // 둘 차이가 1인지 검사
				flag = 1; // 1이라면 종료하기 위해 flag=1로 설정
			}
			if (flag == 1) break; // 종료
			l++; // 다음 몸무게 찾기 위해 l 증가시킴
		}
		else if (tmp > g)
			l++;
		
		else r++; // tmp < g 라면 tmp를 증가시켜야 하므로 r++ 함
	}
	if (v.empty()) // 벡터가 비어있다면
		cout << "-1\n";
	else { // 비어있지 않다면
		for (auto i : v) // 정답 출력
			cout << i << "\n";
	}

	return 0;
}