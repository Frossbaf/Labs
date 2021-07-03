Алексашин Иван Дмитриевич ПИ2-1
Третья лабораторная работа
-Нахождение всех гласных в строке и вывод их на экран.

#include <iostream>
#include <string>
using namespace std;
string str;
 
int vowels(string str){
    for (int i=0; i < str.length(); i++) {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || 
            str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            cout << str[i] << endl;
    }
    return 0;
}
 
int main()
{
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Entered string:" << endl << str << endl;
    cout << "Solution:" << endl;
    vowels(str);
    system ("pause");
    return 0;   
}