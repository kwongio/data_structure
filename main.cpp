#include <iostream>
#include "node.h"
#include "polonomial.h"

using namespace std;



int main() {
    // TODO 구현한 모든 함수 생성자 및 연산자 올바르게 작동하는지 확인하기 호출 전후 현재 다항식의 내용 표시
    polynomial p;
    polynomial copy;
    node first(1.0, 0);
    node second(-0.9, 1);
    node third(0.3, 2);
    node forth(0.5, 3);
    p.list_head_insert(&first);
    p.list_insert(&second, 1);
    p.list_insert(&third, 2);
    p.list_insert(&forth, 3);

    copy.list_copy(&p);
    for (int i = 0; i < p.list_length(); ++i) {
        cout << "coefficients" << p.list_locate(i)->coefficients << endl;
        cout << "exponents" << p.list_locate(i)->exponents << endl;

    }
    cout << "" << endl;
    cout << "list_head_remove " << endl;
    cout << "" << endl;
    p.list_head_remove();


    for (int i = 0; i < p.list_length(); ++i) {
        cout << "coefficients" << p.list_locate(i)->coefficients << endl;
        cout << "exponents" << p.list_locate(i)->exponents << endl;

    }

    p.list_remove(2);
    cout << "" << endl;
    cout << "list_remove " << endl;
    cout << "" << endl;

    for (int i = 0; i < p.list_length(); ++i) {
        cout << "coefficients" << p.list_locate(i)->coefficients << endl;
        cout << "exponents" << p.list_locate(i)->exponents << endl;

    }


    cout << "" << endl;
    cout << "list_clear" << endl;
    cout << "" << endl;
    p.list_clear();

    for (int i = 0; i < p.list_length(); ++i) {
        cout << "coefficients" << p.list_locate(i)->coefficients << endl;
        cout << "exponents" << p.list_locate(i)->exponents << endl;

    }



    for (int i = 0; i < copy.list_length(); ++i) {
        cout << "coefficients" << copy.list_locate(i)->coefficients << endl;
        cout << "exponents" << copy.list_locate(i)->exponents << endl;

    }



    return 0;

}

