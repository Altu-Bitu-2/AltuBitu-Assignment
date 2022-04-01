#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
int n1[10001], n2[10001];
vector<int>ans;

void add() {
	for (int i = a.size(); i > 0; i--) { // 배열 끝부터 덧셈
		int sum = n1[i] + n2[i];
		if (sum >= 10) {
			n1[i - 1]++; // 앞자리수에 1 올리기
			sum -= 10;
		}
		ans.push_back(sum);
	}
}

void print() {
	// n1[0]은 두번째 자리수 들의 합이 10보다 크면 1 넘어 옴
	if (n1[0] != 0) cout << "1";
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
}

void input() {
	cin >> a >> b;

	// 더 긴게 a
	if (a.size() < b.size())
		swap(a, b);

	// int 배열에 저장
	for (int i = 1; i <= a.size(); i++)
		n1[i] = a[i - 1] - '0';
	for (int i = 1; i <= b.size(); i++)
		n2[i + (a.size() - b.size())] = b[i - 1] - '0';
}

int main() {

	input();
	add();
	print();

	return 0;
}
