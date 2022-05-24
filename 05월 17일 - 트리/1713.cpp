#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const pair<int, ci> &c1, const pair<int, ci> &c2) {
    if (c1.second.first != c2.second.first) { // 추천 횟수가 다르다면
        return c1.second.first < c2.second.first; // 추천 횟수가 적은거 삭제
    }
    return c1.second.second < c2.second.second; // 가장 오래된 사진 삭제
}

int main() {
    int n, m, input;

    //입력 & 연산
    cin >> n >> m;
    map<int, ci> candidate; //first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) {
        cin >> input;
        //비어있는 사진틀이 없는 경우
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp)); // min_element 함수를 사용해서 조건에 만족하는 학생 지우기
        }
        //첫 게시라면
        if (candidate.find(input) == candidate.end()) {
            candidate[input].second = i; // 게시 시간 i 넣기
        }
        candidate[input].first++; //추천 횟수 증가
    }

    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
        cout << iter->first << ' '; // 학생 번호 출력
    }
    return 0;
} 