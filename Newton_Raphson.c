#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double guess, double sub_zero, int max, double epsilon);

main(){
    //declared variables
    double guess, sub_zero, epsilon;
    int max;
    
    //user input insctuctions/menu
    printf("Enter the initial guess: ");
    scanf("%lf", &guess);
    printf("Enter the value of C: ");
    scanf("%lf", &sub_zero);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max);
    printf("Enter the maximum error: ");
    scanf("%lf", &epsilon);
    
    //separates input from solution
    printf("\n\n                      Solution \n");
    
    //calls the function newton
    newton(guess, sub_zero, max, epsilon);
    
    //output to inform the user with solution
    printf("\nThe maximum iterations entered was: %d\n", max);
    printf("             The guessed value was: %0.3f\n", guess);
    printf("                The value of C was: %0.3f\n", sub_zero);
    printf("       The error value entered was: %0.3f\n\n", epsilon);
    

    system("pause");
    return 0;
}

double newton(double guess, double sub_zero, int max, double epsilon){
    //declared variables
    double y = guess, fx;
    int count = 0;
    
    //loops until count is less than user input "max"
    while(count < max){
        //exits loop when |f(x)| is less than epsilon
        if(fabs(fx) < epsilon){
                break;
        }
        //other wise perform the newton and the f(x) formula
        else{
                fx = (pow(y,4)-sub_zero);
                y = y - (pow(y,4)-sub_zero)/(4*pow(y,3));
        
                ++count;
        }
    }
    
    //output informs the user with solution
    printf("\n        The Final root estimate is: %f", y);
    printf("\n              The value of f(x) is: %f", fx);
    printf("\n         The total iterations were: %d", count);
    
    return y, fx, count;
}
