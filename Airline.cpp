#include "Airline.h"

Airline::Airline(){
	cout << "������ ����������� ������ Airline" << endl << endl;
	head_aeroflot = nullptr;
	size = 0;
}

Airline::Airline(const Airline &other){
	cout << "������ ����������� ����������� ������ Airline" << endl << endl;

	Aeroflot* current = other.head_aeroflot;			/* ��������� �� ������, �� �������� ����� ���������� */

	/* �������� ������ ������� ������ ������� other*/
	for (int i = 0; i < other.size; ++i) {
		/* �������� ������� ���������� ��� �������� ������� � �������� � �� ������ �� �������, �� �������� �������� */
		this->pushElement(current->getDestination(), current->getFlightNumber(), current->getTypeOfAircraft());
		current = current->getNextAeroflot();			/* ����������� ��������� */
	}
}

Airline::~Airline(){
	cout << "������ ���������� ������ Airline" << endl << endl;
	
	Aeroflot* current = head_aeroflot;							/* ��������� ��� ����������� ������ �������� */

	/* ����� �� ������� �������� � ������ ������ � ������� ���*/
	for (int i = 0; i < size; ++i) {
		head_aeroflot = head_aeroflot->getNextAeroflot();		/* ����������� ��������� �� ������ ������ �� ������ ������� */
		delete current;											/* ������� ������ �������, ������ ������� ���������� ������ */
		current = head_aeroflot;								/* ����� ���������� ������ ������� */
	}
}

void Airline::pushElement(string destination, string flight_number, string type_of_aircraft){
	Aeroflot* new_element = new Aeroflot;				/* ������� ����� ������� ������ */
	
	/* ���������� ���������� ������ � ���� ������ �������� */
	new_element->setDestination(destination);			
	new_element->setFlightNumber(flight_number);
	new_element->setTypeOfAircraft(type_of_aircraft);

	/* ��������� ����� ������� ������ ��� � ������ ������ (��� �������) */
	if (head_aeroflot == nullptr) {						/* ���� ������ ��� ���� */
		head_aeroflot = new_element;					/* ������ ������ - ��� ������ ��� ��������� ������� */
	}
	else {												/* ���� � ������ ���� �������� */
		new_element->setNextAeroflot(head_aeroflot);	/* ��������� ������� ��������� �� ������ ������� � ������ */
		head_aeroflot = new_element;					/* ��������� ������� ���������� ������ � ������ */
	}

	++size;												/* ����������� ������ ������ */
}

void Airline::deleteElement(string flight_number){
	Aeroflot* current = head_aeroflot;								/* ������� �������� �� �������, ������� ����� ������� */
	Aeroflot* prev = head_aeroflot;									/* ���������� ��������� �� �������, ������� ���� �� ��������� �������� */
												
	for (int i = 0; i < size; ++i) {								/* ����� �� ����� ������ */
		if (current->getFlightNumber() == flight_number) {			/* ���������� ������ ������ */
			if (current == head_aeroflot) {							/* ���� ����� ������� ������ �������*/
				head_aeroflot = head_aeroflot->getNextAeroflot();	/* ����������� ��������� �� ������ ������ �� ������ ������� */
				delete current;										/* ������� ������ �������*/
			}
			else {													/* ���� ��������� ������� �� ������ */
				prev->setNextAeroflot(current->getNextAeroflot());	/* ���������� ������� �������� ��������� �� ������� ����� �������� */
				delete current;										/* ������� ������� ������� */
			}		
			--size;													/* ��������� ������ */
			break;													/* �������, ��������� ���� */
		}

		if (i == size - 1)											/* ���� ����� �� ���������� ��������, �� ��� ������ �� ������� */
			cout << "������� ����� ���!" << endl << endl;			/* ������� �� ����� ��������� � ���, ��� ������ ������� */

		prev = current;												/* ���������� ������ ������� */
		current = current->getNextAeroflot();						/* ����������� ������ ������� ��������� */
	}
}

