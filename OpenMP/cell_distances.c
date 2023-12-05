#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

// distance = sqrt(((x2 - x1)**2) + ((y2 - y1)**2) + ((z2 - z1)**2))

int main(int argc, char *argv[]) {

	//const int sz = 100000;
	FILE *file = fopen("cells", "r");
	if (file== NULL) {
		printf("Failed to open file.\n");
		return 1;
	}

	char line[30];
	int64_t lines = 0;
	int sz = 0;
	while (fgets(line, sizeof(line), file) != NULL) {
		//lines++;
		sz++;
	}

	rewind(file);

	double start, end;
	double time;
	int dist;
	int scalingFactor = 100;
	float *x = (float*)malloc(sz * sizeof(float));
	float *y = (float*)malloc(sz * sizeof(float));
	float *z = (float*)malloc(sz * sizeof(float));
	int *instances = (int*)malloc(3466 * sizeof(int));
	bool foundT = false;
	int threads = 0;
	int o = 0;

	if (sscanf(argv[1], "%*[^0-9]%d", &threads) == 1) {
		//printf("Extracted value: %d\n", value);
	} else {
		printf("Integer not found in the string.\n");
	}

	//printf("%d\n", threads);

	omp_set_num_threads(threads);


	//char *buf = malloc(sizeof(short)*sz*24);
	//fread(buf, sz, 24*sizeof(short), file);

	while (fgets(line, sizeof(line), file) != NULL) {
		(sscanf(line, "%f %f %f", &x[o], &y[o], &z[o]));
		o++;
	}

	fclose(file);

	start = omp_get_wtime(); 
	long int i = 0;
	long int j = 0;
	float dx_int;
	float dy_int;
	float dz_int;
#pragma omp parallel for collapse(2) reduction(+:dist,dx_int,dy_int,dz_int,instances[:3466]) 
	for (i = 0; i < sz; i++) {
		for (j = i+1; j < sz; j++) {
			dx_int = x[i] - x[j];
			dy_int = y[i] - y[j];
			dz_int = z[i] - z[j];
			dist = (int)(sqrtf(dx_int * dx_int + dy_int * dy_int + dz_int * dz_int)*100);
			instances[dist]++;
		}
	}
	end = omp_get_wtime();
	time = ((end - start));
	//printf("calculating distances finished, it took %f seconds\n\n", time);

/*	FILE *file2 = fopen("distances.txt", "w");
	if (file2== NULL) {
		printf("Failed to open file.\n");
		return 1;
	} */

	for (int l = 0; l < 3466; l++) {
		if (instances[l] > 0) {
			printf("%05.2f %d\n", (float)l/100, instances[l]);
		}
	}

	//fclose(file2);
	free(instances);

	return 0;

}




