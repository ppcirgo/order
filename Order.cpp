#include"stdio.h"
//演示常见排序算法
#define size 22
//定义排序目标数组
int myList[size]={2,9,7,8,1,0,13,56,34,79,123,88,45,31,27,69,190,146,143,174,256,78};

void display(int *p)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",*(p+i));
    }
    putchar('\n');
}
//冒泡法排序，不适合大的数据集，O（平方）
 void MAOPAO()
{
    printf("正在进行冒泡法排序...\n");
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            int temp;
            if(myList[i]>myList[j])
            {
                temp=myList[i];
                myList[i]=myList[j];
                myList[j]=temp;
            }
        }
    }
}
//插入排序，不适合大的数据集，O（平方）
 void CHARU()
 {
    printf("正在进行插入法排序...\n");
    for(int i=1;i<size;i++)
    {
        //首先获取待插入元素
        int temp = myList[i];
        //定义结束符号(左边默认有序，右边无序)
        int isEnd=i-1;
        while(isEnd>=0 && temp<myList[isEnd])
        {
            myList[isEnd+1]=myList[isEnd];
            --isEnd;
        }
        myList[isEnd+1]=temp;
    }
 }
 //选择排序，不适合大的数据集，O（平方）
  void XUANZE()
  {
      printf("正在进行选择法排序...\n");
      int Min;//就是从第一个位置开始就选择最小的留下来
      for(int i=0;i<size-1;i++)
      {
          Min = i;
          for(int curr=i+1;curr<size;curr++)
          {
              if(myList[curr]<myList[Min])
              {
                  Min = curr;//找到剩下的最小的
              }
          }
          if(Min !=i)
          {
              int temp;
              temp= myList[i];
              myList[i]=myList[Min];
              myList[Min]=temp;
          }
      }
  }
  //快速排序 适用于数据量比较大的情况 O（nlogn）
  void KUAISU()
  {
      //int i,j;
      //int temp = myList[0];//让左边第一个数作为标准
  }

  void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}
  void quicksort(int array[], int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;        // array[end]是数组的最后一位

        while(i < j)
        {
            if(array[i] > array[begin])  // 如果比较的数组元素大于基准数，则交换位置。
            {
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            }
            else
            {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }

        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */

        if(array[i] >= array[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]

        quicksort(array,  begin, i);
        quicksort(array,  j, end);
    }
}
void QuickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
    if(i > j)
    return;
    int temp = array[low];
    while(i != j)
    {
        while(array[j] >= temp && i < j)
            j--;
        while(array[i] <= temp && i < j)
            i++;
        if(i < j)
            swap(&array[i], &array[j]);
    }
    //将基准temp放于自己的位置，（第i个位置）
    swap(&array[low], &array[i]);
    QuickSort(array, low, i - 1);
    QuickSort(array, i + 1, high);
}
int main()
{
    printf("原始数组...\n");
    display(myList);
    //MAOPAO();
    //CHARU();
    //XUANZE();
   // quicksort(myList,0,size-1);
    QuickSort(myList,0,size-1);//好理解
    display(myList);
    return 0;
}
