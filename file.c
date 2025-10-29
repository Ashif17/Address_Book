#include <stdio.h>
#include<string.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        for(int j=i+1;j<(addressBook->contactCount);j++)
        {
            if(strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
            {
                Contact temp=addressBook->contacts[i];
                addressBook->contacts[i]=addressBook->contacts[j];
                addressBook->contacts[j]=temp;
            }
        }
    }
    FILE *fptr=fopen("addressBook.csv","w");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr=fopen("addressBook.csv","r");
    if(fptr==NULL)
    {
        printf("\n\nFILE NOT EXIST!!!");
        return;
    }
    while((fscanf(fptr,"%49[^,],%19[^,],%49[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email))==3)
    {
        addressBook->contactCount++;
    }
    fclose(fptr);
}
