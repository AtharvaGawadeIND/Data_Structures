#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{}

int Count(PNODE first)
{
    return 0 ;
}

void InsertFirst(PPNODE first , int no)
{}

void InsertLast(PPNODE first , int no)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void InsertAtPos(PPNODE first , int no, int Pos)
{}

void DeleteAtPos(PPNODE first, int no , int Pos)
{}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 11);
    InsertLast(&head, 21);

    Display(head);
    Count(head);

    return 0;

}