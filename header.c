/**
@file
kek file
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

enum ROOTS
{
    ROOT_NO = 0,
    ROOT_1 = 1,
    ROOT_2 = 2,
    ROOT_INF = -1,
};

/**
\brief считывает коэффициенты и проводит их проверку
\param const double* a - указатель, по которому записывается первый вводимый коэффициент
\param const double* b - указатель, по которому записывается второй вводимый коэффициент
\param const double* c - указатель, по которому записывается третий вводимый коэффициент
*/
int cl_read(const double* a, const double* b, const double* c);

/**
\brief занимается очисткой буфера ввода
*/
void cleaninput();

/**
\return количество решений квадратного уравнения
\brief решает квадратное уравнение
\param const double a - значение старшего коэффициента(первый коэффициент)
\param const double b - значение второго коэффициента(коэффициент при x)
\param const double c - значение третьего коэффициента коэффициента(свободный член)
\param double* x1 - адрес, в который записывается значение решения x1
\param double* x2 - адрес, в который записывается значение решения x2
*/
int square_solver(const double a, const double b, const double c, double* x1, double* x2);

/**
\return количество решений линейного уравнения
\brief решает решает линейное уравнение
\param const double b - значение первого кэффициента
\param const double c - значение второго коэффициента
\param const double* x1 - адрес, в который записывается значение решения x
*/
int linear_solver(const double b, const double c, double* x1);

/**
\brief выводит решения на экран
\param const int nRoots - количество корней квадратного уравнения
\param const double x1 - значение первого решения
\param const double x2 - значение второго решения
*/
void write_Roots(const int nRoots, const double x1, const double x2);

/**
\return 0, когда fabs(a) больше 1 и 1, когда fabs(a) меньше 1
\brief Сравнивает значение c 0
\param Значение, сравниваемое с 0
*/
int compr_0(double a);

