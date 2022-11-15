// save as cmdline.c
#include <stdio.h>

void main(int argc, char *argv[]) {
    //if no args, just print empty line
    if (argc == 1){
        printf("%s\n", "");
    }
    //else, print up to n - 1
    else{
        
        for (int i = 1; i < argc - 1; i++) {
            printf("%s ",argv[i]);
        }
        
        //at n-1, print with no space
        printf("%s\n", argv[argc - 1]);
    }
}