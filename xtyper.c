#include <stdio.h> // printf
#include <stdlib.h> // exit
#include <string.h> // memset
#include <stdbool.h> // bool, true, false

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#include "utils.h"
#include "xtyper.h"

static int error_code = 0;
static int (*old_error_handler) (Display *, XErrorEvent *);

void open_display(){
    display = XOpenDisplay(NULL);
    if(display == NULL){
        printf("ERROR: Failed to get display\n");
        exit(1);
    }
}

static int error_handler(Display *d, XErrorEvent *xerror){
    error_code = xerror->error_code;
    return 0;
}

void trap_errors(){
    error_code = 0;
    old_error_handler = XSetErrorHandler(error_handler);
}

int untrap_errors(){
    XSetErrorHandler(old_error_handler);
    return error_code;
}

void send_key(char c){
    XTestFakeKeyEvent(display, XKeysymToKeycode(display, (unsigned)c),
            True, CurrentTime);
    XTestFakeKeyEvent(display, XKeysymToKeycode(display, (unsigned)c),
            False, CurrentTime);
    XFlush(display);
}

bool type_string(char *str){
    char key;

    while((key = *str)){
        send_key(key);
        str++;
    }

    return true;
}

int main(int argc, char *argv[]){
    char *text_buf = NULL;

    if(argc < 2 || argc > 2){
        printf("Syntax: %s \"text to type\"\n", argv[0]);
        return 0;
    }

    text_buf = calloc(strlen(argv[1])+1, sizeof(char));
    strcpy(text_buf, argv[1]);

    // open display
    open_display();

    // type!
    type_string(text_buf);

    return 0;
}
