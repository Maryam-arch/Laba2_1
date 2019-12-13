#include "Aeroflot.h"

Aeroflot::Aeroflot(){
	cout << "Вызван конструктор класса Aeroflot" << endl << endl;

	/* Изначальная инициализация данных */
	destination = "No";
	flight_number = "No";
	type_of_aircraft = "No";
}

Aeroflot::Aeroflot(string destination, string flight_number, string type_of_aircraft){
	cout << "Вызван конструктор с параметрами класса Aeroflot" << endl << endl;
	
	/* Записываем в поля данные, которые передали */
	this->destination = destination;
	this->flight_number = flight_number;
	this->type_of_aircraft = type_of_aircraft;
}

Aeroflot::Aeroflot(const Aeroflot &other){
	cout << "Вызван конструктор копирования класса Aeroflot" << endl << endl;
	
	/* Копируем данные из объекта other в объект this */
	this->destination = other.destination;
	this->flight_number = other.flight_number;
	this->type_of_aircraft = other.type_of_aircraft;
}

Aeroflot::~Aeroflot(){
	cout << "Вызван деструктор класса Aeroflot" << endl << endl;
	/* Так как нет динамического выделения памяти в классе Aeroflot, то и удалять нечего */
}

void Aeroflot::changeData(){
	int button;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << *this << endl;
		cout << "Выберите, что нужно поменять" << endl << endl;
		cout << "1 - Пункт назначения рейса" << endl;
		cout << "2 - Номер рейса" << endl;
		cout << "3 - Тип самолёта" << endl;
		cout << "0 - Выход из меню редактирования" << endl;
		cin >> button;

		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
		case 1:
			cout << endl << "Введите новый пункт назначения: ";
			cin >> destination;
			cout << endl << "Пункт назначения успешно изменён!" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << endl << "Введите новый номер рейса: ";
			cin >> flight_number;
			cout << endl << "Номер рейса успешно изменён!" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << endl << "Введите новый тип самолёта: ";
			cin >> type_of_aircraft;
			cout << endl << "Тип самолёта успешно изменён!" << endl << endl;
			system("pause");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "Введена некорректная команда" << endl << endl;
			system("pause");
		}
	}
}

ostream & operator<<(ostream &out, Aeroflot &obj){
	/* Выводим все данные на экран */
	out << "Пункт назначения рейса: " << obj.destination << endl;
	out << "Номер рейса: " << obj.flight_number << endl;
	out << "Тип самолёта: " << obj.type_of_aircraft << endl;
	return out;
}