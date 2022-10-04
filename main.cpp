#include <iostream>
#include "node.h"
#include "polonomial.h"

using namespace std;


int main() {
    // TODO 구현한 모든 함수 생성자 및 연산자 올바르게 작동하는지 확인하기 호출 전후 현재 다항식의 내용 표시
    polynomial p;
    polynomial copy;
    node *first = new node(1.0, 1);
    node *second = new node(2.0, 2);
    node *third = new node(3.0, 3);
    node *forth = new node(4.0, 4);
    p.list_head_insert(first);
    p.list_insert(second, 1);
    p.list_insert(third, 2);
    p.list_insert(forth, 3);
    copy = p;


    return 0;

}

