#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stddef.h>
#include <Windows.h>

typedef struct _PersonPrivate {
	char name[20];
	int balance;
} PersonPrivate;

typedef struct _Person {
	PersonPrivate* _private;
} Person;

typedef struct _PassengerPrivate {
	bool payment_method;
} PassengerPrivate;

typedef struct _Passenger {
	Person person;
	PassengerPrivate* _private;
} Passenger;

typedef struct _FuelPrivate {
	bool capacity;
} FuelPrivate;

typedef struct _Fuel{
	FuelPrivate* _private;
} Fuel;

typedef struct _CarPrivate {
	char brand[20];
	bool rate;
} CarPrivate;

typedef struct _Car {
	Fuel parent;
	CarPrivate* _private;
} Car;

typedef struct _Driver {
	int experience, orderAmount;
} DriverPrivate;

typedef struct _Driver {
	Person person;
	Car car;
	DriverPrivate* _private;
} Driver;

typedef struct _Order {
	bool rate, congestion;
	Driver driver;
	Passenger passenger;
	int payment;
} Order;

/* -------------------------------- Человек ------------------------------------ */

void person_constructor(Person* person);
void person_destructor(Person* person);
Person* person_new(void);
void person_delete(Person* person);
void set_person_name(Person* person, char* name);
const char* get_person_name(Person* person);
void set_person_balance(Person* person, int balance);
int get_person_balance(Person* person);
void input_person(Person* person);
void output_person(Person* person);

void person_constructor(Person* person) {
	person->_private = (PersonPrivate*)malloc(sizeof(PersonPrivate));
	strcpy(person->_private->name, "");
	person->_private->balance = 0;
}

void person_destructor(Person* person) {
	free(person->_private);
}

Person* person_new(void) {
	Person* person = (Person*)malloc(sizeof(Person));
	person_constructor(person);
	return person;
}

void person_delete(Person* person) {
	person_destructor(person);
	free(person);
}

void set_person_name(Person* person, char* name) {
	strcpy(person->_private->name, name);
}

const char* get_person_name(Person* person) {
	return person->_private->name;
}

void set_person_balance(Person* person, int balance) {
	person->_private->balance = balance;
}

int get_person_balance(Person* person) {
	return person->_private->balance;
}

void input_person(Person* person) {
	char temp_char[20]; int temp_int = 0;
	printf("** Ввод данных человека **\n");
	do {
		printf("Введите имя: ");
		gets_s(temp_char);
	} while (temp_char[0] == NULL);
	strcpy(person->_private->name, temp_char);
	do {
		printf("Введите баланс: ");
		while (scanf("%d", &temp_int) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите баланс: ");
		}
	} while (temp_int < 0);
	person->_private->balance = temp_int;
	printf("Данные успешно введены!\n\n");
}

void output_person(Person* person) {
	if (person->_private->name[0] == NULL)
		printf("Данные о человеке отсутствуют!");
	else
		printf("Данные о человеке:\n-Имя: %s\n-Баланс: %d\n", person->_private->name, person->_private->balance);
}

/* -------------------------------- Пассажир ------------------------------------ */

void passenger_constructor(Passenger* passenger, Person* person) {
	person_constructor(person);
	passenger->_private = (PassengerPrivate*)malloc(sizeof(PassengerPrivate));
	passenger->_private->payment_method = 0;
}

void passenger_destructor(Passenger* passenger) {
	free(passenger->_private);
}

Passenger* passenger_new(Person* person) {
	Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
	passenger_constructor(passenger, person);
	return passenger;
}

void passenger_delete(Passenger* passenger) {
	passenger_destructor(passenger);
	free(passenger);
}

void set_passenger_method(Passenger* passenger, bool method) {
	passenger->_private->payment_method = method;
}

bool get_passenger_method(Passenger* passenger) {
	return passenger->_private->payment_method;
}

