#include <iostream>
#include <string>
using namespace std;

template<class T,size_t N>
class Array {
private:
	T _array[N];
};
void test() {
	Array<int, 20> array; //定义一个含有20个int类型的数组

}
//普通模板函数不能实现字符串相加
template<class T>
T add(T& a, T& b) {
	return a + b;
}
//使用模板函数的特化实现字符串想加
template<>
char* add<char*>(char*& a, char*& b) {
	strcat(a, b);
	return a;
}
//对于函数模板不能处理的特殊类型,一般会定义一个此类型的普通函数
//函数模板的特化比较少用
char* add(char*& a, char*& b) {
	strcat(a, b);
	return a;
}
//类模板特化必须有基础模板
template<class T1,class T2>
class A {
	A() {
		cout << "A<T1, T2>" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};
//全特化
template<>
class A<int, char> {
	A() {
		cout << "A<int,char>" << endl;
	}
private:
	int _t1;
	char _t2;
};
//偏特化:部分特化
template<class T>
class A<int, T> {
	A() {
		cout << "A<int,T>" << endl;
	}
private:
	int _t1;
	T _t2;
};
//参数更进一步的限制
template<class T1,class T2>
class A<T1&, T2&> {
	A() {
		cout << "A<T1&,T2&>" << endl;
	}
private:
	T1& _t1;
	T2& _t2;
};
void test()
{
	//C++语言，对于不同类型的数据，输入输出调用不同的重载函数
	// 调用ostream对象的成员函数operator <<
	cout << "abc" << 1 << 2.0 << endl;
	//调用ostream对象的成员函数operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);
	//调用普通函数 operator<<(ostream&, char*)
	operator<<(cout, "abc");
	cout << "abc" << 1 << 2.0 << endl;
	clog << "abc" << 1 << 2.0 << endl;

	int a;
	//调用istream对象的成员函数 operator>>
	cin >> a;
	cin.operator>>(a);

	//C语言，对于不同类型的数据，输入输出调用同一个函数
	printf("%d\n", a);
	scanf("%d", &a);
}


int main() {
	test();

	return 0;
}


