//
//  apue_syslog
//
//
//  Created by liang chengming on 2015-02-11.
//  Copyright (c) 2013年 liang chengming. All rights reserved.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>

/*
 *
 * # add this into your /etc/syslog.conf
 *
 * # log user-application to /var/log/user_app.log
 * user.*                          /var/log/user_app.log
 *
 * $killall -HUP syslogd
 *  */


int main(int argc, const char *argv[])
{
    int option   = LOG_PID | LOG_CONS;
    int facility = LOG_USER;
    int level    = LOG_INFO;

    int priority = facility | level;
    const char* indent   = "Syslog_demo";

    openlog(indent, option, facility);

    syslog(priority, "This is my first log, a socket connection triggerd here\n");
    if(errno) {
        perror("syslog");
        /* fprintf(stderr, "errno=%d, Msg: %s", errno, strerror(errno)); */
    }

    closelog();

    return EXIT_SUCCESS;
}
