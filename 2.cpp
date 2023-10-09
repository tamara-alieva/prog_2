#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool nameCheck(string name) {
	int i = 0; bool f = 1;
	for (i = 0; i < name.length(); i++) {
		if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'А' && name[i] <= 'Я') || (name[i] >= 'а' && name[i] <= 'я')) f = 1;
		else {
			f = 0;
			break;
		}
	}
	return f;
}

bool intCheck(string balance) {
	int i = 0; bool f = 1;
	for (i = 0; i < balance.length(); i++) {
		if (balance[i] >= '0' && balance[i] <= '9') f = 1;
		else {
			f = 0;
			break;
		}
	}
	return f;
}

class Person {
private:
	string name;
	int balance;
public:
	Person() {
		this->name = "";
		this->balance = 0;
	}
	Person(string name) {
		this->name = name;
		this->balance = 0;
	}
	Person(int balance) {
		this->name = "";
		this->balance = balance;
	}
	Person(string name, int balance) {
		this->name = name;
		this->balance = balance;
	}
	void setName(string name) {
		this->name = name;
	}
	void setBalance(int balance) {
		this->balance = balance;
	}
	string getName() {
		return this->name;
	}
	int getBalance() {
		return this->balance;
	}
	void input() {
		string temp;
		cout << "** Ввод данных человека **" << endl;
		do {
			cout << "Введите имя: ";
			cin >> this->name;
		} while (this->name.empty() || nameCheck(this->name) == 0);
		do {
			cout << "Введите баланс: ";
			cin >> temp;
		} while (temp.empty() || intCheck(temp) == 0);
		this->balance = stoi(temp);
		cout << "Данные успешно введены!" << endl << endl;
	}
	void output() {
		if (this->name.empty())
			cout << "Данные о человеке отсутствуют!" << endl;
		else
			cout << "Данные о человеке:" << endl << "-Имя: " << this->name << endl << "-Баланс: " << this->balance << endl;
	}
};

class Passenger : public Person {
private:
	bool payment_method;
public:
	Passenger() : Person() {
		this->payment_method = 0;
	}
	Passenger(string name) : Person(name) {
		this->payment_method = 0;
	}
	Passenger(int balance) : Person(balance) {
		this->payment_method = 0;
	}
	Passenger(string name, int balance, bool method) : Person(name, balance) {
		this->payment_method = method;
	}
	void setMethod(bool method) {
		this->payment_method = method;
	}
	bool getMethod() {
		return this->payment_method;
	}
	void input() {
		string temp;
		cout << "** Ввод данных о пассажире %s **" << this->getName() << endl;
		do {
			cout << "Введите способ оплаты (0 - Наличные, 1 - Банковская карта): ";
			cin >> temp;
		} while (temp != "0" && temp != "1");
		this->payment_method = stoi(temp);
		cout << "Данные успешно введены!" << endl << endl;
	}
	void output() {
		cout << "Данные о пассажире:" << endl << "-Имя: " << this->getName() << endl;
		cout << "-Баланс: " << this->getBalance() << endl << "-Способ оплаты: ";
		if (this->getMethod())
			cout << "Банковская карта" << endl << endl;
		else
			cout << "Наличные" << endl << endl;
	}
	void takePayment(int payment) {
		int old_balance = this->getBalance();
		this->setBalance(old_balance - payment);
	}
};

class Driver : public Person {
private:
	int experience, orderAmount;
public:
	Driver() : Person() {
		this->experience = 0;
		this->orderAmount = 0;
	}
	Driver(string name) : Person(name) {
		this->experience = 0;
		this->orderAmount = 0;
	}
	Driver(int balance) : Person(balance) {
		this->experience = 0;
		this->orderAmount = 0;
	}
	Driver(string name, int balance, int experience, int orderAmount) : Person(name, balance) {
		this->experience = experience;
		this->orderAmount = orderAmount;
	}
	void setExperience(int experience) {
		this->experience = experience;
	}
	void setOrderAmount(int orderAmount) {
		this->orderAmount = orderAmount;
	}
	int getExperience() {
		return this->experience;
	}
	int getOrderAmount() {
		return this->orderAmount;
	}
	void input() {
		string temp;
		cout << "** Ввод данных водителя **" << this->getName() << endl;
		do {
			cout << "Введите количество лет опыта: ";
			cin >> temp;
		} while (temp.empty() || intCheck(temp) == 0);
		this->experience = stoi(temp);
		do {
			cout << "Введите количество выполненных заказов: ";
			cin >> temp;
		} while (temp.empty() || intCheck(temp) == 0);
		this->orderAmount = stoi(temp);
		cout << "Данные успешно введены!" << endl << endl;
	}
	void output() {
		cout << "Данные о водителе:" << endl << "-Имя: " << this->getName() << endl;
		cout << "-Баланс: " << this->getBalance() << endl;
		cout << "-Количество лет опыта: " << this->getExperience() << endl;
		cout << "-Количество выполненных заказов: " << this->getOrderAmount() << endl << endl;
	}
	void givePayment(int payment) {
		int old_balance = this->getBalance();
		this->setBalance(old_balance + payment);
	}
	void increaseOrderAmount() {
		int old_amount = this->getOrderAmount();
		this->setOrderAmount(old_amount + 1);
	}
};