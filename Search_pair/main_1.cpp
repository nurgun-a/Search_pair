#include "User.h"

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Search_pair Svaha;
	vector<User> vv;
	User us,us1;
	int num_city = rand() % 5;
	rand_u(us1, 0, num_city);
	cout << us1 << endl;
	for (int i = 0; i < 200; i++)
	{
		rand_u(us,1, num_city);
		vv.push_back(us);

	}
	//for (auto it : vv)
	//{
	//	cout << it;
	//}
	system("pause");
	system("cls");
	cout << us1<<endl;
	Svaha.Serach(us1, vv);

}