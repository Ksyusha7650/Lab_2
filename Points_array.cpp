#include "Points_array.h"

using namespace std;


void check(Point point, int radius, Point center, res_points_class& res_arr, const int index) {
	if ((pow((point.x - center.x), 2) + pow((point.y - center.y), 2) + pow((point.z - center.z), 2)) <= pow(radius, 2))
		res_arr[index] = 1;
	else res_arr[index] = 0;
	
}

void check_inclusion(Points_class& point_arr, int radius, Point center, res_points_class& res_arr) {
	for (int i = 0; i < point_arr.get_size(); i++) {
		check(point_arr[i], radius, center, res_arr, i);
	}
}

	
