//
//  main.c
//  Bit Fiddling
//
//  Created by Emrah Usar on 4/23/18.
//  Copyright © 2018 Usar Labs. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

char * itobs(int, char *);
void show_bstr(const char *);

int main(int argc, const char * argv[]) {
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;
    
    puts("Enter an integer to see its binary format:");
    
    while (scanf("%d", &number) == 1) {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    
    return 0;
}

char * itobs(int n, char * ps){
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1) {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}

void show_bstr(const char * str){
    int i = 0;
    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i]) {
            putchar(' ');
        }
    }
}
