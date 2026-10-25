// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    int ret = nanosleep(&req, &rem);

    if (ret < 0) {
        return rem.tv_sec;
    }

    return 0;
}
