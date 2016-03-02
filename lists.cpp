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

typedef struct list {
    void *head = nullptr;
    element x;

    // search();
    // delete();
    // insert();
} list;

int main(void)
{
    list l;
    return 0;
}
