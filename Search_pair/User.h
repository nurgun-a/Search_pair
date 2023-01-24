#include <iostream>
#include <iomanip>
#include <map> 
#include <string>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Search_pair;
class User;
struct Wishes
{
	string gender;
	int age1;
	int age2;
	string city;
	string education;
	friend istream& operator >> (istream& is, Wishes& w);
	friend ostream& operator << (ostream& os, Wishes& w);
	Wishes(){}
	Wishes(string _gender, int _age1, int _age2, string _city, string _education);
	friend User;
};
class User
{
protected:
	unsigned int id;	
	string name;
	string surname;
	string gender;
	int age;
	string city;
	string education;
	vector<string> interests;
	struct Wishes ww;
	int ball = 0;
	friend Search_pair;
public:

	User() {}
	User(string _name, string _surname, string _gender, int _age, 
		string _city, string _education, Wishes _ww);
	void Push_interests(string str);
	friend istream& operator >> (istream& is, User& us);
	friend ostream& operator << (ostream& os, User& us);
	string gend_get()
	{
		return gender;
	}
	Wishes Get_wishes();
	vector<string> Get_interes();
	
};

Wishes rand_w();
void rand_u(User& uu, int g1);

class Search_pair: protected User
{
public:
	void Serach(User us1, vector <User>& us_all)
	{
		int* nn = new int[us_all.size()]{};
		int* ii = new int[us_all.size()]{};
		for (int i = 0; i < us_all.size(); i++)
		{
			if (us1.ww.age1 < us_all[i].age && us1.ww.age2 > us_all[i].age &&
				us1.age>us_all[i].ww.age1 && us1.age < us_all[i].ww.age2)nn[i]++;
			if (us1.ww.city== us_all[i].city && us_all[i].ww.city==us1.city)nn[i]++;
			if (us1.ww.education == us_all[i].education && us_all[i].ww.education == us1.education)nn[i]++;


			//set_intersection(us1.ww.interests.begin(), us1.ww.interests.end(), 
			//	us_all[i].interests.begin(), us_all[i].interests.end(), [](User us1, User us2)
			//	{
			//		if(us1.Get_interes() == us2.Get_wishes().interests) cout<< us1.Get_interes()[1];
			//	});

			/*for (int k = 0; k < us1.ww.interests.size(); k++)
			{
				for (int q = 0; q < us_all[i].interests.size(); q++)
				{
					for (int e = 0; e < us1.interests.size(); e++)
					{
						for (int w = 0; w < us_all[i].ww.interests.size(); w++)
						{
							if (us1.ww.interests[k] == us_all[i].interests[q] && us1.interests[e] == us_all[i].ww.interests[w])
							{
								nn[i]++;
							}
						}
					}
					
				}
			}*/
				
		}
		int tmp1,tmp =0;

		for (int i = 0; i < us_all.size(); i++)
		{
			if (tmp<nn[i])
			{
				tmp = nn[i];
				tmp1 = i;
			}
		}
		cout << "Ваша пара: " << endl;
		cout << us_all[tmp1];
	}

	int Count_if(User user1, User user2);
};//cout << us1.ww.interests[k] << "< - >" << us_all[i].interests[q] << endl;