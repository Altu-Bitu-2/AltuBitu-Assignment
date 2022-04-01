#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 모든 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) {
    while (!ground.empty()) { // 그라운드에 남은 카드가 없을 때까지 반복
        deck.push_back(ground.back()); // 그라운드의 뒤에 있는 카드를 덱으로 이동
        ground.pop_back(); // 그라운드 뒤에 있는 카드 하나 pop함
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
    bool turn = false; //도도부터 시작

    while (m--) {
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front();
        ground[turn].push_front(card); // 그라운드 위에 카드 올려놓기
        deck[turn].pop_front(); // 덱 위에 있는 카드 한 장 제거

        if (deck[turn].empty()) { // 덱이 비어있다면 즉시 종료하기
            break;
        }

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5) { // 5 카드가 나온 경우
            bell = 0; // 수연이가 종을 침 (0:수연, 1: 도도)
        }
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) { 
			// 둘 다 그라운드가 비어있지 않고 현재 뽑은 카드와 상대 그라운드에 나와 있는 카드의 합이 5인 경우 
            bell = 1; // 도도가 종을 침
        }

        if (bell != -1) { // 도도나 수연이가 종을 친 경우
            moveCard(deck[bell], ground[!bell]); // 상대의 그라운드에 있는 카드를 자신의 덱으로 옮기기
            moveCard(deck[bell], ground[bell]); // 자신의 그라운드에 있는 카드를 자신의 덱으로 옮기기
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size()); // 덱에 남아 있는 카드 개수 반환
}

/**
 * [숫자 할리갈리 게임] - 시뮬레이션 문제
 * - 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 *
 * 1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
 * 2. 누군가의 카드 덱이 비는 즉시 게임 종료
 * 3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
 */

int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2); // 플레이어가 2명이므로 덱 2개, 그라운드 2개 선언

    cin >> n >> m; // 도도 카드 개수, 수연 카드 개수
    while (n--) {
        cin >> num1 >> num2; // 도도 카드, 수연 카드 
        deck[0].push_front(num1); // 도도 덱에 카드 넣기, 아래 위치한 카드부터 주어지므로 덱의 앞에서부터 넣기
        deck[1].push_front(num2); // 수연 덱에 카드 넣기
    }

    pair<int, int> result = playGame(m, deck, ground); // 게임한 후, 남아 있는 덱의 사이즈 리턴하는 함수 

    if (result.first == result.second) { // 남아 있는 카드 수가 같다면 
        cout << "dosu\n"; // 비김
    }
    else if (result.first > result.second) { // 남아 있는 도도 카드가 더 많다면 
        cout << "do\n"; // 도도가 이김
    }
    else if (result.first < result.second) { // 남아 있는 수연 카드가 더 많다면 
        cout << "su\n"; // 수연이가 이김
    }
    return 0;
}