#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void validate_name(char name[],int *flag,AddressBook *addressBook);
void validate_phone(char phn[],int *flag,AddressBook *addressBook);
void validate_email(char email[],int *flag,AddressBook *addressBook);

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    int SortChoice;
    int flag=1;
    while(flag)
    {
        printf("\n1.List all contacts\n2.List name\n3.List by phone.no\n4.List by email ID\n");
        printf("\nENTER CHOICE : ");
        scanf("%d",&SortChoice);
        switch(SortChoice)
        {
            case 1:
            {
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
                flag=0;
                break;
            }
            case 2:
            {
                char word[50];
                int j=1;
                printf("\nENTER NAME : ");
                scanf("%s",word);
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    int n=strlen(word);
                    if(strncasecmp(addressBook->contacts[i].name,word,n)==0)
                    {
                        printf("%d\t%s\t%s\t%s\n",j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        j++;
                    }
                }
                flag=0;
                break;
            }
            case 3:
            {
                char word[50];
                int j=1;
                printf("\nENTER PHN.NO : ");
                scanf("%s",word);
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    int n=strlen(word);
                    if(strncasecmp(addressBook->contacts[i].phone,word,n)==0)
                    {
                        printf("%d\t%s\t%s\t%s\n",j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        j++;
                    }
                }
                flag=0;
                break;
            }
            case 4:
            {
                char word[50];
                int j=1;
                printf("\nENTER EMAIL ID : ");
                scanf("%s",word);
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    int n=strlen(word);
                    if(strncasecmp(addressBook->contacts[i].email,word,n)==0)
                    {
                        printf("%d\t%s\t%s\t%s\n",j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        j++;
                    }
                }
                flag=0;
                break;
            }
            default :
            {
                printf("\n\nINVALID INPUT!!!");
            }
        }
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[50];
    int flag=1;
    while(flag)
    {
        printf("ENTER NAME : ");
        scanf(" %[^\n]",name);
        validate_name(name,&flag,addressBook);
    }

    //Enter phone number and verify

    char phn[15];
    flag=1;
    while(flag)
    {
        printf("ENTER PHONE NUMBER : ");
        scanf("%s",phn);
        validate_phone(phn,&flag,addressBook);
    }

    //Enter email ID and verify
    char email[50];
    flag=1;
    while(flag)
    {
        printf("ENTER EMAIL ID : ");
        scanf("%s",email);
        validate_email(email,&flag,addressBook);
    }

    //Enter the contact into the addressbook

    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phn);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    printf("\nCONTACT ENTERED SUCCESSFULLY....\n\n");
    (addressBook->contactCount)++;
}

void searchContact(AddressBook *addressBook,int index_array[],int *size) 
{
    /* Define the logic for search */
    if((addressBook->contactCount)==0)
    {
        printf("EMPTY CONTACT LIST!!!\n\n");
        return;
    }
    int selection,flag=1;
    char name[50],phn[12],email[50];
    while(flag)
    {
        printf("\n\n1.Search by name\n2.Search by phn.no\n3.Search by Email ID");
        printf("\n\nENTER CHOICE : ");
        scanf("%d",&selection);
        __fpurge(stdin);
        switch(selection)
        {
            case 1:
            {
                printf("ENTER NAME : ");
                scanf(" %[^\n]",name);
                *size=0;
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasestr(addressBook->contacts[i].name,name))
                    {
                        flag=0;
                        index_array[*size]=i;
                        (*size)++;
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    }
                }
                if(flag)
                {
                    printf("CONTACT NOT FOUND!!!\n\n");
                    flag=0;
                }
                break;
            }
            case 2:
            {
                printf("ENTER PHONE : ");
                scanf("%s",phn);
                *size=0;
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasestr(addressBook->contacts[i].phone,phn))
                    {
                        flag=0;
                        index_array[*size]=i;
                        (*size)++;
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    }
                }
                if(flag)
                {
                    printf("CONTACT NOT FOUND!!!\n\n");
                    flag=0;
                }
                break;
            }
            case 3:
            {
                printf("ENTER EMAIL ID : ");
                scanf("%s",email);
                *size=0;
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasestr(addressBook->contacts[i].email,email))
                    {
                        flag=0;
                        index_array[*size]=i;
                        (*size)++;
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    }
                }
                if(flag)
                {
                    printf("CONTACT NOT FOUND!!!\n\n");
                    flag=0;
                }
                break;
            }
            default :
            {
                printf("INVALID INPUT!!!\n\n");
            }

        }
    }
}

