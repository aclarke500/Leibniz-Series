#include <stdio.h>

float pi(int n){
    // calculate pi using Lebniz's formula
    float pi =0.0;
    float subtract = 1.0;

    for (int i = 1; i <= n; i+=2){
        pi += subtract*(4.0/i);
        subtract *= -1.0;
    }

    return pi;
}


int main(void){
    printf("%.15f\n", pi(1000000));
    return 0;
}