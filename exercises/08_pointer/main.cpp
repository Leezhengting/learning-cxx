#include "../exercise.h"

// READ: 数组向指针退化 <https://zh.cppreference.com/w/cpp/language/array#%E6%95%B0%E7%BB%84%E5%88%B0%E6%8C%87%E9%92%88%E7%9A%84%E9%80%80%E5%8C%96>
bool is_fibonacci(int *ptr, int len, int stride) {
    ASSERT(len >= 3, "`len` should be at least 3");
    // TODO: 编写代码判断从 ptr 开始，每 stride 个元素取 1 个元素，组成长度为 n 的数列是否满足
    // arr[i + 2] = arr[i] + arr[i + 1]
    // for(int i = 1; i < len; i++)
    // {
    //     // if(*(ptr + i * stride) != (*(ptr + (i - 1) * stride) + *(ptr + ((i - 2) * stride))) );
    //     if(ptr[(i + 1) * stride] != ptr[i * stride] + ptr[(i - 1) * stride])
    //     {
    //         return false;
    //     }
    // }
    int a = ptr[0];
    int b = ptr[stride];
    
    // 从第三个斐波那契数开始检查
    for (int i = 2; i < len ; i++) {
        // 计算下一个斐波那契数
        int c = a + b;
        
        // 检查数组中对应的元素是否等于计算出的斐波那契数
        if (ptr[i * stride] != c) {
            return false; // 如果不等于，返回 false
        }
        
        // 更新 a 和 b 为下一个斐波那契数的前两个数
        a = b;
        b = c;
    }
    return true;
}
        // if(*(ptr + i * stride) != (*(ptr + (i - 1) * stride) + *(ptr + ((i - 2) * stride))) );
        // {
        //     std::cout<<(*(ptr + (i - 1) * stride) + *(ptr + ((i - 2) * stride)));
        //     return false;
        // }

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    int arr0[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55},
        arr1[]{0, 1, 2, 3, 4, 5, 6},
        arr2[]{99, 98, 4, 1, 7, 2, 11, 3, 18, 5, 29, 8, 47, 13, 76, 21, 123, 34, 199, 55, 322, 0, 0};
        //                3   4  5 6   7   8  9  10  11 12  13
    // clang-format off
    ASSERT( is_fibonacci(arr0    , sizeof(arr0) / sizeof(*arr0)    , 1),         "arr0 is Fibonacci"    );
    ASSERT( is_fibonacci(arr0 + 2, sizeof(arr0) / sizeof(*arr0) - 4, 1), "part of arr0 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr1    , sizeof(arr1) / sizeof(*arr1)    , 1),         "arr1 is not Fibonacci");
    ASSERT( is_fibonacci(arr1 + 1,  3                              , 1), "part of arr1 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr2    , sizeof(arr2) / sizeof(*arr2)    , 1),         "arr2 is not Fibonacci");
    ASSERT( is_fibonacci(arr2 + 2, 10                              , 2), "part of arr2 is Fibonacci"    );
    ASSERT( is_fibonacci(arr2 + 3,  9                              , 2), "part of arr2 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr2 + 1, 10                              , 2), "guard check"                  );
    ASSERT(!is_fibonacci(arr2 + 3, 10                              , 2), "guard check"                  );
    // clang-format on
    return 0;
}
