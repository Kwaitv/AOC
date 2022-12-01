#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int top3insert(int *top3, int val){
	if(val > top3[0]){
		top3[2]=top3[1];
		top3[1]=top3[0];
		top3[0]=val;
	} else if (val > top3[1]){
		top3[2]=top3[1];
		top3[1]=val;
	} else if (val > top3[2]){
		top3[2]=val;
	}
	return 0;
}

int main(int argc, char* argv[]){
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	fp = fopen(argv[1], "r");
	
	clock_t start = clock(), diff;
	int top3[] = {0,0,0};
	int head = 0;
	while((read = getline(&line, &len, fp)) != -1){
		if (!atoi(line)){
			top3insert(top3, head);
			head = 0;
		} else {
			head += atoi(line);
		}
		
	}

	diff = clock() - start;
	int msec = diff * 1000000 / CLOCKS_PER_SEC;
	printf("Time taken %d microseconds\n", msec);
	printf("top3 sum: %d\n", top3[0]+top3[1]+top3[2]);
	fclose(fp);
	return 0;
}

