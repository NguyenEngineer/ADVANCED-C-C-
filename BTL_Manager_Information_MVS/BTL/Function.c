/*
* File: FunctionFile.c
* Author: Duong Bao Nguyen
* Date: 4/1/2024
* Description: This file is a function file in program is used by building manager
*/
#include "Function.h"


/*
* Function: CreaterMemberNode
* Description: creater member node
* Input:
    MemberData - a Member datatype
* Output:
    return a pointer that store the address of the newly created node
*/
 MemberNode* CreaterMemberNode(MemberData Member)
{
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = Member;
    newNode->next = NULL;
    return newNode;
}

/*
* Function: input
* Description: input data infomation
* Input:
    memberData - a Member datatype
* Output:
    return information of the newly added member
*/
MemberData* input(MemberData* member) {
    /*MemberData* member = (MemberData*)malloc(sizeof(MemberData));*/
    printf("Import information member\n");
    printf("Import UID: ");                 scanf_s("%s", member->uid, sizeof(member->uid));
    printf("Import roomNumbe: \n");           scanf_s("%s", member->roomNumber, sizeof(member->roomNumber));
    printf("Import name: \n");                scanf_s("%s", member->name, sizeof(member->name));
    printf("Import licensePlate: ");        scanf_s("%s", member->licensePlate, sizeof(member->licensePlate));

    return member;
}

/*
* Function: getInfMember
* Description: print data about resident infomation
* Input:
    memberData - a Member datatype
* Output:
*   information of each memberData
*/
void getInfMember(MemberData* member) {
    printf("%s là UID của RFID.\n ", member->uid);
    printf("%s là số phòng.\n ", member->roomNumber);
    printf("%s là tên của cư dân. \n ", member->name);
    printf("%s là biển số xe. \n ", member->licensePlate);
}

/*
* Function: AddMemberNODE
* Description: add member in list.
* Input:
        list member
* Output:
        add a member.
*/
void AddMemberNODE(MemberNode** LK_List)                // tạo 1 Node mới 
{
    MemberData newMem;
    input(&newMem);
    MemberNode* newNode = CreaterMemberNode(newMem);  //newMember is pointer ,need to pass value
    MemberNode* ptr = *LK_List;

    if (*LK_List = NULL) { //if list empty , node becomes the first of list
       *LK_List = newNode;
    }
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
            ptr->next = newNode; //assgine next the last node by address of the newly created node
    }
}

/*
* Function: deleteMemberNODE
* Description: delete member in list.
* Input:
        list member
* Output:
        delete a member.
*/
void deleteMemberNODE(MemberNode** LK_List)
{
    MemberNode* temp, * p;
    p = *LK_List;

    int uid, cnt = 0;
    printf("ID: "); scanf_s("%d", &uid);

    while (LK_List != NULL && cnt < uid - 1)
    {
        p = p->next;
        ++cnt;
    }
    temp = p->next;
    p->next = p->next->next;
    free(temp);
}

/*
* Description: Edit member
* Input:    LK_list
* Output:   return a member has edit
*/
void editMember(MemberNode** LK_List)
{
    MemberNode* p = *LK_List;
    char* UID;
    printf("Enter uid want to edit: "); scanf_s("%s", &UID, sizeof(UID));

    while (p != NULL)
    {
        if (p->data.uid = UID)
        {
            printf("Information member:\n");
            getInfMember(&p->data);
            printf("Edit information member :\n"); 
            input(&p->data);
            return;
        }
        p = p->next;
    }
}

/*
* Description: Search member by UID / licensePlate number in the given file.
* Input: MemberNode* LK_list
* Output: Give member information when the given UID / licensePlate number is found.
*/
void searchMEMBER(MemberNode* LK_List)
{
    unsigned int search = 0;
    printf("1. search by UID\n");
    printf("2. search by License Plate\n");
    scanf_s("d", &search);

    char uid, LisLicensePlate;

    switch (search)
    {
    case 1:
        scanf_s("s", &uid);
        searchUID(LK_List,uid);
        break;
    case 2:
        scanf_s("s", &LisLicensePlate);
        searchLicensePlate(LK_List, LisLicensePlate);
        break;
    default:
        break;
    }
}

/*
* Function: searchUID
* Description: Search member by UID number in the given file.
* Input:
*   list  &&  uid
* Output:
*   return information of resident according to UID corresponding
*/
void searchUID(MemberNode* LK_List, char* uid)
{
    MemberNode* temp = LK_List;

    while (temp != NULL)
    {
        if (temp->data.uid = uid) getInfMember(&temp->data); return;
        temp = temp->next;
    }

}

/*
* Function: searchLicensePlate
* Description: Search member by License Platenumber in the given file.
* Input:
*   LK_list   &&    License Platenumber
* Output:
*   return information of resident according to License Platenumber corresponding
*/
void searchLicensePlate(MemberNode* LK_List, char* LicensePlate)
{
    MemberNode* temp = LK_List;

    while (temp != NULL)
    {
        if (temp->data.licensePlate = LicensePlate)  getInfMember(&temp->data); return;

        temp = temp->next;
    }
}

/*
* Function: createMember
* Description: add the new node at the first position of the linked list
* Input:
*   list - pointer to pointer has datatype is node - address of pointer array which pointer to first node of linked list
*   member - a Member datatype - data
* Output:
*   new list with a new node at the beginning
*/
void createMember(MemberNode** LK_list, MemberData member) {
    MemberNode* newNode = CreaterMemberNode(member);
    newNode->next = (*LK_list);
    (*LK_list) = newNode;
}
/*
* Function: readData
* Description: take data from file.txt to add into Nodemember
* Input:
*   filename  &&  LK_list
* Output:
*   Node LK_list
*/
void readData(const char* fileName, MemberNode** LK_list) { 
    char row[500]; //array to save the line from file

    FILE* file = fopen(fileName, "r"); //open the file in read mode 
    if (file == NULL) {
        printf("Cannot open file name:  %s\n", fileName);
        return;
    }


    char* ptr; //pointer to save each part after separation
    while (fgets(row, 500, file) != NULL) { //feof: check current address whether is last character of the file?
        //saparate the line into part with ,
        ptr = strtok(row, ",");
        MemberData aMember; //variable to save current member information
        memset(&aMember, 0, sizeof(MemberData));
        int cnt = 0; //every line have 4 token
        while (ptr != NULL) {//lặp qua các token trong 1 dòng
            ++cnt;
            switch (cnt) {
            case 1: //first token
                strcpy(aMember.uid, ptr); //write first token into uid of Memnber
                break;
            case 2: //second token
                strcpy(aMember.roomNumber, ptr); //write secon token into roomNumber of Memnber
                break;
            case 3: //third token
                strcpy(aMember.name, ptr); //write third token into name of Memnber
                break;
            case 4: //last token
                strcpy(aMember.licensePlate, ptr); //write last token into licensePlate of Memnber
                break;
            }
            //continue saparate other token in line
            ptr = strtok(NULL, ",");
        }
        createMember(&LK_list, aMember);
    }
    fclose(file); //close file after reading
}



void writeDataIntoFILE(const char* filename, MemberNode** member)
{
    FILE* file = fopen(filename, "w");
    MemberNode* node = member;
    if (file == NULL) printf("File is not exist\n"); return;
    while (node != NULL) {
        fprintf(file, "%d\n", node->data);
        node = node->next;
    }
    // Ghi dữ liệu thành viên vào tệp
    //fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);

    fclose(file);
}