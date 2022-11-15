#include <math.h>
#include <stdio.h>
#include <stdlib.h>




double normpdf(double x) {
    // compute left side constant
    double pi = M_PI;
    double leftSide = 1 / sqrt(2 * pi);

    // compute right side value

    // value we are raising e to
    double exponent = (-1 * powf(x, 2)) / 2;
    // raise e to that value
    double rightSide = exp(exponent);

    // multiply and return them
    return leftSide * rightSide;
}



int divide(int x, int y, int *remainder) {
    // perform integer division
    div_t dv = div(x, y);

    int quotient = dv.quot;
    // store the value in *remainder
    *remainder = dv.rem;
    
    // return the x/y thaang

    return quotient;
}




int main(int argc, char *argv[]) {
    // 1 arg given
    if (argc == 2) {
        // convert char arg to float
        float x = atof(argv[1]);
        float val = normpdf(x);

        // print order : string: "phi(" float :  .6 : string ") =      " float: .8
        printf("phi(%f) = %12.8f\n", x, normpdf(x));

    }
    // 2 args given
    else if (argc == 3) {
        // convert from string to int
        int x = (int)atof(argv[1]);
        int y = (int)atof(argv[2]);

        int remainder;
        int quotient = divide(x, y, &remainder);

        // x '\' y '=' q ', ' x '%' y ' = ' r
        printf("%d / %d = %d, %d %s %d = %d\n", x, y, quotient, x, "%", y, remainder);

    }
    // no args given or 3+
    else {
        fprintf(stderr, "Usage: maths num1 [num2].");
        printf("\n");
        exit(1);
    }
    return 0;
}