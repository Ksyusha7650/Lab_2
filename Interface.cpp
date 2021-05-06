#include "Interface.h"

using namespace std;
using namespace filesystem;


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "Введите число." << endl;
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
		cout << "Введите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

Point get_point(const int index) {
	Point point;
	string name_point;
	if (index == -1) name_point = "центра сферы";
	else name_point = to_string(index + 1);
	cout << "Введите координату " << name_point << " точки по x: ";
	point.x = get_double();
	cout << "Введите координату " << name_point << " точки по y: ";
	point.y = get_double();
	cout << "Введите координату " << name_point << " точки по z: ";
	point.z = get_double();
	cout << "---------------------------------" << endl;
	return point;
}

void size_arr(int& size, Points_class& point_arr, res_points_class& res_point_arr) {
	int radius_t = 0;
	Point center_t;
	cout << "Нажмите 1 для чтения количества точек из файла. 2 - для ручного ввода размера." << endl;
	while (true) {
		int type = get_int();
		if (type == 1) {
			create_file(READ_SIZE, point_arr, res_point_arr, size, radius_t, center_t);
			break;
		}
		else if (type == 2) {
			cout << "Введите количество точек." << endl;
			while (true) {
				size = get_int();
				if (size <= 0) {
					cout << "Размер массива не может быть отрицательным." << endl;
				}
				else break;
			}
			break;
		}
		else {
         cout << "Введите либо 1, либо 2." << endl;
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
	cout << "Введите радиус сферы: ";
	while (true) {
		radius = get_int();
		if (radius <= 0) {
			cout << "Радиус не может быть отрицательным." << endl;
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
	cout << "Точка " << index << " с координатами: " << point.x << " ; " << point.y << " ; " << point.z;
}

void output_arr(Points_class& point_arr, int radius, Point center) {
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "Исходные данные: " << endl;
	cout << "Исходный массив с координатами точек." << endl;
	for (int index = 0; index < point_arr.get_size(); index++) {
		output_point(point_arr[index], index+1);
		cout << endl;
	}
	cout << "Радиус сферы: " << radius << endl;
	cout << "Центр сферы: " << center.x << " ; " << center.y << " ; " << center.z << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

void res_output_arr(Points_class& point_arr, res_points_class& res_point_arr, HANDLE handle) {
	cout << "Получившийся массив с координатами точек." << endl;
	for (int index = 0; index < res_point_arr.get_size(); index++) {
		if (res_point_arr[index] == 1) {
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			output_point(point_arr[index], index+1);
			cout << " - попадает." << endl;
		}
		else {
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			output_point(point_arr[index], index+1);
			cout << " - не попадает." << endl;
		}
	}
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

bool show_or_try(void) {
	cout << "Для того, чтобы показать тесты нажмите 1." << endl;
	cout << "Для того, чтобы протестировать программу нажмите 2." << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "Введите либо 1, либо 2." << endl;
		}
	}
}

void create_file(int mode, Points_class& point_arr, res_points_class& res_point_arr, int& size, int& radius, Point& center) {
	if (mode == READ_SIZE) {
	here: cout << "Введите путь файла, из которого берутся данные." << endl
		<< "Образец: C:\\\\Папка1(если необходимо)\\\\Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl
		<< "Либо введите просто название файла, если он в папке этого проекта."
		<< endl;
		  const int SIZE_NAME = 256;
		  string name = "";
		  cin >> name;
		  fstream output_file(name);
		  int AMOUNT_DATA = 1;
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  if (!(output_file >> size)) {
				  cout << "Некорректные данные." << endl;
				  output_file.close();
				  goto here;
				  break;
			  }
		  }
		  for (int index = 0; index < AMOUNT_DATA; index++) {
			  output_file >> size;
		  }
		  cout <<"Исходное количество точек: " << size << endl;
		  output_file.close();
	}
	else if (mode == READ_POINTS) {
	here_2: cout << "Введите путь файла, из которого берутся данные." << endl
		<< "Образец: C:\\\\Папка1(если необходимо)\\\\Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl
		<< "Либо введите просто название файла, если он в папке этого проекта."
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
				  cout << "Некорректные данные." << endl;
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
	path:cout << "Введите путь файла, в который запишутся данные." << endl << "Образец: C:\\\\Папка1(если необходимо)\\\\"
		"Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl << "Либо введите просто название файла, тогда он будет в папке этого проекта."
		<< endl;
		 const int SIZE_NAME = 256;
		 string name = "";
		 cin >> name;
		 if (ifstream(name)) {
			 bool rewrite = true;
			 cout << "Файл уже существует." << endl;
			 cout << "Введите 0 для того, чтобы перезаписать существующий файл." << endl;
			 cout << "Введите 1 для того, чтобы повторить ввод." << endl;
		 repeat: rewrite = get_int();
			 switch (rewrite) {
			 case 0: cout << "Вы выбрали опцию перезаписать файл." << endl;
				 break;
			 case 1: cout << "Вы выбрали опцию повторить ввод." << endl;
				 goto path;
				 break;
			 default:
				 cout << "Введите 1, либо 2";
				 goto repeat;
			 }
		 }
		 ofstream result_file(name, ofstream::app);
		 error_code ec;
		 if (!is_regular_file(name, ec)) {
			 cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
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
				 << "Результат программы. " << endl
			  << "Получившийся массив с координатами точек:" << endl;
			 for (int index = 0; index < res_point_arr.get_size(); index++) {
				 if (res_point_arr[index] == 1) {
					 result_file << "Точка" << index << "с координатами: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
					  << " - попадает." << endl;
				 }
				 else {
					 result_file << "Точка" << index << " с координатами: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
					 << " - не попадает." << endl;
				 }
			 }
			 cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

			 break;
		 }
		 result_file.close();
	}
}

void greetings() {
	cout << "Программу выполнила Рухлова Ксения Алексеевна." << endl << "Группа: 404." << endl << "Вариант: 22." << endl <<
		"Задача номер 2:" << endl <<
		"В трехмерном пространстве задан массив точек (тройками значений X, Y, Z) и сфера(центр и радиус). " << endl 
		<< "Напишите программу, выводящую точки (их координаты), которые попадают в заданную пользователем сферу."
		<< endl;
}

void input_types(Points_class& arr_point, res_points_class& res_arr_point, int size, int& mode, int& radius, Point& center) {
	cout << "Выберите способ заполнения массива точек:" << endl << "Введите 1 для ввода вручную." << endl
		<< "Введите 2 для генерации случайных координат." << endl << "Введите 3 для использования исходных данных из файла." << endl;
again: int menu_type = get_int();
	mode = menu_type;
	switch (menu_type) {
	case MANUAL:
		cout << "Вы выбрали режим ввода вручную." << endl;
		cout << endl;
		user_input(arr_point, radius, center);
		break;
	case GENERATE:
		cout << "Вы выбрали режим генерации." << endl;
		generation_input(arr_point, radius, center);
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		break;
	case FILE_INPUT:
		cout << "Вы выбрали режим ввода данных из файла." << endl;
		create_file(READ_POINTS, arr_point, res_arr_point, size, radius, center);
		break;
	default:
		cout << "Введите либо 1, либо 2, либо 3." << endl;
		goto again;
	}
}

bool end_program() {
	cout << "Повторить программу? " << endl << "Введите 0 для завершения." << endl << "Введите 1 для повтора." << endl;
again: int end = get_int();
	switch (end) {
	case END:
		cout << "Программа завершается..." << endl;
		break;
	case CONTINUE:
		cout << "Вы выбрали повторить программу: " << endl;
		break;
	default:
		cout << "Введите либо 0, либо 1." << endl;
		goto again;
	}
	return !(end);
}


void saving_results(Points_class& point_arr, res_points_class& res_point_arr) {
	cout << "Сохрaнить результаты в отдельном файле?" << endl << "Введите 1 для сохранения." << endl << "Введите 2, чтобы пропустить сохранение." << endl;
	int size_t = 0, radius_t = 0;
	Point center_t;
	while (true) {
	 int save = get_int();
	 if (save == YES) {
		 create_file(RESULT, point_arr, res_point_arr, size_t, radius_t, center_t);
		 break;
	 }
	 else if (save == NO) {
		 cout << "Вы выбрали пропустить сохранение." << endl;
		 break;
	 }
	 else cout << "Введите либо 1, либо 2." << endl;

	}
}

void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t) {
	int size_t = 0;
	cout << "Вы хотите сохранить данные? Введите 1 - для сохранения, 2 - для пропуска сохранения." << endl;
	while (true) {
	 int save = get_int();
	 if (save == YES) {
		 create_file(DATA, point_arr, res_t, size_t, radius, center);
		 cout << "Данные сохранены." << endl;
		 break;
	 }
	 else if (save == NO) {
		 cout << "Вы выбрали пропустить сохранение." << endl;
		 break;
	 }
	 else cout << "Введите либо 1, либо 2." << endl;
	}
}
