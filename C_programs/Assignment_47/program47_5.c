/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : struct node
//  Description    : Represents a node of singly linear linked list.
//                   Each node contains integer data and a pointer to next node.
//  Members        : int data, struct node *next
//  Author         : Atharva Vinod Gawade
//  Date           : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Type Definitions
//  Description : Improves readability and pointer handling
//  Author      : Atharva Vinod Gawade
//  Date        : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list
//  Input         : PPNODE, int
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list
//  Input         : PPNODE, int
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the linked list
//  Input         : PPNODE
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if (*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the linked list
//  Input         : PPNODE
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if (*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the linked list
//  Input         : PNODE
//  Output        : Prints linked list
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Counts total number of nodes in the linked list
//  Input         : PNODE
//  Output        : Integer count
//  Return Type   : int
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCount = 0;

    while (Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayPrime
//  Description   : Displays only prime number elements from the linked list
//                  without using any flag variable
//  Input         : PNODE
//  Output        : Prints prime number elements
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CountPrime
//  Description   : Counts number of prime number elements in the linked list
//                  without using any flag variable
//  Input         : PNODE
//  Output        : Integer count of prime numbers
//  Return Type   : int
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int CountPrime(PNODE Head)
{
    int iNo = 0;
    int iCnt = 0;
    int iPrimeCnt = 0;

    while (Head != NULL)
    {
        iNo = Head->data;

        if (iNo > 1)
        {
            for (iCnt = 2; iCnt <= iNo / 2; iCnt++)
            {
                if (iNo % iCnt == 0)
                {
                    break;   
                }
            }

            if (iCnt > iNo / 2)   
            {
                iPrimeCnt++;
            }
        }

        Head = Head->next;
    }

    return iPrimeCnt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iNo = 0;
    int iPos = 0;
    int X = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    InsertLast(&head, 101);
    InsertLast(&head, 111);

    InsertFirst (&head,20);
    InsertFirst (&head,2);
    InsertLast(&head, 111);

    Display(head);

    printf("Number of prime elements are : %d\n", CountPrime(head));

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Test Cases Successfully Handled by the Application
//
//    Output:
//    | 2 | -> | 20 | -> | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 111 | -> NULL
//    Number of prime elements are : 3
//
/////////////////////////////////////////////////////////////////////////////////////////////////