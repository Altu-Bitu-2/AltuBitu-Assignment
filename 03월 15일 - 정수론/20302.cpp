#include <iostream>

using namespace std;
const int MAX = 1000001;
int p[MAX]; // 소인수가 나온 횟수 저장하는 배열

// 곱하기 다음 숫자 소인수분해하는 함수
void product_fac(int n) {
	for (int i = 2; i * i <= n;i++)
		while (n % i == 0) n /= i, p[i]++;
	if (n > 1) p[n]++;
}

// 나누기 다음 숫자 소인수분해하는 함수
void divide_fac(int n) {
	for (int i = 2; i * i <= n;i++)
		while (n % i == 0) n /= i, p[i]--;
	if (n > 1) p[n]--;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char sign;
	int n, first, num, flag=0, stop=0;
	cin >> n >> first;

	if (first < 0) first *= -1;
	else if (first == 0) flag = 1;
	if(first) product_fac(first); // 첫번째 수 소인수분해

	while (--n) {
		cin >> sign >> num;
		if (num < 0) num *= -1; // 양수로 만들기
		else if (num == 0) flag = 1; // 0인지 확인
		if (sign == '/') divide_fac(num);
		else if(num) product_fac(num);
	}

	if (flag == 1)
		cout << "mint chocolate" << "\n";
	else { // 음수가 있나 확인
		for (int i = 0; i <= MAX; i++)
			if (p[i] < 0) stop = 1;
		if (stop == 1) cout << "toothpaste" << "\n";
		else cout << "mint chocolate" << "\n";
	}

	return 0;
}