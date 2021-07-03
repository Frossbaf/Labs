Алексашин Иван Дмитриевич ПИ2-1
Вторая лабораторная работа
-Нахождение случайного числа в заданном диапазоне

#include <iostream>
using namespace std;
int main() {
setlocale(LC_ALL, "ru");
int a = 0, b = 10; //Ввод диапазона
cout << "Введите два числа для задания диапазона: ";
cin >> a >> b;
int random = rand() % b;
while (random<a)
random = rand() % b;
cout << "Случайное число в заданно диапазоне: " << random << endl; //Вывод результата
return 0; 
}