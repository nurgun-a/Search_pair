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
	int Get_ball() { return ball; }
	
};

Wishes rand_w();
void rand_u(User& uu, int g1, int c1);

class Search_pair: protected User
{
public:
	void Serach(User us1, vector <User>& us_all)
	{
		for (int i = 0; i < us_all.size(); i++)
		{
			Count_if(us1, us_all[i]);				
		}	
		auto iter=max_element(us_all.begin(), us_all.end(), [](User user1,User user2)
			{
				return user1.Get_ball() < user2.Get_ball();
			});
		cout << "�� ����� ��� ��� ����: " << endl;
		cout << "����������: " << iter->ball << endl;
		//cout <<endl;
		cout << "����� ��������: " << endl;
		vector <string> Vtmp;
		sort(us1.interests.begin(), us1.interests.end());
		sort(iter->interests.begin(), iter->interests.end());

		set_intersection(us1.interests.begin(), us1.interests.end(),
			iter->interests.begin(), iter->interests.end(), back_inserter(Vtmp));		
		for (auto it : Vtmp)
		{
			cout <<'<'<< it <<">  ";
		}
		cout << endl << endl;
		cout << *iter;
	}
	void Count_if(User &user1, User &user2);
};