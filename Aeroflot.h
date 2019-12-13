#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Aeroflot{
	string destination;									/* �������� ������ ���������� ����� */
	string flight_number;								/* ����� ����� */
	string type_of_aircraft;							/* ��� �������� */
	Aeroflot* next_aeroflot;							/* ��������� �� ��������� ������� ������ */
public:
	Aeroflot();											/* ����������� �� ��������� */
	Aeroflot(string, string, string);					/* ����������� � ����������� */		
	Aeroflot(const Aeroflot&);							/* ����������� ����������� */
	~Aeroflot();										/* ���������� */

	/* ������ ��������� �������� � ���� */
	void setDestination(string destination) { this->destination = destination; }
	void setFlightNumber(string flight_number) { this->flight_number = flight_number; }
	void setTypeOfAircraft(string type_of_aircraft) { this->type_of_aircraft = type_of_aircraft; }
	void setNextAeroflot(Aeroflot* next_aeroflot) { this->next_aeroflot = next_aeroflot; }

	/* ������ ������ �������� �� ����� */
	string getDestination() { return this->destination; }
	string getFlightNumber() { return this->flight_number; }
	string getTypeOfAircraft() { return this->type_of_aircraft; }
	Aeroflot* getNextAeroflot() { return this->next_aeroflot; }

	void changeData();									/* ����� �������������� ������ */
 	friend ostream& operator << (ostream&, Aeroflot&);	/* ������������� �������� ������ ������ �� ����� */
};