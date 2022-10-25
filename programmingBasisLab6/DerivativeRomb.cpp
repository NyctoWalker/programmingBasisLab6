#include "DerivativeRomb.h"
#include <cmath>
#define PI 3.14159265358979323846

void NewRomb::NewCreateRomb()
{
	CreateRomb();
	CalculateRomb();
	if (isRomb == true)
	{
		prevA = A;
		prevB = B;
		prevC = C;
		prevD = D;
		middle.x= (A.x + C.x) / 2;
		middle.y= (A.y + C.y) / 2;
		axis_angle = 0;
	}
}

void NewRomb::Reset()
{
	A = prevA;
	B = prevB;
	C = prevC;
	D = prevD;
	axis_angle = 0;

	cout << endl << "���� ��� ��������� � ���������� �� �������� � ��������" << endl << endl;
}

void NewRomb::NewPrintRomb()
{
	cout << endl;
	cout << "���������� ����� �����: \nA(" << A.x << ", " << A.y << ")" << endl;
	cout << "B(" << B.x << ", " << B.y << ")" << endl;
	cout << "C(" << C.x << ", " << C.y << ")" << endl;
	cout << "D(" << D.x << ", " << D.y << ")" << endl;
	cout << "����� ���������� �����: " << middle.x << ", " << middle.y << endl;
	cout << "������� ����� ������������ ������������: " << axis_angle << " ��������" << endl;
	cout << "��������� �����: \nAC: " << dAC << "\nBD: " << dBD << endl;
	cout << "������� �����: " << dAC * dBD / 2 << endl << endl;
}

void NewRomb::TurnPoint(Point &TURN, const double angle)
{
	Point Pnew;
	Pnew.x = (middle.x + (TURN.x - middle.x) * cos(angle) - (TURN.y - middle.y) * sin(angle));
	Pnew.y = (middle.y + (TURN.x - middle.x) * sin(angle) + (TURN.y - middle.y) * cos(angle));
	TURN.x = Pnew.x;
	TURN.y = Pnew.y;
}

void NewRomb::TurnRomb()
{
	double add_angle;
	cout << endl;
	cout << "������� ���������� ���� ��� ��������(� ��������):" << endl;
	cin >> add_angle;
	cout << endl;
	axis_angle += add_angle;
	add_angle = add_angle * PI / 180;
	TurnPoint(A, add_angle);
	TurnPoint(B, add_angle);
	TurnPoint(C, add_angle);
	TurnPoint(D, add_angle);
	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	BD.x = D.x - B.x;
	BD.y = D.y - B.y;
	dAC = sqrt(AC.x * AC.x + AC.y * AC.y);
	dBD = sqrt(BD.x * BD.x + BD.y * BD.y);
	///������ ��� ��������� �� ��������?
	add_angle = 0;

	while (abs(axis_angle >= 360))
	{
		if (axis_angle > 0)
			axis_angle -= 360;
		if (axis_angle < 0)
			axis_angle += 360;
	}
	cout << "������ �������� ������������ ������! ���������� ��������� ����� ������� 4 ��������� ����." << endl << endl;
}