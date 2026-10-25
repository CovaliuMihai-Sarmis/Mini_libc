#ifndef _TIME_H
#define _TIME_H 1

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#endif