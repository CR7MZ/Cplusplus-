#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace My
{
	class string 
	{
	public:
		string(char* str = ""){
			if (str == nullptr)
				str = "";

			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//Éî¿½±´
		string(const string& str)
			:_str(new char[strlen(str._str)+1])
		{
			strcpy(_str, str._str);
		}

		//Éî¿½±´
		string& operator=(const string& s){
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void test(){
	My::string s1("qwer");
	My::string s2(s1);
	My::string s3;
	s3 = s1;
}

int main()
{
	test();
	return 0;
}