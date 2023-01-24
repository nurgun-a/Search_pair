#include "User.h"

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Search_pair Svaha;
	vector<User> vv;
	User us,us1;
	rand_u(us1, 0);
	cout << us1 << endl;
	for (int i = 0; i < 20; i++)
	{
		rand_u(us,1);
		vv.push_back(us);

	}
	for (auto it : vv)
	{
		cout << it;
	}
	system("pause");
	system("cls");
	cout << us1<<endl;
	Svaha.Serach(us1, vv);
}