Алексашин Иван Дмитриевич ПИ2-1
Третья лабораторная работа
-Исключение из массива всех отрицательных чисел.

#include <iostream>
int main()
{
    const int n = 10; int k = 0;
   int a[n] = {1,5,-3,-1,-2,-3,7,-5,6,-4};
   for (int i=0; i<n; ++i)
    if (a[i]<0)
    {
            for (int j=i; j<n-1; ++j)
                a[j] = a[j+1];
            ++k;
            a[n-1] = 0;
            --i;
        }
    for (int i=0; i<n-k; ++i)
       std::cout<<a[i]<<' ';
   return 0;
}