void editContact(AddressBook *addressBook,int index_array[],int *size)
{
	/* Define the logic for Editcontact */
    if((addressBook->contactCount)==0)
    {
        printf("EMPTY CONTACT LIST!!!\n\n");
        return;
    }
    searchContact(addressBook,index_array,size);
    int index,choice,flag=1;
    char name[50],phn[12],email[50];
    while(flag)
    {
        printf("\nENTER SERIAL NO. TO BE EDITED : ");
        scanf("%d",&index);
        __fpurge(stdin);
        index--;
        for(int i=0;i<*size;i++)
        {
            if(index==index_array[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("ERROR : ENTER PROPER INDEX!!!\n\n");
        }
    }
    flag=1;
    while(flag)
    {
        printf("\n\n1.Edit name\n2.Edit phn no.\n3.Edit email ID\n\n ENTER CHOICE : ");
        scanf("%d",&choice);
        __fpurge(stdin);
        switch(choice)
        {
            case 1:
            {
                while(flag)
                {
                    printf("\nENTER NEW NAME : ");
                    scanf(" %[^\n]",name);
                    validate_name(name,&flag,addressBook);
                    printf("\n\nNAME UPDATED SUCCESSFULLY\n\n");
                }
                strcpy(addressBook->contacts[index].name,name);
                break;
            }
            case 2:
            {
                while(flag)
                {
                    printf("\nENTER NEW NUMBER : ");
                    scanf("%s",phn);
                    validate_phone(phn,&flag,addressBook);
                    printf("\n\nPHN.NO UPDATED SUCCESSFULLY\n\n");
                }
                strcpy(addressBook->contacts[index].phone,phn);
                break;
            }
            case 3:
            {
                while(flag)
                {
                    printf("\nENTER NEW EMAIL ID : ");
                    scanf("%s",email);
                    validate_email(email,&flag,addressBook);
                    printf("\n\nEMAIL ID UPDATED SUCCESSFULLY\n\n");
                }
                strcpy(addressBook->contacts[index].email,email);
                break;
            }
            default :
            {
                printf("INVALID OPTION!!!\n\n");
            }
        }
    }


    
}

void deleteContact(AddressBook *addressBook,int index_array[],int *size)
{
	/* Define the logic for deletecontact */
    if((addressBook->contactCount)==0)
    {
        printf("EMPTY CONTACT LIST!!!\n\n");
        return;
    }
    searchContact(addressBook,index_array,size);
    int index,choice,flag=1;
    char name[50],phn[12],email[50];
    if((*size)>1)
    {
        while(flag)
        {
            printf("\nENTER SERIAL NO. TO BE DELETED : ");
            scanf("%d",&index);
            __fpurge(stdin);
            index--;
            for(int i=0;i<*size;i++)
            {
                if(index==index_array[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                printf("ERROR : ENTER PROPER INDEX!!!\n\n");
            }
        }
    }
    else
    {
        index=index_array[0];
    }
    for(int i=index;i<(addressBook->contactCount)-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    (addressBook->contactCount)--;
}

//FUNCTION TO VALIDATE NAME
void validate_name(char name[],int *flag,AddressBook *addressBook)
{
    int i;
    for(i=0;name[i]!=0;i++)
        {
            if(name[i]==' ')
            {
                continue;
            }
            else if(isalpha(name[i])==0)
            {
                printf("PLEASE ENTER A VALID NAME!!!\n\n");
                break;
            }
        }
        if(name[i]=='\0')
        {
            *flag=0;
        }
}
//FUNCTION TO VALIDATE EMAIL
void validate_phone(char phn[],int *flag,AddressBook *addressBook)
{
     int i;
     for(i=0;phn[i]!=0;i++)
        {
            if(phn[i]<48||phn[i]>57)
            {
                break;
            }
        }
        if(i==10&&phn[i]==0)
        {
            // Check if the phone number is already existing or not
            if((addressBook->contactCount)==0)
            {
                 *flag=0;
            }
            for(i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].phone,phn)==0)
                {
                    printf("***");
                    *flag=1;
                    break;
                }
                *flag=0;
            }
            if(*flag)
            {
                printf("CONTACT ALREADY EXIST!!!\n\n");
            }
        }
        else
        {
            printf("PLEASE ENTER VALID 10 DIGIT NUMBER!!!\n\n");
        }
}

//FUNCTION TO VALIDATE EMAIL ID
void validate_email(char email[],int *flag,AddressBook *addressBook)
{
    int i,j=0;
    char *str1=strstr(email,".com");
    char *str2=strchr(email,'@');
    if(str1 && str2 && isalnum(*(str1-1)) && isalnum(*(str2-1)))
    {
        if((addressBook->contactCount)==0)
        {
             *flag=0;
        }
        while(email[j]!='@')
        {
            if(email[j]>=97&&email[j]<=122)
            {
                j++;
                *flag=0;
            }
            else
            {
                printf("##");
                *flag=1;
                break;
            }
        }
        j++;
        while(email[j]!='.')
        {
            if((email[j]>=97&&email[j]<=122))
            {
                j++;
                *flag=0;
            }
            else
            {
                printf("&&");
                *flag=1;
                break;
            }
        }
        if(*flag==0)
        {
            for(i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].email,email)==0)
                {
                    *flag=1;
                    printf("EMAIL ID ALREADY EXIST!!!\n\n");
                    break;
                }
                else
                {
                    *flag=0;
                }
            }
        }
        else
        {
            printf("ENTER VALID EMAIL ID!!!\n\n");
        }     
    }
     else
    {
        printf("ENTER VALID EMAIL ID!!!\n\n");
    }
}