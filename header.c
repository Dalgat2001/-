/**
@file
kek file
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <math.h>

enum ROOTS
{
    ROOT_NO = 0,
    ROOT_1 = 1,
    ROOT_2 = 2,
    ROOT_INF = -1,
};

/**
\brief ��������� ������������ � �������� �� ��������
\param const double* a - ���������, �� �������� ������������ ������ �������� �����������
\param const double* b - ���������, �� �������� ������������ ������ �������� �����������
\param const double* c - ���������, �� �������� ������������ ������ �������� �����������
*/
void cl_read(const double* a, const double* b, const double* c);

/**
\brief ���������� �������� ������ �����
*/
void cleaninput();

/**
\return ���������� ������� ����������� ���������
\brief ������ ���������� ���������
\param const double a - �������� �������� ������������(������ �����������)
\param const double b - �������� ������� ������������(����������� ��� x)
\param const double c - �������� �������� ������������ ������������(��������� ����)
\param double* x1 - �����, � ������� ������������ �������� ������� x1
\param double* x2 - �����, � ������� ������������ �������� ������� x2
*/
int square_solver(const double a, const double b, const double c, double* x1, double* x2);

/**
\return ���������� ������� ��������� ���������
\brief ������ ������ �������� ���������
\param const double b - �������� ������� �����������
\param const double c - �������� ������� ������������
\param const double* x1 - �����, � ������� ������������ �������� ������� x
*/
int linear_solver(const double b, const double c, double* x1);

/**
\brief ������� ������� �� �����
\param const int nRoots - ���������� ������ ����������� ���������
\param const double x1 - �������� ������� �������
\param const double x2 - �������� ������� �������
*/
void write_Roots(const int nRoots, const double x1, const double x2);

/**
\return 0, ����� fabs(a) ������ 1 � 1, ����� fabs(a) ������ 1
\brief ���������� �������� c 0
\param ��������, ������������ � 0
*/
int compr_0(double a);

