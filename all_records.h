void all_records(struct patient_data *ptr) {
    FILE *rafptr;
    rafptr = fopen("all_records.txt", "r");

    if(rafptr == NULL) {
        printf("No Record Found");
    }
    else {
        printf("Reg. No\t\tPatient Name\n");
        char c;
        while((c=getc(rafptr))!=EOF) {
            putchar(c);
        }
    }

}
