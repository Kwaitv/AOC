#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

CUSTOM

int main(int argc, char* argv[]){
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	long unsigned int head = 0;
	while((read = getline( &line, &len, fp)) != -1){
	}
	 
	printf("ans: %d\n", head);
	return 0;
}
