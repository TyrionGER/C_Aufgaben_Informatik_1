#include <stdio.h>

double quad2 (double a, int n, double erg){
    for(int i = 1; i < n; i++){
        erg *= a;
    }
    return erg;
}

double quad(int h, double a, double z, int n){
    if(n >= 2){
        if((n % 2) == 0){
            n -= 2;
            for(a = 1; h == 1;a++ ){
                if(((a+1)*(a+1)) <= z && ((a+2)*(a+2)) >= z){
                    h = 0;
                }
            }
            return quad(h, a, a, n);
            }
        else if((n % 2) == 1){
            for(a = 1; h == 1;a++ ){
                if(((a + 1) * (a + 1) * (a + 1)) <= z && ((a + 2) * (a + 2) * (a + 2)) >= z){
                    h = 0;
                }
            }
            n -= 3;
            return quad(h, a, a, n);
        }
    }
    else if(n < 2){
        return a;
    }
}

double square(double a, double z, int n){
    for(int i = 0;i == 0; ){
        double x = quad2(a, n, a);
        if((z - x) <= 0.001 && (z - x) >= -0.001 ){
            i = 1;
        }
        else if(x < z){
            a = a + (((z -  a) * 0.5) / z);
        }
        else if(x > z){
            a = a - (((z - a) * 0.5) / z);
        }
    }
    //a = a * 100;
    return a;
}

int main() {
    int h = 1, n;
    double a = 0, z, result;
    printf("Enter number for root: ");
    fflush(stdout);
    scanf("%lf", &z);
    fflush(stdin);
    printf("Enter number for n >= 2: ");
    fflush(stdout);
    scanf("%i", &n);
    fflush(stdin);
    a = quad(h, a, z, n);
    printf("%lf", a);
    result = square(a, z, n);
    //result = result / 100;
    printf("\nResult accurate to two decimal places: %.2lf", result);
}