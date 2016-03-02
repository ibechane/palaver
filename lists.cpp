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

typedef struct element {
    void *key;
    void *prev;
    void *next;
} element;

template<typename T>
typedef struct stack {
    stack() {}
    ~stack() {}

    // element *head = NULL;
    // void push(element x) {}
    // T pop(T key) {}
} stack;

template<typename T>
typedef struct list {
    list() {}
    ~list() {}

    T *head = NULL;

    // element search(T *key) {}

    // void delete(element x) {}
    // void insert(element x) {}
} list;

int main(void)
{
    list l;
    return 0;
}
