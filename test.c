#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sample_data {
	char reg_no[100];
	char pat_name[100];
};
int main() {
	FILE *cptr;
	cptr = fopen("count.txt", "r");
	char count[100];
	fscanf(cptr, "%s", count);
	fclose(cptr);
	int c = atoi(count);

	struct sample_data *ptr;
	ptr = (struct sample_data *)malloc((c+1) * sizeof(struct sample_data));

	char fname[100];

	printf("Enter reg no - ");
	gets((ptr + 0)->reg_no);
	strcpy(fname, (ptr + 0)->reg_no);
	strcat((ptr+0)->reg_no, "\n");
	printf("Enter Patient Name - ");
	gets((ptr+0)->pat_name);
	strcat(fname, (ptr+0)->pat_name);
	strcat((ptr+0)->pat_name, "\n");

	strcat(fname, ".txt");

    if(remove(fname) == 0) {
        printf("Record Deleted Successfully\n");
    }
    else {
        printf("Delete: Operation failed\n");
    }


	FILE *r, *pn;
	r = fopen("reg_no.txt", "r");
	pn = fopen("pat_name.txt", "r");

	int ind, indt;

	if(r == NULL || pn == NULL) {
		printf("Record not found\n");
	}
	else {
		for(int i = 1; ((fgets((ptr + i)->reg_no, sizeof(ptr), r))!= NULL && (i < (c+1))); i++) {
			if((strcmp((ptr+0)->reg_no, (ptr+i)->reg_no)) != 0) {
				continue;
			}
			else {
				ind = i;
			}
		}
		printf("\n");
		for(int i = 1; ((fgets((ptr + i)->pat_name, sizeof(ptr), pn))!= NULL && (i < (c+1))); i++) {
			if((strcmp((ptr+0)->pat_name, (ptr+i)->pat_name)) != 0) {
				continue;
			}
			else {
				indt = i;
			}
		}
	}
	FILE *wr, *wpn;
	wr = fopen("reg_no.txt", "w");
	wpn = fopen("pat_name.txt", "w");

	for(int i = 1; i < (c+1); i++) {
		if(ind == i) {
			continue;
		}
		else {
			fprintf(wr, "%s", (ptr+i)->reg_no);
		}
	}
	for(int i = 1; i < (c+1); i++) {
		if(indt == i) {
			continue;
		}
		else {
			fprintf(wpn, "%s", (ptr+i)->pat_name);
		}
	}

	FILE *cnptr;
    cnptr = fopen("count.txt", "r");
    char coun[100];
    fscanf(cnptr, "%s", coun);
    fclose(cnptr);
    int e = atoi(coun);
    e--;
    FILE *captr;
    captr = fopen("count.txt", "w");
    fprintf(captr, "%d", e);
    fclose(captr);


	fclose(r);
	fclose(pn);



	return 0;
}