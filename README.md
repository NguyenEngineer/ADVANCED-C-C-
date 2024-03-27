
# ADVANCE C
</details>
<details><summary> Question Interview C</summary>

1. Khác nhau giữa macro và function
2. Vùng nhớ trên RAM
3. Static hoạt động như thế nào
4. So sánh giữa struct và union
5. Con trỏ là gì, kích thước con trỏ, con trỏ hàm, void, NULL, poiter to poiter.
   - Con trỏ là biến lưu địa chỉ của đối tượng khác khác.
   - Kích thước con trỏ phụ thuộc vào kiến trúc của VXL.    VD: nếu VDK 8bit = 1 byte => kích thước con trỏ là 1 byte.
                                                                nếu VDK 16bit = 2 byte => kích thước con trỏ là 2 byte.    32 bit là 4 byte.
   - Con trỏ hàm là trỏ lưu địa chỉ của 1 hàm.
   - Con trỏ void là con trỏ không kiểu dữ liệu nào cả.
   - Null là ko trỏ tới vùng nhớ hay giá trị nào cả,
   - ** là con trỏ trỏ tới 1 con trỏ khác.
6. Biến Register và Volatile
7. 
<details><summary> LESSION 1: Compiler - Macro C</summary>
  - Macro là một cách để định nghĩa một biểu diễn hoặc mẫu mã được thay thế bằng một chuỗi hoặc một đoạn mã khác trước khi chương trình được biên dịch  (kích thước lớn, tốc độ nhanh).
  - Function là hàm có địa chỉ cố định, Khi được gọi thì con trỏ PC trỏ đến function đó để thực hiện nên (kích thước nhỏ nhưng tốc độ chậm).
</details>
<details><summary> LESSION 2: STDARG - assert.h</summary>

  
</details>
<details><summary> LESSION 3: Point in C</summary>
- Con trỏ là biến lưu địa chỉ của đối tượng khác khác.
- Kích thước con trỏ phụ thuộc vào kiến trúc của VXL.    VD: nếu VDK 8bit = 1 byte => kích thước con trỏ là 1 byte.
                                                                nếu VDK 16bit = 2 byte => kích thước con trỏ là 2 byte.    32 bit là 4 byte.  
- Bản chất của mảng là địa chỉ.
- Biến bình thường là lưu giá trị. Còn biến con trỏ là lưu địa chỉ.  VD: int *prt
- khi khai báo kiểu dữ liệu cho biến con trỏ thì chỉ tham số truyền vào phải đúng KDL đã khai báo của nó. VD: int *ptr (thì biến con trỏ ptr chỉ nhận kiểu dữ liệu int)
- Con trỏ hàm là
                            VD:

                                       void sum (int a, int b)
                                      {
                                          printf("tong la: %d\n", a+b);
                                      }
                                      void tich (int a, int b)
                                      {
                                          printf("tong la: %d\n", a/b);
                                      }
                                      void caculater( void (*pheptinh) (int, int), int a, int b)
                                      {
                                          pheptinh(a,b);
                                      }
                                      int main()
                                      {
                                          caculater(&sum, 8, 9);
                                      }

- const int *ptr là 1 con trỏ hằng số, có thể trỏ đến các đối tượng khác, giá trị của con trỏ này trỏ tới được xem như là 1 hằng số không thể thay đổi.
  
- int *const ADD là không thể trỏ đến các đối tượng khác, giá trị của con trỏ này trỏ có thể thay đổi được.


</details>
<details><summary> LESSION 4: Memory layout in C</summary>
  
 The memory layout in C programming language:
> - Text segment.
> - Initialized data segment.
> - Uninitalized data segment.
> - Heap.
> - Stack.

 Diagram
 
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/afd40e65-9551-4a53-a6f3-58ae27f644fa)

#### - **Text Segment**: 
- Sau khi **compile** chương trình thì chúng ta sẽ có những file nhị phân (những file mà được dùng để execute chương trình của chúng ta khi đổ vào RAM), những file nhị phân (.o) này chứa những cái **instructions**. Và những cái instructions này sẽ stored ở Text Segment of the memory.  
- Text Segment chỉ được read không được modify.
  
