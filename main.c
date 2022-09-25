#include "header.c"
#include "functions.c"

void unit_test();

int main ()
{
    //unit_test();
    while (1)
    {
        double a = 0;
        double b = 0;
        double c = 0;
        cl_read(&a, &b, &c);

        double x1 = 0;
        double x2 = 0;
        int nRoots = square_solver(a, b, c, &x1, &x2);

        write_Roots(nRoots, x1, x2);
    }
}

void unit_test()
{
    double tests[10][6] = {
        {1,  4,  2,  -0.585786, -3.414214,  2}, // 1
        {0,  0,  0,  0,         0,          -1}, // 2
        {0,  0,  1,  0,         0,          0}, // 3
        {1,  1,  1,  0,         0,          0}, // 4
        {1,  6,  1,  228,         0,          0}, // 5 error
        {1,  12, 12, -1.101021, -10.898979, 2}, // 6
        {2,  5,  3,  -1,        -1.5,       2}, // 7
        {12, 23, 11, -0.916667, -1,         2}, // 8
        {0,  5,  3,  -0.6    ,  0,          1}, // 9
        {3,  65, 32, -0.504033, -21.162634, 2}  // 10
    };// a,  b,  c,  x1,        x2,         nRoots
    for (int i = 0; i < 10; i++)
    {
        double x1 = 0, x2 = 0;
        int nRoots = square_solver(tests[i][0], tests[i][1], tests[i][2], &x1, &x2);
        if(compr_0(x1 - tests[i][3]) && compr_0(x2 - tests[i][4]) && nRoots == tests[i][5])
            printf("%d - OK\n", i + 1);
        else
        {
            printf("%d - ERROR\n", i + 1);
            printf("a = %lg, b = %lg, c = %lg\n", tests[i][0], tests[i][1], tests[i][2]);
            printf("Expected out: x1 = %lf, x2 = %lf, nRoots = %lg\n", tests[i][3], tests[i][4], tests[i][5]);
            printf("Real     out: x1 = %lf, x2 = %lf, nRoots = %d\n", x1, x2, nRoots);
        }
    }
}
