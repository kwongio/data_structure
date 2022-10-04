#include <iostream>

using namespace std;

class polynomial {

public:
    node *head = nullptr;
    int size = 0;

    polynomial() {
        head = nullptr;
        size = 0;
    };

    polynomial(double a0) {
        head = new node(a0, 0);
        size = 1;

    };

    polynomial(const polynomial &source) {
        head = source.head;
        size = source.size;
    };

    ~polynomial() {
        cout << "ÇÑ±Û" << endl;
        size = 0;
        delete head;

    }

    polynomial &operator+(polynomial &p1) {

    }

    polynomial operator-(polynomial p) {

    }

    polynomial operator*(polynomial p) {

    }

    polynomial operator=(polynomial p) {
        list_copy(p);
        return *this;


    }

    polynomial operator+=(polynomial p) {

    }

    polynomial operator-=(polynomial p) {

    }

    polynomial operator*=(polynomial p) {

    }

    size_t list_length() const;

    node *list_search(node *item);

    node *list_locate(int index);

    void list_insert(node *newItem, int index);

    void list_head_insert(node *newItem);

    void list_head_remove();

    void list_remove(int index);

    void list_clear();

    void list_copy(polynomial &copy);

    bool isEmpty();



    void show_content(node *&head) {
        node *curr = head;
        for (int i = 0; i < list_length(); ++i) {
            cout << curr->coefficients << "x^" << curr->exponents;
            if (curr->next != nullptr) {
                if (curr->next->coefficients >= 0) {
                    cout << "+";
                }
            }
            curr = curr->next;
        }
        cout << "" << endl;
    }

    double eval(int x) {
        node *curr = head;
        double sum = 0;
        while (curr != nullptr) {
            double result = 1.0;
            for (int i = 0; i < curr->exponents; ++i) {
                result *= curr->coefficients * x;
            }
            sum += result;
            curr = curr->next;
        }
        return sum;
    }
};

size_t polynomial::list_length() const {
    return size;
}

void polynomial::list_head_insert(node *newItem) {
    head = newItem;
    size++;
}


bool polynomial::isEmpty() {
    return size == 0;
}

void polynomial::list_clear() {
    size = 0;
    delete head;
}

void polynomial::list_head_remove() {
    node *removeNode = head;
    head = head->next;
    size--;
    delete removeNode;
}

void polynomial::list_remove(int index) {

    if (!isEmpty() && index >= 0 && index <= size - 1) {
        node *preNode = list_locate(index - 1);
        node *removeNode = preNode->next;
        preNode->next = removeNode->next;
        size--;
        delete removeNode;
    }
}

void polynomial::list_insert(node *newItem, int index) {
    if (index >= 0 && index <= size) {
        node *preNode = list_locate(index - 1);
        newItem->next = preNode->next;
        preNode->next = newItem;
        size++;
    }
}

void polynomial::list_copy(polynomial &copy) {
    if (copy.isEmpty()) {
        return;
    }
    list_clear();
    node *temp = copy.head;


    list_head_insert(new node(copy.head->coefficients, copy.head->exponents));
    temp = temp->next;

    while (temp != nullptr) {
        list_insert(new node(temp->coefficients, temp->exponents), size);
        temp = temp->next;
    }
}

node *polynomial::list_locate(int index) {
    if (isEmpty() || index < 0 || index >= size) {
        return nullptr;
    }
    node *currNode = head;
    for (int i = 0; i < index; i++) {
        currNode = currNode->next;
    }
    return currNode;
}

node *polynomial::list_search(node *item) {
    node *currNode = head;
    for (int i = 0; i < size; ++i) {
        if (currNode == item) {
            return currNode;
        }
        currNode = currNode->next;

    }
    return nullptr;
}






