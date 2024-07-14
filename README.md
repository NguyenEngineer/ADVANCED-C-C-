
# ADVANCE C

   https://hala.edu.vn/c-co-ban/cac_quy_tac_ve_dat_ten_theo_tieu_chuan_autosar_c_coding_guidelines/
   
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

</details>
<details><summary> LESSION 1: Compiler - Macro C</summary>
  - Macro là một cách để định nghĩa một biểu diễn hoặc mẫu mã được thay thế bằng một chuỗi hoặc một đoạn mã khác trước khi chương trình được biên dịch  (kích thước lớn, tốc độ nhanh).
  - Function là hàm có địa chỉ cố định, Khi được gọi thì con trỏ PC trỏ đến function đó để thực hiện nên (kích thước nhỏ nhưng tốc độ chậm).
</details>
<details><summary> LESSION 2: STDARG - assert.h</summary>
   
- Thư viện Stdarg cung cấp các phương thức làm việc với các input parameter không xác định. Ví dụ điển hình là *scanf*,*printf*
- Các tham số:
   + va_list:là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
   + va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
   + va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ .
   + va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

- Thư viện Assert
   + Cung cấp macro assert. 
   + Macro này được sử dụng để kiểm tra một điều kiện. 
   + Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
   + Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
   + Dùng trong debug, dùng #define NDEBUG để tắt debug

  
</details>
<details><summary> LESSION 3: Point in C</summary>
- Con trỏ là biến lưu địa chỉ của đối tượng khác khác.
   
- Kích thước con trỏ phụ thuộc vào kiến trúc của VXL.

        VD:   nếu VDK 8bit = 1 byte => kích thước con trỏ là 1 byte.
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

![image](https://github.com/NguyenEngineer/AdvanceC/assets/124705679/0153edae-9d15-4b48-be4c-f4ba1b1950a4)

- Mình có một mảng này, muốn xóa 1 phần tử bất kì trong chuỗi ta làm lần lượt các bước: cho giá trị tại vị trí đó là *null* xong nhích giá trị hiện tại lên, giá trị phần tử cuối cùng mình reallocate để chuỗi còn (n-1) phần tử.
  **=> Đặt ra vấn đề:Nếu như một mảng có 10000 phần tử chả nhẻ xóa ở vị trí bất kì mình dịch chuyển 9999 vòng lặp như thế sao?**
Hoặc ví dụ nếu mình muốn thêm một phần tử thì các bước : cấp phát thêm ở vị trí cuối mảng (null), sau đó xê dịch lần lượt ra.

*=> Việc xóa hay chèn 1 phần tử rất là mất thời gian* => người ta đưa ra **linked list(mảng nhân tạo)** 

Linked List là một cấu trúc dữ liệu trong lập trình máy tính dùng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các nút (node), mỗi nút chứa một giá trị dữ liệu hoặc một con trỏ(pointer) tới nút tiếp theo trong chuỗi. Note cuối thì con trỏ NULL.
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/4eb21968-3ec1-47fb-add8-267b0711b462)

Muốn thêm một node vào cuối một mảng thì mình tạo ra một note trước, giá trị của con trỏ là null, sau đó mình lưu địa chỉ của nó vào pointer của note trước nó.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1ef71755-233e-46dd-bc8a-60fbfc47ba5a)

*Ví dụ:* thêm node vào vị trí thứ 2 của mảng: ta chỉ cần thay đổi pointer của nút cần thêm vào là dịa chỉ của phần từ tiếp theo , và thay đổi pointer của nút trước đó thành địa chỉ của nút mình muốn thêm vào

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/ecddb42e-c932-490e-b0a5-d92d97b9e8b5)

Tương tự ví dụ:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/46abea42-aac1-4728-8614-21e1238296eb)

=>Muốn xóa một phần tử tại vị trí bất kì ta chỉ cần gì note của phần tử đó vào node của phần tử đứng trước đó(tương đương với ghi địa chỉ của phần tử tiếp theo vào vị trí của phần tử đứng trước đó vì note của phần tử đó lưu địa chỉ của phần tử đứng sau)

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
  
