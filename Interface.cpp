#include "Interface.h"

using namespace std;
using namespace filesystem;


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

int get_int() {
	int input = 0;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

Point get_point(const int index) {
	Point point;
	string name_point;
	if (index == -1) name_point = "������ �����";
	else name_point = to_string(index + 1);
	cout << "������� ���������� " << name_point << " ����� �� x: ";
	point.x = get_double();
	cout << "������� ���������� " << name_point << " ����� �� y: ";
	point.y = get_double();
	cout << "������� ���������� " << name_point << " ����� �� z: ";
	point.z = get_double();
	cout << "---------------------------------" << endl;
	return point;
}

void size_arr(int& size, Points_class& point_arr, res_points_class& res_point_arr) {
	int radius_t = 0;
	Point center_t;
	cout << "������� 1 ��� ������ ���������� ����� �� �����. 2 - ��� ������� ����� �������." << endl;
	while (true) {
		int type = get_int();
		if (type == 1) {
			create_file(READ_SIZE, point_arr, res_point_arr, size, radius_t, center_t);
			break;
		}
		else if (type == 2) {
			cout << "������� ���������� �����." << endl;
			while (true) {
				size = get_int();
				if (size <= 0) {
					cout << "������ ������� �� ����� ���� �������������." << endl;
				}
				else break;
			}
			break;
		}
		else {
         cout << "������� ���� 1, ���� 2." << endl;
		}

	}
	point_arr.set_size(size);
	res_point_arr.set_size(size);
}

void user_input(Points_class& arr_point, int& radius, Point& center) {
	for (int index = 0; index < arr_point.get_size(); index++) {
		Point new_point = get_point(index);
		arr_point[index] = new_point;
	}
	cout << "������� ������ �����: ";
	while (true) {
		radius = get_int();
		if (radius <= 0) {
			cout << "������ �� ����� ���� �������������." << endl;
		}
		else break;
	}
	cout << "---------------------------------" << endl;
	center = get_point(-1);
}

void generation_input(Points_class& arr_point, int& radius, Point& center) {
	const int MIN_POINT = -50;
	const int MAX_POINT = 100;
	const int MIN_RADIUS = 20;
	const int MAX_RADIUS = 100;

	for (int index = 0; index < arr_point.get_size(); index++) {
		arr_point[index].x = ((double)(rand() % MAX_POINT) + MIN_POINT);
		arr_point[index].y = ((double)(rand() % MAX_POINT) + MIN_POINT);
		arr_point[index].z = ((double)(rand() % MAX_POINT) + MIN_POINT);
	}
	radius = ((double)(rand() % MAX_RADIUS) + MIN_RADIUS);
	center.x = ((double)(rand() % MAX_POINT) + MIN_POINT);
	center.y = ((double)(rand() % MAX_POINT) + MIN_POINT);
	center.z = ((double)(rand() % MAX_POINT) + MIN_POINT);
}

void output_point(Point point, const int index) {
	cout << "����� " << index << " � ������������: " << point.x << " ; " << point.y << " ; " << point.z;
}

void output_arr(Points_class& point_arr, int radius, Point center) {
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "�������� ������: " << endl;
	cout << "�������� ������ � ������������ �����." << endl;
	for (int index = 0; index < point_arr.get_size(); index++) {
		output_point(point_arr[index], index+1);
		cout << endl;
	}
	cout << "������ �����: " << radius << endl;
	cout << "����� �����: " << center.x << " ; " << center.y << " ; " << center.z << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

void res_output_arr(Points_class& point_arr, res_points_class& res_point_arr, HANDLE handle) {
	cout << "������������ ������ � ������������ �����." << endl;
	for (int index = 0; index < res_point_arr.get_size(); index++) {
		if (res_point_arr[index] == 1) {
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			output_point(point_arr[index], index+1);
			cout << " - ��������." << endl;
		}
		else {
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			output_point(point_arr[index], index+1);
			cout << " - �� ��������." << endl;
		}
	}
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

bool show_or_try(void) {
	cout << "��� ����, ����� �������� ����� ������� 1." << endl;
	cout << "��� ����, ����� �������������� ��������� ������� 2." << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "������� ���� 1, ���� 2." << endl;
		}
	}
}

void create_file(int mode, Points_class& point_arr, res_points_class& res_point_arr, int& size, int& radius, Point& center) {
	if (mode == READ_SIZE) {
	here: cout << "������� ���� �����, �� �������� ������� ������." << endl
		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
		<< endl;
		  const int SIZE_NAME = 256;
		  string name = "";
		  cin >> name;
		  fstream output_file(name);
		  int AMOUNT_DATA = 1;
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  if (!(output_file >> size)) {
				  cout << "������������ ������." << endl;
				  output_file.close();
				  goto here;
				  break;
			  }
		  }
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  output_file >> size;
		  }
		  cout <<"�������� ���������� �����: " << size << endl;
		  output_file.close();
	}
	else if (mode == READ_POINTS) {
	here_2: cout << "������� ���� �����, �� �������� ������� ������." << endl
		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
		<< endl;
		  const int SIZE_NAME = 256;
		  string name = "";
		  cin >> name;
		  fstream output_file(name);
		  output_file_points file_points;
		  int AMOUNT_DATA = 3*(size + 1) + 1;
		  file_points.set_size(AMOUNT_DATA);
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  if (!(output_file >> file_points[index])) {
				  cout << "������������ ������." << endl;
				  output_file.close();
				  goto here_2;
				  break;
			  }
		  }
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  output_file >> file_points[index];
		  }
		  int j = 0;
		  for (int index = 0; index < size; index++) {
			point_arr[index].x = file_points[j];
			point_arr[index].y = file_points[j + 1];
			point_arr[index].z = file_points[j + 2];
			j += 3;
		  }
		  radius = file_points[size*3];
		  center.x = file_points[AMOUNT_DATA - 3];
		  center.y = file_points[AMOUNT_DATA - 2];
		  center.z = file_points[AMOUNT_DATA - 1];
		  output_file.close();
	}
	else {
	path:cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
		"�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl << "���� ������� ������ �������� �����, ����� �� ����� � ����� ����� �������."
		<< endl;
		 const int SIZE_NAME = 256;
		 string name = "";
		 cin >> name;
		 if (ifstream(name)) {
			 bool rewrite = true;
			 cout << "���� ��� ����������." << endl;
			 cout << "������� 0 ��� ����, ����� ������������ ������������ ����." << endl;
			 cout << "������� 1 ��� ����, ����� ��������� ����." << endl;
		 repeat: rewrite = get_int();
			 switch (rewrite) {
			 case 0: cout << "�� ������� ����� ������������ ����." << endl;
				 break;
			 case 1: cout << "�� ������� ����� ��������� ����." << endl;
				 goto path;
				 break;
			 default:
				 cout << "������� 1, ���� 2";
				 goto repeat;
			 }
		 }
		 ofstream result_file(name, ofstream::app);
		 error_code ec;
		 if (!is_regular_file(name, ec)) {
			 cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			 ec.clear();
			 goto path;
		 }
		 result_file.clear();
		 switch (mode) {
		 case DATA:
			 result_file << size << " ";
			 for (int index = 0; index <= size; index++) {
				 result_file << point_arr[index].x << " " << point_arr[index].y << " " << point_arr[index].z << " ";
				 if (index == size)  result_file << radius << " "<< center.x << " " << center.y << " " << center.z << " ";
			 }
			 break;
		 case RESULT:
			 result_file
				 << "��������� ���������. " << endl
			  << "������������ ������ � ������������ �����:" << endl;
			 for (int index = 0; index < res_point_arr.get_size(); index++) {
				 if (res_point_arr[index] == 1) {
					 result_file << "�����" << index << "� ������������: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
					  << " - ��������." << endl;
				 }
				 else {
					 result_file << "�����" << index << " � ������������: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
					 << " - �� ��������." << endl;
				 }
			 }
			 cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

			 break;
		 }
		 result_file.close();
	}
}

