#pragma once
#include "Interface.h"


struct Point
{
	double x, y, z;
};

class Points_class {
private:
	Point* arr_point;
	int arr_size;

public:
	Point& operator[] (const int index) { 
		return arr_point[index];
	}
	int get_size() {
		return arr_size;
	}
	void set_size(int size) {
		arr_size = size;
		arr_point = new Point[arr_size];
	}


	~Points_class() {
		delete[] arr_point;
	}
};

class res_points_class {
private:
	bool* res_arr_point;
	int res_arr_size;

public:
    bool& operator[] (const int index) {
		return res_arr_point[index];
	}
	int get_size() {
		return res_arr_size;
	}
	void set_size(int size) {
		res_arr_size = size;
		res_arr_point = new bool[res_arr_size];
	}

	~res_points_class() {
		delete[] res_arr_point;
	}
};

void check(Point point, int radius, Point center, res_points_class& res_arr, const int index);
void check_inclusion(Points_class& point_arr, int radius, Point center, res_points_class& res_arr);