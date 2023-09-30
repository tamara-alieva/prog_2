#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
void input_passenger(Passenger person);
void output_passenger(Passenger person);

// Пассажир
typedef struct {
	char name[20];
	int balance;
} Passenger;

// Автомобиль
typedef struct {
	char brand[20];
	bool rate;
	Fuel fuel;
} Car;

// Топливный бак
typedef struct {
	bool capacity;
} Fuel;

// Водитель
typedef struct {
	char name[20];
	Car car;
	int experience, orderAmount, balance;
} Driver;

// Заказ
typedef struct {
	bool rate, congestion;
	Driver driver;
	Passenger passenger;
	int payment;
} Order;

// Ввод данных о пассажире
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
	printf("Данные успешно введены!\n\n");
}

// Вывод данных о пассажире
void output_passenger(Passenger person) {
	if (person.name[0] == NULL || person.balance < 0)
		printf("Данные о пассажире отсутствуют!");
	else
		printf("Данные о пассажире:\n-Имя: %s\n-Баланс: %d\n\n", person.name, person.balance);
}