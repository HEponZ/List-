#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	List list, list2;
	Node* new_head;
	int choise, value;
	enum MENU {
		EXIT = 0,
		ADD,
		PRINT,
		DELETE,
		SEARCH,
		CLONE,
		PLUS,
		YMNOJ
	};

	cout << "1 - Добавить\n2 - Вывести\n3 - Удадить последний\n4 - Поиск\n5 - Клонировать\n6 - Сложение\n7 - Умножение\n";

	do
	{
		try {
			cin >> choise;

			switch (choise)
			{
			case ADD:
				cout << "Введите значение для добваления: ";
				cin >> value;
				list.append(value);

				cout << "Введите значение для добваления 2: ";
				cin >> value;
				list2.append(value);
				break;
			case PRINT:
				list.print();
				break;
			case DELETE:
				list.removeLast();
				break;
			case SEARCH:
				cout << "Введите значение для поиска: ";
				cin >> value;
				if (list.search(value) == true)
				{
					cout << "Значение найдено\n";
				}
				else
				{
					cout << "Такого значения нет\n";
				}
				break;
			case CLONE:
				list.Clone();
				cout << "Копирование выполненно\n";
				break;
			case PLUS:
				cout << "Результат сложения: ";
				print_with_head(list + list2);
				break;
			case YMNOJ:
				cout << "Результат умножения: ";
				print_with_head(list* list2);
				break;
			}
		}
		catch (const char* exc)
		{
			puts(exc);
		}
	} while (choise != 0);

	return 0;
}