/*
Завдання 2.
Описати клас  Студент(ім’я, курс, оцінка у 100-бальній системі).
•	Визначити функцію заповнення вектору(деку) студентів довільними  даними
•	Визначити  функцію виводу вмісту вектору(деку).
•	Впорядкувати вектор(дек) за іменами студентів по зростанню(третій параметр sort вказати як лямбду:
sort(d.begin(), d.end(), [](Student &s1, Student &s2) {return s1.getName() < s2.getName();})
•	Відсортувати вектор(дек) за прізвищами студентів
•	Знайти кількість студентів, що добре навчаються(бал >=74)	count_if
•	Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список) copy_if
•	Встановити у перші три  елементи вектору(деку) студентів самих молодших курсів за зростанням	(partial_sort_copy).
Після кожної операції виводити список студентів у стандартний вихідний потік.
Використайте лямбда-функції.

*/


#include "stdafx.h"
#include <iostream> 
#include <string>
#include <ctime>
#include <deque>
#include <algorithm>
#include <iomanip>

using namespace std;

const string names[10] = { "Oleg", "Petro", "Olga", "Iryna", "Tetyana", "Fedir", "Mukolay", "Viktor", "Natalya", "Oksana" };
const string surnames[10] = { "Kovalenko", "Petrenko", "Shevchenko", "Bondar", "Melnik", "Koval", "Gonchar", "Kravchuk", "Tkach", "Finyuk" };

class Student
{
private:
	struct Person
	{
		string name;
		string surName;
		int course;
		int points;

		void print()
		{
			cout << name << "\t" << surName << setw(30) << "\t(course: " << course << ")\tpoints: " << points << endl;
		}
	};

	deque<Person> d;
public:

	//Визначити функцію заповнення вектору(деку) студентів довільними  даними
	void add()
	{
		Person p;
		p.name = names[(rand() % 10)];
		p.surName = surnames[(rand() % 10)];
		p.course = rand() % 5 + 1;
		p.points = rand() % 50 + 50;
		d.push_back(p);
	}

	//Визначити  функцію виводу вмісту вектору(деку).
	void print(deque<Person> d)
	{
		for (Person elem : d)
			elem.print();
		cout << endl;
	}

	void print()
	{
		for (Person elem : d)
			elem.print();
		cout << endl;
	}

	//Впорядкувати вектор(дек) за іменами студентів по зростанню(третій параметр sort вказати як лямбду :
	//sort(d.begin(), d.end(), [](Student &s1, Student &s2) {return s1.getName() < s2.getName(); })
	void sortName()
	{
		cout << "\tSort by Name\n";
		sort(d.begin(), d.end(), [](Person &p1, Person &p2) {return p1.name < p2.name; });
	}

	//Відсортувати вектор(дек) за прізвищами студентів
	void sortSurName()
	{
		cout << "\tSort by Surname\n";
		sort(d.begin(), d.end(), [](Person &p1, Person &p2) {return p1.surName < p2.surName; });
	}

	bool better(int point)
	{
		if (point < 74)
			return 0;
		else
			return 1;
	}

	//Знайти кількість студентів, що добре навчаються(бал >= 74)	count_if
	int goodPoints()
	{
		int count = count_if(d.begin(), d.end(), [](Person p) {return (p.points > 74); });
		return count;
	}

	//Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список) copy_if
	void listGoodPoints()
	{
		deque<Person> g(goodPoints());
		copy_if(d.begin(), d.end(), g.begin(), [](Person p) {return (p.points > 74); });
		cout << "\tStudents with points more than 74:\n";
		print(g);
	}

	//Встановити у перші три  елементи вектору(деку) студентів самих молодших курсів за зростанням(partial_sort_copy).
	void youngerStudent()
	{
		deque<Person> y(3);
		partial_sort_copy(d.begin(), d.end(), y.begin(), y.end(), [](Person &p1, Person &p2) {return p1.course < p2.course; });
		cout << "\tStudents of young courses:\n";
		print(y);
	}

};


int main()
{
	srand(unsigned(time(0)));
	Student s;
	for (int i = 0; i < 10; ++i) //формуємо список студентів
		s.add();
	s.print();
	s.sortName(); // сортуємо по імені
	s.print();
	s.sortSurName(); // сотуємо по прізвищу
	s.print();
	cout << "Countity of students with points more than 74:\t" << s.goodPoints() << endl; // рахуємо кількість студентів з балом більше 74
	s.listGoodPoints(); // копіюємо кращих
	s.youngerStudent(); // копіюємо молодші курси

	cout << endl;
	system("pause");
	return 0;

}






