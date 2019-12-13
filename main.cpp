#include "Airline.h"

int main() {
	setlocale(LC_ALL, "");

	Airline obj;
	
	int button;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "1 - Добавить рейс" << endl;
		cout << "2 - Удалить рейс" << endl;
		cout << "3 - Вывод всех рейсов на экран" << endl;
		cout << "4 - Вывод рейсов до определённого пункта назначения" << endl;
		cout << "5 - Сортировка рейсов" << endl;
		cout << "6 - Редактирование рейса" << endl;
		cout << "0 - Выход" << endl;
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
			cout << "Введите пункт назначения: ";
			cin >> destination;
			cout << "Введите номер рейса: ";
			cin >> flight_number;
			cout << "Введите тип самолёта: ";
			cin >> type_of_aircraft;
			obj.pushElement(destination, flight_number, type_of_aircraft);
			cout << "Элемент успешно добавлен!" << endl << endl;
		}
			system("pause");
			break;

		case 2: 
			try {
				if (obj.getSize() == 0)
					throw exception("Список рейсов пуст!");

				string flight_number;
				cout << "Введите номер рейса для удаления: ";
				cin >> flight_number;
				obj.deleteElement(flight_number);
				cout << "Элемент успешно удален!" << endl << endl;
				
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
					throw exception("Список рейсов пуст!");

				string destination;
				cout << "Введите пункт назначения: ";
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
			cout << "Список до сортировки" << endl;
			cout << "-------------------------------------------------" << endl << endl << obj << endl << endl;
			obj.sortElement();
			cout << "Спискок после сортировки" << endl;
			cout << "-------------------------------------------------" << endl << endl << obj << endl << endl;
			system("pause");
			break;

		case 6:
			system("cls");
			try {
				if(obj.getSize() == 0)
					throw exception("Список рейсов пуст!");

				int index;
				cout << obj << endl;
				cout << "Введите индекс для редактирования: ";
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
			cout << "Введена некорректная команда" << endl << endl;
			system("pause");
		}
	}

	return 0;
}