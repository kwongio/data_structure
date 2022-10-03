//
// Created by rldh1 on 2022-09-25.
//

#ifndef UNTITLED5_SUB_H
#define UNTITLED5_SUB_H

#endif //UNTITLED5_SUB_H


class node {
public:
    double coefficients;
    unsigned exponents;
    node *next;

    node() {
        coefficients = 0;
        exponents = 0;
        next = nullptr;
    }

    node(double coefficients, int exponents) : exponents(exponents), coefficients(coefficients), next(nullptr) {

    }
};
