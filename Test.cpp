#include "Test.h"
#include "Points_array.h"
#include "Interface.h"
#include <string>

bool Test1(Point& center, Points_class& point_arr, res_points_class& res_point_arr, res_points_class& expected_res_point_arr) {
	int quantity = 0, radius = 0;
	quantity = 5;
	point_arr.set_size(quantity);
	res_point_arr.set_size(quantity);
	expected_res_point_arr.set_size(quantity);
	point_arr[0].x = 0;
	point_arr[0].y = 0;
	point_arr[0].z = 0;
	point_arr[1].x = 1;
	point_arr[1].y = 1;
	point_arr[1].z = 1;
	point_arr[2].x = 2;
	point_arr[2].y = 2;
	point_arr[2].z = 2;
	point_arr[3].x = 3;
	point_arr[3].y = 3;
	point_arr[3].z = 3;
	point_arr[4].x = 1.5;
	point_arr[4].y = 0;
	point_arr[4].z = 0;
	radius = 3;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	expected_res_point_arr[0] = 1;
	expected_res_point_arr[1] = 1;
	expected_res_point_arr[2] = 0;
	expected_res_point_arr[3] = 0;
	expected_res_point_arr[4] = 1;
	int check = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	check_inclusion(point_arr, radius, center, res_point_arr);
	for (int i = 0; i < res_point_arr.get_size(); i++) {
		if (expected_res_point_arr[i] == res_point_arr[i])
			check++;
	}
	if (check == res_point_arr.get_size()) {
		return true;
	}
	else {
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "Тест 1 не пройден!" << endl;
		output_arr(point_arr, radius, center);
		string expected_result, result;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < res_point_arr.get_size(); i++) {
			if (expected_res_point_arr[i] == 1) expected_result = " попадает.";
			else expected_result = " не попадает.";
			cout << "Ожидалось, что точка " << i + 1 << expected_result << endl;
			if (res_point_arr[i] == 1) result = " попадает.";
			else result = " не попадает.";
			cout << "По прохождению теста точка " << i + 1 << result << endl;
		}
		return false;
	}
}

bool Test2(Point& center, Points_class& point_arr, res_points_class& res_point_arr, res_points_class& expected_res_point_arr) {
	int quantity = 5, radius = 0;
	point_arr.set_size(quantity);
	res_point_arr.set_size(quantity);
	expected_res_point_arr.set_size(quantity);
	point_arr[0].x = 0;
	point_arr[0].y = 0;
	point_arr[0].z = 0;
	point_arr[1].x = 1;
	point_arr[1].y = 1;
	point_arr[1].z = 1;
	point_arr[2].x = 2;
	point_arr[2].y = 2;
	point_arr[2].z = 2;
	point_arr[3].x = 3;
	point_arr[3].y = 3;
	point_arr[3].z = 3;
	point_arr[4].x = 1.5;
	point_arr[4].y = 0;
	point_arr[4].z = 0;
	radius = 4;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	expected_res_point_arr[0] = 1;
	expected_res_point_arr[1] = 1;
	expected_res_point_arr[2] = 1;
	expected_res_point_arr[3] = 0;
	expected_res_point_arr[4] = 1;
	int check = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	check_inclusion(point_arr, radius, center, res_point_arr);
	for (int i = 0; i < res_point_arr.get_size(); i++) {
		if (expected_res_point_arr[i] == res_point_arr[i])
			check++;
	}
	if (check == res_point_arr.get_size()) {
		return true;
	}
	else {
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "Тест 2 не пройден!" << endl;
		output_arr(point_arr, radius, center);
		string expected_result, result;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < res_point_arr.get_size(); i++) {
			if (expected_res_point_arr[i] == 1) expected_result = " попадает.";
			else expected_result = " не попадает.";
			cout << "Ожидалось, что точка " << i + 1 << expected_result << endl;
			if (res_point_arr[i] == 1) result = " попадает.";
			else result = " не попадает.";
			cout << "По прохождению теста точка " << i + 1 << result << endl;
		}
		return false;
	}
}

