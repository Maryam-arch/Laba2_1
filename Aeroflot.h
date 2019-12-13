#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Aeroflot{
	string destination;									/* Название пункта назначения рейса */
	string flight_number;								/* Номер рейса */
	string type_of_aircraft;							/* Тип самолета */
	Aeroflot* next_aeroflot;							/* Указатель на следующий элемент списка */
public:
	Aeroflot();											/* Конструктор по умолчанию */
	Aeroflot(string, string, string);					/* Конструктор с параметрами */		
	Aeroflot(const Aeroflot&);							/* Конструктор копирования */
	~Aeroflot();										/* Деструктор */

	/* Методы установки значений в поля */
	void setDestination(string destination) { this->destination = destination; }
	void setFlightNumber(string flight_number) { this->flight_number = flight_number; }
	void setTypeOfAircraft(string type_of_aircraft) { this->type_of_aircraft = type_of_aircraft; }
	void setNextAeroflot(Aeroflot* next_aeroflot) { this->next_aeroflot = next_aeroflot; }

	/* Методы взятия значений из полей */
	string getDestination() { return this->destination; }
	string getFlightNumber() { return this->flight_number; }
	string getTypeOfAircraft() { return this->type_of_aircraft; }
	Aeroflot* getNextAeroflot() { return this->next_aeroflot; }

	void changeData();									/* Метод редактирования данных */
 	friend ostream& operator << (ostream&, Aeroflot&);	/* Перегруженный оператор вывода данных на экран */
};