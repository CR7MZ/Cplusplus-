#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class String
{
public:
	String(const char* str="")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char*tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;
	}
	~String()
	{
		delete[] _str;
	}
private:
	char* _str;
};
//template<class T>
//void Cop1(T* des, T* src, size_t size)
//{
//	memcpy(des, src, sizeof(T)*size);
//}
//template<class T>
//void Cop2(T* des, T* src, size_t size)
//{
//	for(size_t i = 0; i < size; i++)
//	{
//		des[i] = src[i];
//	}
//}
struct truetype
{
	static bool Get()
	{
		return true;
	}
};
struct falsetype
{
	static bool Get()
	{
		return false;
	}
};
template<class T>
struct Type
{
	typedef falsetype podtype;
};

template<>
struct Type<int>
{
	typedef truetype podtype;
};

template<>
struct Type<float>
{
	typedef truetype podtype;
};

template<>
struct Type<char>
{
	typedef truetype podtype;
};
template<class T>
void Copy(T* des, T* src, size_t size)
{
	if (Type<T>::podtype::Get())//内置类型
	{
		//内置类型用memcpy效率高
		memcpy(des, src, sizeof(T)*size);
	}
	else//自定义类型
	{
		for (size_t i = 0; i < size; i++)
		{
			//自定义类型用这个不会出现浅拷贝的问题
			des[i] = src[i];
		}
	}
}
int main()
{
	int str[] = { 1,2,3,4,5,6,7,8 };
	int str2[10];
	Copy(str2, str, 10);
	String s[3] = { "111", "222", "333" };
	String s2[3];
	Copy(s2,s,3);
	system("pause");
	return 0;
}