#include <iostream>

using namespace std;

struct node_info { // 노드 구조체
    int data; // 데이터
    node_info *left; // 왼쪽 서브트리 포인터 
    node_info *right; // 오른쪽 서브트리 포인터
};

node_info *makeTree(node_info *node, int data) { // node, 들어갈 데이터
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; // data 넣기
        node->left = node->right = NULL; // NULL로 초기화하기
    } else if (node->data > data) { // node의 데이터가 현재 들어갈 데이터보다 크다면
        node->left = makeTree(node->left, data); //왼쪽 서브트리로 이동
    } else if (node->data < data) { // data가 node 데이터보다 크다면
        node->right = makeTree(node->right, data); // 오른쪽 서브트리로 이동
    }
    return node; // node 생성한 후 리턴하기
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) { // NULL이면 끝까지 왔다는 거니까 종료
        return;
    }
    postorder(node->left); // 왼쪽 서브트리로 이동
    postorder(node->right); // 오른쪽 서브트리로 이동
    cout << node->data << '\n'; // 가운데 순서로 순회
}

int main() {
    int input;

    //입력 & 연산
    node_info *root = NULL; // 루트 포인터
    while (cin >> input) { // 노드 입력 받으면서
        root = makeTree(root, input); // 트리에 입력으로 받은 노드 넣기
    }

    //출럭
    postorder(root);
    return 0;
}