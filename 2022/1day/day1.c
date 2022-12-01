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
	int count = 0;  // Line counter (result)
	char c;  // To store a character read from file

	// Get file name from user. The file should be
	// either in current folder or complete path should be provided

	// Open the file
	fp = fopen(argv[1], "r");

	// Check if file exists
	if (fp == NULL){
		printf("Could not open file %s", argv[1]);
		return 0;
	}

	// Extract characters from file and store in character c
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
		count = count + 1;

	// Close the file
	fclose(fp);
	
	int *callos = malloc(count*sizeof(int));
	int head=0;
	fp = fopen(argv[1], "r");
	while((read = getline(&line, &len, fp)) != -1){
		
		callos[head]=atoi(line);
		head++;
	}
	fclose(fp);

	
	clock_t start = clock(), diff;
	int top3[] = {0,0,0};
	head = 0;
	for(int i=0; i<count; i++){
		if (!callos[i]){
			top3insert(top3, head);
			head = 0;
		} else {
			head += callos[i];
		}
		
	}

	diff = clock() - start;
	int msec = diff * 1000000 / CLOCKS_PER_SEC;
	printf("Time taken %d microseconds\n", msec);
	printf("top3 sum: %d\n", top3[0]+top3[1]+top3[2]);
	return 0;
}
