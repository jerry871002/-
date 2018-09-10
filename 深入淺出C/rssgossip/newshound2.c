#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> // for fork() and execle()
#include <sys/wait.h> // for waitpid()

void error(char*);

int main(int argc, char *argv[]) {
    char *phrase = argv[1]; // 傳遞搜尋項目作為引數
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/world/rss.xml", NULL};
    FILE *f = fopen("stories.txt", "w");
    if(!f) {
        error("Can't open stories.txt");
    }
    pid_t pid = fork();
    if(pid == -1) {
        error("Can't fork process");
    }
    if(!pid) {
        // 將描述子 #1 指向 stories.txt
        if(dup2(fileno(f), 1) == -1) {
            error("Can't redirect Standard Output");
        }
        if(execle("/usr/bin/python2.7", "/usr/bin/python2.7", "./rssgossip.py", phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    int pid_status;
    if(waitpid(pid, &pid_status, 0) == -1) {
        error("Error waiting for child process");
    }
    return 0;
}

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