#### - **Initialized Data**:
- Initialized Data( data segment): contain values of all static, global, external and constant những cái được initialized trong time thực thi chương trình(# 0).
- Được phép đọc - ghi (vì các value của variables sẽ thay đổi trong khi thực thi chương trình nó không mãi là một constant được nên phải có thể được modify).
- Ví dụ: dưới đây mình khai báo 2 biến , biến **c** được khái báo có giá trị nên nó sẽ nằm trong vùng **data segment** của memory, còn biến **a** sẽ không nằm trong vùng data mà sẽ nằm ở vùng khác.

   ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/9df292be-e1d7-4245-aa67-70c6256c496b)

#### - **Uninitialized Data**:
- Uninitialized Data(BSS): chứa những biến chưa khởi tạo giá trị, và cũng có thể chứa nhưng biến static or global mà được khởi tạo với giá trị là 0.
- Cho phép đọc và ghi.
- Trở lại ví dụ phía trên thì **a** variable sẽ stored in BSS.

> *Một kiểu dữ liệu thì sẽ không nằm trong vùng nào hết, khi nó khai báo biến thì biến đó mới được lưu trong vùng data (initialized or uninitialized) tùy thuộc vào giá trị mà biến đó được khai báo.*

#### - **Heap**:
- Dùng cho bộ nhớ để cấp phát động( trong thời gian chạy chương trình).
- Có thể điều khiển quá trình cấp phát hoặc giải phóng bộ nhớ bằng các câu lệnh như **malloc, calloc, relloc. free, delete,**...
- Khi dùng xong thì phải delete nếu không sẽ bị leak memory.
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/659d19b0-b7c7-470c-8cc8-ceeaf96db913)


       - Malloc & Calloc: 
       >- Malloc: void * malloc(size_t size);
       >- Mục đích: cấp phát một vùng nhớ có kích thước là **size**.
       >- Tham số truyền vào: **1**
       >- Kết quả trả về: là một con trỏ tới vùng nhớ được cấp phát nếu success, NULL nếu fail.
       >- Giá trị khởi tạo: là giá trị rác.
       
       >- Calloc: void * calloc(size_t num, size_t size);
       >- Mục đích: cấp phát một vùng nhớ có chứa **num** phần tử, mỗi phần tử có kích thước là **size**.
       >- Tham số truyền vào: **2**
       >- Kết quả trả về: là một con trỏ tới vùng nhớ được cấp phát nếu fail, NULL nếu success.
       >- Giá trị khởi tạo: là 0.

      Hiệu suất của **malloc** sẽ nhanh hơn **calloc** vì ngoài việc cấp phát vùng nhớ giống **malloc** thì **calloc** còn phải gán cho các phần tử của vùng nhớ vừa cấp phát giá trị là 0.
      Muốn sử dụng calloc hay malloc thì tùy vào người dùng nếu không care tới value của vùng nhớ cấp phát thì use **malloc**, còn nếu muốn all có value bằng 0 thì mình dùng **calloc**.
  
#### - **Stack**:
-  Khác với Heap thì Stack là một vùng nhớ được cấp phát tự động 
- Mỗi khi các function được gọi thì nó sẽ được push vào vùng stack.

  
</details>
<details><summary> LESSION 5: EXTERN - STATIC - VOLATILE - REGISTER</summary>
  
### EXTERN ###
- Dùng để tham chiếu một biến, hàm có cùng name đã được định nghĩa ở nơi khác.
- Khai báo thôi chứ không định nghĩa, biến được kêu ra phải là biến toàn cục của file khác.
### STATIC ###
#### Static với biến cục bộ #### 
- Chỉ có giá trị trong hàm nhưng khi ra khỏi hàm nó ko bị mất đi.
- Một biến được khai báo(định nghĩa hay không định nghĩa) thì nó sẽ bị thu hồi vùng nhớ sau khi ra hỏi hàm. Muốn giữ giá trị của nó không bị mất khi ra khỏi hàm thì dùng từ khóa **Static**.

Ví dụ nếu không dùng biến static:
 
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/fd25bd89-17b3-44ad-a9d5-521031dc7fab)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a567a788-8c2a-497a-b739-b6c818cb3a3c)

               
Ví dụ nếu dùng biến static:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/8ba48217-1993-4adc-b449-0c11dfe0608d)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/103c348a-60ff-48bd-a61a-4185ca616ded)

#### Static với biến toàn cục và hàm: ####
- Chỉ có giá trị trong file chứa nó.
- Dùng được trong chương trình, không cho bên ngoài dùng kể cả **EXTERN.**

