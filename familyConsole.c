/*THIS IS LIKE A MATRIMONY APP, I HAVE GIVEN SOME FAMILY RELATION LIKE -> (HIS/HER NAME, GENDER, FATHER NAME, MOTHER NAME) */
/*IT WILL GIVE YOU YOUR'S COUSIN'S FROM YOUR RELATION */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int got_match = 0;

struct Person
{
    char person_name[20];
    char person_gender[20];
    
    struct Person *person_mom; //
    struct Person *person_dad; // Both points single person only
    
    struct Person *child_head;  // Points to just only one son/daughter
    struct Person *next_sibling;  
    
    struct Person *next;
    
}* person_head = NULL, *person_tail = NULL;

struct Person *check_and_return(char *name, char *gender)
{
    struct Person *ptr = person_head;
    
    while(ptr != NULL)
    {
        if(strcmp(name, ptr->person_name) == 0)
        {
            return ptr;
        }
        
        ptr = ptr->next;
    }
    
    ptr = (struct Person *)malloc(sizeof(struct Person));
    
    strcpy(ptr->person_name, name);
    strcpy(ptr->person_gender, gender);
    
    ptr->person_mom = NULL;
    ptr->person_dad = NULL;
    ptr->next_sibling = NULL;
    ptr->child_head = NULL;
    ptr->next = NULL;
    
    if(person_head == NULL)
    {
        person_head = person_tail = ptr;
    }
    else
    {
        person_tail->next = ptr;
        person_tail = ptr;
    }
    
    return ptr;
}

void push(char *name, char *gender, char *mom, char *dad)
{
    struct Person *ptr = check_and_return(name, gender);
    
    ptr->person_mom = check_and_return(mom, "female");
    
    int flag = 0;
    
    if((ptr->person_mom)->child_head == NULL)
    {
        (ptr->person_mom)->child_head = ptr;
        ptr->next_sibling = NULL;
        flag = 1;
    }
    else
    {
        struct Person *append_sibling = (ptr->person_mom)->child_head;
        
        while(append_sibling ->next_sibling != NULL)
        {
            append_sibling = append_sibling->next_sibling;
        }
        
        append_sibling->next_sibling = ptr;
        ptr->next_sibling = NULL;
    }
    
    ptr->person_dad = check_and_return(dad, "male");
    
    if(flag)
    {
        (ptr->person_dad)->child_head = ptr;
    }
}



void find_partner(char *self_gender, struct Person* grandpa, char *parent_gen )
{
    struct Person *ptr = grandpa->child_head;
    
    while(ptr != NULL)
    {
        if(strcmp(parent_gen, ptr->person_gender) != 0)
        {
            struct Person *current = ptr->child_head;
            
            while(current != NULL)
            {
                if(strcmp(self_gender, current->person_gender) != 0)
                {
                    printf("%s\t", current->person_name);
                    got_match = 1;
                }
                
                current = current->next_sibling;
            }
        }
        
        ptr = ptr->next_sibling;
    }
}


void find_match(char *name)
{
    struct Person *ptr = person_head;
    
    while(ptr != NULL)
    {
        if(strcmp(ptr->person_name, name)== 0)
        {
            break;
        }
        
        ptr = ptr->next;
    }
    if(ptr->person_mom && (ptr->person_mom)->person_mom)
    {
        find_partner(ptr->person_gender, (ptr->person_mom)->person_mom, "female");
    }
    if(ptr->person_dad && (ptr->person_dad)->person_mom)
    {
        find_partner(ptr->person_gender, (ptr->person_dad)->person_mom, "male");
    }
    
   
}

void Display_Members ()
{
    struct Person *ptr = person_head ;
    
    while (ptr != NULL)
    {
        printf ("%s\n%s\n%s\n%s\n\n\n", ptr->person_name, ptr->person_gender, ptr->person_dad->person_name, ptr->person_mom->person_name) ;
        ptr = ptr->next ;
    }
}

int main()
{
    char name[20], gender[20], mom[20], dad[20];
    
    char temp;
    
    
    push ("Praveen", "male", "Sumathi", "Ramar") ;
    push ("Ramar",   "male", "Valli",   "Solai") ;
    push ("Ramya",   "female", "Valli", "Solai") ;
    push ("Sumathi", "female", "Ponkodi", "Ramasamy") ;
    push ("Govindhan", "male", "Ponkodi", "Ramasamy") ;
    push ("Geetha", "female", "Ramya", "Karthick") ;
    push ("Kavi", "female", "Sangeetha", "Govindhan") ;
    push ("Prem Kumar", "male", "Ponkodi", "Ramasamy") ;
    push ("Krishna Priya", "female", "Sathya", "Prem Kumar") ;
    
    
    while(1)
    {
        printf("\n");
    
        printf("\t\tMATRIMONY\n\t\t---------\n\n");
        int choise;
        char temp;
        
        printf("\t1 - Find Match\n");
        printf("\t2 - Display Family Members\n") ;
        printf("\t3 - Exit\n\n");
        
        printf("Enter your choise : ");
        scanf("%d", &choise);
        scanf("%c", &temp);
        
        switch(choise)
        {
            case 1 :
                printf("Enter your name  : ");
                scanf("%[^\n]%*c", name);
                
                //display_all();
                printf("Your matches are : ");
                find_match(name);
                if(got_match == 0)
                {
                    printf("Sorry! No match found");
                }
                got_match = 0;
                break;
            
            case 2 :
                Display_Members () ;
                break ;
            
            case 3 :
                return 0 ;
        }
        
        printf("\n--------------------------------------\n\n");
    }
}
