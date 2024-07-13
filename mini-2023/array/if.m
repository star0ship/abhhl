int r;
char l[10];
main()
{
	int  a , b , c , d , e;
    int *p;
    int k[10];
    

	b = 1;
    c = -b;
    c = 2;
    a = b * c;
    p = &b;
    *p = c + 1;
    b = *p + 1;
    d = b + c;
    d = add(b,c);
    a = - b * c + d ;

    if ( a ) { a = - b * c ; }

    d = 999;

    k[b-1]=1;
    l[k[b-1]]='a';
    l[1]=20;
    k[l[1]]=0;
    print(d);
    zero(p);
    print(b);
    print('\n');
    print(l[1]);
    
}

add(x, y)
{
    int z;
    z = x + y;
    return z;
}

zero(*ptr)
{
    *ptr = 0;
}

