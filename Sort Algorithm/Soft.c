#include <stdio.h>

/*----------------------------------------------BUBBLE SORT---------------------------------------------------*/


void BubbleSort(int arr[], int length)    //sắp xếp nổi bọt
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


/*----------------------------------------------SELECTION SORT---------------------------------------------------*/


void SelectionSort(int arr[], int length)   // sắp xếp chọn
{
    for(int i = 0; i < length; i++)
    {
        int min = i;                       //5 
        for(int j = i+1; j < length; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
        int temp = arr[i];
        arr[i]  = arr[min];
        arr[min]  = temp;
        }
    }    
}



/*----------------------------------------------INTERTION SORT---------------------------------------------------*/



void IntertionSort(int arr[], int lenght)    //sắp xếp chèn
{
    for(int i = 1; i < lenght; i++)  //    5,4,10,25,9,8,15
    {
        int key = arr[i];       //lấy phần tử thứ i để so sánh (phải là sau pt đầu tiên trong arr)
        int pos = i - 1;        //vị trí để hóa đổi pt
        while (pos >= 0 && key < arr[pos])
        {   
            arr[pos + 1] = arr[pos];  //ví trí pt đã lấy ra so sánh và gán giá trị pt ở trước nó
            --pos;
        }
        arr[pos + 1] = key;  //gán pt key = vị trí của pt đã được gán vào vị trí của key
    }

} 


/*----------------------------------------------COUTING SORT---------------------------------------------------*/

int cnt[10000];

void CoutingSort(int arr[], int length)
{
    int max = arr[0];       // tìm pt lớn nhất trong mảng
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for(int i = 0; i < length; i++)
    {
        cnt[arr[i]]++;      //đếm lên các giá trị lặp lại trong mảng (VD: cnt[25] = 2;)
    }

    for(int i = 0; i <= max; i++)
    {
        if(cnt[i] != 0)
        {
            for(int j = 0 ; j < cnt[i]; j++)
            {
                printf(" %d ", i);
            }
        }
    }
}


/*----------------------------------------------MERGE SORT---------------------------------------------------*/


// void merge(int arr[], int l, int m, int r)      // used c++
// {
//     vector<int> x(arr + l, arr + m + 1);
//     vector<int> y(arr + m + 1, arr + r + 1);
//     int i = 0, j = 0;
//     while (i < x.size() && j < y.size())
//     {
//         if(x[i] <=  y[j])   {arr[l] = x[i]; ++l; ++i;}
//         else{ arr[l] = y[j];  ++l; ++j; }
//     }
    
//     while (i < x.size())
//     {
//         arr[l] = x[i]; ++l; ++i;
//     }

//     while (j < y.size())
//     {
//         arr[l] = y[j]; ++l; ++j;
//     }
// }

void merge(int arr[], int l, int m, int r)      // used c
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];  // Tạo mảng tạm để lưu phần tử của mảng gốc

    // Sao chép dữ liệu vào các mảng tạm thời L[] và R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    while (i < n1 && j < n2)    // Gộp hai mảng con tạm thời vào mảng arr gốc
    {
        if(L[i] <=  R[j])   {arr[l] = L[i]; l++; i++;}

        else{ arr[l] = R[j];  l++; j++; }
    }
    
    while (i < n1)      // Sao chép các phần tử còn lại của L[], nếu còn
    {
        arr[l] = L[i]; l++; i++;
    }

    while (j < n2)    // Sao chép các phần tử còn lại của R[], nếu còn
    {
        arr[l] = R[j]; l++; j++;
    }
    
}

void megreSort(int arr[], int l, int r)     //hàm này để chia mảng gốc thành 2 nữa và từ 2 nữa mảng 
                                            //đó tiếp tục tách ra để sắp xếp 
{
    if(l>=r) return;
    int m = (l+r) /2;
    // Đệ quy sắp xếp hai nửa
    megreSort(arr, l, m);
    megreSort(arr, m+1, r); 
    merge(arr, l ,m, r);
}  


/*----------------------------------------------QUICK SORT---------------------------------------------------*/


int Partition_Lomuto(int arr[], int l, int r) // giải thuật quick sort theo thuật lomuto
{
    int key = arr[r];       //pt cuối cùng trong mảng
    int pos = l - 1;

    for(int j = l; j < r; j++)  //0 1 2 3 4
    {
            if(arr[j] <= key)
            {
                pos++;
                int temp = arr[pos];
                arr[pos]  = arr[j];
                arr[j]  = temp;
            }
    }
    pos++;      // đưa key chốt về giữa mảng để phân tách trái và phải
    int temp = arr[pos];
    arr[pos]  = key;
    arr[r] = temp;  // cập nhập lại vị trí key của mảng ở pt cuối
    return pos; // trả về vị trí của key ở giữa mảng
}

void QuickSort(int arr[], int l, int r)
{
    if(l >= r)  return;
    int k = Partition_Lomuto(arr, l, r);
    QuickSort(arr, l, k - 1);       // nếu ko có k -1 mà thay bằng k thì sẽ bị vòng lặp
    QuickSort(arr, k + 1, r);
}



int main() {

    int a[] = {5,4,10,25,9,8,15};

    int a1[] = {5,5,1,25,25,8,15};

//    BubbleSort(a,7);

//    SelectionSort(a,7);

//    IntertionSort(a,7);

//    CoutingSort(a1, 7);

//    megreSort(a, 0, 6);

    QuickSort(a, 0, 6);

    for(int i = 0; i < 7; i++)
    {
        printf(" %d = %d\n", i, a[i]);
    }

    return 0;
}
