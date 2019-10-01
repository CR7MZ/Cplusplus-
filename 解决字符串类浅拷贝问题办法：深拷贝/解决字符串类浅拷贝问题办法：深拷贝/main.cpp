#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
namespace bite
{
	//深拷贝——传统版
	class string
	{
	public:
		string(char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)//拷贝构造函数。
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)//赋值运算符重载
		{
			if (this != &s)
			{
				char* tempStr = new char[strlen(s._str) + 1];
				strcpy(tempStr, s._str);
				delete[] _str;
				_str = tempStr;
			}
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void Test1()
{
	string s1("hello");
	string s2(s1);
	string s3 = s1;
}


namespace bite2
{
	class string//深拷贝——简洁版
	{
	public:
		string(char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(nullptr)
		{
			string TempStr(s._str);
			swap(_str, TempStr._str);
		}
		string& operator=( string s)
		{
			swap(_str, s._str);
			return  *this;
		}
	private:
		char* _str;
	};
}
void test2()
{
	string s1("hello");
	string s2(s1);
	string s3;
	s3 = s2;
	cout << s1 << " " << s2 << " " << s3 << endl;
}
int main()
{
	//Test1();
	test2();
	system("pause");
	return 0;
}