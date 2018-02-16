#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *createStack(void(*printFunction)(void *toBePrinted), void(*deleteFunction)(void *toBeDelted), int(*compareFunction)(const void *first, const void *second)){
    Stack *s = malloc(sizeof(Stack));
    s->count = 0;
    s->list = initializeList(printFunction, deleteFunction, compareFunction);
    
    return s;

}


void push(Stack *s, void *data){
    insertFront(s->list, data);
    s->count++;
}


void pop(Stack *s){

    if(s){
        void *data = top(s);
        int result = deleteNodeFromList(s->list, data);
        if(result == EXIT_SUCCESS){
            s->count--;
        }
        
    }

}


void *top(Stack *s){
    if(s->list == NULL){
        return NULL;
    }
    return getFromFront(s->list);
}


int count(Stack *s){
    return s->count;
}
