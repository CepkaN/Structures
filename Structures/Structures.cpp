#include<iostream>
#include<string>

struct dateData {
	int day = 1;
	int month = 1;
	int year = 1970;
};
struct personData {
	std::string name = "no name";
	dateData birthday;           // объект структуры в качестве поля для другой структуры.
	std::string job = "empty";
	int salary = 0;
};
void show_person(const personData& PD) {
	std::cout << "Name :     " << PD.name << '\n';
	std::cout << "Birthday : " << PD.birthday.day << '.' << PD.birthday.month << '.' << PD.birthday.year << '\n';
	std::cout << "Job :      " << PD.job << '\n';
	std::cout << "Salary :   " << PD.salary << "\n\n";
}
personData input_person() {
	personData tmp;
	std::cout << "Enter name : ";
	std::cin.ignore();           // Съедает первый знак, если без него может полететь функция (при условии, что был использован std::cin>> до этого).
	std::getline(std::cin, tmp.name);
	std::cout << "Enter birthday day: ";
	std::cin >> tmp.birthday.day;
	std::cout << "Enter birthday month: ";
	std::cin >> tmp.birthday.month;
	std::cout << "Enter birthday year: ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore(); std::cout << "Job : ";
	std::getline(std::cin, tmp.job);
	std::cout << "Salary : ";
	std::cin >> tmp.salary;
	return tmp;
}
struct coinKeeper {
	std::string name = "empty";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};
void show_coinKeeper(const coinKeeper& CK) {
	std::cout << "Имя :     " << CK.name << '\n';
	std::cout << "Возраст : " << CK.age << '\n';
	std::cout << "Монеты :  ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b \n";
}
inline int year_of_birth(const coinKeeper& CK, int year) {
	return (year - CK.age);
}
int cash(const coinKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Структура person.
	/*struct person {  // Структура, являющаяся описанием объектов.
		std::string name;  // Поле структуры, являющейся строковой структурой.
		int age;           // Поле структуры, являющейся целочисленной переменной.
		std::string gender;
		std::string job;
		int salary;
	} p1, p2{"Elisa Thompson",22,"female","actress",50000}; // Создание объектов структуры, один из которых мгновенно инициализирован.

	// Обращение к полям объекта структуры.
	p1.name = "Tom Smith";
	p1.age = 26;
	p1.gender = "male";
	p1.job = "programer";
	p1.salary = 80000;
	std::cout << "Name :   " << p1.name << '\n';
	std::cout << "Age :    " << p1.age << '\n';
	std::cout << "Gender : " << p1.gender << '\n';
	std::cout << "Job :    " << p1.job << '\n';
	std::cout << "Salary : " << p1.salary << '\n';
	std::cout << "-----------------------\n";
	std::cout << "Name :   " << p2.name << '\n';
	std::cout << "Age :    " << p2.age << '\n';
	std::cout << "Gender : " << p2.gender << '\n';
	std::cout << "Job :    " << p2.job << '\n';
	std::cout << "Salary : " << p2.salary << '\n';

	// Альтернативный вариант создания объекта.
	person p3{
		"Alex Romanov",
		46,
		"male",
		"director",
		120000
	};
	person p4 = p3; // Прямое присваивание полям объекта p4 значений объекта p3.
	std::cout << "-----------------------\n";
	std::cout << "Name :   " << p4.name << '\n';
	std::cout << "Age :    " << p4.age << '\n';
	std::cout << "Gender : " << p4.gender << '\n';
	std::cout << "Job :    " << p4.job << '\n';
	std::cout << "Salary : " << p4.salary << '\n';*/

	// Структура date.
	/*struct date {
		unsigned int day=1;
		unsigned int month=1;
		unsigned int year=1970;
		std::string note = "empty";  // значение по умолчанию.
	};
	date bd{ 1,5,2010};
	std::cout << bd.day << '.' << bd.month << '.' << bd.year << " - " << bd.note << "\n\n";
	// На экране 1.5.2010 - empty*/

	// Структура personData.
	/*personData pd{"Mike Ledger",{29,7,1998},"teacher",80000};
	show_person(pd);

	personData* pointer = &pd;
	std::cout << pointer->name << "\n";
	std::cout << pointer->birthday.day << "\n";

	//std::cout << *(pointer).name << "\n\n";

	personData pd2 = input_person();
	show_person(pd2);*/

	// Задача 1. Объект с монетами.
	std::cout << "Задача 1\nОбъект : \n";
	coinKeeper keeper{
		"Peter",
		10,
		7,
		new int[7] {2,10,1,1,5,5,10}
	};
	show_coinKeeper(keeper);
	std::cout << "Год рождения : " << year_of_birth(keeper, 2023) << '\n';
	std::cout << "Общие сбережения : " << cash(keeper) << '\n';

	delete[] keeper.coins;





	return 0;
}