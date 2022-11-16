#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

// Задание 3. Площадь треугольника.
struct triangle {
	double a = 0;
	double b = 0;
	double c = 0;
};

double sqr_tri(triangle& T);

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);

template <typename T>
void show_arr(T arr[], const int length);

// Добавление нового элемента в конец массива.
template <typename T>
void append(T*& arr, int length, T val) {
	T* tmp = new T[length + 1];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	tmp[length] = val;
	arr = tmp;
}

// Задача 1. Выделение памяти.
template <typename T>
void memory(T*& ptr, int length);

// Задание 2. объединение массива и определение длины.
template <typename T>
T* pos_arr_concat(T arr1[], T arr2[], const int length1, const int length2, int& var);




int main() {
	setlocale(LC_ALL, "Russian");
	int x;

	// Задача 1. Выделение памяти.
	/*
	std::cout << "\t\tЗадание 1.\n Выделение памяти.\n Введите кол-во элементов массива --> ";
	std::cin >> x;
	int* pArr1 = nullptr;

	try {
		memory(pArr1, x);
		fill_arr(pArr1, x, 1, 101);
		std::cout << " Итоговый массив --> ";
		show_arr(pArr1, x);
		std::cout << "\n\n";
		delete[] pArr1;
	}
	catch(const std::out_of_range& ex) {
		std::cout << " Ошибка: " << ex.what() << "\n\n";
	}
	*/

	// Задание 2. объединение массива и определение длины.
	/*
	std::cout << "\t\tЗадание 2.\n Объединение массива и определение длины.\n Массив 1 --> ";
	const int size1 = 7;
	const int size2 = 5;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, -15, 16);
	fill_arr(arr2, size2, -10, 11);
	show_arr(arr1, size1);
	std::cout << " Массив 2 --> ";
	show_arr(arr2, size2);

	int* result_arr = pos_arr_concat(arr1, arr2, size1, size2, x);
	std::cout << " Итоговый массив --> ";
	show_arr(result_arr, x);
	std::cout << "\n\n";
	delete[] result_arr;
	*/

	// Задание 3. Площадь треугольника.
	std::cout << "\t\tЗадание 3.\n Площадь треугольника.\n Стороны треугольника --> ";
	triangle ABC{ 4,6,8};
	std::cout << ABC.a << ", " << ABC.b << ", " << ABC.c << ".\n";
	std::cout << " Площадь треугольника --> " << sqr_tri(ABC) << "\n\n";



	return 0;
}

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}


// Задача 1. Выделение памяти. 
template <typename T>
void memory(T*& ptr, int length) {
	if (length <= 0)
		throw std::out_of_range("длина массива не может быть отрицательной или равной нулю");
	ptr = new T[length];
}

// Задание 2. объединение массива и определение длины.
template <typename T>
T* pos_arr_concat(T arr1[], T arr2[], const int length1, const int length2, int& var) {
	T* tmp_arr = new T[0];
	int tmp_size = 0;
	for (int i = 0; i < length1; i++)
		if (arr1[i] > 0) {
			append(tmp_arr, tmp_size, arr1[i]);
			tmp_size++;
		}
	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0) {
			append(tmp_arr, tmp_size, arr2[i]);
			tmp_size++;
		}
	var = tmp_size;
	return tmp_arr;
}

// Задание 3. Площадь треугольника.
double sqr_tri(triangle& T) {
	double half_P = (T.a + T.b + T.c) / 2.0;
	double S = sqrt(half_P * (half_P - T.a) * (half_P - T.b) * (half_P - T.c));
	return S;
}