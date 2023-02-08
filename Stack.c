#include <stdio.h>
#include <stdlib.h>
/*int형 스택 IntStack*/
#ifndef ___IntStack
#define ___IntStack
 /*스택을 구현하는 구조체*/
 typedef struct 
 {
     int max;
     int ptr;
     int *stk;
 }IntStack;

 /*스택 초기화*/
 int Initialize(IntStack *s, int max)
 {
     s->ptr = 0;
     if(s->stk = calloc(max, sizeof(int)) == NULL)
     {
         s->max = 0;
         return -1;
     }
     s->max = max;
     return 0;
 }

 /*스택에 데이터를 푸시*/
 int Push(IntStack *s, int *x)
 {
     if(s->ptr == s->max)
         return -1;
     s->stk[s->ptr++] = *x;
     return 0;
 }

 /*스택에서 데이터를 팝*/
 int Pop(IntStack *s, int *x)
 {
     if(s->ptr <= 0)
         return -1;
     *x = s->stk[s->ptr--];
     return 0;
 }

 /*스택에서 데이터를 피크*/
 int Peek(const IntStack *s, int *x)
 {
     if(s->ptr <= 0)
         return -1;
     *x = s->stk[s->ptr-1];
 }

 /*스택 비우기*/
 void Clear(IntStack *s)
 {
     s->ptr = 0;
 }

 /*스택의 최대 용량*/
 int Capacity(const IntStack *s)
 {
     return s->max;
 }

 /*스택의 데이터 개수*/
 int Size(const IntStack *s)
 {
     return s->ptr;
 }

/*스택이 비어있나요*/
int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

/*스택이 가득찼나요*/
int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

/*스택에서 검색*/
int Search(const IntStack *s, int x)
{
    for(int i = s->ptr-1; i >=0  ; i--)
    {
        if(x == s->stk[i])
            return i;
    }
    return -1;
}

/*모든 데이터 출력*/
void Print(const IntStack *s)
{
    for(int i = 0; i < s->ptr ; i++)
    {
        printf("%d ",s->stk[i]);
    }
    printf("\n");
}

/*스택 종료*/
void Terminate(IntStack *s)
{
    if(s->stk != NULL)
        free(s->stk);
    s->ptr = 0;
    s->max = 0;
}