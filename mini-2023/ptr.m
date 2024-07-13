main()
{
	int  a , b , c , d , e;
    int *p;
    

	b = 1;
    c = 2;
    p = &a;
    *p = c + 1;
    print("a1: ",a,"\n");
    add1(p);
    print("a2: ",a,"\n");
    b = *p + 2;

    print("b: ",b,"\n");
    
}

add1(*ptr)
{
    *ptr = *ptr + 1;
}

