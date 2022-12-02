#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/libvec.h"

// a roc b paper c scissors
// response 2nd collumn
#if 0
// part 1
int main(int argc, char* argv[]){
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	long unsigned int head = 0;
	fp = fopen(argv[1], "r");
	while((read = getline( &line, &len, fp)) != 1){
		int add = 0;
		printf("%s", line);
		line[0]-=65;
		line[2]-=88;

		add += line[2]+1;

		if(line[2]==line[0]){
			add +=3;
		} else if (line[2]==(line[0]+1)%3){
			add +=6;
		}
		printf("--%d %d head: %d\n", (int)line[0], (int) line[2], add);
		head += add;
		
	}

	printf("%ld\n", head);
	return 0;
}
#else
// part 2
int main(int argc, char* argv[]){
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	long unsigned int head = 0;
	fp = fopen(argv[1], "r");
	while((read = getline( &line, &len, fp)) != 1){
		int add = 0;
		printf("%s", line);
		line[0]-=65;
		line[2]-=88;

		add += line[2]*3;
		switch(line[2]){
			case 0:
				add +=(line[0]+2)%3 +1;
			break;
			case 1:
				add +=line[0]+1;

			break;
			case 2:
				add +=(line[0]+1)%3 +1;

			break;
		}

		printf("--%d %d head: %d\n", (int)line[0], (int) line[2], add);
		head += add;
		
	}

	printf("%ld\n", head);
	return 0;
}
#endif
