#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#define Max_Cities 30
int count =7;

void storeCities(char cityData[][20],int count,int distance[][30]);
void distanceData(int distance[][30],char cityData[][20],int count);
void displayVehicleData(char type[][20],int data[][4]);
void diliveryCalculatoin(int distance[][30],int count);



int main()
{
    int choice,i,j;
    char cities[30][20];
    int distance[Max_Cities][Max_Cities];
    char Vehicletype[3][20]= {"van","truck","lorry"};
    int vehicleData[3][4] = {{1000,30,60,12},{5000,40,50,16},{10000,80,45,4}};

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

    printf("4. Cast,Time and Fuel Calculation\n");
    printf("5. Delivary Records\n");
    printf("6. Finding the Least-cost Route (Least-Distance)\n");
    printf("7. Performance Reports\n");
    printf("8. exit\n\n");

    while(1)
    {
        printf("Enter your chioce: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

            storeCities(cities,count,distance);
            break;
        case 2:
            distanceData(distance,cities,count);
            break;
        case 3:
            displayVehicleData(Vehicletype,vehicleData);
            break;
        case 4:
            diliveryCalculatoin( distance, count);
            break;

        }



    }
    return 0;
}

void storeCities(char cityData[][20],int count,int distance[][30])
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
                for (i = 0; i <=count; i++)
        {
            distance[count][i] = 0;
            distance[i][count] = 0;
        }
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
                    scanf("%s",cityData[i]);
                    printf("City renamed successfully!\n");
                    break;


                }


            }
            if (i == count)
                        printf("No city named %s found.\n", cityName);

                    break;


        case 3:
            printf("enter the name of the city to delete: ");
            scanf("%s",cityName);
            for (i = 0; i <count; i++)
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
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (distance[i][j] < 0) distance[i][j] = 0;  // optional, just safety
        }
    }
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



        }
            if (findex == -1 || sindex == -1)
            {
                printf("One or both city names not found.\n");
                return;
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
            if(strcmp(cityData[i],fcity)==0)
                findex =i;

            if(strcmp(cityData[i],scity)==0)

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

    printf("index No.");
    printf("%-24s","");
    for(i=0; i<=count; i++)
    {
        printf("%-12s", cityData[i]);
    }
    printf("\n");
    for (i = 0; i <=count; i++)
    {
        printf("%-12d",i);
        printf("%-24s", cityData[i]);

        for (j = 0; j <= count; j++)
        {
            printf("%-12d", distance[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


void displayVehicleData(char type[][20],int data[][4])
{
    printf("Type      Capacity(kg)     Rate Per kM(LKR)      Avg Speed(km/h)     Fual Efficiency (km/I)\n\n");
    for(int i=0; i<3; i++)
    {
        printf("%-12s %-12d %-30d %-24d %-24d \n",type[i],data[i][0],data[i][1],data[i][2],data[i][3]);

    }



    printf("\n\n");
}


void diliveryCalculatoin(int distance[][30],int count)
{
    int sourceIndex,destinationIndex,type;
    float weight;
    printf("=================================================================================\n\n");
    printf("DELIVERY COST ESTIMATION\n\n");
    printf("---------------------------------------------------------------------------------\n\n");

    printf("enter the source city index:");
    scanf("%d",&sourceIndex);
    printf("enter the destination city index:");
    scanf("%d",&destinationIndex);
    printf("enter the weight of the item(kg):");
    scanf("%f",&weight);
    printf("Enter the type:");
    scanf("%d",&type);
    printf("----------------------------------------------------------------------------------\n\n");
    float DCost,FuelConsump,FuelCost,totalCost,profitCal,finalCharge,diliveryTime;

    if(type == 1)
    {
        DCost = distance[sourceIndex][destinationIndex]*30*(1+weight*1.0/10000);
        diliveryTime = distance[sourceIndex][destinationIndex]/60;
        FuelConsump=distance[sourceIndex][destinationIndex]/12;

    }

    else if(type == 2)
    {
        DCost = distance[sourceIndex][destinationIndex]*40*(1+weight*1/10000);
        diliveryTime = distance[sourceIndex][destinationIndex]/50;
        FuelConsump=distance[sourceIndex][destinationIndex]/6;

    }

    else if(type == 3)
    {
        DCost=distance[sourceIndex][destinationIndex]*80*(1+weight*1/10000);
        diliveryTime = distance[sourceIndex][destinationIndex]/45;
        FuelConsump=distance[sourceIndex][destinationIndex]/4;

    }
    else
    {
        printf("Invalid type!\n");
        return;
    }
    FuelCost=FuelConsump*310.0;
    totalCost=DCost+FuelCost;
    profitCal=totalCost*0.25;
    finalCharge = totalCost+profitCal;

    printf("Based Cost:%.3f\n",DCost);
    printf("Fuel Used :%.3f\n",FuelConsump);
    printf("Fuel Cost :%.3f\n",FuelCost);
    printf("Operational Cost:%.3f\n",totalCost);
    printf("profit:%.3f\n",profitCal);
    printf("Customer Charge:%.3f\n",finalCharge);
    printf("Estimated Time:%.3f\n",diliveryTime);
    printf("===================================================================================\n\n");

}