</details>
<details><summary> LESSION 12: Binary search & File operations </summary> 

## Binary search
- Thuật toán tìm kiếm nhị phân:    ---> nếu mảng nhỏ thì tìm kiếm các giá trị phần tử trong mảng rất dễ dàng.
                                   --->  nều mảng tô thì ko thể tìm kiếm như bình thường được nên ta phải dùng thuật toán tìm kiếm nhị phân.
- Cách triển khai:
   - Mảng luôn phải được sắp xếp treo giá trị từ bé đến lớn.
   - Xác định giá trị lớn nhất và nhỏ nhất (đầu mảng và cuối mảng).
   - So sánh giá trị cần tìm với giá trị ở giữa mảng ( mid = (đầu + cuối) / 2).
   - Nếu giá trị cần tìm lớn hơn giá trị mid thì chỉ lấy từ (vùng mid --> cuối) để xử lý.
   - Nếu giá trị cần tìm nhỏ hơn giá trị mid thì chỉ lấy từ (vùng mid --> đầu) để xử lý.       (nếu = mid thì đúng là thoát)                         
   - Thực hiện đến khi tìm đước giá trị bằng với giá trị cần tìm.
 
  VD:
  
                 int binarySearch(int* arr, int l, int r, int x)
               {
                if (r >= l)
                {
                    int mid = (r + l) / 2;
                    if (arr[mid] == x)  return mid;
                    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
                    return binarySearch(arr, mid + 1, r, x);
                }
  
  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/8ccf2e7e-c803-4a84-ac08-bfd68c74fbb4)
  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/360738e9-7172-46b5-a306-4b64541368a1)
  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/b209cf56-7066-4344-b532-03c93637bbb9)
  
## File operations
- Là một loại file văn bản được sử dụng để lưu trữ và truyền tải dữ liệu có cấu trúc dưới dạng bảng, trong đó các dữ liệu của các cột được phân tách bằng dấu phẩy (,) hoặc một ký tự ngăn cách khác.
VD:

            Họ và tên, Tuổi, Địa chỉ, Số điện thoại
            John Doe, 30, 123 Main St, 555-1234
            Jane Smith, 25, 456 Oak St, 555-5678
            Bob Johnson, 40, 789 Pine St, 555-8765
- Để mở 1 file thì dùng lệnh:       FILE *file = fopen(const char *file_name, const char *access_mode);
- Các chế độ:
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/4d7bf42b-9efb-4bfe-a011-687356abf0c5)
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/2c2bbd30-28e0-4734-a81b-270ab7fd7793)
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/56c723a9-7bbd-4ef2-9c0e-bd383d9d510c)
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/d80148f5-7468-40b9-9855-51788ba67320)
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/c2bf2f7a-5a2d-404c-ac4c-c09c22944b17)
         ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/5e140080-b67d-48c0-96de-2089c3250787)

  
</details>

# ADVANCE C++

<details><summary> Lesson 1: Class</summary>
   
- là 1 lớp hoặc là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan.

- Trong 1 class có :  thuộc tính (property), phương thức khởi tạo (constructor), hàm hủy (destructor).

- phương thức khởi tạo (constructor) là một method sẽ được tự động gọi khi khởi tạo object.

- Destructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng.

- Toán tử truy cập < :: >.

VD: 
   
                  public:
                   double chieuDai;      //phương thức khởi tạo
                   double chieuRong;
                   
                   static int var;
               };
                  int HinhChuNhat::var;  // toán tử truy cập
                  
- Static sử dụng trong class: là biến dùng chung, một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.

- 	Khi một method trong class được khai báo với từ khóa static:
         Method này độc lập với bất kỳ đối tượng nào của lớp.
         Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
         Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
         Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
         Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.

</details>   
<details><summary> Lesson 2: OOP </summary>
   
