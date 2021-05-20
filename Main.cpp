#include "Main.h"

int main()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	setlocale(LC_ALL, "Russian");
	greetings();
	bool end = false;
	Points_class point_arr;
	res_points_class res_point_arr;
	int size = 0, mode = 0, radius = 0;
	Point center;
	srand((unsigned)time(NULL));
	do {
	
		if (show_or_try()) run_tests();
		else {
			input_types(point_arr, res_point_arr, size, mode, radius, center);
			output_arr(point_arr, radius, center);
			if (mode != Actions::FILE_INPUT)
			save_data(point_arr, radius, center, res_point_arr, size);
			check_inclusion(point_arr, radius, center, res_point_arr);
			res_output_arr(point_arr, res_point_arr, handle);
			saving_results(point_arr, res_point_arr);
		}
		end = end_program();
	} while (end != true);
}

