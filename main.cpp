#include "Airline.h"

int main() {
	setlocale(LC_ALL, "");

	Airline obj;
	
	int button;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "1 - �������� ����" << endl;
		cout << "2 - ������� ����" << endl;
		cout << "3 - ����� ���� ������ �� �����" << endl;
		cout << "4 - ����� ������ �� ������������ ������ ����������" << endl;
		cout << "5 - ���������� ������" << endl;
		cout << "6 - �������������� �����" << endl;
		cout << "0 - �����" << endl;
		cin >> button;

		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
		case 1: {
			string destination;									
			string flight_number;								
			string type_of_aircraft;						
			cout << "������� ����� ����������: ";
			cin >> destination;
			cout << "������� ����� �����: ";
			cin >> flight_number;
			cout << "������� ��� �������: ";
			cin >> type_of_aircraft;
			obj.pushElement(destination, flight_number, type_of_aircraft);
			cout << "������� ������� ��������!" << endl << endl;
		}
			system("pause");
			break;

		case 2: 
			try {
				if (obj.getSize() == 0)
					throw exception("������ ������ ����!");

				string flight_number;
				cout << "������� ����� ����� ��� ��������: ";
				cin >> flight_number;
				obj.deleteElement(flight_number);
				cout << "������� ������� ������!" << endl << endl;
				
			}
			catch (exception &ex) {
				cout << ex.what() << endl << endl;
			}
			system("pause");
			break;

		case 3:
			system("cls");
			cout << obj;
			system("pause");
			break;

		case 4:
			system("cls");
			try {
				if (obj.getSize() == 0)
					throw exception("������ ������ ����!");

				string destination;
				cout << "������� ����� ����������: ";
				cin >> destination;
				system("cls");
				obj.searchDestination(destination);
			}
			catch (exception &ex) {
				cout << ex.what() << endl << endl;
			}
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "������ �� ����������" << endl;
			cout << "-------------------------------------------------" << endl << endl << obj << endl << endl;
			obj.sortElement();
			cout << "������� ����� ����������" << endl;
			cout << "-------------------------------------------------" << endl << endl << obj << endl << endl;
			system("pause");
			break;

		case 6:
			system("cls");
			try {
				if(obj.getSize() == 0)
					throw exception("������ ������ ����!");

				int index;
				cout << obj << endl;
				cout << "������� ������ ��� ��������������: ";
				cin >> index;
				obj.changeElement(index);
			}
			catch (exception &ex) {
				cout << ex.what() << endl << endl;
			}
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "������� ������������ �������" << endl << endl;
			system("pause");
		}
	}

	return 0;
}