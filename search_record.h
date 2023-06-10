void search_record(struct patient_data *ptr) {
    printf("Enter Registration Number - ");
    gets((ptr + 0)->reg_no);

    printf("Enter Patient Name - ");
    gets((ptr + 0)->pat_name);

    char fname[100];
    strcpy(fname, (ptr + 0)->reg_no);
    strcat(fname, (ptr + 0)->pat_name);
    strcat(fname, ".txt");

    FILE *fptr;
    fptr = fopen(fname, "r");

    if(fptr == NULL) {
        printf("There is no record for %s(%s)", (ptr + 0)->pat_name, (ptr + 0)->reg_no);
        fclose(fptr);
    }
    else {
        printf("\nRecord found for %s(%s)\n\n", (ptr + 0)->pat_name, (ptr + 0)->reg_no);

        char data[18][200];
        for(int i =0; (fgets(data[i], sizeof(data), fptr) != NULL) && (i < 18); i++) {
            continue;
        }
        strcpy((ptr + 0)->reg_no, data[0]);
        strcpy((ptr + 0)->pat_name, data[1]);
        strcpy((ptr + 0)->guar_name, data[2]);
        strcpy((ptr + 0)->gen, data[3]);
        strcpy((ptr + 0)->bgrp, data[4]);
        strcpy((ptr + 0)->age, data[5]);
        strcpy((ptr + 0)->address[0], data[6]);
        strcpy((ptr + 0)->address[1], data[7]);
        strcpy((ptr + 0)->address[2], data[8]);
        strcpy((ptr + 0)->address[3], data[9]);
        strcpy((ptr + 0)->phn, data[10]);
        strcpy((ptr + 0)->dis_name, data[11]);
        strcpy((ptr + 0)->doc_name, data[12]);
        strcpy((ptr + 0)->his_desc, data[13]);
        strcpy((ptr + 0)->date_treat, data[14]);
        strcpy((ptr + 0)->treat_given, data[15]);
        strcpy((ptr + 0)->med_pres, data[16]);

        printf("Registration Number - ");
        puts((ptr + 0)->reg_no);

        printf("Patient Name - ");
        puts((ptr + 0)->pat_name);

        printf("Patient's Guardian Name - ");
        puts((ptr + 0)->guar_name);

        printf("Patient's Gender - ");
        puts((ptr + 0)->gen);

        printf("Patient's Blood Group - ");
        puts((ptr + 0)->bgrp);

        printf("Patient's Age - ");
        puts((ptr + 0)->age);

        printf("Patient's Address -\n");
        printf("\tHouse No - ");
        puts((ptr + 0)->address[0]);

        printf("\tStreet - ");
        puts((ptr + 0)->address[1]);

        printf("\tCity - ");
        puts((ptr + 0)->address[2]);

        printf("\tState - ");
        puts((ptr + 0)->address[3]);

        printf("Phone Number - ");
        puts((ptr + 0)->phn);

        printf("Disease Name - ");
        puts((ptr + 0)->dis_name);

        printf("Doctor's Name - ");
        puts((ptr + 0)->doc_name);

        printf("History - ");
        puts((ptr + 0)->his_desc);

        printf("Treatment Date - ");
        puts((ptr + 0)->date_treat);

        printf("Treatment Given - ");
        puts((ptr + 0)->treat_given);

        printf("Medicine Prescribed - ");
        puts((ptr + 0)->med_pres);

        fclose(fptr);
    }

}