bool Test3(Point& center, Points_class& point_arr, res_points_class& res_point_arr, res_points_class& expected_res_point_arr) {
	int quantity = 3, radius = 2;
	point_arr.set_size(quantity);
	res_point_arr.set_size(quantity);
	expected_res_point_arr.set_size(quantity);
	point_arr[0].x = 0;
	point_arr[0].y = 0;
	point_arr[0].z = 0;
	point_arr[1].x = -1;
	point_arr[1].y = -1;
	point_arr[1].z = -1;
	point_arr[2].x = 2;
	point_arr[2].y = 2;
	point_arr[2].z = 2;
	center.x = 1;
	center.y = 1;
	center.z = 1;
	expected_res_point_arr[0] = 1;
	expected_res_point_arr[1] = 0;
	expected_res_point_arr[2] = 1;
	int check = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	check_inclusion(point_arr, radius, center, res_point_arr);
	for (int i = 0; i < res_point_arr.get_size(); i++) {
		if (expected_res_point_arr[i] == res_point_arr[i])
			check++;
	}
	if (check == res_point_arr.get_size()) {
		return true;
	}
	else {
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "Тест 3 не пройден!" << endl;
		output_arr(point_arr, radius, center);
		string expected_result, result;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < res_point_arr.get_size(); i++) {
			if (expected_res_point_arr[i] == 1) expected_result = " попадает.";
			else expected_result = " не попадает.";
			cout << "Ожидалось, что точка " << i + 1 << expected_result << endl;
			if (res_point_arr[i] == 1) result = " попадает.";
			else result = " не попадает.";
			cout << "По прохождению теста точка " << i + 1 << result << endl;
		}
		return false;
	}
}

bool Test4(Point& center, Points_class& point_arr, res_points_class& res_point_arr, res_points_class& expected_res_point_arr) {
	int quantity = 3, radius = 2;
	point_arr.set_size(quantity);
	res_point_arr.set_size(quantity);
	expected_res_point_arr.set_size(quantity);
	point_arr[0].x = 0;
	point_arr[0].y = 0;
	point_arr[0].z = 0;
	point_arr[1].x = -1;
	point_arr[1].y = -1;
	point_arr[1].z = -1;
	point_arr[2].x = 2;
	point_arr[2].y = 2;
	point_arr[2].z = 2;
	center.x = 100;
	center.y = 100;
	center.z = 100;
	expected_res_point_arr[0] = 0;
	expected_res_point_arr[1] = 0;
	expected_res_point_arr[2] = 0;
	int check = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	check_inclusion(point_arr, radius, center, res_point_arr);
	for (int i = 0; i < res_point_arr.get_size(); i++) {
		if (expected_res_point_arr[i] == res_point_arr[i])
			check++;
	}
	if (check == res_point_arr.get_size()) {
		return true;
	}
	else {
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "Тест 4 не пройден!" << endl;
		output_arr(point_arr, radius, center);
		string expected_result, result;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < res_point_arr.get_size(); i++) {
			if (expected_res_point_arr[i] == 1) expected_result = " попадает.";
			else expected_result = " не попадает.";
			cout << "Ожидалось, что точка " << i + 1 << expected_result << endl;
			if (res_point_arr[i] == 1) result = " попадает.";
			else result = " не попадает.";
			cout << "По прохождению теста точка " << i + 1 << result << endl;
		}
		return false;
	}
}

void run_tests(void) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point center;
	Points_class point_arr;
	res_points_class res_point_arr, expected_res_point_arr;
	if (Test1(center, point_arr, res_point_arr, expected_res_point_arr) && 
		Test2(center, point_arr, res_point_arr, expected_res_point_arr) && 
		Test3(center, point_arr, res_point_arr, expected_res_point_arr) && 
		Test4(center, point_arr, res_point_arr, expected_res_point_arr)) {
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
		cout << "Все тесты пройдены!" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
}
