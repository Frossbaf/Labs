Алексашин Иван Дмитриевич ПИ2-1
Вторая лабораторная работа
-Решение квадратного уравнения
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
float a, b, c, x, v;
cout << "Введите значение a: ";
cin >> a;
cout << "Введите значение b: ";
cin >> b;
cout << "Введите значение c: ";
cin >> c;
if ((b * b - 4 * a * c) >= 0)  //Дискриминант
{
x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a); //1 корень
cout << "x1 = " << x << endl;
v = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a); //2 корень
cout << "x2 = " << v << endl;
}
else
{
cout << "Дискриминант меньше 0, корней нет" << endl;
}
cout << endl;

    
}