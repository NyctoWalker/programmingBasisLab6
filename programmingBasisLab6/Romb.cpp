#include "Romb.h"

void Romb::CreateRomb() //���� �������� ��� �����
{
	cout << "��������! ��������� ����� - AC � BD." << endl;
	cout << "������� ���������� A(x, y) ����� ������ ��� ���������������" << endl;
	cin >> A.x >> A.y;
	cout << endl;
	cout << "������� ���������� B(x, y) ����� ������ ��� ���������������" << endl;
	cin >> B.x >> B.y;
	cout << endl;
	cout << "������� ���������� C(x, y) ����� ������ ��� ���������������" << endl;
	cin >> C.x >> C.y;
	cout << endl;
}

void Romb::CalculateRomb() //������� 4 ����� ����� � �������
{
	double xCenter = (A.x + C.x) / 2;
	double yCenter = (A.y + C.y) / 2;

	D.x = (2 * xCenter - B.x); //��� ��� xCenter=(B.x+D.x)/2
	D.y = (2 * yCenter - B.y);

	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	BD.x = D.x - B.x;
	BD.y = D.y - B.y;
	//����������� ��������� ������ ����� y=y0/x0. ������� �� ����������� ��������������� ������ �����, ����� ��������� ������������ �� ������������� ����� -1.
	//����������: ���� ��������� ����� �� ���� ������ �� �������� �������� (�.�. ������ ������������ ��� OY), �� ��� ������ ��������������� � ������ ������ ��� 
	//�������, ��� ��������� ��������� �� �������� �������� (����� ������ ������ ������������ ��� �������). � ��������� ������ ������ �� ���������������. 
	bool isPerpendicular = (((AC.y * BD.y) / (AC.x * BD.x) == -1) || (AC.y == 0 && BD.x == 0) || (AC.x == 0 && BD.y == 0));

	if (!isPerpendicular)
	{
		cout << "��������� �� ���������������! ��� ����� �� ����." << endl;
		isRomb = false;
	}
	else
	{
		dAC = sqrt(AC.x * AC.x + AC.y * AC.y);
		dBD = sqrt(BD.x * BD.x + BD.y * BD.y);
		cout << "���� ��������! ������� 4 � �������� ���� ��� ��������� ����������." << endl;

		isRomb = true;
	}
}

void Romb::PrintRomb()
{
	cout << endl;
	cout << "���������� ����� �����: \nA(" << A.x << ", " << A.y << ")" << endl;
	cout << "B(" << B.x << ", " << B.y << ")" << endl;
	cout << "C(" << C.x << ", " << C.y << ")" << endl;
	cout << "D(" << D.x << ", " << D.y << ")" << endl;
	cout << "����� ���������� �����: " << (A.x + C.x) / 2 << ", " << (A.y + C.y) / 2 << endl;
	cout << "��������� �����: \nAC: " << dAC << "\nBD: " << dBD << endl;
	cout << "������� �����: " << dAC * dBD / 2 << endl << endl;
}

void Romb::MoveRomb()
{
	int c;
	double addX, addY;
	cout << "������� 1 ��� �������� ����� ������������ ��������� X � Y(���������� ��������)" << endl;
	cout << "������� 2 ��� �������� ������ ����� �� �������� ���������� X � Y" << endl;
	cin >> c;
	cout << endl;

	switch (c)
	{
	case 1:
	{
		cout << "������� ���������� �������� X � Y(����� ������ ��� ����� ������� �������)" << endl;
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
		cout << "���� ������! ������� 4 � ������� ���� ����� ����������� ��� ����� ���������." << endl;

		break;
	}
	case 2:
	{
		cout << "������� ���������� �������� ������ ������ X � Y(����� ������ ��� ����� ������� �������)" << endl;
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
		cout << "������������ �����." << endl;
		break;
	}
	}
}

void Romb::CheckCross()
{
	bool crossX = ((A.x * C.x <= 0) || (B.x * D.x <= 0));
	bool crossY = ((A.y * C.y <= 0) || (B.y * D.y <= 0));

	if (crossX)
		cout << "������ ���������� ��� X" << endl;
	else
		cout << "������ �� ���������� ��� X" << endl;

	if (crossY)
		cout << "������ ���������� ��� Y" << endl;
	else
		cout << "������ �� ���������� ��� Y" << endl;
	cout << endl;
}

double Square(Point f_point) //������� ������� � ���������� ���������� Math
{
	return (sqrt(f_point.x * f_point.x + f_point.y * f_point.y));
}

double Square(Point f_point, Point s_point) //������� ������� � ���������� ���������� Math
{
	return (sqrt((f_point.x - s_point.x) * (f_point.x - s_point.x) + (f_point.y - s_point.y) * (f_point.y - s_point.y)));
}

void Romb::CheckPoint(Point check_point)
{
	//���������� ������ ������� ����� � ���������� ����������� x � y � ������������� ������� ����� ����� � ��������� ����� ������� �������
	//���������� ���������� ����������� � ��������, ��� ���������� ���������� ����� �������� ���� �� (1-������) �� (1+������)
	//������ �� �������� ������ 0.005
	//

	Point AB, BC, CD, DA, ABcheck, BCcheck, CDcheck, DAcheck; //�������������
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
		cout << "\n����� ����������� ��������� ������(� �������� 0.005)\n";
	else
		cout << "\n����� �� ����������� ��������� �����\n";
}