void input_passenger(Passenger* passenger) {
	int temp = 1;
	printf("** Ввод данных о пассажире **\n");
	do {
		printf("Введите способ оплаты (0 - Наличные, 1 - Банковская карта): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите способ оплаты: ");
		}
	} while (temp != 0 && temp != 1);
	passenger->_private->payment_method = temp;
	printf("Данные успешно введены!\n\n");
}

void output_passenger(Passenger* passenger) {
	printf("Данные о пассажире:\n-Способ оплаты: ");
	if (passenger->_private->payment_method)
		printf("Банксовская карта\n\n");
	else
		printf("Наличные\n\n");
}

/* -------------------------------- Топливный бак ------------------------------------ */

void fuel_constructor(Fuel* fuel);
void fuel_destructor(Fuel* fuel);
Fuel* fuel_new(void);
void fuel_delete(Fuel* fuel);
void set_fuel_capacity(Fuel* fuel, bool capacity);
bool get_fuel_capacity(Fuel* fuel);
void input_fuel(Fuel* fuel);
void output_fuel(Fuel* fuel);
void fill_fuel(Fuel* fuel);
void empty_fuel(Fuel* fuel);

void fuel_constructor(Fuel* fuel) {
	fuel->_private = (FuelPrivate*)malloc(sizeof(FuelPrivate));
	fuel->_private->capacity = 0;
}

void fuel_destructor(Fuel* fuel) {
	free(fuel->_private);
}

Fuel* fuel_new(void) {
	Fuel* fuel = (Fuel*)malloc(sizeof(Fuel));
	fuel_constructor(fuel);
	return fuel;
}

void fuel_delete(Fuel* fuel) {
	fuel_destructor(fuel);
	free(fuel);
}

void set_fuel_capacity(Fuel* fuel, bool capacity) {
	fuel->_private->capacity = capacity;
}

bool get_fuel_capacity(Fuel* fuel) {
	return fuel->_private->capacity;
}

void input_fuel(Fuel* fuel) {
	int temp = 1;
	printf("** Ввод данных о топливном баке **\n");
	do {
		printf("Введите заполенность бака (0 - Пустой, 1 - Полный): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите заполненность бака: ");
		}
	} while (temp != 0 && temp != 1);
	fuel->_private->capacity = temp;
	printf("Данные успешно введены!\n\n");
}

void output_fuel(Fuel* fuel) {
	printf("Данные о топливном баке:\n-Заполненность: ");
	if (fuel->_private->capacity)
		printf("Полный\n\n");
	else
		printf("Пустой\n\n");
}

void fill_fuel(Fuel* fuel) {
	fuel->_private->capacity = 1;
}

void empty_fuel(Fuel* fuel) {
	fuel->_private->capacity = 0;
}

/* -------------------------------- Автомобиль ------------------------------------ */

void car_constructor(Car* car);
void car_destructor(Car* car);
Car* car_new(void);
void car_delete(Car* car);
void set_car_brand(Car* car, char* brand);
void set_car_rate(Car* car, bool rate);
const char* get_car_brand(Car* car);
bool get_car_rate(Car* car);
void input_car_brand(Car* car);
void input_car_rate(Car* car);
void input_car(Car* car);
void output_car(Car* car);

void car_constructor(Car* car) {
	fuel_constructor(&car->parent);
	car->_private = (CarPrivate*)malloc(sizeof(CarPrivate));
	strcpy(car->_private->brand, "");
	car->_private->rate = 0;
}

void car_destructor(Car* car) {
	fuel_destructor(&car->parent);
	free(car->_private);
}

Car* car_new(void) {
	Car* car = (Car*)malloc(sizeof(Car));
	car_constructor(car);
	return car;
}

void car_delete(Car* car) {
	car_destructor(car);
	free(car);
}

void set_car_brand(Car* car, char* brand) {
	strcpy(car->_private->brand, brand);
}

void set_car_rate(Car* car, bool rate) {
	car->_private->rate = rate;
}

const char* get_car_brand(Car* car) {
	return car->_private->brand;
}

bool get_car_rate(Car* car) {
	return car->_private->rate;
}

