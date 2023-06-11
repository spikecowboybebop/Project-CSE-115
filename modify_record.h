void modify_record(struct patient_data *ptr) {
	printf("Enter Registration Number - ");
	gets((ptr + 0)->reg_no);
	printf("Enter Patient Name - ");
	gets((ptr + 0)->pat_name);
	char fname[100];
	strcpy(fname, (ptr+0)->reg_no);
	strcat(fname, (ptr+0)->pat_name);
	strcat(fname, ".txt");

	FILE *fptr;
	fptr = fopen(fname, "r");

	if(fptr == NULL) {
		printf("No record found for %s(%s)\n", (ptr+0)->pat_name, (ptr+0)->reg_no);
	}
	else {
		printf("Record Found for %s(%s)\n", (ptr+0)->pat_name, (ptr+0)->reg_no);

		char data[18][200];
		for(int i = 0; (fgets(data[i], sizeof(data), fptr) && (i < 18) ); i++) {
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

    fclose(fptr);

    printf("[Enter 1] - Modify Patient's Name\n");
    printf("[Enter 2] - Modify Patient's Guardian's Name\n");
    printf("[Enter 3] - Modify Patient's Gender\n");
    printf("[Enter 4] - Modify Patient's Blood Group\n");
    printf("[Enter 5] - Modify Patient's Age\n");
    printf("[Enter 6] - Modify Patient's House No\n");
    printf("[Enter 7] - Modify Patient's Address Street\n");
    printf("[Enter 8] - Modify Patient's Address City\n");
    printf("[Enter 9] - Modify Patient's Address State\n");
    printf("[Enter 10] - Modify Patient's Phone\n");
    printf("[Enter 11] - Modify Patient's Disease Name\n");
    printf("[Enter 12] - Modify Patient's Doctor's Name\n");
    printf("[Enter 13] - Modify Patient's History(Description)\n");
    printf("[Enter 14] - Modify Patient's History(Treatment Date)\n");
    printf("[Enter 15] - Modify Patient's History(Treatment Given)\n");
    printf("[Enter 16] - Modify Patient's History(Medicine Prescribed)\n");
    
    FILE *dfptr;
    dfptr = fopen(fname, "w+");

    int a;
    printf("Choice: ");
    scanf("%d", &a);
    fflush(stdin);

    switch(a) {
        case 1:
            printf("Enter Patient's Name - ");
            gets((ptr + 0)->pat_name);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "\n%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 2:
            printf("Enter Patient's Guardian's Name - ");
            gets((ptr + 0)->guar_name);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "\n%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 3:
            printf("Enter Patient's Gender - ");
            gets((ptr + 0)->gen);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "\n%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 4:
            printf("Enter Patient's Blood Group - ");
            gets((ptr + 0)->bgrp);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "\n%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 5:
            printf("Enter Patient's Age - ");
            gets((ptr + 0)->age);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 6:
            printf("Enter Patient's House No - ");
            gets((ptr + 0)->address[0]);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 7:
            printf("Enter Patient's Street - ");
            gets((ptr + 0)->address[1]);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 8:
            printf("Enter Patient's City - ");
            gets((ptr + 0)->address[2]);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 9:
            printf("Enter Patient's Phone Number - ");
            gets((ptr + 0)->address[3]);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "\n%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 10:
            printf("Enter Patient's Disease Name - ");
            gets((ptr + 0)->dis_name);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "\n%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 11:
            printf("Enter Patient's Doctor's Name - ");
            gets((ptr + 0)->doc_name);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "\n%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 12:
            printf("Enter Patient's History(Description) - ");
            gets((ptr + 0)->his_desc);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "\n%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 13:
            printf("Enter Patient's History(Treatment Date) - ");
            gets((ptr + 0)->date_treat);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "\n%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 14:
            printf("Enter Patient's History(Treatment Given) - ");
            gets((ptr + 0)->treat_given);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "\n%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "\n%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "%s", (ptr + 0)->med_pres);

            break;
        case 15:
            printf("Enter Patient's History(Medicine Prescribed) - ");
            gets((ptr + 0)->med_pres);

            fprintf(dfptr, "%s", (ptr + 0)->reg_no);
            fprintf(dfptr, "%s", (ptr + 0)->pat_name);
            fprintf(dfptr, "%s", (ptr + 0)->guar_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->dis_name);
            fprintf(dfptr, "%s", (ptr + 0)->doc_name);
            fprintf(dfptr, "%s", (ptr + 0)->his_desc);
            fprintf(dfptr, "%s", (ptr + 0)->date_treat);
            fprintf(dfptr, "%s", (ptr + 0)->treat_given);
            fprintf(dfptr, "\n%s", (ptr + 0)->med_pres);

            break;
        default:
            printf("Error!\n");
            break;
    }
    fclose(dfptr);
	}
}
