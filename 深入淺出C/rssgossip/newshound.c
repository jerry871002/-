#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> // for fork() and execle()

int main(int argc, char *argv[]) {
    // 找一些自己想要的 RSS feed
    char *feeds[] = {"http://rss.cnn.com/rss/edition_world.rss",
                     "http://feeds.bbci.co.uk/news/world/rss.xml"};

    int times = 3;
    char *phrase = argv[1]; // 傳遞搜尋項目作為引數
    for(int i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        pid_t pid = fork();
        // 假如 fork() 回傳 -1，表示行程複製發生問題
        if(pid == -1) {
            fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
            return 1;
        }
        // 假如 fork() 回傳 0，表示程式碼執行在子行程裡
        if(!pid) {
            if(execle("/usr/bin/python2.7", "/usr/bin/python2.7", "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Can't run script: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}
