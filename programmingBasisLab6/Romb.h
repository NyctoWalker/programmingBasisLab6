#pragma once
#include <iostream>

using namespace std;

//����� ���� ����� �������� � ������ ����, ��� ��� ����� ����������� �� ������ �����
class Point
{
public:
	double x;
	double y;
};
/// ��� public ������ ������ ����������, ���� ����� ������� � �������� ������, ���� ������ ��������� ���� �����. �����������.
class Romb
{
public:
	Point A, B, C, D;
	Point AC; //��� ������������
	Point BD; //��� ������������
	double dAC = 0; //���������
	double dBD = 0;


	bool isRomb = 0;

	void CreateRomb(); //���� �������� ��� �����
	void CalculateRomb(); //������� 4 ����� ����� � �������
	void PrintRomb();
	void MoveRomb();
	void CheckCross();
	void CheckPoint(Point check_point);
};