/* Um programa para calcular o mdc
   segundo o algoritmo de Euclides.*/

int a[10];

int gcd (int u, int v){
    if (v == 0) return u;
        else 
        return gcd(v, u-u/v*v);
}

void main(int k)
{   
    int x; int y;
    x = input(); 
    y = input();
    while(x!=y)
    a[1] = 1;
    output(gcd(x,y));
    return 0;
}