void greetings() {
	cout << "��������� ��������� ������� ������ ����������." << endl << "������: 404." << endl << "�������: 22." << endl <<
		"������ ����� 2:" << endl <<
		"� ���������� ������������ ����� ������ ����� (�������� �������� X, Y, Z) � �����(����� � ������). " << endl 
		<< "�������� ���������, ��������� ����� (�� ����������), ������� �������� � �������� ������������� �����."
		<< endl;
}

void input_types(Points_class& arr_point, res_points_class& res_arr_point, int size, int& mode, int& radius, Point& center) {
	cout << "�������� ������ ���������� ������� �����:" << endl << "������� 1 ��� ����� �������." << endl
		<< "������� 2 ��� ��������� ��������� ���������." << endl << "������� 3 ��� ������������� �������� ������ �� �����." << endl;
again: int menu_type = get_int();
	mode = menu_type;
	switch (menu_type) {
	case MANUAL:
		cout << "�� ������� ����� ����� �������." << endl;
		cout << endl;
		user_input(arr_point, radius, center);
		break;
	case GENERATE:
		cout << "�� ������� ����� ���������." << endl;
		generation_input(arr_point, radius, center);
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		break;
	case FILE_INPUT:
		cout << "�� ������� ����� ����� ������ �� �����." << endl;
		create_file(READ_POINTS, arr_point, res_arr_point, size, radius, center);
		break;
	default:
		cout << "������� ���� 1, ���� 2, ���� 3." << endl;
		goto again;
	}
}

bool end_program() {
	cout << "��������� ���������? " << endl << "������� 0 ��� ����������." << endl << "������� 1 ��� �������." << endl;
again: int end = get_int();
	switch (end) {
	case END:
		cout << "��������� �����������..." << endl;
		break;
	case CONTINUE:
		cout << "�� ������� ��������� ���������: " << endl;
		break;
	default:
		cout << "������� ���� 0, ���� 1." << endl;
		goto again;
	}
	return !(end);
}


void saving_results(Points_class& point_arr, res_points_class& res_point_arr) {
	cout << "����a���� ���������� � ��������� �����?" << endl << "������� 1 ��� ����������." << endl << "������� 2, ����� ���������� ����������." << endl;
	int size_t = 0, radius_t = 0;
	Point center_t;
	while (true) {
	 int save = get_int();
	 if (save == YES) {
		 create_file(RESULT, point_arr, res_point_arr, size_t, radius_t, center_t);
		 break;
	 }
	 else if (save == NO) {
		 cout << "�� ������� ���������� ����������." << endl;
		 break;
	 }
	 else cout << "������� ���� 1, ���� 2." << endl;

	}
}

void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t) {
	int size_t = 0;
	cout << "�� ������ ��������� ������? ������� 1 - ��� ����������, 2 - ��� �������� ����������." << endl;
	while (true) {
	 int save = get_int();
	 if (save == YES) {
		 create_file(DATA, point_arr, res_t, size_t, radius, center);
		 cout << "������ ���������." << endl;
		 break;
	 }
	 else if (save == NO) {
		 cout << "�� ������� ���������� ����������." << endl;
		 break;
	 }
	 else cout << "������� ���� 1, ���� 2." << endl;
	}
}
