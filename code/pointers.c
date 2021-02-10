void Pointers()
{
    char x = 5; // 4 byte
    char* px = 0;
    char** pp = 0;
    
    px = x;
    pp = px;
    x = 7;
    px = x;
    
    x = pp;
    
    printf("x = %d\nx adress = %u\n", x, &x);
    printf("px = %d\npx adress = %u\n", px, &px);
    printf("px = %d\npx adress = %u\n", pp, &pp);
}