/* Program:     threads.c
 * Author:      Justin Cromer
 * Date:        Thu May 11 2023
 * Description: A simple example of using threads to change values while the 
 *              main loop handles rewriting a line over and over.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

static int loops;

typedef struct thread_func_args {
        char target;
        int id;
} Args;

#define MAX_BUF         1000
char msg[MAX_BUF];

void *randomize(void *arg)
{
        int i = loops - ((Args*)arg)->id * 50;
        while (i-- > 0)
        {
                /* Change the value of the target to be a random character, 
                   excluding control characters. */
                ((Args*)arg)->target = rand() % 93 + 32;
                usleep(10000);
        }
        ((Args*)arg)->target = msg[((Args*)arg)->id];
        return NULL;
}

int main(int argc, char *argv[])
{
        int len = strlen(msg);

        if (argc == 2)
        {
                len = strlen(argv[1]);
                strncpy(msg, argv[1], len > MAX_BUF ? MAX_BUF : len);
        }
        else
        {
                fprintf(stderr, "Usage: ./threads <SECRET-MESSAGE>\n");
                exit(1);
        }

        loops = len * 50;

        Args args[len];
        pthread_t threads[len];

        // Assign a character to be controlled by a thread.
        for (int t = 0; t < len; ++t)
        {
                args[t].id = t;
                pthread_create(&threads[t], NULL, randomize, &args[t]);
        }

        int i = loops;
        while (i-- > 0)
        {
                printf("\r");
                for (int j = 0; j < len; ++j)
                {
                        printf("%c ", args[j].target);
                }
                fflush(stdout);
                usleep(10000);
        }
        printf("\n");

        return 0;
}