void Airline::sortElement(){
	/* ���������� ������� �������� (��������� N^2, ��� N - ������) */
	for (int i = 0; i < size - 1; ++i) {
		Aeroflot *current = head_aeroflot;									/* ��������� �� ������� ������� */
		Aeroflot *prev = head_aeroflot;										/* ��������� �� ���������� ������� */

		while (current->getNextAeroflot() != nullptr) {						/* ����, ���� ���������� ��������� ������� �� ������� */
			Aeroflot* next = current->getNextAeroflot();					/* ��������� �� ��������� ������� */

			if (current->getFlightNumber() > next->getFlightNumber()) {		/* ��������� ������� ������ */
				if (current == head_aeroflot) {								/* ���� ������� ������� ������, �� ���� ������ ��������� �� ������ ������ */
					head_aeroflot = next;									/* ������ ������ ������ ������ ������� */
					current->setNextAeroflot(next->getNextAeroflot());		/* ������ ������� ������ ��������� �� ������ ������� */
					next->setNextAeroflot(current);							/* ������ ������� ������ ��������� �� ������ */
					current = head_aeroflot;								/* ��������� ������� ��������� */
				}	
				else {
					prev->setNextAeroflot(next);							/* ���������� ������� ��������� �� ��������� */
					current->setNextAeroflot(next->getNextAeroflot());		/* ������� ��������� �� ������� ����� ��������� */
					next->setNextAeroflot(current);							/* ��������� ��������� �� ������� ������� */
					current = next;											/* ��������� ������� ��������� */
				}
			}
		
			prev = current;												/* ���������� ���������� ������� */
			current = current->getNextAeroflot();						/* ����������� ������� ��������� �� ������ */
		}
	}
}

void Airline::searchDestination(string destination){
	Aeroflot* current = head_aeroflot;						/* ���������, ����� ������ �� ������ */
	bool flag = false;										/* ����, ����������� �� ������� ������ ������. ���� �� ���, �� flag = false */

	for (int i = 0; i < size; ++i) {						/* ����� �� ������ */
		if (current->getDestination() == destination) {		/* ���������� ������ ���������� */
			cout << *current << endl;						/* ������� ���������� � ����� */
			flag = true;									/* ��������� ���� � ������� ������� ������ ������ */
		}

		current = current->getNextAeroflot();				/* ����������� ��������� ������ */
	}

	if (!flag)												/* ���� ��� ������ ������ */
		cout << "���������� ������ ���!" << endl << endl;	/* ������� �� ���� ��������� �� ����� */
}

void Airline::changeElement(int index){
	Aeroflot* current = head_aeroflot;						/* ���������, ����� ������ �� ������ */

	for (int i = 1; i < index; ++i)							/* ����� �� ��������, ������� ����� �������� */
		current = current->getNextAeroflot();				/* ����������� ��������� */
	
	current->changeData();									/* ������� ����� ��������� ������ */
}

ostream & operator<<(ostream &out, Airline &obj){
	try {
		if (!obj.size)									/* ���������, ���� �� ������ */
			throw exception("������ ������ ����!");		/* ���� ������ ����, �� ���������� �������������� �������� */

		Aeroflot* current = obj.head_aeroflot;			/* ���������, ����� ������ �� ������ */

		for (int i = 0; i < obj.size; ++i) {			/* ����� �� ������ �������� */
			cout << *current << endl;					/* ������� ������� �� ����� */
			current = current->getNextAeroflot();		/* ����������� ��������� �� ��������� ������� ������ */
		}
		cout << endl;									/* ����� ��� ����, ����� ��������� ������� �� ������ ��������� ����� ������� */
	}
	catch (exception &ex) {								/* ����� ������ */
		cout << ex.what() << endl << endl;				/* ������� � �� ����� */
	}
	return out;											/* ���������� ������ �� ����� ������ */
}