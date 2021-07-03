////// В написании групповой работы принимали участие: /////
////// Ярославцев В.А.
/////  Виноградов А.А.
/////  Алексашин И.Д.
/////  Акил Амр
/////  Карась Д.Г.
/////  Судаков В.А.
/////  Алешин И.




#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;


class lake {
private:
	string name; // название
	float area; // площадь
	float deep; // средняя глубина
	string continent; // континент
	int local_choice;
public:
	lake(string n = "NULL", float a = 0, float d = 0, string c = "NULL") {
		name = n;
		area = a;
		deep = d;
		continent = c;
	}

	void print() {
		cout << "Название: " << name << endl;
		cout << "Площадь: " << area << endl;
		cout << "Средняя глубина: " << deep << endl;
		cout << "Континент: " << continent << endl;
	}

	string getName() { return name; }
	
	void addItem() {
		cout << "Введите название: ";
		cin >> name;
		cout << "Введите площадь: ";
		cin >> area;
		cout << "Введите среднюю глубину: ";
		cin >> deep;
		cout << "Введите континент: ";
		cin >> continent;
	}
	

};

class river {
private:
	string name; // название
	float deep; // средняя глубина
	float length;	// протяженность
	string continent; // континент
public:
	river(string n = "NULL", float d = 0, float l = 0, string c = "NULL") {
		name = n;
		deep = d;
		length = l;
		continent = c;
	}
	string getName() { return name; }
	void addItem() {
		cout << "Введите название: ";
		cin >> name;
		cout << "Введите среднюю глубину: ";
		cin >> deep;
		cout << "Введите протяженность: ";
		cin >> length;
		cout << "Введите континент: ";
		cin >> continent;
	}
	void print() {
		cout << "Название: " << name << endl;
		cout << "Средняя глубина: " << deep << endl;
		cout << "Протяженность: " << length << endl;
		cout << "Континент: " << continent << endl;
	}
};

class waterfall {
private:
	string name;// название
	float height; // высота
	float width; // ширина
	string continent; // континент
public:
	waterfall(string n = "NULL", float h = 0, float w = 0, string c = "NULL") {
		name = n;
		height = h;
		width = w;
		continent = c;
	}

	string getName() { return name; }

	void addItem() {
		cout << "Введите название: ";
		cin >> name;
		cout << "Введите высоту: ";
		cin >> height;
		cout << "Введите ширину: ";
		cin >> width;
		cout << "Введите континент: ";
		cin >> continent;
	}

	void print() {
		cout << "Название: " << name << endl;
		cout << "Высота: " << height << endl;
		cout << "Ширина: " << width << endl;
		cout << "Континент: " << continent << endl;
	}
};



class directory {
private:
	vector<lake> lake_obj;
	vector<river> river_obj;
	vector<waterfall> waterfall_obj;
	int choice = 0;
public:
	directory() {
		auto_fill();
		start();
	}
	void auto_fill() {
		lake l1("Байкал", 31722, 1000, "Европа");
		lake_obj.push_back(l1);
		lake l2("Верхнее", 82414, 350, "Северная Америка");
		lake_obj.push_back(l2);
		lake l3("Виктория", 69485, 70, "Африка");
		lake_obj.push_back(l3);

		river r1("Амазонка", 50, 7100, "Южная Америка");
		river_obj.push_back(r1);
		river r2("Нил", 30, 6670, "Африка");
		river_obj.push_back(r2);
		river r3("Янцзы", 6300, 45, "Азия");
		river_obj.push_back(r3);

		waterfall w1("Анхель", 979, 107, "Южная Америка");
		waterfall_obj.push_back(w1);
		waterfall w2("Виктория", 108, 1800, "Африка");
		waterfall_obj.push_back(w2);
		waterfall w3("Ниагарский", 53, 323, "Африка");
		waterfall_obj.push_back(w3);
	}

