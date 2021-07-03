#include <iostream>
#include <string>
using namespace std;


class Harbinger
{
private:
	std::string h_name;
	int h_age;
	string CatchPhrase;
public:
	Harbinger(std::string name = "Jesus", int age = 2000)
		: h_name(name), h_age(age)
	{
	}

	Harbinger(std::string name, int age, string phrase) : h_name(name), h_age(age), CatchPhrase(phrase) {}
	std::string getName() const { return h_name; }
	int getAge() const {
		return h_age;
	}

	void setAge(int age) {
		h_age = age;
	}

	void setName(string name) {
		h_name = name;
	}

	void setPhrase(string phrase) {
		CatchPhrase = phrase;
	}

	string getPhrase() const { return CatchPhrase; }
};


class Prophet : public Harbinger {
private:
	string* MagnumOpus = new string[3];
	string ph_name;
	int ph_age;
	string ph_call;
public:

	Prophet(string name = "Vanya", int age = 20, string call = "") : ph_name(name),ph_age(age),ph_call(call){
		setMagnum();
	}

	void setMagnum(string* arr=NULL) {
		if (arr) {
			for (int i = 0; i < 3; i++)
			{
				if (arr[i].length() > 25) cout << "������ ����� ������!";
				return;
			}
			MagnumOpus = arr;
			setCall();
		}

		else {
			MagnumOpus[0] = "�������� � ������ ������� �� ���� ���������.";
			MagnumOpus[1] = "��� ������";
			MagnumOpus[2] = "�������� �������";
			setCall();
		}
	}

	string* getMagnum() {
		return MagnumOpus;
	}

	void setCall() {
		string max = MagnumOpus[0];
		if (MagnumOpus[1].length() > max.length())
			max = MagnumOpus[1];
		if (MagnumOpus[2].length() > max.length())
			max = MagnumOpus[2];
		if (ph_call.length() < max.length())
			ph_call = max;
	}

	string getCall() { return ph_call;  }

	void setAge(int age) { ph_age = age; }
	int getAge() { return ph_age; }

	void setName(string name) { ph_name = name; }
	string getName() { return ph_name; }
};

class DeusEx : public Prophet {
private:
	string gd_name;
	int gd_year;
	Harbinger hb;
	Prophet pr;

public:
	DeusEx() {
		gd_year = 2021;
		gd_name = "Jesus";
	}
		void print() {
			cout << hb.getName() << " � �������� " << hb.getAge() << " �������, ��� " << hb.getPhrase() << endl;
			cout << endl;
			cout << "������ �����������: " << (pr.getMagnum())[1] << endl;
			cout << "������ �����������: " << (pr.getMagnum())[2] << endl;
			cout << "������� �����������: " << (pr.getCall()) << endl;
			cout << endl;
			cout << "��� ������� " << pr.getName() << " � �������� " << pr.getAge() << endl;
			cout << "� ��� " << gd_year << " ������ " << gd_name << ", �������� ���������� " << hb.getName() << " � " << pr.getName() << endl;
		}

		string getName() { return gd_name; }
		int getYear() { return gd_year; }
	
};

class Believer : private DeusEx {
private:
	string bv_name;
	int bv_age;
	DeusEx de;
	Prophet ph;
public:

	Believer(string name, int age) {
		bv_name = name;
		bv_age = age;
	}
	void setName(string name) { bv_name = name; }
	void setAge(int age) { bv_age = age; }

	string getName() { return bv_name; }
	int getAge() { return bv_age; }

	void print() {
		cout << endl;
		cout << "�������� " << bv_name << " ������� " << de.getName() << " ������ " << ph.getName() <<
			" � " << de.getYear() << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	const string name = "�������";
	const int age = 200;

	DeusEx obj;
	obj.print();

	Believer obj2(name,age);
	obj2.print();

	return 0;
}