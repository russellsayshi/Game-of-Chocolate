#include <stdio.h>

int get_integer(void) {
    char buf[16];
    
    //Read line from input into buf
    if(fgets(buf, sizeof(buf), stdin) != buf) {
        return -1;
    }
    
    //Find integer
    int result;
    if(sscanf(buf, "%d", &result) != 1) {
        return -1;
    }
    return result;
}