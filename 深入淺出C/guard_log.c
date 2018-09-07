#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now() {
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main() {
    char commemt[80];
    char cmd[120];
    fgets(commemt, 80, stdin);
    // try ' && ls / && echo '
    sprintf(cmd, "echo '%s %s' >> reports.log", commemt, now());
    system(cmd);
    return 0;
}
