#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#define Max_Cities 30
int count =7;
int deliveryCount = 0;

void storeCities(char cityData[][20],int *count,int distance[][30]);
void distanceData(int distance[][30],char cityData[][20],int count);
void displayVehicleData(char type[][20],int data[][4]);
void diliveryCalculatoin(int distance[][30],int *count,float deliveries[][7], int totalDistance[50]);
void deliveryReport(int count, float deliveries[][7]);
void theLeastCostRoute(int distance[][30],int count,char cityData[][20]);
void performnceReport(int totalDistance[50],float deliveries[][7],int *count);



int main()
{
    int choice,i,j;
    char cities[30][20];
    int distance[Max_Cities][Max_Cities];
    float deliveries[50][7];
    char Vehicletype[3][20]= {"van","truck","lorry"};
    int vehicleData[3][4] = {{1000,30,60,12},{5000,40,50,16},{10000,80,45,4}};
    int totalDistance[50];

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

            storeCities(cities,&count,distance);
            break;
        case 2:
            distanceData(distance,cities,count);
            break;
        case 3:
            displayVehicleData(Vehicletype,vehicleData);
            break;
        case 4:
            diliveryCalculatoin( distance, &deliveryCount,deliveries,totalDistance);
            break;
        case 5:
            deliveryReport(deliveryCount,deliveries);
            break;

        case 6:
            theLeastCostRoute( distance,count,cities);
            break;
        case 7:
            performnceReport(totalDistance,deliveries,&deliveryCount);


        }



    }
    return 0;
}

void storeCities(char cityData[][20],int *count,int distance[][30])
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
                scanf("%s",cityData[*count]);

                for (i = 0; i <=*count; i++)
                {
                    distance[*count][i] = 0;
                    distance[i][*count] = 0;
                }
                 (*count)++;

                printf("Do you like to add another city(y/n):");
                scanf(" %c",&choice1);
            }
            while(choice1== 'Y'||choice1 =='y');
            break;
        case 2:


            printf("enter the name of the city:");
            scanf("%s",cityName);
            for(i=0; i<*count; i++)
            {
                if(strcmp(cityData[i],cityName)==0)
                {

                    printf("enter the new name of city: ");
                    scanf("%s",cityData[i]);
                    printf("City renamed successfully!\n");
                    break;


                }


            }
            if (i == *count)
                printf("No city named %s found.\n", cityName);

            break;


        case 3:
            printf("enter the name of the city to delete: ");
            scanf("%s",cityName);
            for (i = 0; i <*count; i++)
            {
                if (strcmp(cityData[i],cityName) == 0)
                {

                    for (j = i; j <*count- 1; j++)
                    {
                        strcpy(cityData[j], cityData[j + 1]);
                    }
                    (*count)--;
                    printf("%s has been successfully deleted.\n", cityName);
                    break;
                }
            }
            if (i == *count)
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
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count; j++)
        {
            if (distance[i][j] < 0) distance[i][j] = 0;
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
findex = sindex = -1;
        for(i=0; i<count; i++)
        {
            if(strcmp(cityData[i],fcity)==0)
            {
                findex =i;
            }


            if(strcmp(cityData[i],scity)==0)
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
    for(i=0; i<count; i++)
    {
        printf("%-12s", cityData[i]);
    }
    printf("\n");
    for (i = 0; i <count; i++)
    {
        printf("%-12d",i);
        printf("%-24s", cityData[i]);

        for (j = 0; j < count; j++)
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


void diliveryCalculatoin(int distance[][30],int *count,float deliveries[][7], int totalDistance[])
{
    int sourceIndex,destinationIndex,type;
    float weight;
    char choice2;
    do
    {
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
            continue;
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

        deliveries[*count][0]=DCost;
        deliveries[*count][1]=FuelConsump;
        deliveries[*count][2]=FuelCost;
        deliveries[*count][3]=totalCost;
        deliveries[*count][4]=profitCal;
        deliveries[*count][5]=finalCharge;
        deliveries[*count][6]=diliveryTime;
        totalDistance[*count]= distance[sourceIndex][destinationIndex];
        (*count)++;
        printf("Do you want to add another(y/n): ");
        scanf(" %c",&choice2);
    }
    while(choice2 =='y'|| choice2 =='Y');
}

void deliveryReport(int count, float deliveries[][7])
{
    int i;

    printf("-----------delivery Report--------------------\n\n");

    printf("Deliveery No.   Based Cost         Fuel Used        Fuel Cost       Operational Cost          profit         Customer Charge        Estimated Time   \n\n");

    for(i=0; i<count; i++)
    {

        printf("%2d     %18.2f   %15.2f   %15.2f    %15.2f    %15.2f     %15.2f     %18.2f \n",i+1,deliveries[i][0],deliveries[i][1],deliveries[i][2],deliveries[i][3],deliveries[i][4],deliveries[i][5],deliveries[i][6]);
    }


}

void theLeastCostRoute(int distance[][30],int count,char cityData[][20])
{
    int sIndex,dIndex,i,mcity;
    printf("enter the source city index:");
    scanf("%d",&sIndex);
    printf("enter the destination city index:");
    scanf("%d",&dIndex);
if(sIndex >30 || dIndex> 30){
    printf("invalid Index!..Please try Again\n\n");
    return;

}
    int minDistance= distance[sIndex][dIndex];

    for(i=0; i<count; i++)
    {
        if(i!=sIndex && i!=dIndex)
        {
            int newDistance=distance[sIndex][i]+distance[i][dIndex];
            if(newDistance<minDistance)
            {
                minDistance=newDistance;
                mcity =i;
            }
        }

    }


    printf("\n --------LEAST COST ROUTE----------- \n\n");


    if (mcity=-1)
    {
        printf("Best Route: %s -> %s \n",cityData[sIndex],cityData[dIndex]);
    }
    else
    {
        printf("Best Route: %s -> %s -> %s \n",cityData[sIndex],cityData[mcity],cityData[dIndex]);


    }
    printf("Minimum Distance: %d km\n\n", minDistance);


}

void performnceReport(int totalDistance[50],float deliveries[][7],int *count){

printf("\n\n--------REPORTS-----------\n\n\n");

printf("Total Deliveries Completed: %d\n",*count);
int i,totalDis =0;
float totalProfit=0.0,avgTime=0.0;
for(i=0;i<*count;i++){
    totalDis+=totalDistance[i];
    totalProfit+=deliveries[i][4];
    avgTime+=deliveries[i][6];
}
printf("Total Distance Covered: %d km\n",totalDis);
printf("Average Delivery Time : %.2f hrs.\n",avgTime);
printf("Total Revenue And Profit : %.2f LKR\n",totalProfit);

int longestRoute = totalDistance[0];
for(i=0;i<*count;i++ ){
    if(totalDistance[i]>longestRoute)
    longestRoute=totalDistance[i];
}
printf("Longest Route Completed: %d km\n",longestRoute);


int shortestRoute = totalDistance[0];
for(i=0;i<*count;i++ ){
    if(totalDistance[i]<shortestRoute)
    shortestRoute=totalDistance[i];
}
printf("Shortest Route Completed: %d km\n\n\n",shortestRoute);

}
