#pragma once
#include "Aeroflot.h"

class Airline {
	Aeroflot *head_aeroflot;							/* ��������� �� ������ ������ */
	int size;											/* ������ ������ */
public:
	Airline();											/* ����������� �� ��������� */
	Airline(const Airline&);							/* ����������� ����������� */
	~Airline();											/* ���������� */

	int getSize() { return size; }						/* ����� ������ ������� ������ */
	void pushElement(string, string, string);			/* ����� ���������� ������ �������� ������ */
	void deleteElement(string);							/* ����� �������� �������� �� ������ ����� */
	void sortElement();									/* ����� ���������� ������ */
	void searchDestination(string);						/* ����� ������ ������ �� ������ ���������� */
	void changeElement(int);							/* ����� �������������� ������ */
	friend ostream& operator << (ostream&, Airline&);	/* ������������� �������� ������ ������ ������ �� ����� */
};