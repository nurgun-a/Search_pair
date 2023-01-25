#include "User.h"

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Search_pair Svaha;
	vector<User> vv;
	User us,us1;	
	//for (auto it : vv)
	//{
	//	cout << it;
	//}
	char ch;
	bool key = 1;

	do
	{
		cout << "Пожалуйста выберите действие:" << endl << endl;
		cout << "1 - Ввести данные вручную" << endl;
		cout << "2 - Сгенерировать данные" << endl;
		cout << "0 - Выход" << endl;
		cout << "Enter: "; cin >> ch; cout << endl;
		system("cls");
		if (ch < '0' || ch>'2')
		{
			cout << "Некорректный ввод. Попробуйте снова" << endl << endl;
			system("pause");
			system("cls");
		}
		else if (ch == '0')break;
		else
		{
			if (ch == '1')
			{
				cin >> us1; cout << us1 << endl;
				for (int i = 0; i < 200; i++)
				{
					rand_u(us, (us1.gend_get() == "Мужской" ? 1 : 0), rand()%5);
					vv.push_back(us);
				}
				cout << "\nДалее мы найдем для вас наиболее подходящую пару\n\n" << endl;
				system("pause");
				system("cls");
				cout << us1 << endl;
				Svaha.Serach_p(us1, vv);
				vv.clear();
			}
			else if (ch == '2')
			{
				int num_city = rand() % 5, num_g = rand() % 2;
				rand_u(us1, num_g, num_city);
				cout << us1 << endl;
				for (int i = 0; i < 200; i++)
				{
					rand_u(us, (num_g == 0 ? 1 : 0), num_city);
					vv.push_back(us);
				}
				cout << "\nДалее мы найдем для вас наиболее подходящую пару\n\n" << endl;
				system("pause");
				system("cls");
				cout << us1 << endl;
				Svaha.Serach_p(us1, vv);
				vv.clear();
			}
		}
		
	} while (key);
}

//switch (ch)
//{
//case '1':
//{
//
//}break;
//case '2':
//{
//
//}break;
//default:
//	break;
//}