## Encapsulation
- Encapsulation (tính đóng gói) là dùng để ẩn đi các property "bảo mật" khỏi người dùng. Khai báo các property ở quyền private (không thể truy cập trực tiếp với các property này).
- Để truy cập được vào các property đã được bảo mật thì ta phải khao báo nó thông qua các method ở vùng public.
VD: 

                     class Student
                     {
                         private:
                             string Name;
                             double GPA;
                             int StudentID;
                         public:
                         Student(string name);
                     
                         string getName()
                         {
                             return Name;
                         }
                     
                         void setGPA(double gpa)
                         {
                             GPA = gpa;
                         }
                         double getGPA()
                         {
                             return GPA;
                         }
                     
                         int getID()
                         {
                             return StudentID;
                         }               
                     };
                     
## Inheritance (tính kế thừa)                
- Inheritance (tính kế thừa) là class sẽ được kế thừa các property và methor của class cha.
- Để được kế thừa thì phải thông qua ký tự " : "
- Có 3 kiểu kế thừa ( private, protected, public)
VD:

                  class Person
                  {
                  protected:
                    string Name;
                    int Age;
                    string Home_Address;
                  
                  public:
                    string getName()
                    {
                      return Name;
                    }
                    void setName(string name)
                    {
                      Name = name;
                    }
                  
                    int getAge()
                    {
                      return Age;
                    }
                    void setAge(int age)
                    {
                      Age = age;
                    }
                  
                    string getAddress()
                    {
                      return Home_Address;
                    }
                    void setAddress(string address)
                    {
                      Home_Address = address;
                    }
                  
                    void displayInfo()
                    {
                      cout << "Name: " << Name << endl;
                      cout << "Age: " << Age << endl;
                      cout << "Address: " << Home_Address << endl;
                    }};
                  
                  class Student : public Person
                  {
                  private:
                    string School_Name;
                    double GPA;
                    int StudentID;
                  
                  public:
                    Student()
                    {
                      static int id = 1000;
                      StudentID = id;
                      id++;
                    }
                  
                    string getSchoolName()
                    {
                      return School_Name;
                    }
                    void setSchoolName(string school_name)
                    {
                      School_Name = school_name;
                    }
                  
                    double getGPA()
                    {
                      return GPA;
                    }
                    void setGPA(double gpa)
                    {
                      GPA = gpa;
                    }
                  
                    int getID()
                    {
                      return StudentID;
                    }
                  
                    void displayInfo() // overriding
                    {
                      cout << "Name: " << Name << endl;
                      cout << "Age: " << Age << endl;
                      cout << "Address: " << Home_Address << endl;
                      cout << "School name: " << School_Name << endl;
                      cout << "GPA: " << GPA << endl;
                    }
                  };
- Sự khác nhau giữa private và protected:
   + Giống nhau: Các property của 2 quyền truy cập đều được ẩn khỏi người dùng và chỉ đươc truy cập thông qua các method ở vùng public
   + Khác nhau: Khi được kế thừa thì chỉ có Protected và public được kế thừa, còn privater không được kế thừa.
 
## Polymorphism
- Polymorphism (tính đa hình) là cách dùng những method được kế thừa để thực hiện các tác vụ khác nhau. Cùng là 1 method nhưng có nhiều kiểu dùng khác nhau
- (Function overriding) là lớp con ghi đè được lên lớp cha thông qua phương thức
  
- (Function overloading) cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.
- Từ khóa virtual là từ khóa giúp cho lớp con ghi đề được lên lớp cha khi kế thừa
VD:

         class Person
         {
         protected:
           string Name;
           int Age;
           string Home_Address;
         
         public:
           virtual string test()
           {
             return "Hello person";
           }
         
           void displayInfo()
           {
             cout << test() << endl;
           }  
         };
         
         class Student : public Person
         {
         private:
           string School_Name;
           double GPA;
           int StudentID;
         
         public:
           string test()
           {
             return "Hello student";
           }
         };

