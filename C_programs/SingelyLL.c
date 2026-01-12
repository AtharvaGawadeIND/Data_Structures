#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf ("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0 ;

    while(first != NULL)
    {
        iCount++;
        first = first->next;

    }
    return iCount;
}

void InsertFirst(PPNODE first , int no)
{

     PNODE newn = NULL;

     newn = (PNODE)malloc(sizeof(NODE));

     newn->data = no;
     newn->next = NULL;
     
     if(*first == NULL)
     {
        *first = newn;
     }

     else
     {
        newn->next = (*first);
        (*first )= newn;
     }
    
}

void InsertLast(PPNODE first , int no)
{
      PNODE newn = NULL;
      PNODE temp= NULL;
     newn = (PNODE)malloc(sizeof(NODE));

     newn->data = no;
     newn->next = NULL;

     
     if(*first == NULL)
     {
        *first = newn;
        return;
     }

     else
     {
        temp = *first;

        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
            temp->next = newn;
     }

}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first )== NULL)
    {
        return;
    }

    else if((*first)-> next == NULL)
    {   
        free(*first);
        *first = NULL;
    }

    else
    {
        temp = (*first);
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first )== NULL)
    {
        return ;
    }
    else if((*first)-> next == NULL)
    {   
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }

}

void InsertAtPos(PPNODE first , int no, int Pos)
{

    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0 ;

    iSize = Count(*first);

    if(Pos<1 || Pos < iSize +1 )
    {
        printf("Invalid Position");
        return ;
    }

    if(Pos == 1)
    {
        InsertFirst(first , no);
    }

    else if (Pos == iSize+1 )
    {
        InsertLast(first ,no);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1 ; iCnt <Pos-1 ;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

    }

}

void DeleteAtPos(PPNODE first,int Pos)
{
    int iSize = 0 ;
    int iCnt = 0; 

    PNODE temp = NULL;
    PNODE target =NULL;
    
    iSize = Count(*first);

    if((Pos<1)|| (Pos>iSize))
    {
        printf("Invalid position");

        return;   
    }

    if(Pos == 1)

    {
        DeleteFirst(first);
    }

    else if(Pos ==iSize)
    {
        DeleteLast(first);
    }


    else
    {
        temp = *first;

        for(iCnt =1 ; iCnt<Pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = target->next;
        free(target);
    }

}

int main()
{
PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,105,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    DeleteAtPos(&head,4);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}