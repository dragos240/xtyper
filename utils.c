#include <unistd.h>

#include "utils.h"

// float sleep
void fsleep(double s){
    usleep((int)(s*USEC_IN_SEC));
}
