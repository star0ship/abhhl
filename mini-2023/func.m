int d;

main() 
{
	int a,b,c;

	a = 1;
	b = 2;
    c = add(a+1, b+2) ;
    d = 999;
}

add(x, y)
{ 
    int a;
    a = x + y;
    d = a;
    return a ; 
}
