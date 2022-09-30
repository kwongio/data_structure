#include <iostream>
#include "node.h"
#include "polonomial.h"

using namespace std;


int main() {

    polynomial p;
    node first(1.0, 0);
    node second(-0.9, 1);
    node third(0.5, 2);
    node forth(0.3, 3);
    p.list_head_insert(&first);
    p.list_head_insert(&second);
    p.list_head_insert(&third);
    p.list_head_insert(&forth);
    cout << "출력해야지" << endl;
    cout << p.list_length() << endl;


    return 0;

}

