#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
namespace bite
{
	class string
	{
	public:
		string(char* str = "")
			:Pcount(new int(1))
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = s._str;
			Pcount = s.Pcount;
			++(*Pcount);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				if (0 == (--(*Pcount)))
				{
					delete[] _str;
					delete Pcount;
				}
				_str = s._str;
				Pcount = s.Pcount;
				++(*Pcount);
			}
			return *this;
		}
		~string()
		{
			if (_str && (--(*Pcount)))
			{
					delete[] _str;
					_str = nullptr;
					delete Pcount;
					Pcount = nullptr;
			}
		}
	private:
		char* _str;
		int* Pcount;
	};
}



void Test()
{
	bite::string s("hello");
	bite::string s2(s);
	bite::string s3;
	s3 = s;
}
int main()
{
	Test();
	system("pause");
	return 0;
}