### VOLATILE ###
- Thông báo cho compiler ko được tối ưu biến này.
- Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua mã nguồn code.  VD: volatile int var; 
                                                                                                   int volatile var;
  
### REGISTER ###
- là biến yêu cầu lưu nó vào thanh ghi trong PC.
- Giúp tăng tốc độ thực thi chương trình.

</details>
<details><summary> LESSION 6: GOTO - setjmp</summary>
  
*Goto* là một từ khóa trong ngôn ngữ lập trình C cho phép người dùng nhảy đến một label đã được đặt trước đó trong cùng một. Không được khuyến khích dùng vì nó làm cho chương trình trở nên khó đọc và bảo trì. 
>- Ví dụ về từ khóa *go to*

                            #include <stdio.h>
                            void delay(double second)
                            {
                                double start = 0;
                                while (start < second * 6000000)
                                {
                                    start++;
                                }
                            }
                            // Khai báo các trạng thái đèn giao thông
                            typedef enum //1 thời điểm chỉ có 1 đèn để 
                            {
                                RED,
                                YELLOW,
                                GREEN
                            } TrafficLightState;
                            int main() {
                                // Ban đầu, đèn giao thông ở trạng thái đỏ
                                TrafficLightState state = RED;
                            
                                // Vòng lặp vô hạn để mô phỏng đèn giao thông
                                while (1) {
                                    switch (state) {
                                        case RED:
                                            printf("RED Light\n");
                                            delay(50);  // Giữ trạng thái đèn đỏ trong x giây
                                            
                                            // Chuyển đến trạng thái đèn xanh
                                            state = GREEN;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                        case YELLOW:
                                            printf("YELLOW Light\n");
                                            delay(20);  // Giữ trạng thái đèn vàng trong y giây
                                            
                                            // Chuyển đến trạng thái đèn đỏ
                                            state = RED;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                        case GREEN:
                                            printf("GREEN Light\n");
                                            delay(100);  // Giữ trạng thái đèn xanh trong z giây
                                            
                                            // Chuyển đến trạng thái đèn vàng
                                            state = YELLOW;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                    }
                                    // Nhãn để nhảy qua sleep() khi chuyển trạng thái
                                    skip_sleep:;
                                }
                                return 0;
                            }

 >- Trong ví dụ trên trạng thái đèn đỏ đầu tiên, khi chờ khoảng 50s thì trạng thái đèn xanh, nó sẽ thoát ra khỏi switch và bắt đầu switch case khác vì nó đã dùng label skip_Spleep (cái này được đặt ngoài hàm nên nôn na sẽ thoát khỏi hàm, lần lượt chuyển sang đèn khác thứ tự là **ĐỎ - XANH - VÀNG**
*Setjmp.h* là một thư viện trong ngôn ngữ lập trình C cung cấp 2 hàm là *setjmp* và *longjmp* dùng để xử lí ngoại lệ trong( nó không tiêu biểu để xử lí ngoại lệ trong ngôn ngữ này).
>- Ví dụ về *Setjmp.h*

                       #include <stdio.h>
                       #include <setjmp.h>
                       
                       jmp_buf buf;
                       int exception_code;
                       
                       #define TRY if ((exception_code = setjmp(buf)) == 0) 
                       #define CATCH(x) else if (exception_code == (x)) 
                       #define THROW(x) longjmp(buf, (x))
                       
                       
                       double divide(int a, int b) {
                           if (b == 0) {
                               THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
                           }
                           return (double)a / b;
                       }
                       
                       int main() {
                           int a = 10;
                           int b = 0;
                           double result = 0.0;
                       
                           TRY {
                               result = divide(a, b);
                               printf("Result: %f\n", result);
                           } CATCH(1) {
                               printf("Error: Divide by 0!\n");
                           }
                   
                           // Các xử lý khác của chương trình
                           return 0;
                       }


</details>
<details><summary> LESSION 7: BITMASK</summary>

- NOT bit: Đảo bit.      Ví dụ: ~1 = 0 hoặc ~0 = 1
 
- AND biswise: Nhân bit. 0 & 0 = 0
                         1 & 0 = 0
                         0 & 1 = 0
                         1 & 1 = 1
  
- OR biswise: cộng bit.  0 & 0 = 0
                         1 & 0 = 1
                         0 & 1 = 1
                         1 & 1 = 1
  
- XOR bitwise: cộng bit.  0 & 0 = 0
                          1 & 0 = 1
                          0 & 1 = 1
                          1 & 1 = 0
- Sift Left và Shif Right bitwise: << (dịch trái) , >> (dịch phải).
  * Thường ta sẽ bù bit 0 nhưng khi dịch phải có 1 lưu ý đó là: phải chú ý đến bit cao nhất (bit dấu).
  * Bit dấu: nếu bit max là 1 thì đó là số âm nên khi dịch phải mình bù vào số 1.
  * Còn nếu là số dương (bit dấu = 0) thì khi dịch phải truyền vào số 0.

 
</details>
<details><summary> LESSION 8: Struct & Union in C</summary>

 ### Struct ###
  - Là một nhóm kiểu dữ liệu người dùng tự định nghĩa.
  - Mỗi nhóm KDL đều có địa chỉ ô nhớ riêng của nó.
  - Kích thước kiểu dữ kiệu Struct này là tổng byte các kiểu dữ liệu có trong Struct.
    >- VD:
    
             struct Example {    // Struct này sẽ lấy kiểu dữ liệu có byte lớn nhất để tính (ở đây là int có 4 byte) 
             uint8_t a;   //   |1|0|0|0|  chiếm 1 byte
             uint16_t b;  //   |1|1|1|0|  chiếm 2 byte vì đủ kích thước để chứa trong 4 ô
             uint32_t c;  //   |1|1|1|0|  KDL này có 4 byte ko đủ trong ô nhớ vì chỉ còn dư 1 ô
                          //   |1|1|1|1|  nên sẽ tạo thêm 4 ô nữa để chứa đủ 4 byte KDL
             };                  // Tổng kích thước sẽ là 8 byte.
    
 ### Union ###
  - Union trong C là một kiểu dữ liệu đặc biệt có sẵn trong C cho phép lưu trữ các kiểu dữ liệu khác nhau trong cùng một vị trí bộ nhớ.
  - Cấu trúc của Union là tất cả các thành phần của nó dùng chung một vùng nhớ có kích thước tương ứng với thành phần lớn nhất.
  - Dùng để tối kích thước bộ nhớ vì khi dùng 1 thành viên được gọi sẽ sử dụng vùng nhớ đã được cấp đó, tương tự như các thành viên còn lại.
  - Mỗi thành viên đều dùng chung địa chỉ ô nhớ đó.
  - Union chỉ cho phép dùng chung 1 vùng nhớ có kiểu dữ liệu lớn nhất trong nó.
    >- VD:

            Union Example {    // Union này sẽ lấy kiểu dữ liệu có byte lớn nhất (ở đây là int có 4 byte) 
             uint8_t a;   //   |1|0|0|0|  khi được gọi thì biến a (1 byte) chỉ dùng 4 ô. ADD |0x1|0x2|0x3|0x4|
             uint16_t b;  //   |1|1|0|0|  khi được gọi thì biến b (2 byte) chỉ dùng 4 ô. ADD |0x1|0x2|0x3|0x4|
             uint32_t c;  //   |1|1|1|1|  khi được gọi thì biến c (4 byte) chỉ dùng 4 ô. ADD |0x1|0x2|0x3|0x4|
             };                 // Tổng kích thước sẽ là 4 byte.
    
    >- VD:

            Union Example {    // Union này sẽ lấy kiểu dữ liệu có byte lớn nhất (ở đây là int có 4 byte) 
             uint8_t a[9];    //   có 4 ô byte được cấp phát và kiểu dữ liệu biến a này là 2 byte nên tổng biến a này sử dụng 12 byte
                              //            |1|1|1|1|                         |1|1|1|1|                         |1|0|0|0|
                              //  | a[1] | a[2] | a[3] | a[4] |     | a[5] | a[6] | a[7] | a[8] |      | a[9] | 0 | 0 | 0 |
    
             uint16_t b[3];  //   Tổng biến b này sử dụng là  8 byte        | b[1] | b[1] | b[2] | b[2] |         | b[3] | b[3] | 0 | 0 |
             uint32_t c[3];  //   Tổng biến c này sử dụng là  12 byte        | c[1] | c[1] | c[1] | c[1] |       | c[2] | c[2] | c[2] | c[2] |     | c[3] | c[3] | c[3] | c[3] |
             };                  // Tổng kích thước Union sẽ là 12 byte.      
 ### Dùng kết hợp Union && Struct ###
 - Dùng để chia nhỏ dữ liệu ra để dễ xử lý hơn.
  >- Ví dụ:
    
          typedef union
          {
              struct 
              {
                  uint8_t ID[2];
                  uint8_t data[4];
                  uint8_t PRB[2];     //  Struct data này có chiều dài là 8 byte
              }data;
              uint8_t frame[8];       // biến này chiếm 1 byte
          } DT_frame;                 => Union này lấy 8 byte cùng nhớ
  
</details>        
<details><summary> LESSION 9: JSON in C</summary>
  
- Định dạng: luôn bắt đầu bằng dấu "........."
              Một object luôn nằm trong dấu {........}
              "<key (luôn là kiểu String)>"  :  " value "

  VD:

                    char *json = "
                    {
                      "name" : "Nguyen",
                      "age" : 23,
                      "City" : "BinnDinh",
                      "Job"  : "Embedded"
                      "SLR"  : [20, 30, 50]
                    } "

- Các kiểu của JSON                              typedef enum {
                                                              JS_NULL,
                                                              JS_Boolean,
                                                              JS_Number,
                                                              JS_String,
                                                              JS_Array,
                                                              JS_Ọpect
                                                  } JS_type;

  
</details>
<details><summary> LESSION 10: Linker List</summary>
  
</details>
<details><summary> LESSION 11: Stack and Queue </summary>
  
Stack: 
- là một cấu trúc dữ liệu được xếp theo nguyên tắc LIFO (Last in Firt out), nghĩa là phần từ đầu tiên được đưa vào thì sẽ được lấy ra sau cùng và phần tử được đưa vào cuối cùng sẽ được lấy ra đầu tiên.
- Thao tác trên Stack:     - Push - Pop - Top 
  
  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/120b0018-4490-49f0-b9ec-1a15a7e94622)

