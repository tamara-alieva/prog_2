#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
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

typedef struct _DriverPrivate {
	int experience, orderAmount;
} DriverPrivate;

typedef struct _Driver {
	Person person;
	DriverPrivate* _private;
} Driver;

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
		printf("Данные о человеке отсутствуют!\n");
	else
		printf("Данные о человеке:\n-Имя: %s\n-Баланс: %d\n", person->_private->name, person->_private->balance);
}

/* -------------------------------- Пассажир ------------------------------------ */

void passenger_constructor(Passenger* passenger, Person* person);
void passenger_destructor(Passenger* passenger);
Passenger* passenger_new(Person* person);
void passenger_delete(Passenger* passenger);
void set_passenger_method(Passenger* passenger, bool method);
bool get_passenger_method(Passenger* passenger);
void input_passenger(Passenger* passenger);
void output_passenger(Passenger* passenger);
void take_payment(Passenger* passenger, int payment);

void passenger_constructor(Passenger* passenger, Person* person) {
	passenger->person = *person;
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
	printf("** Ввод данных о пассажире %s **\n", get_person_name((Person*)passenger));
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
	printf("Данные о пассажире:\n-Имя: %s\n", get_person_name((Person*)passenger));
	printf("-Баланс: %d\n-Способ оплаты: ", get_person_balance((Person*)passenger));
	if (passenger->_private->payment_method)
		printf("Банковская карта\n\n");
	else
		printf("Наличные\n\n");
}

void take_payment(Passenger* passenger, int payment) {
	int old_balance = get_person_balance((Person*)passenger);
	set_person_balance((Person*)passenger, old_balance - payment);
}

/* -------------------------------- Водитель ------------------------------------ */

void driver_constructor(Driver* driver, Person* person);
void driver_destructor(Driver* driver);
Driver* driver_new(Person* person);
void driver_delete(Driver* driver);
void set_driver_experience(Driver* driver, int experience);
void set_driver_order_amount(Driver* driver, int amount);
int get_driver_experience(Driver* driver);
int get_driver_order_amount(Driver* driver);
void input_driver(Driver* driver);
void output_driver(Driver* driver);
void give_payment(Driver* driver, int payment);

void driver_constructor(Driver* driver, Person* person) {
	driver->person = *person;
	driver->_private = (DriverPrivate*)malloc(sizeof(DriverPrivate));
	driver->_private->experience = 0;
	driver->_private->orderAmount = 0;
}

void driver_destructor(Driver* driver) {
	free(driver->_private);
}

Driver* driver_new(Person* person) {
	Driver* driver = (Driver*)malloc(sizeof(Driver));
	driver_constructor(driver, person);
	return driver;
}

void driver_delete(Driver* driver) {
	driver_destructor(driver);
	free(driver);
}

void set_driver_experience(Driver* driver, int experience) {
	driver->_private->experience = experience;
}

void set_driver_order_amount(Driver* driver, int amount) {
	driver->_private->orderAmount = amount;
}

int get_driver_experience(Driver* driver) {
	return driver->_private->experience;
}

int get_driver_order_amount(Driver* driver) {
	return driver->_private->orderAmount;
}

void input_driver(Driver* driver) {
	int temp = 1;
	printf("** Ввод данных о водителе %s **\n", get_person_name((Person*)driver));
	do {
		printf("Введите количество лет опыта: ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите количество лет опыта: ");
		}
	} while (temp < 0);
	driver->_private->experience = temp;
	do {
		printf("Введите количество выполненных заказов: ");
		while (scanf("%d", &temp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите количество выполненных заказов: ");
		}
	} while (temp < 0);
	driver->_private->orderAmount = temp;
	printf("Данные успешно введены!\n\n");
}

void output_driver(Driver* driver) {
	printf("Данные о водителе:\n-Имя: %s\n", get_person_name((Person*)driver));
	printf("-Баланс: %d\n", get_person_balance((Person*)driver));
	printf("-Количество лет опыта: %d\n", driver->_private->experience);
	printf("-Количество выполненных заказов: %d\n\n", driver->_private->orderAmount);
}

