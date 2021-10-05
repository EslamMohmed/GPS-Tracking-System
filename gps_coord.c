#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "functions_prototype.h"

double convert_string_to_double(char *string)
{
		double dou;
    dou = strtod(string,NULL);
    return dou;
}




double true_coord (double in)
{
    int mid= (in/100);
    in  -= (mid*100);
    in = (in/60);
    return(mid+in);
    
    
}



double gps_coord_lat (char *gps_data1)
{
    char *gps_data =gps_data1;
   char *crop;
   double latitude;
	 int i;
   crop = strtok(gps_data, ",");
  
	for (i=0;i<=100;i++)
	{
	    
  crop = strtok(NULL, ",");
	    if(i==1)
	    {
	       latitude=convert_string_to_double(crop);

	    }

	}	     
	return (latitude);
}


double gps_coord_long (char *gps_data2)
{
    char *gps_data = gps_data2;
	int j;
   char *crop;
   double longitude;
   crop = strtok(gps_data, ",");
	 for ( j=0;j<=100;j++)
	{
	    
  crop = strtok(NULL, ",");
	    if(j==3)
	    {
	       longitude=convert_string_to_double(crop);
	       

	    }

	}	     
      
	return (longitude);
}


double GPGGA_lat(char *gps_data)
{
  char *crop1;
  //char *crop2;
	int i;
	double x;
	double true_lat ;
	
    crop1 = strtok(gps_data, "$");
    //crop2 = crop1;

         
	for (i=0;i<=100;i++)
	{
	    
        crop1 = strtok(NULL, "$");
	    if(i==17)
	    {

	     x = gps_coord_lat(crop1);
	     true_lat = true_coord(x);
	    

	    }
	    

	}		
	return (true_lat);
}

double GPGGA_long(char *gps_data)
{
  char *crop1;
  char *crop2;
	int i;
	double y;
	double  true_long;
	
    crop1 = strtok(gps_data, "$");
    crop2 = crop1;

         
	for (i=0;i<=100;i++)
	{
	    
        crop1 = strtok(NULL, "$");
	    if(i==17)
	    {	      
	    y = gps_coord_long(crop2);
		  true_long = true_coord(y);
	    }
	    

	}		
	return (true_long);
}  
    

    


















	





	
