#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMode(int arr[],int size);
int findMedian(int arr[],int size);
int calcGeometricAvr(int arr[], double size);
int calcHarmonicAvr(int arr[],int size);
int calcArithmeticAvr(int arr[], int size);
int calcRangeOfDispersion(int arr[],int size);
int calcWideOfDispersion(int arr[],int size);
int calcAbsoluteDeflection(int arr[], int size);
int calcMassVariance(int arr[], int size);
int calcStandarDeflection(int arr[],int size);
int switchCase(int arr[], int size);


int main() {
	//kulanýcýdan dizi boyutunu al
	int size;
	printf("Dizinin eleman sayisini giriniz : ");
	scanf("%d",&size);
	int arr[size];
	
	//kullanýcýdan dizideki degerleri al
	int i,j;
	for(i = 0; i < size; i++){
		printf("Dizinin %d.Elemanini giriniz : \n",i);
		scanf("%d",&arr[i]);
	}	
	
	switchCase(arr,size);
	char x;
	printf("Cikis icin C'ye basin ,Ana Menuye donmek icin Bir tusa Basin !!");
    scanf("%c",&x);
    if(x=='c'||x=='C'){
        system("CLS");
        exit(1);
    }
    else{
        switchCase(arr,size);
    }
}

//Implementation of functions 

int switchCase(int arr[], int size){
		int secim;
   printf("Menuden Islem Seciniz : ");
   printf("\n\n\n\n\n\n");
   printf("\t\t\t\t\t\t________MENU________\n\n");
   printf("\t\t\t\t\t\t[1]-Mod Hesapla\n\n");
   printf("\t\t\t\t\t\t[2]-Medyan Hesapla\n\n");
   printf("\t\t\t\t\t\t[3]-Geometrik Ortalama Hesapla\n\n");
   printf("\t\t\t\t\t\t[4]-Harmonik Ortalama Hesapla\n\n");
   printf("\t\t\t\t\t\t[5]-Aritmetik Ortalama Hesapla\n\n");
   printf("\t\t\t\t\t\t[6]-Dagilim Sinirlarini Hesapla\n\n");
   printf("\t\t\t\t\t\t[7]-Dagilim Genisligini Hesapla\n\n");
   printf("\t\t\t\t\t\t[8]-Mutlak Sapma Hesapla\n\n");
   printf("\t\t\t\t\t\t[9]-Kitle Varyansini Hesapla\n\n");
   printf("\t\t\t\t\t\t[10]-Standart Sapma Hesapla\n\n");
   printf("Tercih Ettiginiz Islem Numarasi ");
	scanf("%d",&secim);
	switch(secim){
		case 1:findMode(arr,size);break;
		case 2:findMedian(arr,size);break;
		case 3:calcGeometricAvr(arr,size);break;
		case 4:calcHarmonicAvr(arr,size);break;
		case 5:calcArithmeticAvr(arr,size);break;
		case 6:calcRangeOfDispersion(arr, size);break;
		case 7:calcWideOfDispersion(arr, size);break;
		case 8:calcAbsoluteDeflection(arr, size);break;
		case 9:calcMassVariance(arr, size);break;
		case 10:calcStandarDeflection(arr, size);break;
	}
}

int findMode(int arr[], int size)
{
	int i,j;
	for(i = 0; i < size ;i++){
		for(j = i +1 ;j < size; j++){
			if(arr[i] == arr[j]){
				printf("Tekrar eden sayi : %d\n",arr[i]);
			}
		}
	}
}

int findMedian(int arr[], int size){
	int i,middle;
	for(i=0;i<size;i++){
		if(size % 2 == 0){
			middle = arr[size/2];
		}else{
			middle = arr[(size + 1) / 2];
		}
	}
	printf("Ortanca deger : %d\n",middle); 
}

calcGeometricAvr(int arr[], double size){
	int i;
	double multiply=1;
	double result;
	for(i = 0; i < size;i++){
		multiply = multiply * arr[i];
	}
	result = pow(multiply ,(1/size)); 
	//printf("multiply : %.1lf\n",multiply);
	printf("Geometrik Ortalama : %.1lf\n",result);
}

calcHarmonicAvr(int arr[],int size){
	int i;
	float result = 0;
	for(i = 0; i<size;i++){
		result = result + (float)1/arr[i];
	}
	printf("Harmonik Ortalama : %.2f\n",result);
}

calcArithmeticAvr(int arr[], int size){
	int i;
	float result = 0;
	for(i = 0; i<size;i++){
		result = result + arr[i] / (float)size;
	}
	printf("Aritmetik Ortalama : %.2f\n", result);
}

calcRangeOfDispersion(int arr[],int size){
	int i,max,min;
	max = arr[0];
	min = arr[0];
	for(i = 0;i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
		
		if(arr[i] < min ){
			min = arr[i];
		}
	}
	
	printf("En buyuk eleman : %d\n",max);
	printf("En kucuk Eleman : %d\n",min);
}

calcWideOfDispersion(int arr[],int size){
	int i,max,min;
	max = arr[0];
	min = arr[0];
	for(i = 0;i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
		
		if(arr[i] < min ){
			min = arr[i];
		}
	}
	printf("Dagilim Genisligi : %d\n",max-min);
}

calcAbsoluteDeflection(int arr[], int size){
	int i,average,sum=0,sumOfDiff=0,deflection;
	for(i = 0; i< size; i++){
		sum += arr[i]; 
		average = sum / size;
		sumOfDiff = sumOfDiff + abs(arr[i] - average);
	}
	deflection = sumOfDiff / size;
	printf("Mutlak Sapma : %d\n",deflection);
}

calcMassVariance(int arr[], int size){
	int i,j,average,sum=0,result;
	int sumOfDiff [size],sumOfSqr = 0;
	for(i = 0;i < size; i++){
		sum += arr[i];
		average = sum / size;
		for(j = 0;j < size;j++){
			sumOfDiff[j] = abs(arr[i] - average);
			sumOfSqr += pow(sumOfDiff[j] , 2);
		}	
	}
	result = sumOfSqr / size;
	printf("Kitle Varyansi : %d\n",result);
	return result;
}

calcStandarDeflection(int arr[],int size){
	int sqrtOfMass = sqrt(calcMassVariance(arr,size));
	printf("Standart Sapma : %d\n", sqrtOfMass);
}






