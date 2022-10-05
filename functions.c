int cl_read(const double* a, const double* b, const double* c)
{
    assert(a != b && a != c && b != c);

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("\nWhat's up?\n");
    printf("Enter a, b, c or 'exit'\n\n");

    int sc_val;
    while ((sc_val = scanf("%lf%lf%lf", a, b, c)) != 3 || getchar() != '\n')
    {
        char in_str[1024];
        scanf("%s", in_str);
        if ((strcmp(in_str, "exit") == 0 || strcmp(in_str, "EXIT") == 0) && sc_val != 3)
            return 1;

        printf("Wrong input, try again\n\n");
        cleaninput();
    }

    return 0;
}

void cleaninput()
{
    while(getchar() != '\n');
}

int square_solver(const double a, const double b, const double c, double* x1, double* x2)
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != NULL);
    assert(x2 != NULL);

    assert(x1 != x2);

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
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != NULL);

    if(b == 0 && c != 0)
        return ROOT_NO;

    if(b == 0 && c == 0)
        return ROOT_INF;

    *x1 = -c / b;
    return ROOT_1;
}

void write_Roots(const int nRoots, const double x1, const double x2)
{
    assert(isfinite (x1));
    assert(isfinite (x2));


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
    printf("\n");
}

int compr_0(double a)
{
    assert(isfinite (a));

    return (fabs(a) < 0.00001);
}