void input_car_brand(Car* car) {
	char temp[20];
	printf("** Ввод марки автомобиля **\n");
	while (getchar() != '\n');
	do {
		printf("Введите марку: ");
		gets_s(temp);
	} while (temp[0] == NULL);
	strcpy(car->_private->brand, temp);
	printf("Данные успешно введены!\n\n");
}

void input_car_rate(Car* car) {
	int temp = 0;
	printf("** Ввод класса автомобиля **\n");
	do {
		printf("Введите баланс (0 - Эконом, 1 - Комфорт): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите класс автомобиля: ");
		}
	} while (temp != 0 && temp != 1);
	car->_private->rate = temp;
	printf("Данные успешно введены!\n\n");
}

void input_car(Car* car) {
	char temp_char[20]; int temp_int = 0;
	printf("** Ввод данных автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(temp_char);
	} while (temp_char[0] == NULL);
	strcpy(car->_private->brand, temp_char);
	do {
		printf("Введите баланс (0 - Эконом, 1 - Комфорт): ");
		while (scanf("%d", &temp_int) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите класс автомобиля: ");
		}
	} while (temp_int != 0 && temp_int != 1);
	car->_private->rate = temp_int;
	printf("Данные успешно введены!\n\n");
}

void output_car(Car* car) {
	if (car->_private->brand[0] == NULL)
		printf("Данные об автомобиле отсутствуют!");
	else {
		printf("Данные об автомобиле:\n-Марка: %s\n-Класс: ", car->_private->brand);
		if (car->_private->rate)
			printf("Комфорт\n");
		else
			printf("Эконом\n");
	}
}

/* -------------------------------- Водитель ------------------------------------ */
/* -------------------------------- Заказ ------------------------------------ */

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("ТЕСТЫ:\n");
	printf("---------------------- Топливный бак -----------------------\n\n");
	Fuel* fuel_dynamic = fuel_new();
	Fuel fuel_static = *fuel_dynamic;
	set_fuel_capacity(fuel_dynamic, 1);
	printf("--- Тест set_fuel_capacity (установлено значение 1) и get_fuel_capacity: заполненность = %d\n", get_fuel_capacity(fuel_dynamic));
	printf("--- Тест input_fuel (ввести данные о топливном баке):\n");
	input_fuel(fuel_dynamic);
	printf("--- Тест output_fuel (вывести данные о топливном баке):\n");
	output_fuel(fuel_dynamic);
	empty_fuel(&fuel_static);
	printf("--- Тест empty_fuel (опустошить бак): заполненность = %d\n", get_fuel_capacity(&fuel_static));
	fill_fuel(fuel_dynamic);
	printf("--- Тест fill_fuel (заполнить бак): заполненность = %d\n", get_fuel_capacity(fuel_dynamic));
	fuel_delete(fuel_dynamic);

	printf("\n---------------------- Автомобиль --------------------------\n\n");
	Car car_static;
	Car* car_dynamic = car_new();
	car_static = *car_dynamic;
	char brand[20];
	strcpy(brand, "Volvo");
	set_car_brand(car_dynamic, brand);
	printf("--- Тест set_car_brand (установлено значение \"Volvo\") и get_car_brand: марка - %s\n", get_car_brand(car_dynamic));
	set_car_rate(car_dynamic, 1);
	printf("--- Тест set_car_rate (установлено значение 1 - Комфорт) и get_car_rate: класс автомобиля - %d\n", get_car_rate(car_dynamic));
	printf("--- Тест input_car_brand (ввести марку):\n");
	input_car_brand(car_dynamic);
	printf("--- Тест input_car_rate (ввести класс автомобиля):\n");
	input_car_rate(car_dynamic);
	printf("--- Тест output_car (вывести данные об автомобиле):\n");
	output_car(&car_static);
	fill_fuel((Fuel*)car_dynamic);
	printf("--- Тест fill_fuel (заполнить бак, через дочерний объект Car): заполненность = %d\n", get_fuel_capacity((Fuel*)car_dynamic));
	car_delete(car_dynamic);

	return 0;
}