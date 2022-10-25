#include "Romb.h"

void Romb::CreateRomb() //Ввод значений трёх точек
{
	cout << "Внимание! Диагонали ромба - AC и BD." << endl;
	cout << "Введите координаты A(x, y) через пробел или последовательно" << endl;
	cin >> A.x >> A.y;
	cout << endl;
	cout << "Введите координаты B(x, y) через пробел или последовательно" << endl;
	cin >> B.x >> B.y;
	cout << endl;
	cout << "Введите координаты C(x, y) через пробел или последовательно" << endl;
	cin >> C.x >> C.y;
	cout << endl;
}

void Romb::CalculateRomb() //Подсчёт 4 точки ромба и площади
{
	double xCenter = (A.x + C.x) / 2;
	double yCenter = (A.y + C.y) / 2;

	D.x = (2 * xCenter - B.x); //Так как xCenter=(B.x+D.x)/2
	D.y = (2 * yCenter - B.y);

	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	BD.x = D.x - B.x;
	BD.y = D.y - B.y;
	//Коэффициент уравнения прямой через y=y0/x0. Векторы по определению перпендикулярны только тогда, когда скалярное произведение их коэффициентов равно -1.
	//Дополнение: Если уравнение одной из двух прямых не содержит ординаты (т.е. прямая параллельная оси OY), то эта прямая перпендикулярна к другой прямой при 
	//условии, что уравнение последней не содержит абсциссы (тогда вторая прямая параллельная оси абсцисс). В противном случае прямые не перпендикулярны. 
	bool isPerpendicular = (((AC.y * BD.y) / (AC.x * BD.x) == -1) || (AC.y == 0 && BD.x == 0) || (AC.x == 0 && BD.y == 0));

	if (!isPerpendicular)
	{
		cout << "Диагонали не перпендикулярны! Был задан не ромб." << endl;
		isRomb = false;
	}
	else
	{
		dAC = sqrt(AC.x * AC.x + AC.y * AC.y);
		dBD = sqrt(BD.x * BD.x + BD.y * BD.y);
		cout << "Ромб построен! Нажмите 4 в основном меню для просмотра параметров." << endl;

		isRomb = true;
	}
}

void Romb::PrintRomb()
{
	cout << endl;
	cout << "Координаты точек Ромба: \nA(" << A.x << ", " << A.y << ")" << endl;
	cout << "B(" << B.x << ", " << B.y << ")" << endl;
	cout << "C(" << C.x << ", " << C.y << ")" << endl;
	cout << "D(" << D.x << ", " << D.y << ")" << endl;
	cout << "Центр диагоналей ромба: " << (A.x + C.x) / 2 << ", " << (A.y + C.y) / 2 << endl;
	cout << "Диагонали ромба: \nAC: " << dAC << "\nBD: " << dBD << endl;
	cout << "Площадь ромба: " << dAC * dBD / 2 << endl << endl;
}

void Romb::MoveRomb()
{
	int c;
	double addX, addY;
	cout << "Введите 1 для смещения ромба относительно координат X и Y(добавочные значения)" << endl;
	cout << "Введите 2 для смещения центра ромба на заданные координаты X и Y" << endl;
	cin >> c;
	cout << endl;

	switch (c)
	{
	case 1:
	{
		cout << "Введите добавочные значения X и Y(через пробел или двумя разными вводами)" << endl;
		cin >> addX >> addY;
		cout << endl;

		A.x += addX;
		B.x += addX;
		C.x += addX;
		D.x += addX;
		A.y += addY;
		B.y += addY;
		C.y += addY;
		D.y += addY;
		cout << "Ромб смещён! Нажмите 4 в главном меню чтобы просмотреть его новые параметры." << endl;

		break;
	}
	case 2:
	{
		cout << "Введите абсолютные значения нового центра X и Y(через пробел или двумя разными вводами)" << endl;
		cin >> addX >> addY;
		cout << endl;

		double xCenter = (A.x + C.x) / 2;
		double yCenter = (A.y + C.y) / 2;

		A.x += (addX - xCenter);
		B.x += (addX - xCenter);
		C.x += (addX - xCenter);
		D.x += (addX - xCenter);
		A.y += (addY - yCenter);
		B.y += (addY - yCenter);
		C.y += (addY - yCenter);
		D.y += (addY - yCenter);

		break;
	}
	default:
	{
		cout << "Некорректный выбор." << endl;
		break;
	}
	}
}

void Romb::CheckCross()
{
	bool crossX = ((A.x * C.x <= 0) || (B.x * D.x <= 0));
	bool crossY = ((A.y * C.y <= 0) || (B.y * D.y <= 0));

	if (crossX)
		cout << "Фигура пересекает ось X" << endl;
	else
		cout << "Фигура не пересекает ось X" << endl;

	if (crossY)
		cout << "Фигура пересекает ось Y" << endl;
	else
		cout << "Фигура не пересекает ось Y" << endl;
	cout << endl;
}

double Square(Point f_point) //Простая функция в отсутствии библиотеки Math
{
	return (sqrt(f_point.x * f_point.x + f_point.y * f_point.y));
}

double Square(Point f_point, Point s_point) //Простая функция в отсутствии библиотеки Math
{
	return (sqrt((f_point.x - s_point.x) * (f_point.x - s_point.x) + (f_point.y - s_point.y) * (f_point.y - s_point.y)));
}

void Romb::CheckPoint(Point check_point)
{
	//Направляем вектор стороны ромба и сравниваем соотношения x и y с соотношениями вектора новой точки и начальной точки вектора стороны
	//Сравниваем полученное соотношение с допуском, для совпадения необходимо чтобы сходство было от (1-допуск) до (1+допуск)
	//Допуск по условиям задачи 0.005
	//

	Point AB, BC, CD, DA, ABcheck, BCcheck, CDcheck, DAcheck; //Псевдовекторы
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	BC.x = C.x - B.x;
	BC.y = C.y - B.y;
	CD.x = D.x - C.x;
	CD.y = D.y - C.y;
	DA.x = A.x - D.x;
	DA.y = A.y - D.y;

	ABcheck.x = check_point.x - A.x;
	ABcheck.y = check_point.y - A.y;
	BCcheck.x = check_point.x - B.x;
	BCcheck.y = check_point.y - B.y;
	CDcheck.x = check_point.x - C.x;
	CDcheck.y = check_point.y - C.y;
	DAcheck.x = check_point.x - D.x;
	DAcheck.y = check_point.y - D.y;

	bool belongAB = (abs((AB.x / AB.y) - (ABcheck.x / ABcheck.y)) <= (0.005));
	bool belongBC = (abs((BC.x / BC.y) - (BCcheck.x / BCcheck.y)) <= (0.005));
	bool belongCD = (abs((CD.x / CD.y) - (CDcheck.x / CDcheck.y)) <= (0.005));
	bool belongDA = (abs((DA.x / DA.y) - (DAcheck.x / DAcheck.y)) <= (0.005));

	if (belongAB || belongBC || belongCD || belongDA)
		cout << "\nТочка принадлежит периметру фигуры(с допуском 0.005)\n";
	else
		cout << "\nТочка НЕ пренадлежит периметру ромба\n";
}