- PUSH : Đưa phần tử vào
- POP : Lấy phần tử trên cùng ra
- TOP : Lấy giá trị trên cùng
- VD:
  
                                typedef struct Stack {      // Khởi tạo struct chứa các kiểu dữ liệu của stack
                                    int* items;
                                    int size;
                                    int top;
                                } Stack;
                                
                                void initialize( Stack *stack, int size) {                // khởi tạo stack và size của nó
                                    stack->items = (int*) malloc(sizeof(int) * size);     // cấp phát ô nhớ cho mảng stack có size ổ nhớ của phân từ và mỗi ô nhớ của phần tử đó kích thước kiểu int
                                                                                            // Vd size = 5 thì mảng stack đó có 5 phần tử và mỗi phần tử có kích thước 4byte kiểu int. size của mảng sẽ là 20 byte
                                                                                            // kích thước mảng= kích thước của mỗi phần tử X số lượng phần tử    
                                    stack->size = size;  
                                    stack->top = -1;
                                }
                                
                                int is_empty( Stack stack) {
                                    return stack.top == -1;
                                }
                                
                                int is_full( Stack stack) {
                                    return stack.top == stack.size - 1;          // Kiểm tra vị trí hiện tại có bằng với size đó ko. VD: stach.top = 4, stack.size-1 = 5 - 1 2 cái bằng nhau thì trả về 1.
                                }
                                
                                void push( Stack *stack, int value) {
                                    if (!is_full(*stack)) {                      // kiểm tra xem stack đó đã max phần tử hay chưa
                                        stack->items[++stack->top] = value;
                                    } else {
                                        printf("Stack overflow\n");
                                    }
                                }
                                
                                int pop( Stack *stack) {
                                    if (!is_empty(*stack)) {
                                        return stack->items[stack->top--];       // trả về giá trị item và top - 1 VD: top = 3,   stack->top-- = 3-1 = 2,  return imtems[2].
                                    } else {
                                        printf("Stack underflow\n");
                                        return -1;
                                    }
                                }
                                
                                int top( Stack stack) {
                                    if (!is_empty(stack)) {
                                        return stack.items[stack.top];
                                    } else {
                                        printf("Stack is empty\n");
                                        return -1;
                                    }
                                }
                                
                                int main() {
                                    Stack stack1;
                                    initialize(&stack1, 5);
                                
                                
                                    push(&stack1, 10);
                                    push(&stack1, 20);
                                    push(&stack1, 30);
                                    push(&stack1, 40);
                                    push(&stack1, 50);
                                    push(&stack1, 60);
                                
                                    printf("Top element: %d\n", top(stack1));
                                
                                    printf("Pop element: %d\n", pop(&stack1));
                                    printf("Pop element: %d\n", pop(&stack1));
                                
                                    printf("Top element: %d\n", top(stack1));
                                
                                    return 0;
                                }
