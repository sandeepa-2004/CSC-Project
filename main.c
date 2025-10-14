#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#define Max_Cities 30
int citycount =6;
int distanceCount = 6;
void storeCities(char cityData[][20],int count);
void distanceData(int distance[][30],char cityData[][20],int count);
int main()
{
    int choice,i,j;
    char cities[30][20];
    int distance[Max_Cities][Max_Cities];

    char defaultcities[7][20] = {"kalutara", "jaffna", "colombo", "galle","matara","gampaha","kandy"};
    int defaultdistance[7][7]= {{0,400,40,45,79,100,150},{400,0,350,450,500,300,200},{40,350,0,200,250,40,100},{79,450,200,0,50,240,300},{100,500,250,50,0,300,400},{100,300,40,240,300,0,80},{150,200,100,300,400,80,0}};

    for (i = 0; i < 7; i++)
    {
        snprintf(cities[i], 20, "%s", defaultcities[i]);
    }


    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            distance[i][j] = defaultdistance[i][j];
        }
    }



    printf("1. City management\n");
    printf("2. Distance management\n");
    printf("3. Vehicale Management\n");
    printf("4. Delivery Request Handling\n");
    printf("5. Cast,Time and Fuel Calculation\n");
    printf("6. Delivary Records\n");
    printf("7. Finding the Least-cost Route (Least-Distance)\n");
    printf("8. Performance Reports\n");
    printf("9. exit\n\n");

    while(1)
    {
        printf("Enter your chioce: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

            storeCities(cities,citycount);
            break;
        case 2:
            distanceData(distance,cities,distanceCount);
            break;

        }



    }
    return 0;
}

void storeCities(char cityData[][20],int count)
{

    char choice1,cityName[20];
    int select;
    int i,j;
    printf("1.Add a new City\n");
    printf("2.Rename City\n");
    printf("3.delete City\n");
    printf("4. excit\n\n");
    while(1)
    {


        printf("Enter your chioce: ");
        scanf("%d",&select);

        switch(select)
        {
        case 1:
            do
            {
                printf("Add a new city : ");
                scanf("%s",cityData[count]);
                count++;
                printf("Do you like to add another city(y/n):");
                scanf(" %c",&choice1);
            }
            while(choice1== 'Y'||choice1 =='y');
            break;
        case 2:


            printf("enter the name of the city:");
            scanf("%s",cityName);
            for(i=0; i<count; i++)
            {
                if(strcmp(cityData[i],cityName)==0)
                {

                    printf("enter the new name of city: ");
                    scanf("%S",cityData[i]);
                    printf("City renamed successfully!\n");
                    if (i == count)
                        printf("No city named %s found.\n", cityName);

                    break;


                }


            }

        case 3:
            printf("enter the name of the city to delete: ");
            scanf("%s",cityName);
            for (i = 0; i <=count; i++)
            {
                if (strcmp(cityData[i],cityName) == 0)
                {

                    for (j = i; j <count- 1; j++)
                    {
                        strcpy(cityData[j], cityData[j + 1]);
                    }
                    count--;
                    printf("%s has been successfully deleted.\n", cityName);
                    break;
                }
            }
            if (i == count)
                printf("No city named %s found.\n", cityName);
            break;

        case 4:
            return;
            break;
        default:
            printf("Invalid choice! Try again.\n");

        }


    }


}


void distanceData(int distance[][Max_Cities],char cityData[][20], int count)
{
    char fcity[20],scity[20],c;
    int findex=-1,sindex=-1,dis,i,j;
    printf("do you want to input distance between two cities(y/n): ");
    scanf(" %c",&c);
    if(c=='y'||c=='Y')
    {

        printf("enter the first city:");
        scanf("%s",fcity);
        printf("enter the second city:");
        scanf("%s",scity);

        for(i=0; i<count; i++)
        {
            if(strcmp(cityData[i],fcity))
            {
                findex =i;
            }


            if(strcmp(cityData[i],scity))
            {
                sindex =i;
            }

            if (findex == -1 || sindex == -1)
            {
                printf("One or both city names not found.\n");
                return;
            }


        }
        if (distance[findex][sindex] ==0)
        {
            printf("enter the distance: ");
            scanf("%d",&dis);
            distance[findex][sindex] = dis;
            distance[sindex][findex] = dis;
            printf("Distance between %s and %s set to %d km.\n", fcity, scity, dis);
        }

        else
        {
            printf("The distance between %s and %s already exists (%d km).\n",fcity, scity, distance[findex][sindex]);
        }
    }

    printf("do you want to delete distance between two cities(y/n): ");
    scanf(" %c",&c);
    if(c=='y'||c=='Y')
    {

        printf("enter the first city:");
        scanf("%s",fcity);
        printf("enter the second city:");
        scanf("%s",scity);
        findex = -1;
        sindex = -1;
        for(i=0; i<count; i++)
        {
            if(strcmp(cityData[i],fcity))
                findex =i;

            if(strcmp(cityData[i],scity))

                sindex =i;

        }
        if (findex == -1 || sindex == -1)
        {
            printf("One or both city names not found.\n");
            return;
        }
        if (distance[findex][sindex] != 0)
        {
            distance[findex][sindex] = 0;
            distance[sindex][findex] = 0;
            printf("Distance between %s and %s deleted.\n", fcity, scity);
        }
        else
        {
            printf("No distance recorded between %s and %s.\n", fcity, scity);
        }

    }

printf("\n\n");
    printf("                      -------Distance table------\n\n");
printf("%-12s","");
    for(i=0;i<=count;i++){
        printf("%-12s", cityData[i]);
    }
    printf("\n");
     for (i = 0; i <=count; i++) {
        printf("%-12s", cityData[i]);

        for (j = 0; j <= count; j++) {
            printf("%-12d", distance[i][j]);
        }
        printf("\n");
    }
printf("\n\n");
        }

