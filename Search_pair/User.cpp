#include "User.h"
int idd = 0;
int g = 0;
int c = 0;
string* city = new string[5]{ "Москва","Якутск","Владивосток", "Новосибирск", "Уфа" };
string* educ = new string[3]{ "Среднее","Среднеспециальное","Высшее" };
string* gender = new string[2]{ "Мужской","Женский" };
vector <string> interes
{
	"животные","музыка","кино","спорт","путешествия",
	"исскуство","книги","психология","религия","природа","юмор",
	"кулинария","живопись","наука","политика","история","астрономия"
	,"фантастика"
};
vector <int> vec_age
{
	18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37
};

istream& operator>>(istream& is, Wishes& w)
{
	int tmp = 0;
	do
	{
		try
		{
			w.gender = gender[(g == 1 ? 0 : 1)];
			cout << "\tВведите диапозон возраста: "<<endl;	
			cout << "Enter: "; is >> w.age1; cout << "-> ";  is>> w.age2; cout << endl;

			cout << "\tГород: " << endl;
			for (int i = 0; i < 5; i++)	cout << i + 1 << " ) " << city[i] << endl;
			cout << "Enter: "; is >> tmp; if (tmp < 1 || tmp>5)throw 5; else w.city = city[tmp - 1]; tmp = 0;
			system("cls");

			cout << "\tОбразование: " << endl;
			for (int i = 0; i < 3; i++)	cout << i + 1 << " ) " << educ[i] << endl;
			cout << "Enter: "; is >> tmp; if (tmp < 1 || tmp>3)throw 5; else w.education = educ[tmp - 1]; tmp = 0; break;
			system("cls");
		}
		catch (int n)
		{
			cout << "Ошибка ввода!" << endl;
			system("pause");
		}
	} while (true);	
	return is;
}

ostream& operator<<(ostream& os, Wishes& w)
{
	os << "Предпочтения: " << endl;
	os <<"Пол: ["<< w.gender << "] Возраст: [" << (w.age1< w.age2? w.age1: w.age2) << '-' 
		<< (w.age2 > w.age1 ? w.age2 : w.age1) << "]\nГород: [" << w.city <<
		"] Образование: [" << w.education <<']' << endl;
	return os;
}

istream& operator>>(istream& is, User& us)
{
	int count_tmp = 0;
	int I_tmp = 0;
	bool key_1;
	cout << "\tВведите Фамилию: "; is >> us.surname; cout << endl;
	cout << "\tВведите имя: "; is >> us.name; cout << endl;
	cout << "\tДалее выберите подходящие варианты: " << endl;

	do
	{
		try
		{
			cout << "\tПол: \n\t1 - Мужской\n\t2 - Женский" << endl;
			cout << "\tEnter: "; is >> I_tmp;
			if (I_tmp < 1 || I_tmp>2) throw 5; else us.gender = gender[I_tmp - 1]; g = I_tmp - 1;
			cout << endl;
			system("cls");
			cout << "\tВозраст: " << endl;
			for (auto it : vec_age)
			{
				++count_tmp;
				cout << count_tmp << " ) " << it << endl;
			}
			count_tmp = 0;
			cout << "\tEnter: "; is >> I_tmp; if (I_tmp < 1 || I_tmp>20)throw 5; else us.age = vec_age[I_tmp - 1]; I_tmp = 0;
			system("cls");
			cout << "\tГород: " << endl;
			for (int i = 0; i < 5; i++)
				cout << i + 1 << " ) " << city[i] << endl;
			cout << "\tEnter: "; is >> I_tmp; if (I_tmp < 1 || I_tmp>5)throw 5; else us.city = city[I_tmp - 1]; I_tmp = 0;
			system("cls");
			cout << "\tОбразование: " << endl;
			for (int i = 0; i < 3; i++)
				cout << i + 1 << " ) " << educ[i] << endl;
			cout << "\tEnter: "; is >> I_tmp; if (I_tmp < 1 || I_tmp>3)throw 5; else us.education = educ[I_tmp - 1]; I_tmp = 0;
			system("cls");
			vector <string> inter = interes;
			auto it = inter.begin();
			do
			{
				for (auto it : inter)
				{
					++count_tmp;
					cout << count_tmp << " ) " << it << endl;
				}
				count_tmp = 0;

				cout << "\tEnter: "; is >> I_tmp;
				system("cls");
				cout << '<' << inter[I_tmp - 1] << '>' << endl;
				us.interests.push_back(inter[I_tmp - 1]);
				it = inter.begin();
				advance(it, I_tmp - 1);
				inter.erase(it);
				cout << "1 - Добавить  \n0 - Продолжить" << endl;
				cout << "\tEnter: "; is >> key_1;
			} while (key_1);
			system("cls");

			cout << "\tДалее введите пожелания:" << endl; is >> us.ww;
			us.id = ++idd;
			system("cls");
			key_1 = 0;
			return is;
		}
		catch (int n)
		{
			cout << "\tОшибка ввода!" << endl;
			system("pause");
			system("cls");
			key_1 = 1;
		}
	} while (key_1);
	
	
}

