#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
void input_passenger(Passenger person);

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