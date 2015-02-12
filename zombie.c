//
//  zombie
//
//
//  Created by liang chengming on 2015-02-12.
//  Copyright (c) 2013年 liang chengming. All rights reserved.
//
//

/*
 * $ gcc zombie.c -o zombie
 * $ ./zombie
 * $ ps -eo stat,args,pid,ppid,user  | grep -v grep | grep Z
 */


//stdc
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//linux
#include <unistd.h>
#include <sys/types.h>


int main(int argc, const char *argv[])
{
    pid_t child = fork();


    if( child < 0  )
    {
        perror("fork process fail.\n");                     //fork error.
    }
    else if( child ==0  )
    {
        printf(" fork succ, this run in child process\n "); // in child process
    }
    else
    {
        sleep(10);                                          // sleep 10seconds
        printf(" this run in parent process\n ");           // in parent process
    }

    return EXIT_SUCCESS;
}
