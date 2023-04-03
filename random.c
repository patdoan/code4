//Function
void addavgstoarray(struct data arr[], struct data returnarr[], char geo[], int row, int *index){
	
	struct data temp15, temp16, temp17, temp18, temp19, temp20, temp21;
	double sum2015avg = 0, num2015ofinstances = 0;
	double sum2016avg = 0, num2016ofinstances = 0;
	double sum2017avg = 0, num2017ofinstances = 0;
	double sum2018avg = 0, num2018ofinstances = 0;
	double sum2019avg = 0, num2019ofinstances = 0;
	double sum2020avg = 0, num2020ofinstances = 0;
	double sum2021avg = 0, num2021ofinstances = 0;
	
	int counter = *index;
	
	char pt1[50] = "\"";
	char pt2[50] = "\"";
	strcat(pt1, geo);
	strcat(pt1,pt2);
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(arr[i].geo, pt1)){
			
			if((arr[i].date == 2015)){
				num2015ofinstances++;
				sum2015avg += arr[i].value;
			
		   	}else if((arr[i].date == 2016)){
				num2016ofinstances++;
				sum2016avg += arr[i].value;
			
			}else if((arr[i].date == 2017)){
				num2017ofinstances++;
				sum2017avg += arr[i].value;
				
			}else if((arr[i].date == 2018)){
				num2018ofinstances++;
				sum2018avg += arr[i].value;
				
			}else if((arr[i].date == 2019)){
				num2019ofinstances++;
				sum2019avg += arr[i].value;
			}else if((arr[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += arr[i].value;
			}else if((arr[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += arr[i].value;
			}
		}
	}
	temp15.date = 2015;
	strcpy(temp15.geo, pt1);
	strcpy(temp15.agegroup, " ");
	strcpy(temp15.sex, " "); 
	temp15.value = sum2015avg/num2015ofinstances;
	returnarr[counter] = temp15;
	counter++;
	temp16.date = 2016;
	strcpy(temp16.geo, pt1);
	strcpy(temp16.agegroup, "");
	strcpy(temp16.sex, "");
	temp16.value = sum2016avg/num2016ofinstances;
	returnarr[counter] = temp16;
	counter++;
	temp17.date = 2017;
	strcpy(temp17.geo, pt1);
	strcpy(temp17.agegroup, " ");
	strcpy(temp17.sex, " ");
	temp17.value = sum2017avg/num2017ofinstances;
	returnarr[counter] = temp17;
	counter++;
	temp18.date = 2018;
	strcpy(temp18.geo, pt1);
	strcpy(temp18.agegroup, " ");
	strcpy(temp18.sex, " ");
	temp18.value = sum2018avg/num2018ofinstances;
	returnarr[counter] = temp18;
	counter++;
	temp19.date = 2019;
	strcpy(temp19.geo, pt1);
	strcpy(temp19.agegroup, " ");
	strcpy(temp19.sex, " ");
	temp19.value = sum2019avg/num2019ofinstances;
	returnarr[counter] = temp19;
	counter++;
	temp20.date = 2020;
	strcpy(temp20.geo, pt1);
	strcpy(temp20.agegroup, " ");
	strcpy(temp20.sex, " ");
	temp20.value = sum2020avg/num2020ofinstances;
	returnarr[counter] = temp20;
	counter++;
	temp21.date = 2021;
	strcpy(temp21.geo, pt1);
	strcpy(temp21.agegroup, " ");
	strcpy(temp21.sex, " ");
	temp21.value = sum2021avg/num2021ofinstances;
	returnarr[counter] = temp21;
	counter++;
	*index = counter;
}
	//main
	struct data yearlyavgarray[35];
	int index = 0;
	addavgstoarray(datalist, yearlyavgarray, "Canada (excluding territories)", row, &index);
	addavgstoarray(datalist, yearlyavgarray, "Quebec", row, &index);
	addavgstoarray(datalist, yearlyavgarray, "Ontario", row, &index);
	addavgstoarray(datalist, yearlyavgarray, "Alberta", row, &index);
	addavgstoarray(datalist, yearlyavgarray, "British Columbia", row, &index);
	
	double highestvalue = yearlyavgarray[0].value, lowestvalue = yearlyavgarray[0].value;
	for(int i = 0; i < 35; i++){
		if(highestvalue < yearlyavgarray[i].value){
			highestvalue = yearlyavgarray[i].value;
		}
		if(lowestvalue > yearlyavgarray[i].value){
			lowestvalue = yearlyavgarray[i].value;
		}
	}
	
	printf("\nHighest percentage of diabetes in all years and all provinces: \n---------------------------------------------------------------\n");
	for(int i = 0; i < 35; i++){
		if(yearlyavgarray[i].value == highestvalue)
			printf("%s, %d, %.2lf\n", yearlyavgarray[i].geo, yearlyavgarray[i].date, yearlyavgarray[i].value);
	}
	printf("\nLowest percentage of diabetes in all years and all provinces: \n---------------------------------------------------------------\n");
	for(int i = 0; i < 35; i++){
		if(yearlyavgarray[i].value == lowestvalue)
			printf("%s, %d, %.2lf\n", yearlyavgarray[i].geo, yearlyavgarray[i].date, yearlyavgarray[i].value);
	}
