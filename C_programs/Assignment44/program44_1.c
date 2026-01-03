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
//  Description   : Counts number of nodes in the linked list
//  Input         : PNODE
//  Output        : Integer count
//  Return Type   : int
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a node at specified position
//  Input         : PPNODE, int, int
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iCnt = 0;
    int iSize = Count(*first);
    PNODE newn = NULL;
    PNODE temp = NULL;

    if ((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(first, no);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from specified position
//  Input         : PPNODE, int
//  Output        : None
//  Return Type   : void
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int pos)
{
    int iCnt = 0;
    int iSize = Count(*first);
    PNODE temp = NULL;
    PNODE target = NULL;

    if ((pos < 1) || (pos > iSize))
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first);
    }
    else if (pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Search
//  Description   : Searches an element in the linked list
//  Input         : PNODE, int
//  Output        : true if found, false otherwise
//  Return Type   : bool
//  Author        : Atharva Vinod Gawade
//  Date          : 1/1/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

bool Search(PNODE Head, int No)
{
    while (Head != NULL)
    {
        if (Head->data == No)
        {
            return true;
        }
        Head = Head->next;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    bool bRet = false;
    int iSearch = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    InsertLast(&head, 101);
    InsertLast(&head, 111);

    Display(head);
    printf("Number of nodes are : %d\n", Count(head));

    printf("Enter the element to search : \n");
    scanf("%d", &iSearch);

    bRet = Search(head, iSearch);

    if (bRet == true)
    {
        printf("Element %d is present in the linked list\n", iSearch);
    }
    else
    {
        printf("Element %d is NOT present in the linked list\n", iSearch);
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Cases Successfully Handled by the Application
//
//  Input : | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
//  Number of nodes are : 5
//  Enter the element to search : 
//  51
//  
//  Output:
//  Element 51 is present in the linked list
//
/////////////////////////////////////////////////////////////////////////////////////////////////
