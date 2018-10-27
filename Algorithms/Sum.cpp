int sum(const int& n)
{
    int su=0;
    int cont=1;
    while(cont!=n)
    {
        if(cont%5==0 || cont%3==0)
            su+=cont;
        cont++;
    }
    return su;
}