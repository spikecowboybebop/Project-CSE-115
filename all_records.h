void all_records() {
    FILE *rafptr, *paptr;
    rafptr = fopen("reg_no.txt", "r");
    paptr = fopen("pat_name.txt", "r");

    FILE *cptr;
    cptr = fopen("count.txt", "r");
    char count[100];
    fscanf(cptr, "%s", count);
    fclose(cptr);
    int c = atoi(count);

    char r_data[c][100];
    char pat_data[c][100];
    if(rafptr == NULL && paptr == NULL) {
        printf("No Record Found");
    }
    else {
        printf("Data Format:\n\nRegistration Number\nPatient Name\n\n");
        for(int i =0; (fgets(r_data[i], sizeof(r_data), rafptr) != NULL) && (i < c); i++) {
            continue;
        }
        for(int i =0; (fgets(pat_data[i], sizeof(pat_data), paptr) != NULL) && (i < c); i++) {
            continue;
        }
        for(int i = 0; i < c; i++) {
            strcat(r_data[i], pat_data[i]);
            puts(r_data[i]);
        }
    }
}
