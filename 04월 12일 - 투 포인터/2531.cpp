#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 슬라이딩 윈도우 사이즈 = k

	int n, d, k, c;
	cin >> n >> d >> k >> c; // 접시 수, 초밥 종류 갯수, 연속 갯수, 쿠폰 번호
	vector <int> v(n+1);
	map <int, int> sushi; // 스시 번호, 개수
	for (int i = 0; i < n;i++) // 입력 받기
		cin >> v[i];
	int l = 0, r = k-1;
	
	sushi[c]++; // 쿠폰 개수 1 더하기
	for (int i = l; i <= r; i++) { // l부터 r까지 종류 계산하기
		sushi[v[i]]++; 
	}

	int answer = sushi.size(); // 처음 종류 개수

	for (int i = 1; i < n; i++) { // n-1 번 반복
		sushi[v[l]]--; // l번째 수 제거하고
		if (sushi[v[l]] <= 0) sushi.erase(v[l]); // 값이 0이나 음수라면 값 삭제
		l = (l + 1) % n; // l 인덱스 증가
		r = (r + 1) % n; // r 인덱스 증가
		sushi[v[r]]++; // r 번째 수 넣기
		sushi[c]++; // 쿠폰 넣기
		int tmp = sushi.size();
		answer = max(answer, tmp); // 최대 종류의 개수
	}

	cout << answer << '\n';
	return 0;
}