#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int t_elem;

typedef struct {
    int max;
    int top_index;
    t_elem *items;
} Stack;

Stack *create_stack(int size);
void destroy_stack(Stack* stack);
int is_full(Stack *stack);
int is_empty(Stack *stack);
int push(Stack *stack, t_elem x);
int pop(Stack *stack, t_elem *x);
int top(Stack *stack, t_elem *x);

#endif
