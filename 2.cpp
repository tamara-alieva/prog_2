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

// Пассажир
Passenger passenger_new(void);
void set_passenger_name(Passenger* person, char* name);
void set_passenger_balance(Passenger* person, int balance);
const char* get_passenger_name(Passenger person);
int get_passenger_balance(Passenger person);
void input_car(Car car);

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

void output_passenger(Passenger person) {
	if (person.name[0] == NULL || person.balance < 0)
		printf("Данные о пассажире отсутствуют!");
	else
		printf("Данные о пассажире:\n-Имя: %s\n-Баланс: %d\n\n", person.name, person.balance);
}

// Автомобиль

void input_car(Car car) {
	printf("** Ввод данных автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(car.brand);
	} while (car.brand[0] == NULL);
}

// Топливный бак
// Водитель
// Заказ