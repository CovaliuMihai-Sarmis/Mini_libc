// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <internal/io.h>

int puts(char* str){
	size_t len = strlen(str);
	ssize_t ret1 = write(1, str, len);
	if(ret1 < 0) {
		return -1;
	}
	ssize_t ret2 = write(1, "\n", 1);
	if(ret2 < 0) {
		return -1;
	}
	return (int)(ret1 + ret2);
}
