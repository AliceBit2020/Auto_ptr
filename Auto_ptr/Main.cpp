#include <iostream>
//#include <memory>
using namespace std;

class Foo
{
private:

	int m_number;

public:
	Foo(int number) : m_number(number)
	{
	}
	Foo() : m_number(0)
	{
	}

	int GetNumber()
	{
		return m_number;
	}
};


void Func(Foo* obj)
{

}
void Func(auto_ptr<Foo> obj)/////  move
{

}////

void Func1(auto_ptr<Foo>& obj)/////  
{

}////
void main() 
{
	//Foo* arr_ptr = new Foo (5);
	//int a;
	//cin >> a;
	//if (a == 0)
	//	return;
	//delete  arr_ptr;






	//
	//	std::auto_ptr<Foo> p1(new Foo(5));    /////   Foo* ptr=new Foo(5);

	//	cout << p1.get() << ' ' << p1.get()->GetNumber() << endl;
	//	cout << (*p1).GetNumber() << endl;
	//
	//	p1.reset(new Foo(6));

	//	//Foo* ptr=p1.release();

	//	auto_ptr<Foo> p11(p1.release());
	//	cout << "p11   new Foo(6)" << p11.get() << ' ' << p11.get()->GetNumber() << endl;

	//std::auto_ptr<Foo> p2;
	//p2 = p11;	   ////�� ���� copy       = � ���������� � �������� ������ �� move
	////
	//cout <<"p2=p11:   " << p2.get() << ' ' << p2.get()->GetNumber() << endl;
	//cout <<"p11:  " << p11.get() << endl;




	////////////////////////  new Foo[5]

	Foo** arr_foo = new Foo*[5];


	for (int i = 0; i < 5; i++)
	{
		arr_foo[i] = new Foo(i+1);

	}

	


	std::unique_ptr<unique_ptr<Foo*>[]> arr(new unique_ptr<Foo*> [5] );



	for (int i = 0; i < 5; i++)
	{
		
		arr[i]= make_unique<Foo*>(new Foo(i + 1));

		
		cout << arr[i]<<" : " << (*(arr[i]))->GetNumber() << endl;
	}




	//cout << p1.get()->GetNumber() << endl;
	//
	//
	//Func1(p2);
	//cout << p2.get();

	//Func(p2);
	//cout << p2.get();

}

/////���������� std::auto_ptr
/*
1. ��� ������� � ����������� delete ��� �� �������� ��� ���������� �� �������  (no delete[])
2. ��� ����������� ����� ���������� ��� ������� ������������ ��������� ����������� 
��� �������� � ������� �� ��������
	Func(p2);
void Func(auto_ptr<Foo> obj)
{

}
�� �������� �������� ���������, ��� ������ �� ������� ��������� ���������� ������ ���������, 
� �������� ����������� � ������� �� ��������� ����������� � ���� ���� nullptr
3. ����� ��������� � ���� �������� � ������ ������� ������ ������������ �������


*/