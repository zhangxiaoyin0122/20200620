#include <iostream>
#include <string>
using namespace std;

template<class T,size_t N>
class Array {
private:
	T _array[N];
};
void test() {
	Array<int, 20> array; //����һ������20��int���͵�����

}
//��ͨģ�庯������ʵ���ַ������
template<class T>
T add(T& a, T& b) {
	return a + b;
}
//ʹ��ģ�庯�����ػ�ʵ���ַ������
template<>
char* add<char*>(char*& a, char*& b) {
	strcat(a, b);
	return a;
}
//���ں���ģ�岻�ܴ������������,һ��ᶨ��һ�������͵���ͨ����
//����ģ����ػ��Ƚ�����
char* add(char*& a, char*& b) {
	strcat(a, b);
	return a;
}
//��ģ���ػ������л���ģ��
template<class T1,class T2>
class A {
	A() {
		cout << "A<T1, T2>" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};
//ȫ�ػ�
template<>
class A<int, char> {
	A() {
		cout << "A<int,char>" << endl;
	}
private:
	int _t1;
	char _t2;
};
//ƫ�ػ�:�����ػ�
template<class T>
class A<int, T> {
	A() {
		cout << "A<int,T>" << endl;
	}
private:
	int _t1;
	T _t2;
};
//��������һ��������
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
	//C++���ԣ����ڲ�ͬ���͵����ݣ�����������ò�ͬ�����غ���
	// ����ostream����ĳ�Ա����operator <<
	cout << "abc" << 1 << 2.0 << endl;
	//����ostream����ĳ�Ա����operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);
	//������ͨ���� operator<<(ostream&, char*)
	operator<<(cout, "abc");
	cout << "abc" << 1 << 2.0 << endl;
	clog << "abc" << 1 << 2.0 << endl;

	int a;
	//����istream����ĳ�Ա���� operator>>
	cin >> a;
	cin.operator>>(a);

	//C���ԣ����ڲ�ͬ���͵����ݣ������������ͬһ������
	printf("%d\n", a);
	scanf("%d", &a);
}


int main() {
	test();

	return 0;
}