Queue:
- một cấu trúc dữ liệu được xếp theo nguyên tắc FIFO (Fast in Firt out), nghĩa là phần từ đầu tiên được thêm vào sẽ được lấy ra đầu tiên.
- “enqueue” (thêm phần tử vào cuối hàng đợi)      ( nếu đã full mà enqueue nữa thì sẽ bị Stack overflow )
- “dequeue” (lấy phần tử từ đầu hàng đợi).      ( nếu ko có phần tử nào trong mảng đó thì khi dequeue thì sẽ báo lỗi )
- “front”   để lấy giá trị của phần tử đứng đầu hàng đợi.

  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/73e6bfe1-6d68-4746-ae66-595f37fec8c6)

- VD:
  
                                typedef struct Queue {
                                    int* items;
                                    int size;
                                    int front, rear;
                                } Queue;
                                
                                void initialize(Queue *queue, int size) 
                                {
                                    queue->items = (int*) malloc(sizeof(int)* size);    // cấp phát ô nhớ cho mảng queue có size ổ nhớ của phân từ và mỗi ô nhớ của phần tử đó kích thước kiểu int
                                                                                            // Vd size = 5 thì mảng queue đó có 5 phần tử và mỗi phần tử có kích thước 4byte kiểu int. size của mảng sẽ là 20 byte
                                                                                            // kích thước mảng= kích thước của mỗi phần tử X số lượng phần tử 
                                    queue->front = -1;                                  // khởi tạo phần từ
                                    queue->rear = -1;                                   // khởi tạo phần từ
                                    queue->size = size;                                 // khởi tạo kích thước
                                }
                                
                                int is_empty(Queue queue) {
                                    return queue.front == -1;
                                }
                                
                                int is_full(Queue queue) {
                                    return (queue.rear + 1) % queue.size == queue.front;           // (4 + 1) % 5 = 0 => đủ bộ nhớ
                                }
                                
                                void enqueue(Queue *queue, int value) {                            // Thêm phần tử vào
                                    if (!is_full(*queue)) {                                        // kiểm tra có bị full hay ko
                                        if (is_empty(*queue)) {                                    // kiểm tra có bị rỗng hay ko
                                            queue->front = queue->rear = 0;                            // nếu rỗng thì gán front và rear = 0 để chỉ tới ô thứ tự đầu tiên trong mảng
                                        } else {
                                            queue->rear = (queue->rear + 1) % queue->size;             // nếu không rỗng thì gán vào rear để chỉ tới ô thứ tự rear trong mảng. VD: (0 + 1) % 5 = 0.1 dư 1 => rear = 1
                                        }                                                                                                                                          (1 + 1) % 5 = 0.2 dư 2 => rear = 2
                                        queue->items[queue->rear] = value;                         // gán giá trị vào ô thứ tự rear đó. VD: rear =0 thì items[0] = 4.
                                    } else {                                                                                                            items[1] = 5.
                                        printf("Queue overflow\n");
                                    }
                                }
                                
                                int dequeue(Queue *queue) {
                                    if (!is_empty(*queue)) {
                                        int dequeued_value = queue->items[queue->front];
                                        if (queue->front == queue->rear) {
                                            queue->front = queue->rear = -1;
                                        } else {
                                            queue->front = (queue->front + 1) % queue->size;
                                        }
                                        return dequeued_value;
                                    } else {
                                        printf("Queue underflow\n");
                                        return -1;
                                    }
                                }
                                
                                int front(Queue queue) {
                                    if (!is_empty(queue)) {
                                        return queue.items[queue.front];
                                    } else {
                                        printf("Queue is empty\n");
                                        return -1;
                                    }
                                }
                                
                                int main() {
                                    Queue queue;
                                    initialize(&queue, 3);
                                
                                    enqueue(&queue, 10);
                                    enqueue(&queue, 20);
                                    enqueue(&queue, 30);}
  
                                
