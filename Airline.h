#pragma once
#include "Aeroflot.h"

class Airline {
	Aeroflot *head_aeroflot;							/* Указатель на начало списка */
	int size;											/* Размер списка */
public:
	Airline();											/* Конструктор по умолчанию */
	Airline(const Airline&);							/* Конструктор копирования */
	~Airline();											/* Деструктор */

	int getSize() { return size; }						/* Метод взятия размера списка */
	void pushElement(string, string, string);			/* Метод добавления нового элемента списка */
	void deleteElement(string);							/* Метод удаления элемента по номеру рейса */
	void sortElement();									/* Метод сортировки рейсов */
	void searchDestination(string);						/* Метод поиска рейсов по пунтку назанчения */
	void changeElement(int);							/* Метод редактирования данных */
	friend ostream& operator << (ostream&, Airline&);	/* Перегруженный оператор вывода данных списка на экран */
};