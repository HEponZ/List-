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

	cout << "1 - ��������\n2 - �������\n3 - ������� ���������\n4 - �����\n5 - �����������\n6 - ��������\n7 - ���������\n";

	do
	{
		try {
			cin >> choise;

			switch (choise)
			{
			case ADD:
				cout << "������� �������� ��� ����������: ";
				cin >> value;
				list.append(value);

				cout << "������� �������� ��� ���������� 2: ";
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
				cout << "������� �������� ��� ������: ";
				cin >> value;
				if (list.search(value) == true)
				{
					cout << "�������� �������\n";
				}
				else
				{
					cout << "������ �������� ���\n";
				}
				break;
			case CLONE:
				list.Clone();
				cout << "����������� ����������\n";
				break;
			case PLUS:
				cout << "��������� ��������: ";
				print_with_head(list + list2);
				break;
			case YMNOJ:
				cout << "��������� ���������: ";
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