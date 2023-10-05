#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "stdlib.h"
#include <conio.h>
#include <string.h>
#include <Windows.h>

typedef struct _Passenger {
	char name[20];
	int balance;
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
	char name[20];
	Car car;
	int experience, orderAmount, balance;
} Driver;

typedef struct _Order {
	bool rate, congestion;
	Driver driver;
	Passenger passenger;
	int payment;
} Order;

/* -------------------------------- Пассажир ------------------------------------ */

Passenger passenger_new(void);
void set_passenger_name(Passenger* person, char* name);
void set_passenger_balance(Passenger* person, int balance);
const char* get_passenger_name(Passenger person);
int get_passenger_balance(Passenger person);
void input_passenger_name(Passenger* person);
void input_passenger_balance(Passenger* person);
void input_passenger(Passenger* person);
void output_passenger(Passenger person);

Passenger passenger_new(void) {
	Passenger passenger;
	strcpy(passenger.name, "");
	passenger.balance = 0;
	return passenger;
}

void set_passenger_name(Passenger* person, char* name) {
	strcpy(person->name, name);
}

void set_passenger_balance(Passenger* person, int balance) {
	person->balance = balance;
}

const char* get_passenger_name(Passenger person) {
	return person.name;
}

int get_passenger_balance(Passenger person) {
	return person.balance;
}

void input_passenger_name(Passenger* person) {
	char temp[20];
	printf("** Ввод имени пассажира **\n");
	do {
		printf("Введите имя: ");
		gets_s(temp);
	} while (temp[0] == NULL);
	strcpy(person->name, temp);
	printf("Данные успешно введены!\n\n");
}

void input_passenger_balance(Passenger* person) {
	int temp = 0;
	printf("** Ввод баланса пассажира **\n");
	do {
		printf("Введите баланс: ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите баланс: ");
		}
	} while (temp < 0);
	person->balance = temp;
	printf("Данные успешно введены!\n\n");
}

void input_passenger(Passenger* person) {
	char temp_char[20]; int temp_int = 0;
	printf("** Ввод данных пассажира **\n");
	do {
		printf("Введите имя: ");
		gets_s(temp_char);
	} while (temp_char[0] == NULL);
	strcpy(person->name, temp_char);
	do {
		printf("Введите баланс: ");
		while (scanf("%d", &temp_int) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите баланс: ");
		}
	} while (temp_int < 0);
	person->balance = temp_int;
	printf("Данные успешно введены!\n\n");
}

void output_passenger(Passenger person) {
	if (person.name[0] == NULL || person.balance < 0)
		printf("Данные о пассажире отсутствуют!");
	else
		printf("Данные о пассажире:\n-Имя: %s\n-Баланс: %d\n\n", person.name, person.balance);
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
	Fuel* fuel = fuel_new();
	set_fuel_capacity(fuel, 1);
	printf("--- Тест set_fuel_capacity (установлено значение 1) и get_fuel_capacity: заполненность = %d\n", get_fuel_capacity(fuel));
	printf("--- Тест input_fuel (ввести данные о топливном баке):\n");
	input_fuel(fuel);
	printf("--- Тест output_fuel (вывести данные о топливном баке):\n");
	output_fuel(fuel);
	empty_fuel(fuel);
	printf("--- Тест empty_fuel (опустошить бак): заполненность = %d\n", get_fuel_capacity(fuel));
	fill_fuel(fuel);
	printf("--- Тест fill_fuel (заполнить бак): заполненность = %d\n", get_fuel_capacity(fuel));
	fuel_delete(fuel);

	printf("\n---------------------- Автомобиль --------------------------\n\n");
	Car* car = car_new();
	char brand[20];
	strcpy(brand, "Volvo");
	set_car_brand(car, brand);
	printf("--- Тест set_car_brand (установлено значение \"Volvo\") и get_car_brand: марка - %s\n", get_car_brand(car));
	set_car_rate(car, 1);
	printf("--- Тест set_car_rate (установлено значение 1 - Комфорт) и get_car_rate: класс автомобиля - %d\n", get_car_rate(car));
	printf("--- Тест input_car_brand (ввести марку):\n");
	input_car_brand(car);
	printf("--- Тест input_car_rate (ввести класс автомобиля):\n");
	input_car_rate(car);
	printf("--- Тест output_car (вывести данные об автомобиле):\n");
	output_car(car);
	fill_fuel((Fuel*)car);
	printf("--- Тест fill_fuel (заполнить бак, через дочерний объект Car): заполненность = %d\n", get_fuel_capacity((Fuel*)car));
	car_delete(car);

	return 0;
}