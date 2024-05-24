#include "stack.h"

// Função para criar a pilha
Stack *create_stack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->items = (int *)malloc(sizeof(int) * size);
    stack->max = size;
    stack->top_index = -1;
    return stack;
}

// Função para verificar se a pilha está vazia
int is_empty(Stack *stack) {
    return stack->top_index < 0;
}

// Função para verificar se a pilha está cheia
int is_full(Stack *stack) {
    return stack->top_index == stack->max - 1;
}

// Função para empilhar um elemento
int push(Stack *stack, t_elem x) {
    if (is_full(stack)) {
        return 0;
    }
    stack->items[++(stack->top_index)] = x;
    return 1;
}

// Função para desempilhar um elemento
int pop(Stack *stack, t_elem *x) {
    if (is_empty(stack)) {
        return 0;
    }
    *x = stack->items[(stack->top_index)--];
    return 1;
}

// Função para obter o elemento no topo da pilha sem removê-lo
int top(Stack *stack, t_elem *x) {
    if (is_empty(stack)) {
        return 0;
    }
    *x = stack->items[stack->top_index];
    return 1;
}

// Função para destruir a pilha
void destroy_stack(Stack *stack) {
    free(stack->items);
    free(stack);
}
