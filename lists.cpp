// ============================================================================
//
//       Filename:  lists.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  03/02/2016 17:03:58
//       Revision:  none
//       Compiler:  clang++ -std=c++14
//
//         Author:  Matthew Harrigan (mj), git@mjharrigan.com
//   Organization:
//
// ============================================================================

template<typename T>
typedef struct element {
    T *key;
    element *prev;
    T *next;
} element;

template<typename T>
typedef struct stack {
    stack() {}
    ~stack() {}

    element *head = NULL;
    void push(T key) {
        element x {key, head, NULL};

        head->next = x;
        head = &x;
    }

    // T pop(T key) {}
} stack;

// template<typename T>
// typedef struct list {
//     list() {}
//     ~list() {}
//
//     T *head = NULL;
//
//     // element search(T *key) {}
//
//     // void delete(element x) {}
//     // void insert(element x) {}
// } list;

int main(void)
{
    stack S;
    return 0;
}
