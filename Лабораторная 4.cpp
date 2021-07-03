////// � ��������� ��������� ������ ��������� �������: /////
////// ���������� �.�.
/////  ���������� �.�.
/////  ��������� �.�.
/////  ���� ���
/////  ������ �.�.
/////  ������� �.�.
/////  ������ �.




#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;


class lake {
private:
	string name; // ��������
	float area; // �������
	float deep; // ������� �������
	string continent; // ���������
	int local_choice;
public:
	lake(string n = "NULL", float a = 0, float d = 0, string c = "NULL") {
		name = n;
		area = a;
		deep = d;
		continent = c;
	}

	void print() {
		cout << "��������: " << name << endl;
		cout << "�������: " << area << endl;
		cout << "������� �������: " << deep << endl;
		cout << "���������: " << continent << endl;
	}

	string getName() { return name; }
	
	void addItem() {
		cout << "������� ��������: ";
		cin >> name;
		cout << "������� �������: ";
		cin >> area;
		cout << "������� ������� �������: ";
		cin >> deep;
		cout << "������� ���������: ";
		cin >> continent;
	}
	

};

class river {
private:
	string name; // ��������
	float deep; // ������� �������
	float length;	// �������������
	string continent; // ���������
public:
	river(string n = "NULL", float d = 0, float l = 0, string c = "NULL") {
		name = n;
		deep = d;
		length = l;
		continent = c;
	}
	string getName() { return name; }
	void addItem() {
		cout << "������� ��������: ";
		cin >> name;
		cout << "������� ������� �������: ";
		cin >> deep;
		cout << "������� �������������: ";
		cin >> length;
		cout << "������� ���������: ";
		cin >> continent;
	}
	void print() {
		cout << "��������: " << name << endl;
		cout << "������� �������: " << deep << endl;
		cout << "�������������: " << length << endl;
		cout << "���������: " << continent << endl;
	}
};

class waterfall {
private:
	string name;// ��������
	float height; // ������
	float width; // ������
	string continent; // ���������
public:
	waterfall(string n = "NULL", float h = 0, float w = 0, string c = "NULL") {
		name = n;
		height = h;
		width = w;
		continent = c;
	}

	string getName() { return name; }

	void addItem() {
		cout << "������� ��������: ";
		cin >> name;
		cout << "������� ������: ";
		cin >> height;
		cout << "������� ������: ";
		cin >> width;
		cout << "������� ���������: ";
		cin >> continent;
	}

	void print() {
		cout << "��������: " << name << endl;
		cout << "������: " << height << endl;
		cout << "������: " << width << endl;
		cout << "���������: " << continent << endl;
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
		lake l1("������", 31722, 1000, "������");
		lake_obj.push_back(l1);
		lake l2("�������", 82414, 350, "�������� �������");
		lake_obj.push_back(l2);
		lake l3("��������", 69485, 70, "������");
		lake_obj.push_back(l3);

		river r1("��������", 50, 7100, "����� �������");
		river_obj.push_back(r1);
		river r2("���", 30, 6670, "������");
		river_obj.push_back(r2);
		river r3("�����", 6300, 45, "����");
		river_obj.push_back(r3);

		waterfall w1("������", 979, 107, "����� �������");
		waterfall_obj.push_back(w1);
		waterfall w2("��������", 108, 1800, "������");
		waterfall_obj.push_back(w2);
		waterfall w3("����������", 53, 323, "������");
		waterfall_obj.push_back(w3);
	}

	void start() {
		system("cls");

		cout << "�������� ����������� ����������: " << endl;
		cout << "1. ���������� ����" << endl;
		cout << "2. ���������� ���" << endl;
		cout << "3. ���������� ���������" << endl;
		cout << endl << "4. ����� �� ����������" << endl;
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
			cout << "�������� ����������� ��������: " << endl;
			cout << "1. �������� ��� ������" << endl;
			cout << "2. ����� ������ �� ��������" << endl;
			cout << "3. �������� ������ �� ����������� ������" << endl;
			cout << "4. ���������� ����� ������" << endl;
			cout << "5. ����� � ���� �����������" << endl;
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
				cout << "������� �������� ��� ������: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < lake_obj.size(); i++) {
					if (lake_obj[i].getName() == str) {
						test = false;
						lake_obj[i].print();
					}
				}
				if (test) { cout << "����� ������� �� ������!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number; 
				cout << "������� ����� ��� �������� ��������: ";
				cin >> number;
				while (number > lake_obj.size()) { cout << "������, ������� ���������� �����!" << endl; cin >> number; }
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
				cout << "������� �������� ��� ������: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < river_obj.size(); i++) {
					if (river_obj[i].getName() == str) {
						test = false;
						river_obj[i].print();
					}
				}
				if (test) { cout << "����� ������� �� ������!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number;
				cout << "������� ����� ��� �������� ��������: ";
				cin >> number;
				while (number > river_obj.size()) { cout << "������, ������� ���������� �����!" << endl; cin >> number; }
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
				cout << "������� �������� ��� ������: ";
				string str;
				cin >> str;
				bool test = true;
				for (int i = 0; i < waterfall_obj.size(); i++) {
					if (waterfall_obj[i].getName() == str) {
						test = false;
						waterfall_obj[i].print();
					}
				}
				if (test) { cout << "����� ������� �� ������!"; }
				showMenu();

			}
			else if (ch2 == 3) {
				int number;
				cout << "������� ����� ��� �������� ��������: ";
				cin >> number;
				while (number > waterfall_obj.size()) { cout << "������, ������� ���������� �����!" << endl; cin >> number; }
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