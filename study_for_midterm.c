#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char * argv[]){



}



float mean(float arr[], int size){
	float total = 0.0;
	float mean = 0.0;
	for(int i = 0; i <size; i++){
		total +=arr[i];


	}
	float newSize = (float)size;
	mean = total/newSize;
	return mean;

}

float median(float arr[], int size){
	int position = 0;
	int position2 = 0;
	if (size%2 =0){
		position = size/2;
		position2 = (size/2)+1;
	}else{
	position = size+1/2;

	}


}


float mode(float arr[], int size){

	int numberOfAmount=0;
	float mostCommon=0.0

	for(int i = 0; i<size; i++){

		int count=0;

		for(int j = 0; j<size; j++){
		if(arr[i] = arr[j]){
			index++;

		}


		}
		if(count>= mostCommon){
			mostCommon = arr[i];

		}

	}

}



float std_dev(float arr[], int size){
	int denomantor = size-1;
	float total = 0.0;
	float mean = 0.0;




}




int * rounded_vals(float arr[], int size){
	static int arr2[size];
	int roundedValues = 0;
	for(int i = 0; i <size; i++){
		roundedValues = round(arr[i]);
		arr2[i] = roundedValues;
	}


return arr2;




}



char * ascii(float arr[], int size){

	static char arr2[size];
	for(int i = 0; i < size; i++){

		if ((int)arr[i]<255|| (int) arr[i] >=0){
			arr2[i] = (char)arr[i];


		}else{
		arr2[i] = '*';

		}


	}


	return arr2;
}






