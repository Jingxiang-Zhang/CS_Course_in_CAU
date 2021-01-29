#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <algorithm>
#include "sort.h"

using namespace std;

void init(vote a[], int n)      //使用随机数初始化待排序数组
{
    default_random_engine e;    //调用c++11支持的随机数生成引擎
    e.seed(time(0));
    uniform_int_distribution<unsigned> u(1, n); //设置数组分布为均匀分布
    for (int i = 0; i < n; i++)
    {
        a[i].point = u(e);
        a[i].number = i + 1;
    }
}

int main()
{
    ofstream out;
    out.open("data.txt");       //打开文件流，准备将数据输入进文件里

    clock_t start, end;
    vote *a = nullptr;

    for (int i = 10; i < 1000000; i+=100)   //每增加100个数据，做一次排序并记录运行时间
    {
        if (a)
            delete[] a;
        a = new vote[i];

        init(a, i);             //初始化待排序数组

        Sort b;

        start = clock();

        //选择待测试排序算法

//        b.bubble_sort(a, 0, i-1);
//        b.select_sort(a, 0, i-1);
//        b.insert_sort(a, 0, i-1);
//        b.shell_sort(a, 0, i-1);
//        b.merge_sort()a, 0, i-1);
//        b.quickSort(a, 0, i-1);
//        b.base_sort(a, 0, i-1);
//        b.bucket_sort(a, 0, i-1);
//        b.counting_sort(a, 0, i-1);
        b.heap_sort(a, 0, i-1);

        end = clock();

        out << end - start << endl;         //将结果输出到文件

        delete[] a;
        a = nullptr;
    }

    out.close();                //关闭文件流
    return 0;
}
