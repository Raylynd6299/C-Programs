#include <stdio.h>
#include <stdlib.h>

#define TamInicial 2

typedef int PilaTipo;

typedef struct Pila{
    int top;
    int len;
    PilaTipo *array;
}Pila;

void CrearPila(Pila* );
void Push(Pila* ,PilaTipo );
int Pop(Pila*,PilaTipo* );
void MostrarPila(Pila *);

void main(){
    Pila stack;
    PilaTipo regreso;

    CrearPila(&stack);
    
    printf("Top: %d, Len: %d, array[0]:%d \n",stack.top,stack.len,*stack.array);
    Push(&stack,10);
    printf("Top: %d, Len: %d, array[0]:%d \n",stack.top,stack.len,*stack.array);
    MostrarPila(&stack);
    Push(&stack,15);
    printf("Top: %d, Len: %d, array[0]:%d \n",stack.top,stack.len,*stack.array);
    MostrarPila(&stack);
    Push(&stack,20);
    printf("Top: %d, Len: %d, array[0]:%d \n",stack.top,stack.len,*stack.array);
    MostrarPila(&stack);

    if(Pop(&stack,&regreso) == -1){
        printf("StackOverFlow");
    }
    printf("Top: %d, Len: %d, Retorno:%d \n",stack.top,stack.len,regreso);
    MostrarPila(&stack);
    if(Pop(&stack,&regreso) == -1){
        printf("StackOverFlow");
    }
    printf("Top: %d, Len: %d, Retorno:%d \n",stack.top,stack.len,regreso);
    MostrarPila(&stack);
    if(Pop(&stack,&regreso) == -1){
        printf("StackOverFlow");
    }
    printf("Top: %d, Len: %d, Retorno:%d \n",stack.top,stack.len,regreso);
    MostrarPila(&stack);
    if(Pop(&stack,&regreso) == -1){
        printf("StackOverFlow\n");
    }
    printf("Top: %d, Len: %d, Retorno:%d \n",stack.top,stack.len,regreso);
    MostrarPila(&stack);
}

void CrearPila(Pila* stack){
    stack->len = TamInicial;
    stack->top = -1;
    stack->array = (PilaTipo *)malloc(sizeof(PilaTipo) * TamInicial);
    if (stack->array == NULL){
        perror("Error obteniendo memoria para la Pila");
        exit(EXIT_FAILURE);
    }
}

void MostrarPila(Pila *stack){
    for(int indice = 0; indice < stack->len ; indice++){
        if(indice == stack->top){
            printf("| T -> %d |",*(stack->array + indice));
        }else{
            printf("| %d |",*(stack->array + indice));
        }
    }
    printf("\n");
}

void Push(Pila* stack,PilaTipo valor){
    if ( stack->top+1 <  stack->len ){//Tenemos espacio
        stack->top ++;
        *(stack->array + stack->top) = valor;
    }else{
        stack->array = (PilaTipo *)realloc(stack->array,sizeof(PilaTipo)*(stack->len+3));
        stack->len += 3;
        stack->top ++;
        *(stack->array + stack->top) = valor;
    }
}

int Pop(Pila* stack,PilaTipo* retorno){
    if(stack->top == -1){
        return -1;
    }else{
        *retorno = *(stack->array + stack->top);
        stack->top--;
        return 0;
    }
}

