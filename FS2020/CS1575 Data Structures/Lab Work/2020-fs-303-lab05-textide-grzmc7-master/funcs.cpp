unsigned long factorial(unsigned long n)
{
    if(n < 2)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

unsigned long combination(unsigned long n, unsigned long m)
{
    if(n >= m)
    {
        unsigned long n_fac = 1, m_fac = 1, n_minus_m_fac = 1;

        //finding n!
        for(int i = 2; i <= n; i++)
        {
            n_fac *= i;
        }

        //finding m!
        for(int j = 2; j <= m; j++)
        {
            m_fac *= j;
        }

        //finding (m - n)!
        for(int k = 2; k <= (n - m); k++)
        {
            n_minus_m_fac *= k;
        }

        return ( n_fac / (m_fac * n_minus_m_fac) );
    }

    else
        return n; //this should not ever execute
}
