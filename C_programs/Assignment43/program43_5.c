/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Description :   It inserts elements at the last index
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Atharva Vinod Gawade
//  Date :          17/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////


void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

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
} // End of InsertLast

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Description :   It displays all elements in the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Atharva Vinod Gawade
//  Date :          17/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d |->", first->data);
        first = first->next;
    }
    printf("NULL\n");
} // End of Display

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : SumDigit
//  Description :   It displays the sum of the digits of the elements of the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Atharva Vinod Gawade
//  Date :          17/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void SumDigit(PNODE first)
{
    int iSum = 0;
    int iNo = 0;

    while (first != NULL)
    {
        iSum = 0;              
        iNo = first->data;

        while (iNo != 0)
        {
            iSum = iSum + (iNo % 10);
            iNo = iNo / 10;
        }
   
        first = first->next;
        printf("%d ", iSum);
    }
    printf("\n");
} // End of SumDigit


/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iValue = 0;
    int iRet = 0;

    InsertLast(&head, 10);
    InsertLast(&head, 20);
    InsertLast(&head, 33);
    InsertLast(&head, 40);

    Display(head);

    printf("Sum of all digits in linked list: \n");
    SumDigit(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Output:
//  | 10 |->| 20 |->| 33 |->| 40 |->NULL
//  Sum of all digits in linked list: 
//  1 2 6 4   
//
/////////////////////////////////////////////////////////////////////////////////////////////////