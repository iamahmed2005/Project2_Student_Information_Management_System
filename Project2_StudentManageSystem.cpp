#include<stdio.h>
#include<string.h>

int Roll[100];
char Name[100][100];
float CGPA[100];
int n = 0;

void StudentAdding() {

    printf("Enter First Name: ");
    scanf("%s", Name[n]);

    int tempRoll;
    int i;

    for(;;) {

        int same = 0;
        
        printf("Enter a unique roll: ");
        scanf("%d", &tempRoll);

        for (int i = 0; i < n; i++)
        {
            if (Roll[i] == tempRoll)
            {
                printf("The roll already exists. Please try again.\n");
                same = 1;
                break;
            }
        }
        
        if (same == 0)
        {
            Roll[n] = tempRoll;
            break;
        }
    }

    printf("Enter your CGPA: ");
    scanf("%f", &CGPA[n]);

    n++;
    printf("Student has been added.\n");
}

void StudentDeletion() {

    int rollDel;
    int Found = 0;

    printf("Enter a roll to delete from your system: ");
    scanf("%d", &rollDel);

    for (int i = 0; i < n; i++)
    {
        if (Roll[i] == rollDel)
        {
            for (int j = i; j < n-1; j++)
            {
                strcpy(Name[j], Name[j+1]);
                Roll[j] = Roll[j+1];
                CGPA[j] = CGPA[j+1];
            }
            n--;
            Found = 1;
            printf("Student Deleted Successfully.\n");
            break;
        }
    }
    
    if (Found == 0)
    {
        printf("Given roll is not found.\n");
    }
}

void SearchUsingName() {

    char item[100];
    int Found = 0;

    printf("Enter name to search: ");
    scanf("%s", item);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(Name[i], item) == 0)
        {
            printf("Student Found: %s  --  Roll:%d  --  CGPA:%.2f\n", Name[i], Roll[i], CGPA[i]);
            Found = 1;
            break;
        }   
    }

    if (Found == 0)
    {
        printf("Provided name is not found.\n");
    }  
}

void SearchUsingRoll() {

    int KEY;
    int found = 0;

    printf("Enter a roll number to search: ");
    scanf("%d", &KEY);

    for (int i = 0; i < n; i++)
    {
        if (Roll[i] == KEY)
        {
            printf("Student Found: %s  --  Roll:%d  --  CGPA:%.2f\n", Name[i], Roll[i], CGPA[i]);
            found = 1;
            break;
        }  
    }
    
    if (found == 0)
    {
        printf("Provided roll is not found.\n");
    }
}

void CountStudent() {
    
    printf("Total number of students: %d\n", n);

}

void Updation() {

        int target;
        int found = 0;
        
        printf("Enter the roll of the student to further updation: ");
        scanf("%d", &target);

        for (int i = 0; i < n; i++)
        {
            if (Roll[i] == target)
            {
                found = 1;

                int choice;
            printf("1.Update First Name\n");
            printf("2.Update student's CGPA\n");
            printf("3.Exit\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter a new name: ");
                scanf("%s", Name[i]);
                break;
            case 2:
                printf("Enter new CGPA: ");
                scanf("%f", &CGPA[i]);
                break;
            case 3:
                printf("Exiting from updation.");
                break;
            
            default:
                printf("Choice is Invalid. Please try again.\n");
            }
            
            }
        }
        if (found == 0)
        {
            printf("Student not found.\n");
        }
        
    }


void StudentDisplay() {

    if (n == 0)
    {
        printf("No student has been saved.\n");
        return;
    }

    //swapping part
     for (int i = 0; i < n-1; i++)    
     {
          for (int j = 0; j < n-1-i; j++)    
          {
               if (strcmp(Name[j], Name[j+1]) > 0)   
               {
                    //swap the names:
                    char TempName[100];
                    strcpy(TempName, Name[j]);
                    strcpy(Name[j], Name[j+1]);
                    strcpy(Name[j+1], TempName);

                    //Swap the rolls:
                    int tempRoll = Roll[j];
                    Roll[j] = Roll[j+1];
                    Roll[j+1] = tempRoll;

                    //Swap cgpa:
                    float TempCGPA = CGPA[j];
                    CGPA[j] = CGPA[j+1];
                    CGPA[j+1] = TempCGPA;
               }
          }    
     }
    
    printf("\n All Student Informations: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s  --  Roll:%d  --  CGPA:%.2f\n", i+1, Name[i], Roll[i], CGPA[i]);
    }
}


int main() {

    printf("\n---Welcome to Student Information Management System---\n");

    int Choice;

    for(;;) {

        printf("\nStudent Information Management System Menu:\n");
        printf("1. Add a Student\n");
        printf("2. Delete a Student\n");
        printf("3. Search a Student using FirstName\n");
        printf("4. Search a Student using Roll\n");
        printf("5. Update student's information\n");
        printf("6. Count total number of students in system\n");
        printf("7. Display Student\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &Choice);
        
        switch (Choice)
        {
        case 1:
            StudentAdding();
            break;
        case 2:
            StudentDeletion();
            break;
        case 3:
            SearchUsingName();
            break;
        case 4:
           SearchUsingRoll();
            break;
        case 5:
            Updation();
            break;
        case 6:
            CountStudent();
            break;
        case 7:
            StudentDisplay();
            break;
        case 8:
            printf("\n--Exiting from Student Management System--");
        return 0;
        
        default:
            printf("Choice is Invalid. Please try again.\n");
        }
    }
    return 0;
}