## Abstract
- Abstract (tính trừ tượng) là việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.
class GiaiPhuongTrinh
VD:

            {
                private:
                    double a;
                    double b;
                    double c;
                    double x1;
                    double x2;
                    double delta;
                    void tinhNghiem()    // ẩn đi hàm tính ko cho người dùng thấy
                    {
                        delta = b*b - 4*a*c;
                        if (delta < 0)
                        {
                            delta = -1;
                        }
                        else if (delta == 0)
                        {
                            x1 = x2 = -b/ (2*a);
                        }
                        else if (delta > 0)
                        {
                            x1 = (-b + sqrt(delta))/(2*a);
                            x2 = (-b - sqrt(delta))/(2*a);
                        }
                    }
                    
                public:
            
                    void enterNumber(double num_a, double num_b, double num_c);
                    void printResult();
            
            };
            
            void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c)
            {
                a = num_a;
                b = num_b;
                c = num_c;
            }
            
            void GiaiPhuongTrinh::printResult()
            {
                tinhNghiem();
                if (delta == -1)
                {
                    cout << "PT vo nghiem" << endl;
                }
                else if (delta == 0)
                {
                    cout << "PT co nghiem chung: " << x1 << endl;
                }
                else if (delta > 0)
                {
                    cout << "PT co 2 nghiem: \n";
                    cout << "x1: " << x1 << endl;
                    cout << "x2: " << x2 << endl;
                }
                
                
            }
            
            
            int main()
            {
              GiaiPhuongTrinh phuongtrinh1;
              phuongtrinh1.enterNumber(1,5,4);
              phuongtrinh1.printResult();
            
              return 0;
            }
  
</details>
<details><summary> LESSION 3: Standard template library C</summary>       


</details>
<details><summary> LESSION 4: Template && Generic C</summary>    

## Function Template in C
- Function templates là một tính năng giúp viết các function hoặc class chung có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau.
VD:

      template <typename T>
      T myFunction(T a, T b) {
          return a + b;
      }
      int result1 = myFunction(5, 10);       // Tự động suy luận T là int
      double result2 = myFunction(3.14, 2.71);  // Tự động suy luận T là double
  
## Function Template in Class
- Tương tự như function templates, nhưng được áp dụng cho class thay vì function.
- Class templates cho phép bạn viết một lớp chung mà có thể được sử dụng với nhiều kiểu dữ liệu khác nhau.
VD:

         template <typename T>                                    // Khai báo ra 1 template tên T
         class MyContainer {
         private:
             T element;                                          // khai báo tên element với kiểu dữ liệu là T (kdl ko biết trc)
         
         public:
             MyContainer(T val) : element(val) {}               // đây là cách code nhanh gọn giống kiểu gán giá trị   VD: MyContainer(T val) {  element = val; }
         
             T getValue() const {
                 return element;
             }
         };
         int main()
         {
             MyContainer<int> intContainer(42);                  // khi sử dụng thì phải chỉ định cụ thể KDL của nó 
             MyContainer<double> doubleContainer(3.14);
             MyContainer<string> stringContainer("Trung");
         
             int intValue = intContainer.getValue();
             double doubleValue = doubleContainer.getValue();
             string stringValue = stringContainer.getValue();
         
             cout << "int value: " << intValue << endl;
             cout << "double value: " << doubleValue << endl;
             cout << "string value: " << stringValue << endl;
         
             return 0;
         }

</details>
<details><summary> LESSION 5: Smart Poiter </summary>


- Để có thể tự động hóa việc cấp phát và tự thu hồi vùng nhớ thì ta sử dụng object trong c++.

- Smart poiter là con trỏ có thể tự giải phóng nó sau khi đã sử dụng để tránh lỗi memory leak.

