#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef struct datas
{
    int ArrayStack[MAX_STACK_SIZE];
    int top;
}StackType;
//initializing stack
void init_stack(StackType *s)
{
    s->top=-1;
}
//스택에 대한 모든 연산은 구조체의 포인터를 받게 된다.(이제는 top값이 전역변수가 아님.)
int is_empty(StackType *s)
{
    return(s->top==-1);
}
int is_full(StackType *s)
{
    return(s->top==MAX_STACK_SIZE-1);
}
//push연산
void push(StackType *s,int item)
{
    if(is_full(s))
        printf("Error, can't push");
    else
        s->ArrayStack[++(s->top)]=item;
}
//pop연산
int pop(StackType *s)
{
    if(is_empty(s))
        printf("Error, can't pop");
    else
        return s->ArrayStack[(s->top)--];
}
//peek function
int peek(StackType *s)
{
    if(is_empty(s))
        printf("Error, can't peek");
    else
        return s->ArrayStack[s->top];
}
int main()
{
    StackType *s;
    char input[100];
    init_stack(s);
    printf("수식: ");
    scanf("%s",input);
    int i=0;
    int num=1;
    while(input[i]!=NULL)
    {
        if(input[i]=='(')
        {
            push(s,num);
            printf("%d ",num);
            num++;
        }
        else if(input[i]==')')
        {
            printf("%d ",pop(s));
        }
        i++;
    }
    return 0;
}
