
# ADVANCE C
## **LESSION 1: Compiler - Macro C**
## **LESSION 2: STDARG - assert.h**
## **LESSION 3: Point in C**


## **LESSION 4: Memory layout in C**
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

  
## **LESSION 5: EXTERN - STATIC - VOLATILE - REGISTER**
### EXTERN ###
- Dùng để tham chiếu một biến, hàm có cùng name đã được định nghĩa ở nơi khác.
- Khai báo thôi chứ không định nghĩa, biến được kêu ra phải là biến toàn cục của file khác.
### STATIC ###
#### Static với biến cục bộ #### 
- Một biến được khai báo(định nghĩa hay không định nghĩa) thì nó sẽ bị thu hồi vùng nhớ sau khi ra hỏi hàm. Muốn giữ giá trị của nó không bị mất khi ra khỏi hàm thì dùng từ khóa **Static**.

Ví dụ nếu không dùng biến static:
 
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/fd25bd89-17b3-44ad-a9d5-521031dc7fab)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a567a788-8c2a-497a-b739-b6c818cb3a3c)

               
Ví dụ nếu dùng biến static:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/8ba48217-1993-4adc-b449-0c11dfe0608d)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/103c348a-60ff-48bd-a61a-4185ca616ded)

#### Static với biến toàn cục và hàm: ####
- Dùng được trong chương trình không cho bên ngoài dùng kể cả **EXTERN.**

### VOLATILE ###
- Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua mã nguồn code.  VD: volatile int var; 
                                                                                                   int volatile var;
  
### REGISTER ###



## **LESSION 6: GOTO - setjmp**
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


## **LESSION 7: BITMASK**

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
 
## **LESSION 8: Struct & Union in C**

 ### Struct ###
  - Là một nhóm kiểu dữ liệu người dùng tự định nghĩa.
  - Mỗi nhóm KDL đều có địa chỉ ô nhớ riêng của nó.
  - Kích thước kiểu dữ kiệu Struct này là tổng byte các kiểu dữ liệu có trong Struct.         VD: struct Example {    // Struct này sẽ lấy kiểu dữ liệu có byte lớn nhất để tính (ở đây là int có 4 byte) 
                                                                                                     uint8_t a;   //   |1|0|0|0|  chiếm 1 byte
                                                                                                     uint16_t b;  //   |1|1|1|0|  chiếm 2 byte vì đủ kích thước để chứa trong 4 ô
                                                                                                     uint32_t c;  //   |1|1|1|0|  KDL này có 4 byte ko đủ trong ô nhớ vì chỉ còn dư 1 ô
                                                                                                                  //   |1|1|1|1|  nên sẽ tạo thêm 4 ô nữa để chứa đủ 4 byte KDL
                                                                                                  };                  // Tổng kích thước sẽ là 8 byte.
 ### Union ###
  - Là một cấu trúc dữ liệu nhóm gồm nhiều kiểu dữ liệu khác nhau vào chung 1 Union, mỗi khi dùng thì chỉ 1 thành viên trong Union dùng vùng nhớ.
  - Dùng để tối kích thước bộ nhớ vì khi dùng 1 thành viên được gọi sẽ sử dụng vùng nhớ đã được cấp đó, tương tự như các thành viên còn lại.
  - Mỗi thành viên đều dùng chung địa chỉ ô nhớ đó.
  - Union chỉ cho phép dùng chung 1 vùng nhớ có kiểu dữ liệu lớn nhất trong nó.               VD: Union Example {    // Union này sẽ lấy kiểu dữ liệu có byte lớn nhất (ở đây là int có 4 byte) 
                                                                                                     uint8_t a;   //   |1|0|0|0|  khi được gọi thì biến a (1 byte) chỉ dùng 4 ô.
                                                                                                     uint16_t b;  //   |1|1|0|0|  khi được gọi thì biến b (2 byte) chỉ dùng 4 ô.
                                                                                                     uint32_t c;  //   |1|1|1|1|  khi được gọi thì biến c (4 byte) chỉ dùng 4 ô.
                                                                                                  };                 // Tổng kích thước sẽ là 4 byte.