![image](https://github.com/user-attachments/assets/18cbf258-cccb-4e31-98f6-bca707e291be)


- Sử dụng bộ thư viện <memory> để sử dụng các smart poiter này.

Các loại poiter:
•	auto_ptr (ít được dùng)

•	unique_ptr (sở hữu độc quyền 1 đối tượng được cấp phát động)  

- Unipue poiter chỉ cho phép 1 owner duy nhất tại 1 thời điểm.( tức là chỉ 1 con trỏ chỉ đc trỏ tới 1 đối tượng).

- Khi có 2 unique_ptr quản lý 1 tài nguyên thì sẽ vi phạm nguyên tắc. Để chuyển tài nguyên của 1 unique_ptr này sang unique_ ptr khác ta dùng lệnh move().

  ![image](https://github.com/user-attachments/assets/97b4d4c1-9d57-4ff3-a3f7-6f83b1aed6d6)


•	shared_ptr (cho phép nhiều con trỏ share_poiter cùng trỏ đến 1 đối tượng được cấp phát. Nghĩa là tài nguyên mà share_ptr chia sẽ thì các đối tượng khác có thể sở hữu nó)

- Dùng nhiều sẽ giảm hiệu suất CT.

- Để quản lý share_ptr sử dụng cơ chế reference couting (đếm về 0 )để đảm bảo khi share_ptr ko còn quản lý tài nguyên đó nữa thì nó sẽ tự động thu hồi.

- Vấn đề rủi ro: Cyclic dependency của share_ptr (sảy ra khi 2 class chứa share_poiter trỏ vào nhau)

- Khi này cơ chế reference couting ko thể đếm về 0 để thu hồi vùng nhớ khiến cho vùng nhớ ko đc giải phóng. Do vậy ta có thêm weak_ptr.

         VD: 
                     #include<iostream>
                     #include<memory>
                     
                     using namespace std;
                     
                     class Tinhdientich
                     {
                     private:
                         int chieudai;
                         int chieurong;
                     
                     public:
                         Tinhdientich(int num_cd, int num_cr)
                         {
                             chieudai = num_cd;
                             chieurong = num_cr;
                             cout << "constuct is call" << endl;
                         }
                         void dientich()
                         {
                             cout << "Dien tich: " << chieudai * chieurong << endl;
                         }
                     
                     
                         ~Tinhdientich()
                         {
                             cout << " Destructer " << endl;
                         };
                     };
                     
                     int main()
                     {
                         shared_ptr <Tinhdientich> ptr1(new Tinhdientich(20,10));
                     
                         (*ptr1).dientich();
                     
                         cout << ptr1.use_count();
                     
                         return 0;
                     }

•	weak_ptr ( giống như share_ptr nhưng nó ko duy trì cơ chế reference couting. Nghĩa là dù có 4 weak_ptr trỏ vào tài nguyên đó mà ko có share_ptr nào trỏ đến TN đó hết thì vùng nhớ sẽ đc thu hồi)
weak_ptr được sử dụng với các shared_ptr trong trường hợp circular dependencies (có thể gây nên circular references

![image](https://github.com/user-attachments/assets/f69a08ff-c274-494f-b9c2-4eee7a187feb)

![image](https://github.com/user-attachments/assets/64616a5c-3271-4a8c-afd1-ccd4ee802fcd)

 
- weak_ptr cũng có 1 điểm yếu rất lớn khi sử dụng, mỗi lần sử dụng tài nguyên mà weak_ptr tham chiếu đến, cần phải thực hiện câu lệnh lock() để tạo ra 1 shared_ptr trỏ tới tài nguyên đó
- chi phí để copy-constructing 1 shared_ptr (tạo ra 1 đối tượng shared_ptr bằng copy constructor của nó thông qua 1 shared_ptr khác đã tham chiếu tài nguyên) là rất lớn so với các câu lệnh tính toán thông thường 


   
</details>
<details><summary> LESSION 6: Mutithreading </summary>
   
## Process (tiến trình)
- Là để chỉ 1 chương trình khi dang chạy trên 1 hệ thống hoặc công việc chạy trên máy tính.
   
- Trong tiến trình (process) có thể bao gồm 1 hoặc nhiều thread khác nhau thực hiện công việc.

- Và process chứa các tài nguyên như bộ nhớ, CPU, ...

- Bản chất VDK là 1 tiến trình và mỗi process là 1 con VDK khác nhau.

- Process based multitasking tiêu tốn nhiều tài nguyên hơn.

- Process cần phải cấp phát không gian địa chỉ (address space) cho chính nó.

Exam: Trên máy tính ta chạy nhiều app khác nhau như chrom, word,..

## Thread (luồng)
- Trong thread nằm trong 1 process. Có 1 hoặc nhiều thread chạy cùng lúc. Mỗi thread chạy 1 công việc khác nhau

- Bản chất luồng là nó chạy 1 cách tuần tự (nhìn như chạy song song nhưng là tuần tự).

- Các thread trong cùng 1 process chia sẽ với nhau cùng 1 vùng nhớ và các tài nguyên khác của process (biến toàn cục và cục bộ).

- Thread tiêu tốn ít tài nguyên hơn so với process.

- Các thread chia sẻ không gian địa chỉ (address space) với nhau.

- Trong thread based multitasking thì thread được coi là đơn vị tính nhỏ nhất.

  ![image](https://github.com/NguyenEngineer/ADVANCED-C-C-/assets/120030797/8e1385d9-53bd-442d-857c-d381af08782c)

Ex: Khi sử dụng trình duyệt chorme, ta có thể vừa lướt web, vừa download file cùng một thời điểm. Ở đây, ta nhận thấy lướt web là một thread và việc download là một thread khác.
    Trong 1 app zalo ta có thể làm nhiều việc như đọc thông báo, nhắn tin, gọi điện, ....

- Dùng std:thread để khởi tạo 1 thread object và tham số truyền vào là 1 callable (đối tượng có thể gọi).

- Callable là 1 đoạn code có thể thực thi mà ta mong muốn khi 1 thread chạy.
  
                     Cú pháp: thread _NAME_ (_NAME_FUNCTION_)
                           VD: thread thread_1(task_1);
                                thread_1.join();       // câu lệnh này là đê thread thực hiện task_1 đến khi kết thúc hàm task_1
            
- Một thread có thể được create bằng nhiều callable khách nhau:
  + Sử dụng Function Object
        Là một đối tượng có thể được gọi như một hàm, nhờ vào việc overload operator(). Điều này cho phép bạn truyền đối tượng đó như một hàm vào các API yêu cầu hàm
        Là 1 lớp có toán tử operator, Đây là nơi bạn định nghĩa công việc mà bạn muốn thực hiện trong thread.

             VD:        #include<iostream>
                        #include<thread>
                        
                        using namespace std;
                        
                        class FunOBJ
                        {
                        private:
                            
                        public:
                            void operator() ()
                            {
                                this_thread::sleep_for(chrono::seconds(2)); // giống hàm delay
                                cout << "this is Function object" << endl;
                            }
                        };
                        
                        void task_1()
                        {
                            this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                            cout << "this is Function task_1" << endl;
                        }
                        
                        int main()
                        {
                            FunOBJ myFunction;
                            
                            myFunction();
                        
                            thread thread_OBJ(myFunction);
                            thread thread_1(task_1);
                        
                            thread_OBJ.join();
                            thread_1.join();
                        
                            return 0;
                        }
                          
  + Sử dụng Function Pointer
            
          VD:     #include<iostream>
                  #include<thread>
                  using namespace std;
                  void task_1()
                  {
                      //do something
                  }
                  int main()
                  {
                      thread thread_1(task_1);       // Khởi tạo 1 thread có tên là thread_1 và thread này có nhiệm vụ thực thi hàm task_1
                      thread_1.join();               // câu lệnh này để thread_1 thực thi hàm task_1 để tránh lỗi bỏ qua lệnh.
                      return 0;
                  }
    
  + Sử dụng Lambda Function
  
- Các vấn đề thường gặp trong đa luồng:
     + Data Race: đồng bộ hóa dữ liệu.
       
            VD: Phần mềm vscode bản chất là 1 tiến trình và terminal là 1 tài nguyên, thì tất các các luồng đều truy cập đến tài nguyên chung.
       
                Mà đối với các tài nguyên sử dụng chung, trong 1 thời điểm chỉ cho phép 1 luồng truy cập vào nó.
       
                + TH1: Nếu ko sử dụng mutex thì cả 3 luồng sẽ truy cập đến tài nguyên chung sẽ gây ra lỗi đầu ra dữ liệu ko mong muốn.
       
                + TH2: Nếu sử dụng mutex thì mutex giúp 1 trong 3 luồng truy cập đến tài nguyên chung. (task_1 truy cập đến tài nguyên chung thì task_2 và task_3 ko đc truy cập đến và ngược lại).

                       Cách ct thực hiện:  task_1 tới hàm mutex_cout.lock() thì ko khóa thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_2
                                           task_2 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy tới hàm task_3
                                           tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy trở về lại hàm task_1

                                           task_1 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_2.
                                           task_2 tới hàm mutex_cout.lock() kiểm tra thì đã mở khóa ở trên thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_3
                                           tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy trở về lại hàm task_1
       
                                           task_1 tới hàm mutex_cout.lock() và kiểm tra thấy đã khóa ở trên và đứng chờ và nhảy tới hàm task_2.
                                           task_2 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_3.
                                           tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã mở khóa ở trên thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_1
       
                                           task_1 tới hàm mutex_cout.lock() và kiểm tra thấy đã khóa ở trên và đứng chờ và nhảy tới hàm task_2.
                                           task_2 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy tới hàm task_3
                                           tash_3 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_1.
                                            

                                    #include<thread>
                                    #include<mutex>
                                    using namespace std;
                                    mutex mutex_cout;
                                    void task_1()
                                    {
                                        this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                        mutex_cout.lock();                              // Nếu luồng truy cập đến mà lock này đã khóa thì chờ ở dòng này, còn ko thì khóa lại và thực thi tiếp dòng tiếp theo.
                                        cout << "this is Function task_1" << endl;
                                        mutex_cout.unlock();                            // Mở khóa
                                    }
                                    
                                    void task_2()
                                    {
                                        this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                        mutex_cout.lock();
                                        cout << "this is Function task_2" << endl;
                                        mutex_cout.unlock();
                                    }
                                    
                                    void task_3()
                                    {
                                        this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                        mutex_cout.lock();
                                        cout << "this is Function task_3" << endl;
                                        mutex_cout.unlock();
                                    }
                                    
                                    int main()
                                    {
                                        while (1)
                                        {
                                            thread thread_1(task_1);
                                            thread thread_2(task_2);
                                            thread thread_3(task_3);
                                    
                                            thread_1.join();
                                            thread_2.join();
                                            thread_3.join();
                                        }
                                        return 0;
                                    }
                                               
     + DeadLock:

                 -Khi ta đặt nhiều khóa trong luồng và ta đặt thứ tự khóa chéo nhau trong các luồng thì sẽ xảy ra hiện tượng deadLock.
               
                               VD:     mutex mutex_cout, mutex2;
                                       void task_1()
                                       {
                                           this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                           mutex_cout.lock();                              // Bước 1
                                           mutex2.lock();                                  // Bước 4
                                           cout << "this is Function task_1" << endl;
                                           mutex_cout.unlock();
                                       }
                                       
                                       void task_2()
                                       {
                                           this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                           mutex2.lock();                                  // Bước 2
                                           mutex_cout.lock();                              // Bước 3
                                           cout << "this is Function task_2" << endl;
       
                 - CT sẽ bị deadlock vì task_1 sẽ bị đứng chờ ở lệnh mutex2.lock() và task_2 bị đứng ở lệnh mutex_cout.lock()

                => Vậy nên phải đặt đúng thứ tự các khóa lại với nhau.
       
                                      VD:     mutex mutex_cout, mutex2;
                                       void task_1()
                                       {
                                           this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                           mutex_cout.lock();                              // Bước 1
                                           mutex2.lock();                                  // Bước 4
                                           cout << "this is Function task_1" << endl;
                                           mutex_cout.unlock();
                                       }
                                       
                                       void task_2()
                                       {
                                           this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                           mutex_cout.lock();                              // Bước 3
                                           mutex2.lock();                                  // Bước 2
                                           cout << "this is Function task_2" << endl;
       
     + Race Condition:
          - Là điều kiện thực thi luồng, kiểu như là ta muốn luồng nào đc thực thi trước luồng nào thực thi tiếp theo.
            
                                      VD:    #include<condition_variable>
                                             mutex mutex_cout, mutex2;
                                             
                                             condition_variable make_cake;
                                             bool Ready = false;
                                             
                                             void task_1()
                                             {
                                                 this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                             
                                                 lock_guard<mutex> lock(mutex_cout);           // giống smart poiter và chức năng giống như lock() nếu khóa thì đứng chờ, chưa khóa thì khóa và thực hiện lệnh tiếp theo
                                                 Ready = true;
                                                 cout << "Function task_1 is done" << endl;
                                                 make_cake.notify_one();                        // tự mở khi thực hiện xong hàm, báo cho luồng khác là đã xong.
                                             }
                                             void task_2()
                                             {
                                                 unique_lock<mutex>  lock(mutex2);
                                                 make_cake.wait(lock, [] {return Ready; });      //chờ khi có luồng khác báo đã thực thi xong và thực thi hàm của mình đi. 
                                                 Ready = false;
                                                 cout << "this is Function task_2" << endl;
                                             }
            
               - Ví dụ trên thực thi xong luồng task_1 thì luồng task_2 mới được thực thi.
- Luồng có 2 loại: (đồng bộ và bất dồng bộ)
     + Đồng bộ là luồng hoạt động bình thường, sử dụng các tài nguyên chung truy cập cùng nhau cùng 1 thời điểm. Làm việc chung với nhau.
 
     + Bất đồng bộ là luồng hoạt động không cần chờ đợi kết quả trước khi tiếp tục thực hiện luồng khác. Các luồng làm việc độc lập và ko phụ thuộc vào nhau.
 
                                VD: #include<future>
                                    int Couter = 0;
                                    mutex mutex_cout;
                                    void loading()
                                    {
                                        for(Couter = 0; Couter <= 10; Couter++)
                                        {
                                            this_thread::sleep_for(chrono::seconds(2));
                                        }
                                    
                                    }
                                    
                                    void displayProcessLoading()
                                    {
                                        while (1)
                                        {
                                            this_thread::sleep_for(chrono::seconds(1));
                                            mutex_cout.lock();
                                            cout << "Loading game: " << Couter * 10 << "%" <<  endl;
                                            mutex_cout.unlock();
                                    
                                            if(Couter == 10) break;
                                        }  
                                    }
                                    
                                    void displayComplete()
                                    {
                                        mutex_cout.lock();
                                        cout << "Screen display game" << endl;
                                        mutex_cout.unlock();
                                    }
                                    
                                    int main()
                                    {
                                        future<void> result = async(launch::async, loading);            // khởi tạo luồng chạy độc lập (bất đồng bộ) và tham số truyền vào là hàm loading
                                        thread thread_1(displayProcessLoading);
                                    
                                        result.get();                                                   // lệnh này là kiểm tra hàm async đã thực hiện xong chưa 
                                        displayComplete();
                                    
                                        thread_1.join();
                                        return 0;
                                    }

  Giải thích:
     + "future<void> result = async(launch::async, loading) " khởi tạo 1 luồng bất đồng bộ đươc thực hiện riêng biệt ko lm ảnh hường đến ct chính.
     
     + Sau khi đã khởi tạo 1 luồng bất đồng bộ thì CT tiếp tục thực hiện hàm tiếp theo " thread thread_1(displayProcessLoading) "
     
     + "result.get()" CT sẽ tiếp tục chạy và hàm này sẽ kiểm tra xem luồng bất đồng bộ đã thực hiện xong chưa. Nếu chưa thì chờ, nếu xong thì nhảy xuống thực hiện lệnh tiếp theo "displayComplete();"
