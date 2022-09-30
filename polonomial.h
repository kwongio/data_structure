//
// Created by rldh1 on 2022-09-30.
//

#ifndef UNTITLED5_POLONOMIAL_H
#define UNTITLED5_POLONOMIAL_H

#endif //UNTITLED5_POLONOMIAL_H

#include <iostream>
#include "list"

using namespace std;

class polynomial {
private:
    node *head;
    size_t length;
public:
    polynomial() {
        head = nullptr;
        length = 0;
    };

    polynomial(double a0) {

    };

    polynomial(const polynomial &source) {
        head = source.head;
        length = source.length;
    };

    ~polynomial() {
        list_clear();
        delete head;
    }

    size_t list_length() const;

    node* list_search(node *item);

    node* list_locate(int index);

    void list_insert(node *newItem, int index);

    void list_head_insert(node *newItem);

    void list_head_remove();

    void list_remove(int index);

    void list_clear();

    void list_copy(polynomial *copy);

    node *getNode(int index);

    bool isEmpty();

};

size_t polynomial::list_length() const {
    return length;
}

void polynomial::list_head_insert(node *newItem) {
    newItem->next = head->next;
    head->next = newItem;
    head = newItem;
    length++;
}

void polynomial::list_insert(node *newItem, int index) {
    if (!isEmpty() && index >= 0 && index <= length - 1) {
        node *preNode = getNode(index - 1);
        newItem->next = preNode->next;
        preNode->next = newItem;
        length++;
    }

}

node *polynomial::getNode(int index) {
    if (!isEmpty() && index >= 0 && index <= length - 1) {
        node *curr = head;
        for (int i = 0; i <= index; ++i) {
            curr = curr->next;
        }
        return curr;
    }
    return nullptr;

}

bool polynomial::isEmpty() {
    return length == 0;
}

void polynomial::list_clear() {
    for (int i = 0; i < length; ++i) {
        list_remove(i);
    }
    length = 0;
    head = nullptr;
}

void polynomial::list_head_remove() {
    node *removeNode = head;
    head = head->next;
    delete removeNode;
}

void polynomial::list_remove(int index) {
    if (!isEmpty() && index >= 0 && index <= length - 1) {
        node *preNode = getNode(index - 1);
        node *removeNode = preNode->next;
        preNode->next = removeNode->next;
        delete removeNode;
    }
}

void polynomial::list_copy(polynomial *copy) {
    list_clear();
    head = copy->head;
    length = copy->length;

}

node *polynomial::list_locate(int index) {
    if (isEmpty() || index < 0 || index >= length) {
        return nullptr;
    }
    node* currNode = head;
    for (int i = 0; i <= index; ++i) {
        currNode = currNode->next;
    }
    return currNode;
}

node *polynomial::list_search(node *item) {

    node* currNode = head;
    for (int i = 0; i < length; ++i) {
        currNode = currNode->next;
        if (currNode->exponents == item->exponents && currNode->coefficients == item->coefficients) {
            return currNode;
        }
    }
    return nullptr;
}




