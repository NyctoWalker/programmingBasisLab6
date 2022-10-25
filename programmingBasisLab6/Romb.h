#pragma once
#include <iostream>

using namespace std;

//Такие вещи лучше выносить в другой файл, так как класс принадлежит не только ромбу
class Point
{
public:
	double x;
	double y;
};
/// Без public нельзя изъять переменные, даже через геттеры в исходном классе, хотя объект наследует этот класс. Разобраться.
class Romb
{
public:
	Point A, B, C, D;
	Point AC; //Это псевдовектор
	Point BD; //Это псевдовектор
	double dAC = 0; //Диагональ
	double dBD = 0;


	bool isRomb = 0;

	void CreateRomb(); //Ввод значений трёх точек
	void CalculateRomb(); //Подсчёт 4 точки ромба и площади
	void PrintRomb();
	void MoveRomb();
	void CheckCross();
	void CheckPoint(Point check_point);
};