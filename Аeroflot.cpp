#include "Aeroflot.h"

Aeroflot::Aeroflot(){
	cout << "������ ����������� ������ Aeroflot" << endl << endl;

	/* ����������� ������������� ������ */
	destination = "No";
	flight_number = "No";
	type_of_aircraft = "No";
}

Aeroflot::Aeroflot(string destination, string flight_number, string type_of_aircraft){
	cout << "������ ����������� � ����������� ������ Aeroflot" << endl << endl;
	
	/* ���������� � ���� ������, ������� �������� */
	this->destination = destination;
	this->flight_number = flight_number;
	this->type_of_aircraft = type_of_aircraft;
}

Aeroflot::Aeroflot(const Aeroflot &other){
	cout << "������ ����������� ����������� ������ Aeroflot" << endl << endl;
	
	/* �������� ������ �� ������� other � ������ this */
	this->destination = other.destination;
	this->flight_number = other.flight_number;
	this->type_of_aircraft = other.type_of_aircraft;
}

Aeroflot::~Aeroflot(){
	cout << "������ ���������� ������ Aeroflot" << endl << endl;
	/* ��� ��� ��� ������������� ��������� ������ � ������ Aeroflot, �� � ������� ������ */
}

void Aeroflot::changeData(){
	int button;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << *this << endl;
		cout << "��������, ��� ����� ��������" << endl << endl;
		cout << "1 - ����� ���������� �����" << endl;
		cout << "2 - ����� �����" << endl;
		cout << "3 - ��� �������" << endl;
		cout << "0 - ����� �� ���� ��������������" << endl;
		cin >> button;

		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
		case 1:
			cout << endl << "������� ����� ����� ����������: ";
			cin >> destination;
			cout << endl << "����� ���������� ������� ������!" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << endl << "������� ����� ����� �����: ";
			cin >> flight_number;
			cout << endl << "����� ����� ������� ������!" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << endl << "������� ����� ��� �������: ";
			cin >> type_of_aircraft;
			cout << endl << "��� ������� ������� ������!" << endl << endl;
			system("pause");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "������� ������������ �������" << endl << endl;
			system("pause");
		}
	}
}

ostream & operator<<(ostream &out, Aeroflot &obj){
	/* ������� ��� ������ �� ����� */
	out << "����� ���������� �����: " << obj.destination << endl;
	out << "����� �����: " << obj.flight_number << endl;
	out << "��� �������: " << obj.type_of_aircraft << endl;
	return out;
}