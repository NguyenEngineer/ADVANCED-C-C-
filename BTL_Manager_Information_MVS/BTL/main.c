/*
* File: main.c
* Author: Duong Bao Nguyen
* Date: 4/1/2024
* Description: This is an apartment member information management program, includes basic functions: add, delete, edit and search resident information
*/
#include "Function.h"

typedef enum {
    STOP_PROGRAM,
    ADD_NEW_MEMBER,
    DELETE_MEMBER,
    EDIT_MEMBER,
    SEARCH_MEMBER
} FunctionManager;

int main()
{
    MemberNode* LK_List ;

    FunctionManager choosefunc = ADD_NEW_MEMBER;

    while (1)
    {
        readData("file.txt", &LK_List);
        printf("Manage apartment member information\n");
        printf("0.  Stop program\n");
        printf("1.  Add new member\n");
        printf("2.  Delete member\n");
        printf("3.  Edit member\n");
        printf("4.  Search member\n");

        printf("Please choose function: ");
        scanf_s("%d", &choosefunc);

        switch (choosefunc)
        {
        case STOP_PROGRAM:
            printf("Program has stop\n");
            break;
        case ADD_NEW_MEMBER:
            AddMemberNODE(&LK_List);
            printf("Add new member succesful\n");
            break;
        case DELETE_MEMBER:
            printf("Enter ID to delete member\n");
            deleteMemberNODE(&LK_List);
            printf("Delete has succesful\n");
            break;
        case EDIT_MEMBER:
            editMember(&LK_List);
            break;
        case SEARCH_MEMBER:
            printf("Choose propety search member:\n");
            searchMEMBER(&LK_List);
            break;
        default:
            printf("Error. Please choose again.\n");
            break;
        }
        writeDataIntoFILE("file.txt", &LK_List);
    }
}