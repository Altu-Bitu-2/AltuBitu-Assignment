#include <iostream>
#include <algorithm>
using namespace std;

long long dist[100000], oil[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	long long price=0, cur_price=0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) 
		cin >> dist[i]; // 거리 입력
	
	for (int i = 0; i < n;i++) 
		cin >> oil[i]; // 기름값 입력
	
	cur_price = oil[0]; 
	price += cur_price * dist[0]; // 한 칸은 가야 함

	for(int i =1 ; i<n-1 ; i++){
		cur_price = min(cur_price, oil[i]); // 최소 가격으로 갱신
		price += cur_price * dist[i]; 
	}

	cout << price << "\n";


	return 0;
}