#include "Airline.h"

Airline::Airline(){
	cout << "Вызван конструктор класса Airline" << endl << endl;
	head_aeroflot = nullptr;
	size = 0;
}

Airline::Airline(const Airline &other){
	cout << "Вызван конструктор копирования класса Airline" << endl << endl;

	Aeroflot* current = other.head_aeroflot;			/* Указатель на список, из которого нужно копировать */

	/* Копируем каждый элемент списка объекта other*/
	for (int i = 0; i < other.size; ++i) {
		/* Вызываем функцию добавления для текущего объекта и передаем в неё данные из объекта, из которого копируем */
		this->pushElement(current->getDestination(), current->getFlightNumber(), current->getTypeOfAircraft());
		current = current->getNextAeroflot();			/* Передвигаем указатель */
	}
}

Airline::~Airline(){
	cout << "Вызван деструктор класса Airline" << endl << endl;
	
	Aeroflot* current = head_aeroflot;							/* Указатель для запоминания адреса объектов */

	/* Бежим по каждому элементу с начала списка и удаляем его*/
	for (int i = 0; i < size; ++i) {
		head_aeroflot = head_aeroflot->getNextAeroflot();		/* Передвигаем указатель на начало списка на второй элемент */
		delete current;											/* Удаляем первый элемент, второй элемент становится первым */
		current = head_aeroflot;								/* Снова запоминаем первый элемент */
	}
}

void Airline::pushElement(string destination, string flight_number, string type_of_aircraft){
	Aeroflot* new_element = new Aeroflot;				/* Создаем новый элемент списка */
	
	/* Записываем переданные данные в поля нового элемента */
	new_element->setDestination(destination);			
	new_element->setFlightNumber(flight_number);
	new_element->setTypeOfAircraft(type_of_aircraft);

	/* Добавляем новый элемент каждый раз в начало списка (так быстрее) */
	if (head_aeroflot == nullptr) {						/* Если список был пуст */
		head_aeroflot = new_element;					/* Начало списка - это только что созданный элемент */
	}
	else {												/* Если в списке были элементы */
		new_element->setNextAeroflot(head_aeroflot);	/* Созданный элемент указывает на первый элемент в списке */
		head_aeroflot = new_element;					/* Созданный элемент становится первым в списке */
	}

	++size;												/* Увеличиваем размер списка */
}

void Airline::deleteElement(string flight_number){
	Aeroflot* current = head_aeroflot;								/* Текущий казатель на элемент, который нужно удалить */
	Aeroflot* prev = head_aeroflot;									/* Предыдущий указатель на элемент, который идет до удаляемго элемента */
												
	for (int i = 0; i < size; ++i) {								/* Бежим по всему списку */
		if (current->getFlightNumber() == flight_number) {			/* Сравниваем номера рейсов */
			if (current == head_aeroflot) {							/* Если нужно удалить первый элемент*/
				head_aeroflot = head_aeroflot->getNextAeroflot();	/* Передвигаем указатель на начало списка на второй элемент */
				delete current;										/* Удаялем первый элемент*/
			}
			else {													/* Если удаялемый элемент не первый */
				prev->setNextAeroflot(current->getNextAeroflot());	/* Пердыдущий элемент начинает указывать на элемент после текущего */
				delete current;										/* Удаляем текущий элемент */
			}		
			--size;													/* Уменьшаем размер */
			break;													/* Удалили, завершаем цикл */
		}

		if (i == size - 1)											/* Если дошли до последнего элемента, но так ничего не удалили */
			cout << "Нужного рейса нет!" << endl << endl;			/* Выводим на экран сообщение о том, что нечего удалять */

		prev = current;												/* Пердыдущий теперь текущий */
		current = current->getNextAeroflot();						/* Передвигаем дальше текущий указатель */
	}
}

void Airline::sortElement(){
	/* Сортировка методом пузырька (Сложность N^2, где N - размер) */
	for (int i = 0; i < size - 1; ++i) {
		Aeroflot *current = head_aeroflot;									/* Указатель на текущий элемент */
		Aeroflot *prev = head_aeroflot;										/* Указатель на предыдущий элемент */

		while (current->getNextAeroflot() != nullptr) {						/* Идем, пока существует следующий элемент за текущим */
			Aeroflot* next = current->getNextAeroflot();					/* Указатель на следующий элемент */

			if (current->getFlightNumber() > next->getFlightNumber()) {		/* Сравнение номером рейсов */
				if (current == head_aeroflot) {								/* Если текущий элемент первый, то надо менять указатель на начало списка */
					head_aeroflot = next;									/* Начало списка теперь второй элемент */
					current->setNextAeroflot(next->getNextAeroflot());		/* Первый элемент теперь указывает на третий элемент */
					next->setNextAeroflot(current);							/* Второй элемент теперь указывает на первый */
					current = head_aeroflot;								/* Сохраняем позицию указателя */
				}	
				else {
					prev->setNextAeroflot(next);							/* Предыдущий элемент указывает на следующий */
					current->setNextAeroflot(next->getNextAeroflot());		/* Текущий указывает на элемент после следующго */
					next->setNextAeroflot(current);							/* Следующий указывает на текущий элемент */
					current = next;											/* Сохраняем позицию указателя */
				}
			}
		
			prev = current;												/* Предыдущий становится текущим */
			current = current->getNextAeroflot();						/* Передвигаем текущий указатель по списку */
		}
	}
}

void Airline::searchDestination(string destination){
	Aeroflot* current = head_aeroflot;						/* Указатель, чтобы бегать по списку */
	bool flag = false;										/* Флаг, указывающий на наличие нужных рейсов. Если их нет, то flag = false */

	for (int i = 0; i < size; ++i) {						/* Бежим по списку */
		if (current->getDestination() == destination) {		/* Сравниваем пункты назначения */
			cout << *current << endl;						/* Выводим информацию о рейсе */
			flag = true;									/* Переводим флаг в позицию наличия нужный рейсов */
		}

		current = current->getNextAeroflot();				/* Передвигаем указатель дальше */
	}

	if (!flag)												/* Если нет нужных рейсов */
		cout << "Подходящих рейсов нет!" << endl << endl;	/* Выводим об этом сообщение на экран */
}

void Airline::changeElement(int index){
	Aeroflot* current = head_aeroflot;						/* Указатель, чтобы бегать по списку */

	for (int i = 1; i < index; ++i)							/* Бежим по элемента, который нужно изменить */
		current = current->getNextAeroflot();				/* Передвигаем указатели */
	
	current->changeData();									/* Вызваем метод изменения данных */
}

ostream & operator<<(ostream &out, Airline &obj){
	try {
		if (!obj.size)									/* Проверяем, пуст ли список */
			throw exception("Список рейсов пуст!");		/* Если список пуст, то генерируем исключительную ситуацию */

		Aeroflot* current = obj.head_aeroflot;			/* Указатель, чтобы бегать по списку */

		for (int i = 0; i < obj.size; ++i) {			/* Бежим по кажому элементу */
			cout << *current << endl;					/* Выводим элемент на экран */
			current = current->getNextAeroflot();		/* Передвигаем указатель на следующий элемент списка */
		}
		cout << endl;									/* Нужно для того, чтобы следующая надпись на экране появилась через строчку */
	}
	catch (exception &ex) {								/* Ловим ошибку */
		cout << ex.what() << endl << endl;				/* Выводим её на экран */
	}
	return out;											/* Возвращаем ссылку на поток вывода */
}