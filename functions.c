void cl_read(const double* a, const double* b, const double* c)
{
    assert(a != b && a != c && b != c);

    printf("\nWhat's up?\n");
    printf("Enter a, b, c\n");

    while (scanf("%lf%lf%lf", a, b, c) != 3 || getchar() != '\n')
    {
        printf("Wrong input, try again\n");
        cleaninput();
    }
}

void cleaninput()
{
    while(getchar() != '\n');
}

int square_solver(const double a, const double b, const double c, double* x1, double* x2)
{
    assert( x1 != x2);

    if(a == 0)
        return linear_solver(b, c, x1);

    double disc = b*b - 4*a*c;


    if(disc < 0)
        return ROOT_NO;
    if(disc == 0)
    {
        *x1 = -b / 2*a;
        return ROOT_1;
    }

    *x1 = ( -b + sqrt(disc) ) / (2*a);
    *x2 = ( -b - sqrt(disc) ) / (2*a);
    return ROOT_2;

}

int linear_solver(const double b, const double c, double* x1)
{
    if(b == 0 && c != 0)
        return ROOT_NO;

    if(b == 0 && c == 0)
        return ROOT_INF;

    *x1 = -c / b;
    return ROOT_1;
}

void write_Roots(const int nRoots, const double x1, const double x2)
{
    switch(nRoots)
    {
        case ROOT_INF:
            printf ("INFINITY number of Roots");
            break;
        case ROOT_NO:
            printf("No Roots");
            break;
        case ROOT_1:
            printf("x = %lf", x1);
            break;
        case ROOT_2:
            printf("x1 = %lf\nx2 = %lf", x1, x2);
            break;
    }
}

int compr_0(double a)
{
    return (fabs(a) < 0.00001);
}
