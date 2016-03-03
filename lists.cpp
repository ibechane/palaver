// ============================================================================
//
//       Filename:  lists.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  03/03/2016 15:47:57
//       Revision:  none
//       Compiler:  clang++ -std=c++14
//
//         Author:  Matthew Harrigan (mj), git@mjharrigan.com
//   Organization:
//
// ============================================================================

#include<iostream>

using namespace std;

template<typename T>
struct element {
    T key = 0;
    element<T> *prev;
    element<T> *next;
};

template<typename T>
struct stack {
    element<T> *head = nullptr;

    void push(T k) {
        element<T> *x = new element<T>;

        x->key = k;
        x->prev = nullptr;
        x->next = this->head;

        if (this->head)
            this->head->prev = x;

        this->head = x;
    }

    T pop(void) {
        if (!this->head)
            throw "Stack is empty.";

        T k = this->head->key;

        if (this->head->next) {
            this->head = this->head->next;
            delete[] this->head->prev;
            this->head->prev = nullptr;
        } else {
            delete[] this->head;
            this->head = nullptr;
        }

        return k;
    }
};

int main(void)
{
    stack<int> S;

    for (int i=0; i!=10; ++i)
        S.push(i);

     for (int i=0; i!=10; ++i)
        cout << S.pop() << endl;

    return 0;
}
