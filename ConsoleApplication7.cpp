#include "stdafx.h"
#include <iostream>  

class smart_array {
private:
	int* data;
	size_t size;
	size_t capacity;

public:
	smart_array(size_t capacity) : capacity(capacity), size(0) {
		data = new int[capacity];
	}

	~smart_array() {
		delete data;
	}

	void add_element(int value) {
		if (size >= capacity) {
			std::cout << "Ошибка: превышен максимальный размер массива" << std::endl;
			return;
		}
		data[size++] = value;
	}

	int get_element(size_t index) const {
		if (index >= size || index < 0) {
			std::cout << "Ошибка: неверный индекс" << std::endl;
			return -1;
		}
		return data[index];
	}

	void print() const {
		for (size_t i = 0; i < size; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
	smart_array& operator=(const smart_array& other) {
		if (this != &other) { 
			delete data;
			size = other.size;
			data = new int[size];
			for (size_t i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
};

int main() {
	setlocale(LC_ALL, "russian");
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		std::cout << "Первый массив: " << std::endl;
		arr.print();
		std::cout << std::endl;

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34); 
		std::cout << "Второй массив: " << std::endl;
		arr.print();
		std::cout << std::endl;

		arr = new_array;
		std::cout << "Массив после присваивания: " << std::endl;
		arr.print();
		std::cout << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
