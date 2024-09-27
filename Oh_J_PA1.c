#include <stdio.h>
#include <math.h>


float mean(float arr[], int size){ 

	 float mean = 0;
	 float total = 0.0;
	 for(int i = 0; i<size; i++){
		
		total+=arr[i]; 

	}
	
	mean = total/size; 
	return mean;

}


float median(float arr[], int size){



	int median_positionNumerator = size+1;
	int median_position = median_positionNumerator/2;
	

	return arr[median_position];


}


float mode(float arr[], int size){

	int likeValueCounter = 0;
	float modeValueNumber = 0.0;

	for(int i =0; i<size; i++){
		int count = 0;

		for(int j = 0; j<size; j++){

                      if (arr[i] == arr[j]){
			
			count++;
		}
	}


	if (count>likeValueCounter){
		likeValueCounter = count;
		modeValueNumber = arr[i];

	}


	}

	return modeValueNumber;
}


float std_dev(float arr[], int size){
		
		
 

	 float mean = 0;
	 float total = 0.0;
	 for(int i = 0; i<size; i++){
		
		total+=arr[i]; 

	}
	
	mean = total/size; 

	int numerator = size-1;
	float tempVarible = 0.0;
	float totalToBeUsed =0.0;	
	for (int i = 0; i<size; i++){
		
		tempVarible = arr[i]-mean;
		totalToBeUsed += pow(tempVarible,2);				
	

	}


	return totalToBeUsed/numerator;
}

void rounded_vals(float arr[] ,int size,int returnableArr[]){

	for(int i = 0; i<size; i++){
	
		returnableArr[i] = (int)round(arr[i]);

	}
	
}


void ascii(float arr[], int size, int arrReturnable[]){

	int tempInt = 0;
	for(int i =0; i<size; i++){
	
		tempInt = (int) arr[i];
		arrReturnable[i] = tempInt;


	
	}

}



int main(int argc, char *argv[]){
	if(argc<2){
		printf("Usage: %s\n", argv[0]);
		return 1;

	}
	int size = argc - 1;
	float arr[size];

	for(int i = 0; i < size; i++){

		const char *stringArgumentTake = argv[i+1];
		float resultStoredReturn = 0.0;
		float fct = 1.0;
		
		while(*stringArgumentTake != '\0'){

			if(*stringArgumentTake == '.'){

			fct = 0.1;
			stringArgumentTake++;
			continue;
			}
	
			if(fct == 1.0){

			resultStoredReturn = resultStoredReturn * 10.0f + (*stringArgumentTake - '0');

			}else{
			resultStoredReturn += (*stringArgumentTake - '0') * fct;
			fct *= 0.1;


			}


			stringArgumentTake++;
		}

			arr[i] = resultStoredReturn;
	}

	int returnableArr[size];
	printf("Mean: %f\n",mean(arr, size));
	printf(" , Median: %f\n", median(arr,size));
	printf(" , Mode: %f\n", mode(arr,size));
	printf(" , Std_Dev%f\n", std_dev(arr,size));

		rounded_vals(arr,size,returnableArr);

	printf("Rounded Values: ");
	for(int i = 0; i<size; i++){
		printf("%d " , returnableArr[i]);


	}
	printf("\n");
	ascii(arr,size,arrReturnable);
	printf("Ascii values");
		for(int j = 0; j<size; j++){
		printf("%i " , arrReturnable[j]);


	}
	
	return 0;
}
