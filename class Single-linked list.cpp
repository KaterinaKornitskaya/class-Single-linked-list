// class Single-linked list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
	В класс односвязного списка (см. код в Тимс) добавить метод, 
	добавляющий элемент к началу (голове) списка.
*/

struct Element      // структура Элемент
{
	char data;      // значение, которое хранит эл-т 
	Element* next;  // указатель на адрес следующего эл-та	
};

class SL_list       // класс Односвязный список
{
	Element* head;  // указатель на адрес головного эл-та
	Element* tail;  // указатель на адрес конечного эл-та
	short count;    // колличество эл-тов в списке
public:
	SL_list()       
		: head{ nullptr }, tail{ nullptr }, count{ 0 } {}
	                
	~SL_list();

	void add_to_tail(char data);         // добавление эл-та к хвосту
	void add_to_head(char data);         // добавление эл-та к голове
	void del_from_head();                // удаление эл-та начиная с головы
	void del_all();                      // удаление всего списка
	void print();                        // вывод на экран списка (с головы)
	void print_head();                   // вывод на экран головного эл-та
	void print_tail();                   // вывод на экран конечного эл-та
	void print_position(short n);        // вывод на экран позиции эл-та
	int get_count()				         // получение колличества эл-тов списка
	{
		return count;                    // возвращаем количество элементов
	}
};

SL_list::~SL_list()  // деструктор
{
	del_all();       // вызов метода удаления
}

void SL_list::add_to_tail(char data)  // метод - добавление эл-та к хвосту
{
	Element* temp = new Element;  // создание нового эл-та
	temp->data = data;            // заполняем значение эл-та
	temp->next = nullptr;         // следующий эл-т - отсутствует
	if (head != nullptr)          // если в списке есть эл-ты
	{
		tail->next = temp;        // заполняем следующий после старого хвоста
		tail = temp;              // добавленный эл-т - новый хвост
	}
	else                          // если список был пуст
	{
		head = tail = temp;       // добавленный эл-т - звост и голова одновременно
	}
	count++;                      // считаем кол-во эл-тов
}

void SL_list::add_to_head(char data)  // метод - добавление эл-та к голове
{
	Element* temp = new Element;      // создание нового эл-та
	temp->data;                       // заполняем значение эл-та
	temp->next = head;                // теперь следующий эл-т - бывшая голова
	if (head != nullptr)              // если в списке есть какие-либо элементы
	{
		head = temp;                  // новая голова - элемент, который добавили
	}
	count++;                          // считаем кол-во эл-тов
}

void SL_list::del_from_head()  // метод - удаление эл-та начиная с головы
{
	Element* temp = head;      // запоминаем адрес головного элемента
	head = head->next;         // перебрасываем голову на следующий элемент
	delete temp;               // удаляем бывший головной элемент
	count--;                   // отнимаем удаленный эл-т от колличества
}

void SL_list::del_all()      // удаление всего списка
{
	while (head != nullptr)  // пока есть эл-ты в списке
	{
		del_from_head();     // вызываем метод удаления по очереди
	}
	count = 0;
}

void SL_list::print()                    // вывод на экран списка (с головы)
{
	Element* temp = head;                // запоминаем адрес головного элемента
	while (temp != nullptr)              // пока есть эл-ты
	{
		std::cout << temp->data << ' ';  // выводим на экран текущий эл-т
		temp = temp->next;               // переставляем на следующий эл-т
	}
	std::cout << std::endl;
}

void SL_list::print_head()                 // метод - вывод на экран головного эл-та
{						                   
	Element* temp = head;                  // запоминаем адрес головного элемента
	std::cout << "\nHead " << temp->data;  // вывод на экран данных
}

void SL_list::print_tail()                 // метод - вывод на экран конечного эл-та
{						                  
	Element* temp = tail;                  // запоминаем адрес головного элемента
	std::cout << "\nTail " << temp->data;  // вывод на экран данных
}

void SL_list::print_position(short n)  // метод - вывод на экран позиции эл-та
{
	Element* temp = head;              // запоминаем адрес головного элемента
	int i = 1;  		               
	while (i < n)                      // пока не достигли нужной позиции
	{					               
		temp = temp->next;             // переходим на следующий эл-т
		i++;
	}
	std::cout << "\nPosition: " << temp->data;  // когда вышли из цикла - 
												// вывод эл-та на экран
}

int main()
{
	SL_list obj1;                       // cоздаем объект класса SL_list
	char string[]{ "Happy Holidays" };  // создаем массив элементов
	std::cout << string << std::endl;  
	int len = strlen(string);
	for (int i{ 0 }; i < len; i++)
	{
		obj1.add_to_tail(string[i]);    // вывод на экран эл-тов
	}
	obj1.add_to_head(1);                // добавили символ к голове
	obj1.print();                       // вывод на экран
	
	obj1.del_from_head();               // удаление одного эл-та (с головы)
	obj1.del_from_head();
	
	obj1.print();
	obj1.get_count();

	std::cout << "Number of elements: " 
		<< obj1.get_count() << std::endl;
	std::cout << "\nEnter position: ";
	short position;                     // переменная для выбора позиции эл-та
	std::cin >> position;
	obj1.print_position(position);      // вывод на экран эл-та на данной позиции
	obj1.print_head();                  // вывод на экран головного эл-та
	obj1.print_tail();                  // вывод на экран конечного эл-та
	return 0;
}



