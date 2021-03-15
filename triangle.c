# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Example - 0 points 
// void triangle(unsigned width)
// {
//     unsigned i, j;
    
//     i = 0;
//     while (i <= width) {
//         j = 0;
//         while (j < i) {
//             putchar('*');
//             ++j;
//         }
//         putchar('\n');
//         ++i;
//     }
// }

// 3 points
void triangle(unsigned width)
{
    int i, j;
    for (i = 0; i <= width; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

// 3 points
void v_triangle(unsigned width)
{
    int i, j;
    for (i = width; i >= 1; --i)
    {
        for (j = 1; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

// 3 points
void h_triangle(unsigned width)
{
    int i, j;
    for (i = 1; i <= width; i++)     
    {
        for (j = 1; j < i; j++){
            printf(" ");
        }
        for (j = i; j <= width; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int 
main(int argc, char **argv)
{
    // One argument is not allowed
    if (argc == 1)
    {
        // This below just letting the user know of how to run the program in the future
        printf("----------------------------\n");
        printf("Expecting a second argument!\n");
        printf("EXIT_FAILURE\n");
        printf("----------------------------\n");
        exit(EXIT_FAILURE); // I know i could have just called this and end the program 
    }

    // 2nd argument must be an integer
    if (atoi(argv[1]) == 0)
    {
        // This below just letting the user know of how to run the program in the future
        printf("----------------------------\n");
        printf("Expecting a second argument to be integer >= 1!\n");
        printf("EXIT_FAILURE\n");
        printf("----------------------------\n");
        exit(EXIT_FAILURE); // I know i could have just called this and end the program 
    }
    printf("\n");
    printf("------------------------\n");
    printf("Passed %d arguments!\n", argc);
    for (int i=0; i < argc; i++)
    {
        if (i > 2 ){
            printf("arg %d - %s <- not allowed\n", i, argv[i]);
        }else{
            // if (atoi(argv[2]) == 0){
            //     printf("arg %d - %s <- should be a string\n", i, argv[i]);
            // }
            printf("arg %d - %s\n", i, argv[i]);
        }
    }
    // This is just for my purpose to see what is being inputed from the command line
    printf("ByteSize is %zu,\nArgument in Int: %d\n", sizeof(atoi(argv[1])), atoi(argv[1]));
    printf("------------------------\n");

    // [3] points noted
    if (argc <= 2)
    {
        if (atoi(argv[1]) == -1){
            printf("------------------------\n");
            printf("Please enter a non negative integer!\n");
            printf("EXIT_FAILURE\n");
            printf("------------------------\n");
            exit(EXIT_FAILURE);
        }
        printf("------------------------\n");
        printf("Function - triangle\n");
        printf("------------------------\n");
        triangle(atoi(argv[1])); // now the passed arguments is converted to int size 4
        printf("------------------------\n");
    }else 
    {
        if (argc > 2 && argc < 4)
        {
            if ((strcmp(argv[2], "h") == 0)||(strcmp(argv[2], "v") == 0)){
                if (strcmp(argv[2], "v") == 0)
                {
                    printf("------------------------\n");
                    printf("Function - v_triangle\n");
                    printf("------------------------\n");
                    v_triangle(atoi(argv[1]));
                    printf("------------------------\n");
                }
                if (strcmp(argv[2], "h") == 0)
                {
                    printf("------------------------\n");
                    printf("Function - h_triangle\n");
                    printf("------------------------\n");
                    h_triangle(atoi(argv[1]));
                    printf("------------------------\n");
                }
            }else{
                // This below just letting the user know of how to run the program in the future
                printf("----------------------------\n");
                printf("Arguments allowed: [v] or [h]\n");
                printf("EXIT_FAILURE\n");
                printf("----------------------------\n");
                exit(EXIT_FAILURE); // I know i could have just called this and end the program 
            }
        }

        // Nothing should be done when arguments exceeds argc > 3
        if (argc >= 4)
        {
            // This below just letting the user know of how to run the program in the future
            printf("----------------------------\n");
            printf("Too many arguments, Good Bye!\n");
            printf("EXIT_FAILURE\n");
            printf("----------------------------\n");
            exit(EXIT_FAILURE); // I know i could have just called this and end the program 
        }
    }
    printf("EXIT_SUCCESS\n");
    printf("------------------------\n\n");
    return EXIT_SUCCESS;
}

// Important data to go over 
/**
 * printf("The size of integer is %lu\n", (unsigned long)sizeof(n));
 * 
 * printf("The size of integer is %zu\n", sizeof(n));
 * 
 * printf("The size of integer is %d\n", sizeof(int));
 * */

/**
 * atoi() : returns an integer
 * 
 * atof() : returns an floating point decimal 
 * 
 * atol() : returns as long 
 * */