	void start() {
		system("cls");

		cout << "Выберите необходимый справочник: " << endl;
		cout << "1. Справочник озер" << endl;
		cout << "2. Справочник рек" << endl;
		cout << "3. Справочник водопадов" << endl;
		cout << endl << "4. Выход из приложения" << endl;
		cin >> choice;
		if (choice == 4)
			exit(0);
		system("cls");

		showMenu();

	}

	void showMenu() {
		cout << endl;
		if (choice) {
			int choice2;
			cout << "Выберите необходимое действие: " << endl;
			cout << "1. Показать все записи" << endl;
			cout << "2. Поиск записи по названию" << endl;
			cout << "3. Удаление записи по порядковому номеру" << endl;
			cout << "4. Добавление новой записи" << endl;
			cout << "5. Выход в меню справочника" << endl;
			cin >> choice2;

			get_directory(choice2);
		}
	}
		
	void get_directory(int ch2) {
		if (choice == 1) {
			if (ch2 == 1) {
				for (int i = 0; i < lake_obj.size(); i++) {
					lake_obj[i].print();
					cout << endl << "------------------------------";
				}
				showMenu();
			}


			else if (ch2 == 2) {
				cout << "Введите название для поиска: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < lake_obj.size(); i++) {
					if (lake_obj[i].getName() == str) {
						test = false;
						lake_obj[i].print();
					}
				}
				if (test) { cout << "Такой элемент не найден!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number; 
				cout << "Введите номер для удаления элемента: ";
				cin >> number;
				while (number > lake_obj.size()) { cout << "Ошибка, введите корректный номер!" << endl; cin >> number; }
				number--;
				lake_obj.erase(lake_obj.begin() + number);
				showMenu();

			}
			else if (ch2 == 4) {
				lake item;
				item.addItem();
				lake_obj.push_back(item);
				cout << endl << endl;
				showMenu();

			}
			else if (ch2 == 5) {
				start();
			}

		}
		if (choice == 2) {
			if (ch2 == 1) {
				for (int i = 0; i < river_obj.size(); i++) {
					river_obj[i].print();
					cout << endl << "------------------------------";
				}
				showMenu();
			}


			else if (ch2 == 2) {
				cout << "Введите название для поиска: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < river_obj.size(); i++) {
					if (river_obj[i].getName() == str) {
						test = false;
						river_obj[i].print();
					}
				}
				if (test) { cout << "Такой элемент не найден!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number;
				cout << "Введите номер для удаления элемента: ";
				cin >> number;
				while (number > river_obj.size()) { cout << "Ошибка, введите корректный номер!" << endl; cin >> number; }
				number--;
				river_obj.erase(river_obj.begin() + number);
				showMenu();

			}
			else if (ch2 == 4) {
				river item;
				item.addItem();
				river_obj.push_back(item);
				cout << endl << endl;
				showMenu();

			}
			else if (ch2 == 5) {
				start();
			}

		}

		if (choice == 3) {
			if (ch2 == 1) {
				for (int i = 0; i < waterfall_obj.size(); i++) {
					waterfall_obj[i].print();
					cout << endl << "------------------------------";
				}
				showMenu();
			}


			else if (ch2 == 2) {
				cout << "Введите название для поиска: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < waterfall_obj.size(); i++) {
					if (waterfall_obj[i].getName() == str) {
						test = false;
						waterfall_obj[i].print();
					}
				}
				if (test) { cout << "Такой элемент не найден!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number;
				cout << "Введите номер для удаления элемента: ";
				cin >> number;
				while (number > waterfall_obj.size()) { cout << "Ошибка, введите корректный номер!" << endl; cin >> number; }
				number--;
				waterfall_obj.erase(waterfall_obj.begin() + number);
				showMenu();

			}
			else if (ch2 == 4) {
				waterfall item;
				item.addItem();
				waterfall_obj.push_back(item);
				cout << endl << endl;
				showMenu();

			}
			else if (ch2 == 5) {
				start();
			}

		}
	}
	
	};


int main() {
	setlocale(LC_CTYPE, "rus"); 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	directory test;

	return 0;
}