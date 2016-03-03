// ============================================================================
//
//       Filename:  lists.c
//
//    Description:
//
//        Version:  1.0
//        Created:  03/02/2016 17:03:58
//       Revision:  none
//       Compiler:  clang
//
//         Author:  Matthew Harrigan (mj), git@mjharrigan.com
//   Organization:
//
// ============================================================================

#include<stdlib.h>
#include<stdio.h>

typedef struct element element;

struct element {
    int key;
    element *prev;
    element *next;
};

typedef struct stack {
    element *head;
} stack;

void push(stack* s, int key) {
    element *x = (element *) malloc(1);

    x->key = key;
    x->prev = NULL;

    if (s->head) {
        x->next = s->head;
    } else {
        x->next = NULL;
    }

    s->head = x;
}

int pop(stack* s) {
    if (!s->head)
        exit(1);

    element *x = s->head;

    int key = x->key;

    if (x->next) {
        s->head = x->next;
        s->head->prev = NULL;
    }

    // free(x);

    return key;
}

int main(void)
{
    stack S;
    S.head = NULL;

    for (int i=0; i!=10; ++i) {
        push(&S, i);
        printf("%d\n", pop(&S));
    }

    push(&S, 0);
    push(&S, 1);
    push(&S, 2);

    printf("%d\n", pop(&S));
    printf("%d\n", pop(&S));
    printf("%d\n", pop(&S));

    return 0;
}
