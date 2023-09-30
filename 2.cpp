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

/* -------------------------------- Автомобиль ------------------------------------ */

Car car_new(Fuel fuel);
void set_car_brand(Car* car, char* brand);
void set_car_rate(Car* car, bool rate);
void set_car_fuel(Car* car, Fuel fuel);
const char* get_car_brand(Car car);
bool get_car_rate(Car car);
Fuel get_car_fuel(Car car);
void input_car_brand(Car* car);
void input_car_rate(Car* car);
void input_car_fuel_capacity(Car* car);
void input_car(Car* car);
void output_car(Car car);

Car car_new(Fuel fuel) {
	Car car;
	strcpy(car.brand, "");
	car.rate = 0;
	car.fuel = fuel;
	return car;
}

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

void input_car_brand(Car* car) {
	char temp[20];
	printf("** Ввод марки автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(temp);
	} while (temp[0] == NULL);
	strcpy(car->brand, temp);
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
	car->rate = temp;
	printf("Данные успешно введены!\n\n");
}

void input_car_fuel_capacity(Car* car) {
	int temp = 0;
	printf("** Ввод заполненности бака автомобиля **\n");
	do {
		printf("Введите заполенность бака (0 - Пустой, 1 - Полный): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите заполненность бака: ");
		}
	} while (temp != 0 && temp != 1);
	car->fuel.capacity = temp;
	printf("Данные успешно введены!\n\n");
}

void input_car(Car* car) {
	char temp_char[20]; int temp_int = 0;
	printf("** Ввод данных автомобиля **\n");
	do {
		printf("Введите марку: ");
		gets_s(temp_char);
	} while (temp_char[0] == NULL);
	strcpy(car->brand, temp_char);
	do {
		printf("Введите баланс (0 - Эконом, 1 - Комфорт): ");
		while (scanf("%d", &temp_int) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите класс автомобиля: ");
		}
	} while (temp_int != 0 && temp_int != 1);
	car->rate = temp_int;
	do {
		printf("Введите заполенность бака (0 - Пустой, 1 - Полный): ");
		while (scanf("%d", &temp_int) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите заполненность бака: ");
		}
	} while (temp_int != 0 && temp_int != 1);
	car->fuel.capacity = temp_int;
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
		printf("-Заполненность топливного бака: ");
		if (car.fuel.capacity)
			printf("Полный\n\n");
		else
			printf("Пустой\n\n");
	}
}

/* -------------------------------- Топливный бак ------------------------------------ */

Fuel fuel_new(void);
void set_fuel_capacity(Fuel* fuel, bool capacity);
bool get_fuel_capacity(Fuel fuel);
void input_fuel(Fuel* fuel);
void output_fuel(Fuel fuel);
void fill_fuel(Fuel* fuel);
void empty_fuel(Fuel* fuel);

Fuel fuel_new(void) {
	Fuel fuel;
	fuel.capacity = 1;
	return fuel;
}

void set_fuel_capacity(Fuel* fuel, bool capacity) {
	fuel->capacity = capacity;
}

bool get_fuel_capacity(Fuel fuel) {
	return fuel.capacity;
}

void input_fuel(Fuel* fuel) {
	int temp = 1;
	printf("** Ввод данных о топливном баке**\n");
	do {
		printf("Введите заполенность бака (0 - Пустой, 1 - Полный): ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите заполненность бака: ");
		}
	} while (temp != 0 && temp != 1);
	fuel->capacity = temp;
	printf("Данные успешно введены!\n\n");
}

void output_fuel(Fuel fuel) {
	printf("Данные о топливном баке:\n-Заполненность: ");
	if (fuel.capacity)
		printf("Полный\n\n");
	else
		printf("Пустой\n\n");
}

void fill_fuel(Fuel* fuel) {
	fuel->capacity = 1;
}

void empty_fuel(Fuel* fuel) {
	fuel->capacity = 0;
}

/* -------------------------------- Водитель ------------------------------------ */
/* -------------------------------- Заказ ------------------------------------ */
