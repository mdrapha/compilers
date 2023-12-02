/* Um programa para calcular o mdc
   segundo o algoritmo de Euclides.*/

int input(void){}
void output(int a){}

int a[10];

int gcd (int u, int v){
    int x;
    if (v == 0) return u;
        else 
        return gcd(v, u-u/v*v);
}


void main(int k)
{   
    int x; int y;
    int ab[100];
    ab[0] = 1;
    x = input(); 
    y = input();
    /*while(x!=y)
        if (x>y) x=x-y;
        else y=y-x;*/
    
    output(gcd(x,y));
    return 0;
}