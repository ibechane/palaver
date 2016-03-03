/*
 * ============================================================================
 *
 *       Filename:  lists.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/02/2016 17:03:58
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Matthew Harrigan (mj), git@mjharrigan.com
 *   Organization:
 *
 * ============================================================================
 */

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
    element *x = (element *) malloc(sizeof(element));

    x->key = key;
    x->prev = NULL;
    x->next = s->head;

    if (s->head)
        s->head->prev = x;

    s->head = x;
}

int pop(stack* s) {
    if (!s->head)
        exit(1);

    int key = s->head->key;

    if (s->head->next) {
        s->head = s->head->next;
        free(s->head->prev);
        s->head->prev = NULL;
    } else {
        free(s->head);
        s->head = NULL;
    }

    return key;
}
 
int main(void)
{
    stack S;
    S.head = NULL;

    for (int i=0; i!=10; ++i)
        push(&S, i);

    for (int i=0; i!=10; ++i)
        printf("%d\n", pop(&S));

    return 0;
}
