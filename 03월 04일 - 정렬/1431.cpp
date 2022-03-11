#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int addNumber(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i])) sum += (s[i] - '0');
	return sum;
}
bool cmp(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();

	int sum_a = addNumber(s1);
	int sum_b = addNumber(s2);
	
	if (sum_a != sum_b)
		return sum_a < sum_b;

	return s1 < s2;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	string arr[51];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	return 0;
}
