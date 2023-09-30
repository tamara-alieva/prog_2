#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "stdlib.h"
#include <conio.h>
#include <string.h>
#include <Windows.h>

typedef struct {
	char name[20];
	int balance;
} Passenger;

typedef struct {
	char brand[20];
	bool rate;
	Fuel fuel;
} Car;

typedef struct {
	bool capacity;
} Fuel;

typedef struct {
	char name[20];
	Car car;
	int experience, orderAmount, balance;
} Driver;

typedef struct {
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
void input_passenger_name(Passenger person);
void input_passenger_balance(Passenger person);
void input_passenger(Passenger person);
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

void input_passenger_name(Passenger person) {
	printf("** Ввод имени пассажира **\n");
	do {
		printf("Введите имя: ");
		gets_s(person.name);
	} while (person.name[0] == NULL);
	printf("Данные успешно введены!\n\n");
}

void input_passenger_balance(Passenger person) {
	printf("** Ввод баланса пассажира **\n");
	do {
		printf("Введите баланс: ");
		while (scanf("%d", &person.balance) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите баланс: ");
		}
	} while (person.balance < 0);
	printf("Данные успешно введены!\n\n");
}

void input_passenger(Passenger person) {
	printf("** Ввод данных пассажира **\n");
	do {
		printf("Введите имя: ");
		gets_s(person.name);
	} while (person.name[0] == NULL);
	do {
		printf("Введите баланс: ");
		while (scanf("%d", &person.balance) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите баланс: ");
		}
	} while (person.balance < 0);
}

void output_passenger(Passenger person) {
	if (person.name[0] == NULL || person.balance < 0)
		printf("Данные о пассажире отсутствуют!");
	else
		printf("Данные о пассажире:\n-Имя: %s\n-Баланс: %d\n\n", person.name, person.balance);
}

/* -------------------------------- Автомобиль ------------------------------------ */

Car car_new(Fuel fuel) {
	Car car;
	strcpy(car.brand, "");
	car.rate = 0;
	car.fuel = fuel;
	return car;
}

void set_car_brand(Car* car, char* brand);
void set_car_rate(Car* car, bool rate);
void set_car_fuel(Car* car, Fuel fuel);
const char* get_car_brand(Car car);
bool get_car_rate(Car car);
Fuel get_car_fuel(Car car);
void input_car_brand(Car car);
void input_car_rate(Car car);
void input_car(Car car);
void output_car(Car car);

void set_car_brand(Car* car, char* brand) {
	strcpy(car->brand, brand);
}

void set_car_rate(Car* car, bool rate) {
	car->rate = rate;
}

void set_car_fuel(Car* car, Fuel fuel) {
	car->fuel = fuel;
}

const char* get_car_brand(Car car) {
	return car.brand;
}

bool get_car_rate(Car car) {
	return car.rate;
}

Fuel get_car_fuel(Car car) {
	return car.fuel;
}

void input_car_brand(Car car) {
	printf("** Ввод марки автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(car.brand);
	} while (car.brand[0] == NULL);
	printf("Данные успешно введены!\n\n");
}

void input_car_rate(Car car) {
	int temp;
	printf("** Ввод класса автомобиля **\n");
	do {
		printf("Введите баланс (0 - Эконом, 1 - Комфорт): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите класс автомобиля: ");
		}
	} while (temp != 0 && temp != 1);
	car.rate = temp;
	printf("Данные успешно введены!\n\n");
}

void input_car(Car car) {
	int temp;
	printf("** Ввод данных автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(car.brand);
	} while (car.brand[0] == NULL);
	do {
		printf("Введите баланс (0 - Эконом, 1 - Комфорт): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите класс автомобиля: ");
		}
	} while (temp != 0 && temp != 1);
	car.rate = temp;
	printf("Данные успешно введены!\n\n");
}

void output_car(Car car) {
	if (car.brand[0] == NULL)
		printf("Данные об автомобиле отсутствуют!");
	else {
		printf("Данные об автомобиле:\n-Марка: %s\n-Класс: ", car.brand);
		if (car.rate)
			printf("Комфорт\n");
		else
			printf("Эконом\n");
		printf("-Ёмкость топливного бака: ");
		if (car.fuel.capacity)
			printf("Полный\n\n");
		else
			printf("Пустой\n\n");
	}
}


/* -------------------------------- Топливный бак ------------------------------------ */
/* -------------------------------- Водитель ------------------------------------ */
/* -------------------------------- Заказ ------------------------------------ */
