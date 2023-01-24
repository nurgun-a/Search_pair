#include "User.h"
int idd = 0;
int g = 0;
int c = 0;

istream& operator>>(istream& is, Wishes& w)
{
	cout << "\t������� ���: "; is >> w.gender; cout << endl;
	cout << "\t������� �������� ��������: ";	is >> w.age1 >> w.age2; cout << endl;
	cout << "\t������� �����: ";is >> w.city; cout << endl;
	cout << "\t������� �����������: "; is >> w.education; cout << endl;
	cout << ""<<endl;
	

	return is;
}

ostream& operator<<(ostream& os, Wishes& w)
{
	os << "������������: " << endl;
	os <<"���: "<< w.gender << "; �������: " << w.age1 << '-' << w.age2 << "; �����: " << w.city <<
		"; �����������: " << w.education << endl;
	return os;
}

istream& operator>>(istream& is, User& us)
{
	cout << "\t������� �������: "; is >> us.surname; cout << endl;
	cout << "\t������� ���: "; is >> us.name; cout << endl;
	cout << "\t������� ���: "; is >> us.gender; cout << endl;
	cout << "\t������� �������: ";	is >> us.age ; cout << endl;
	cout << "\t������� �����: "; is >> us.city; cout << endl;
	cout << "\t������� �����������: "; is >> us.education; cout << endl;
	cout << "" << endl;
	us.id = ++idd;
	return is;
}

ostream& operator<<(ostream& os, User& us)
{
	cout << "--------------------------------------------------------------------------------" << endl;
	os << "���: " << us.name << "; �������: " << us.surname << "; ���:" << us.gender << "; �������:" <<
		us.age << "; �����: " << us.city << "; �����������: " << us.education << endl << endl;
	os << "��������: " << endl;
	for (auto it : us.interests)
	{
		os << "<" << it << "> ";
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	os << us.ww;
	cout << "--------------------------------------------------------------------------------" << endl;
	return os;
}

Wishes::Wishes(string _gender, int _age1, int _age2, string _city,
	string _education)
{
	gender = _gender; age1 = _age1; age2 = _age2; city = _city;
	education = _education;
}

User::User(string _name, string _surname, string _gender, int _age, 
	string _city, string _education, Wishes _ww)
{
	name = _name; surname = _surname; gender = _gender; age = _age; city = _city;
	education = _education; ww = _ww;
	id = ++idd;
}

void User::Push_interests(string str)
{
	interests.push_back(str);
}

Wishes User::Get_wishes()
{
	return ww;
}

vector<string> User::Get_interes()
{
	return interests;
}


Wishes rand_w()
{
	vector <string> interes
	{
		"��������","������","����","�����","�����������","�������",
		"���������","�����","����������","�������","�������","����",
		"���������","��������","�����","��������","�������","����������"
		,"����������"
	};

	string* educ = new string[3]
	{ "�������","�����������������","������" };
	string* city = new string[5]{ "������","������","�����������", "�����������", "������" };
	string* gender = new string[2]{ "�������","�������" };
	string gg = (g == 0 ? gender[1] : gender[0]);
	string name1, surname1;
	int a1 = rand() % 18 + 18;
	int a2 = rand() % 18 + 18;
	Wishes Wtmp(gg, (a1 > a2 ? a2 : a1), (a1 > a2 ? a1 : a2), city[c], educ[rand() % 3]);

	return Wtmp;
}

void rand_u(User& uu, int g1)
{
	

	vector <string> interes
	{
		"��������","������","����","�����","�����������","�������",
		"���������","�����","����������","�������","�������","����",
		"���������","��������","�����","��������","�������","����������"
		,"����������"
	};

	string* educ = new string[3]
	{ "�������","�����������������","������" };
	string* city = new string[5]{ "������","������","�����������", "�����������", "������" };
	string* gender = new string[2]{ "�������","�������" };
	g = g1;
	string gg = gender[g];
	string name1, surname1;
	if (gg == "�������")
	{
		string* name2 = new string[10]
		{ "����������","���������","���","������","����","����","�������","�����","����","����" };
		string* surname2 = new string[10]
		{ "�������","������","�������","�����","��������","�������","���������","�����","������","�������" };
		name1 = name2[rand() % 10];
		surname1 = surname2[rand() % 10];
	}
	else
	{
		string* name3 = new string[10]
		{ "��������","�����","�������","�����", "����������","�����","����","���","�������","�����" };
		string* surname3 = new string[10]
		{ "���������","��������","��������","���������", "���������","������","��������","�������","�������","����������" };
		name1 = name3[rand() % 10];
		surname1 = surname3[rand() % 10];
	}
	int cc = rand() % 5;
	c = cc;
	interes.size();
	Wishes Wt = rand_w();
	User Utmp(name1, surname1, gg, rand() % 18 + 18, city[cc], educ[rand() % 3], Wt);
	int tm = 0;
	auto it = interes.begin();
	for (int i = 0; i < rand() % 7 + 3; i++)
	{
		tm = rand() % interes.size();
		Utmp.Push_interests(interes[tm]);
		it = interes.begin();
		advance(it, tm);
		interes.erase(it);
	}
	uu = Utmp;
}

int Search_pair::Count_if(User user1, User user2)
{
	if (user.ww.age1 < us_all[i].age && us1.ww.age2 > us_all[i].age &&
		us1.age > us_all[i].ww.age1 && us1.age < us_all[i].ww.age2)nn[i]++;
	if (us1.ww.city == us_all[i].city && us_all[i].ww.city == us1.city)nn[i]++;
	if (us1.ww.education == us_all[i].education && us_all[i].ww.education == us1.education)nn[i]++;
}
