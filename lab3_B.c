#include <stdio.h>
#include <stdlib.h>


//function that finds min of three integers
int minimum (int a, int b, int c){
    if(a<=b & a<=c){
        return a;
    }
    else if(b<=c){
        return b;
    }
    else{
        return c;
    }
}

//function that finds max of three integers
int maximum (int a, int b, int c){
    if(a>=b & a>=c){
        return a;
    }
    else if(b>=c){
        return b;
    }
    else{
        return c;
    }
}

// product of two integers
int product (int a, int b){
    return a*b;
}

//retunrs product of max and min of three integers
int compute(int (*mx)(int,int,int), int (*mn)(int,int,int), int(*prd)(int, int), int num1, int num2, int num3){
    int min_val = mn(num1, num2, num3);
    int max_val = mx(num1, num2, num3);
    return prd(min_val, max_val);
}

int main() {

    int num1, num2, num3;

    //user input
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = compute(minimum, maximum, product, num1, num2, num3);

    printf("Product of minimum and maximum: %d\n", result);

    return 0;
}
