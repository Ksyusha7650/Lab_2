#pragma once
#include "Points_array.h"
#include "Main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>
#include <Windows.h>

class res_points_class;
class Points_class;
struct Point;

class output_file_points {
private:
	double* file_arr_point;
	int file_arr_size;

public:
	double& operator[] (const int index) {
		return file_arr_point[index];
	}
	int get_size() {
		return file_arr_size;
	}
	void set_size(int size) {
		file_arr_size = size;
		file_arr_point = new double[file_arr_size];
	}

	~output_file_points() {
		delete[] file_arr_point;
	}
};

enum Actions {
	END, CONTINUE,
	MANUAL = 1, GENERATE, FILE_INPUT,
	YES = 1, NO,
	QUANTITY_COORDINATES, SIZE_BYTE = 1,
	NOT_FALL = 0, FALL, 
	DATA, RESULT, READ_POINTS,
	TEST = 1, TRY,
	REWRITE = 0, REPEAT,
	CENTER_POINT = -1
};

int get_int();
double get_double();
void greetings();
Point get_point();
void input_types(Points_class& arr_point, res_points_class& res_arr_point, int& size, int& mode, int& radius, Point& center);
bool show_or_try();
bool end_program();
void size_arr(int& size, Points_class& point_arr, res_points_class& res_point_arr);
void output_point(Point point);
void output_arr(Points_class& point_arr, int radius, Point center);
void res_output_arr(Points_class& point_arr, res_points_class& res_point_arr, HANDLE handle);
void create_file(int mode, Points_class&  arr_point, res_points_class& res_arr_point, int& size, int& radius, Point& center);
void saving_results(Points_class& point_arr, res_points_class& res_point_arr);
void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t, int size);