﻿#pragma once

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

bool balanceCheck(string balance) {
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
		} while (temp.empty() || balanceCheck(temp) == 0);
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