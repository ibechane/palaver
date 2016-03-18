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
#include <initializer_list>

using namespace std;

template<typename T>
struct element {
    T key = 0;
    element<T> *prev;
    element<T> *next;
};

// template<typename T>
// struct list {
//     element<T> *elem = nullptr;
//     element<T> *elem = nullptr;
// 
//     insert;
//     search;
//     delete;
// };

template<typename T>
struct stack {
    element<T> *head = nullptr;

    stack() {}

    stack(std::initializer_list<T> args) {
        for (const auto& arg : args)
            this->push(arg);
    }

    virtual ~stack() = default;  // TODO: Add full dealloc.

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

int main(int argc, char *argv[])
{
    stack<int> S {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // for (int i=0; i!=10; ++i)
    //     S.push(i);

     for (int i=0; i!=10; ++i)
        cout << S.pop() << endl;

    return 0;
}
