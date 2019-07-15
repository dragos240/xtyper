#ifndef XTYPER_H
#define XTYPER_H

#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct {
    char key;
    int code;
    KeySym symbol;
} charcode_t;

Display *display;
Window root_window;
charcode_t *charcodes;
int charcodes_len;

#endif /* !XTYPER_H */
