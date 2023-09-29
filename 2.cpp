#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct Passenger {
	int balance;
};

struct Car {
	bool rate;
	Fuel fuel;
};

struct Fuel {
	bool capacity;
};

struct Driver {
	Car car;
	int experience, orderAmount, balance;
};

struct Order {
	bool rate, congestion;
	Driver driver;
	Passenger passenger;
	int payment;
};