void give_payment(Driver* driver, int payment) {
	int old_balance = get_person_balance((Person*)driver);
	set_person_balance((Person*)driver, old_balance + payment);
}

void increase_order_amount(Driver* driver) {
	int old_amount = get_driver_order_amount(driver);
	set_driver_order_amount(driver, old_amount + 1);
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
		printf("Данные об автомобиле отсутствуют!\n");
	else {
		printf("Данные об автомобиле:\n-Марка: %s\n-Класс: ", car->_private->brand);
		if (car->_private->rate)
			printf("Комфорт\n");
		else
			printf("Эконом\n");
	}
}

/* -------------------------------- Функция заказа ------------------------------------ */

void order(bool rate, bool congestion, Passenger* passenger, Driver* driver, Car* car);

void order(bool rate, bool congestion, Passenger* passenger, Driver* driver, Car* car) {
	printf("ЗАКАЗ\n");
	int payment;
	int status = 0;
	if (rate) payment = 500; // Класс поездки - Комфорт
	else payment = 200; // Класс поездки - Эконом

	if (congestion) payment *= 2; // Если дороги загруженны

	if (get_person_balance((Person*)passenger) < payment)
		printf("На балансе пассажира недостаточно средств! (Сумма поездки: %d)\n", payment);
	else {
		if (get_fuel_capacity((Fuel*)car) == 0)
			printf("У выбранной машины не заполнен топливный бак!\n");
		else {
			if (rate) { // Класс поездки - Комфорт
				if (get_driver_experience(driver) < 10 || get_driver_order_amount(driver) < 30)
					printf("У выбранного водителя недостаточно лет опыта или завершённых заказов для выполнения заказа уровня Комфорт!\n");
				else {
					if (get_car_rate(car) == 0)
						printf("Выбранный автомобиль недостаточно высокого класса для выполнения заказа уровня Комфорт!\n");
					else
						status = 1;
				}
			}
			else  // Класс поездки - Эконом
				status = 1;
		}
	}

	if (status) {
		take_payment(passenger, payment);
		give_payment(driver, payment);
		increase_order_amount(driver);
		empty_fuel((Fuel*)car);

		printf("Заказ выполнен успешно! Информация на момент завершения заказа:\n\nКласс поездки: ");
		if (rate) printf("Комфорт\n");
		else printf("Эконом\n");

		printf("Загруженность дорог: ");
		if (congestion) printf("Есть\n");
		else printf("Нет\n");

		printf("Стоимость поездки: %d\n\n", payment);

		output_passenger(passenger);
		output_driver(driver);
		output_car(car);
	}
	printf("\n");
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char buffer[20];

	printf("ТЕСТЫ:\n");
	printf("---------------------- Человек -----------------------------\n\n");
	Person* person_dynamic_1 = person_new(); // Человек 1 (пассажир)
	Person person_static_1 = *person_dynamic_1;
	Person* person_dynamic_2 = person_new(); // Человек 2 (водитель)
	strcpy(buffer, "Иван");
	set_person_name(&person_static_1, buffer);
	printf("--- Тест set_person_name (установлено значение \"Иван\") и get_person_name: имя - %s\n", get_person_name(person_dynamic_1));
	set_person_balance(person_dynamic_1, 200);
	printf("--- Тест set_person_balance (установлено значение 200) и get_person_balance: баланс = %d\n", get_person_balance(&person_static_1));
	printf("--- Тест input_person (ввести данные о человеке):\n");
	input_person(person_dynamic_2);
	printf("--- Тест output_person (вывести данные о человеке):\n");
	output_person(person_dynamic_2);

	printf("\n---------------------- Пассажир ----------------------------\n\n");
	Passenger* passenger_dynamic = passenger_new(&person_static_1);
	Passenger passenger_static = *passenger_dynamic;
	set_passenger_method(&passenger_static, 1);
	printf("--- Тест set_passenger_method (установлено значение 1 - Банковская карта) и get_passenger_method: способ оплаты - %d\n", get_passenger_method(passenger_dynamic));
	printf("--- Тест input_passenger (ввести данные о пассажире):\n");
	input_passenger(passenger_dynamic);
	printf("--- Тест output_passenger (вывести данные о пассажире):\n");
	output_passenger(&passenger_static);

	printf("---------------------- Водитель ----------------------------\n\n");
	Driver* driver_dynamic = driver_new(person_dynamic_2);
	Driver driver_static = *driver_dynamic;
	set_driver_experience(&driver_static, 5);
	printf("--- Тест set_driver_experience (установлено значение 5) и get_driver_experience: опыт вождения (лет) = %d\n", get_driver_experience(&driver_static));
	set_driver_order_amount(driver_dynamic, 15);
	printf("--- Тест set_driver_order_amount (установлено значение 15) и get_driver_order_amount: кол-во выполненных заказов = %d\n", get_driver_order_amount(driver_dynamic));
	printf("--- Тест input_driver (ввести данные о водителе):\n");
	input_driver(driver_dynamic);
	printf("--- Тест output_driver (вывести данные о водителе):\n");
	output_driver(&driver_static);

	printf("\n---------------------- Топливный бак -----------------------\n\n");
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
	printf("--- Тест fill_fuel (заполнить бак): заполненность = %d\n\n", get_fuel_capacity(fuel_dynamic));

	printf("---------------------- Автомобиль --------------------------\n\n");
	Car car_static;
	Car* car_dynamic = car_new();
	car_static = *car_dynamic;
	strcpy(buffer, "Toyota");
	set_car_brand(car_dynamic, buffer);
	printf("--- Тест set_car_brand (установлено значение \"Toyota\") и get_car_brand: марка - %s\n", get_car_brand(car_dynamic));
	set_car_rate(car_dynamic, 0);
	printf("--- Тест set_car_rate (установлено значение 0 - Эконом) и get_car_rate: класс автомобиля - %d\n", get_car_rate(car_dynamic));
	printf("--- Тест input_car_brand (ввести марку):\n");
	input_car_brand(car_dynamic);
	printf("--- Тест input_car_rate (ввести класс автомобиля):\n");
	input_car_rate(car_dynamic);
	printf("--- Тест output_car (вывести данные об автомобиле):\n");
	output_car(&car_static);
	fill_fuel((Fuel*)car_dynamic);
	printf("--- Тест fill_fuel (заполнить бак, через дочерний объект Car): заполненность = %d\n", get_fuel_capacity((Fuel*)car_dynamic));

	printf("---------------------- Заказ -------------------------------\n");
	int rate = 0; // Класс поездки - Эконом
	int congestion = 0; // Загруженность дорог - нет

	printf("--- Тест 1 (Эконом): заказ успешно выполняется\n");
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 2 (Эконом): на балансе пассажира недостаточно средств\n");
	set_person_balance((Person*)passenger_dynamic, 100);
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 3 (Эконом): топливный бак автомобиля не заполнен\n");
	set_person_balance((Person*)passenger_dynamic, 300);
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 4 (Комфорт): у водителя недостаточно лет опыта вождения\n");
	rate = 1;
	congestion = 1;
	fill_fuel((Fuel*)car_dynamic);
	set_person_balance((Person*)passenger_dynamic, 1500);
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 5 (Комфорт): у водителя недостаточно выполненных заказов\n");
	set_driver_experience(driver_dynamic, 17);
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 6 (Комфорт): автомобиль недостаточно высокого класса\n");
	set_driver_order_amount(driver_dynamic, 50);
	order(rate, congestion, passenger_dynamic, &driver_static, car_dynamic);

	printf("--- Тест 7 (Комфорт): заказ успешно выполняется\n");
	strcpy(buffer, "Volvo");
	set_car_brand(car_dynamic, buffer);
	set_car_rate(car_dynamic, 1);
	order(rate, congestion, passenger_dynamic, driver_dynamic, car_dynamic);

	passenger_delete(passenger_dynamic);
	person_delete(person_dynamic_1);
	driver_delete(driver_dynamic);
	person_delete(person_dynamic_2);
	fuel_delete(fuel_dynamic);
	car_delete(car_dynamic);

	return 0;
}