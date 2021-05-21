#include <math.h>
#include "Points_array.h"

void check(Point point, int radius, Point center, res_points_class& res_arr, const int index) {
	if ((pow((point.x - center.x), 2) + pow((point.y - center.y), 2) + pow((point.z - center.z), 2)) <= pow(radius, 2))
		res_arr[index] = FALL;
	else res_arr[index] = NOT_FALL;
	
}

void check_inclusion(Points_class& point_arr, int radius, Point center, res_points_class& res_arr) {
	for (int index = 0; index < point_arr.get_size(); index++) {
		check(point_arr[index], radius, center, res_arr, index);
	}
}

	