ostream& operator<<(ostream& os, User& us)
{
	cout << "*******************************************************************************" << endl;
	os <<"Id: "<<us.id << endl;
	os << "Имя: [" << us.name << "] Фамилия: [" << us.surname << "] Пол: [" << us.gender << "] Возраст: [" <<
		us.age << "]\nГород: [" << us.city << "] Образование: [" << us.education <<']'<< endl << endl;
	os << "Интересы: " << endl;
	for (auto it : us.interests)
	{
		os << "<" << it << "> ";
	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	os << us.ww;
	cout << "*******************************************************************************" << endl;
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
	string gg = (g == 0 ? gender[1] : gender[0]);
	int a1 = rand() % 18 + 18;
	int a2 = rand() % 18 + 18;
	Wishes Wtmp(gg, (a1 > a2 ? a2 : a1), (a1 > a2 ? a1 : a2), city[c], educ[rand() % 3]);
	return Wtmp;
}

void rand_u(User& uu, int g1, int c1)
{
	vector <string> inter= interes;
	g = g1;
	string gg = gender[g];
	string name1, surname1;
	if (gg == "Мужской")
	{
		string* name2 = new string[10]
		{ "Константин","Александр","Лев","Леонид","Артём","Иван","Виталий","Денис","Илья","Петр" };
		string* surname2 = new string[10]
		{ "Соколов","Злобин","Кулаков","Ильин","Кузнецов","Антонов","Чеботарев","Зорин","Иванов","Головин" };
		name1 = name2[rand() % 10];
		surname1 = surname2[rand() % 10];
	}
	else
	{
		string* name3 = new string[10]
		{ "Виктория","Диана","Варвара","Ольга", "Александра","Дарья","Анна","Ева","Клавдия","Софья" };
		string* surname3 = new string[10]
		{ "Николаева","Антонова","Горохова","Муравьева", "Воробьева","Шилова","Логинова","Грачева","Карпова","Никольская" };
		name1 = name3[rand() % 10];
		surname1 = surname3[rand() % 10];
	}
	
	c = c1;	
	Wishes Wt = rand_w();
	User Utmp(name1, surname1, gg, rand() % 18 + 18, city[c], educ[rand() % 3], Wt);
	int tm = 0;
	auto it = inter.begin();
	for (int i = 0; i < rand() % 7 + 3; i++)
	{
		tm = rand() % inter.size();
		Utmp.Push_interests(inter[tm]);
		it = inter.begin();
		advance(it, tm);
		inter.erase(it);
	}
	uu = Utmp;
}

void Search_pair::Serach_p(User us1, vector<User>& us_all)
{
	for (int i = 0; i < us_all.size(); i++)
		Count_ball(us1, us_all[i]);

	auto iter = max_element(us_all.begin(), us_all.end(), [](User user1, User user2)
		{
			return user1.Get_ball() < user2.Get_ball();
		});
	cout << "Мы нашли для вас пару: " << endl;
	cout << "Совпадений: " << iter->ball << endl;
	cout << "Общие интересы: " << endl;
	vector <string> Vtmp;
	sort(us1.interests.begin(), us1.interests.end());
	sort(iter->interests.begin(), iter->interests.end());
	set_intersection(us1.interests.begin(), us1.interests.end(),
		iter->interests.begin(), iter->interests.end(), back_inserter(Vtmp));
	for (auto it : Vtmp)
	{
		cout << '<' << it << ">  ";
	}
	cout << endl << endl;
	cout << *iter;
}

void Search_pair::Count_ball(User &user1, User &user2)
{
	int tmp1,tmp = 0;
	vector <string> Vtmp;
	if (user1.ww.age1 <user2.age && user1.ww.age2 > user2.age && 
		user1.age > user2.ww.age1 && user1.age < user2.ww.age2)user2.ball++;
	if (user1.ww.city == user2.city && user2.ww.city == user1.city)user2.ball++;
	if(user1.ww.education == user2.education && 
		user2.ww.education == user1.education)user2.ball++;

	sort(user1.interests.begin(), user1.interests.end());
	sort(user2.interests.begin(), user2.interests.end());
	set_intersection(user1.interests.begin(), user1.interests.end(),
		user2.interests.begin(), user2.interests.end(), back_inserter(Vtmp));
	user2.ball += Vtmp.size();
}

void Show_menu()
{
	cout << "Добро пожаловать в электорнную сваху." << endl;
	cout << "Мы подберём для вас подхлдящую пару" << endl;
}