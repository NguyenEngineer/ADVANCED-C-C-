#include<stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct note
{
    int value;
    struct note *next;    // một con trỏ kiểu struct note, nó trỏ tới một cấu trúc note khác.
}note;

note* createrNOTE(int value)  // tạo ra một nút mới
{
    note* ptr = (note*)malloc(sizeof(note));  // cấp phát bộ nhớ để chứa 1 struct node 

    ptr->next = NULL;
    ptr->value = value;
    return ptr;
}

void push_back(note** array, int value)
{
    note* temp;
    temp = createrNOTE(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        note* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void pop_back(note** array)
{
    note* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}


int get(note* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

void push_front(note **array, int value) // thêm node vào đầu chuỗi
                                        //    *(&arr) có nghĩa là "con trỏ  mang giá trị địa chỉ đầu tiên trong danh sách liên kết"
{
    note* newnode = createrNOTE(value);
    if (*array == NULL)   // if array doesn't have any node yet
    {
        *array = newnode;
    }else
    {
        newnode->next = *array;

        *array = newnode;  // cập nhập lại newnode là phẩn tử mảng đầu tiên
    }
}

void pop_front(note **array) // xóa node vào đầu chuỗi
{
    if (*array = NULL)
    {
        printf("List rỗng");
    }

    note* deletetNode;     // tạo 1 node giá trị = NULL
    deletetNode = *array;  // cho deletNode bằng địa chỉ pt đầu trong mảng
                                                                    /*deletnode:    add             0x1 
                                                                                    val             5               
                                                                                    addNext         0x2         */
    *array = deletetNode->next;     // gán cho mảng đầu = với địa chỉ của addNext của node deletNode. arr = 0x1 sau khi xóa phần tử đầu thì arr = 0x2;
    free(deletetNode);  // giải phỏng 0x1

    /* list:        add        0x1             0x2             0x3
                    val        1               2               3
                    addNext    0x2             0x3             NULL
    */
}

int front(note *array) // lay gia tri cua node đầu tiên
{
    int val = array->value;
    return val;
}

int back(note *array)  // lay gia tri cua node cuoi cung
{
    while (array->next != NULL)
    {
        array->next;
    }
    return array->value;

}


 void insert(note **array, int value, int pos) // them 1 node vao mot vi tri bat ky
 {
    note *temp, * p;                // khỏi tạo 2 biến trung gian temp để lưu note mới,  p để lưu add next của phần tử
    temp = createrNOTE(value);
    p = *array;                     // cho p = phần tử note đầu tiên

    unsigned int i = 1;             // cho i = 1 để biết vị trí của phần tử cần thêm
    if(pos == 0)            // nếu thứ tự nhập vào bằng phẩn tử mảng đầu thì gán note mới vào
    {
        temp->next = *array;

        *array = temp;
    }else{
        while (p->next != NULL && pos != i)     // p lưu phần tử đầu và duyệt add next cho đến khi pos = vị trí cần thêm note
        {
            p = p->next;                        // gán p = add next của phần tử đang duyệt
            i++;
        }

        temp->next = p->next;                   // cho add next note temp = add next note của p đã duyệt
        p->next = temp; }                        // gán add next của node p hiện tại = add của temp
 }

void deletee(note **array, int pos) // xoa 1 node tai mot vi tri bat ky
{
    note *temp, * p;                // khỏi tạo 2 biến trung gian temp để lưu note mới,  p để lưu add next của phần tử
    p = *array; 
    unsigned int i = 1;

        while (p->next != NULL && pos != i)     // p lưu phần tử đầu và duyệt add next cho đến khi pos = vị trí cần thêm note
        {
            p = p->next;                        // gán p = add next của phần tử đang duyệt
            i++;
        }

        temp->next = p->next;                   // cho add next note temp = add next note của p đã duyệt
        p->next = p->next->next;
        free(temp);                      // gán add next của node p hiện tại = add của temp
 }                    // cho p = phần tử note đầu tiên

 int size(note **array) // lay kich thuoc cua list
 {
    note *p = *array; 
    unsigned int cout = 1;
    while (p->next != NULL)     // p lưu phần tử đầu và duyệt add next cho đến khi pos = vị trí cần thêm note
    {
         p = p->next;                        // gán p = add next của phần tử đang duyệt
        cout++;
    }
    return cout;
 }
int empty(note **array) // kiem tra list co rong hay khong
 {
    if(array == NULL)
    {
        return 1;
    }else return 0;
 }

int main()
{
    note* arr = NULL;
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    
    // push_front(&arr, 2);
    // printf("Value test: %d\n", get(arr, 0));
    // pop_front(&arr);
    // printf("Value test: %d\n", get(arr, 0));

    printf("Value test: %d\n", size(&arr));

    deletee(&arr,3);
    printf("Value test: %d\n", size(&arr));
    printf("Value test: %d\n", empty(&arr));

	return 0;
}

