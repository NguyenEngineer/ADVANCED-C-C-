#pragma once
/*
* File: FunctionFile.h
* Author: Duong Bao Nguyen
* Date: 4/1/2024
* Description: This file is a function file header in program is used by building manager
*/

#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char* uid;                   // UID của RFID
    char* roomNumber;            // Số Phòng
    char* name;                  // Tên
    char* licensePlate;          // Biển số xe
} MemberData;

typedef struct MemberNode
{
    MemberData data;
    struct MemberNode* next;
} MemberNode;


MemberNode* CreaterMemberNode(MemberData CreaterMember);

MemberData* input(MemberData* member);
void getInfMember(MemberData* member);
void AddMemberNODE(MemberNode** LK_List);
void deleteMemberNODE(MemberNode** LK_List);
void editMember(MemberNode** LK_List);

void searchMEMBER(MemberNode* LK_List);
void searchUID(MemberNode* LK_List, char* uid);
void searchLicensePlate(MemberNode* LK_List, char* LicensePlate);

void readData(const char* fileName, MemberNode** LK_list);
void writeDataIntoFILE(const char* filename, MemberNode** member);


#endif