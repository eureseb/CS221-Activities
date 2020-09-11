#include "survey.h"
#include <stdio.h>
#include <stdlib.h>
void add(Statistician answer, int *count, int *SIZE, int item){
	int i,j,temp;
	if((*count)-1 == (*SIZE)-1){
		(*SIZE) *= 2;
		answer = (Statistician)realloc(answer,(*SIZE)*sizeof(int));
	}
	
	answer[(*count)] = item;
	(*count)++;
	for (i = 0; i < *count - 1; i++) { 
        for (j = i + 1; j < *count; j++) {
        	  if (answer[j] < answer[i]){
            	temp = answer[j];
            	answer[j] = answer[i];
            	answer[i] = temp;
			}
		}
    } 
}
float mean(Statistician answer, int count){
	float mean=0;
	int i;
	for(i=0 ; i<count; i++){
		mean += answer[i];
	}
	return mean /= count;	
}

float median(Statistician answer, int count){
	float median;
	if(count%2 == 1){
		median = (float)answer[(count/2)];
	}else{
		median = ((float)answer[count/2]+answer[(count/2)-1])/2;
	}
	return median;
}

int max(Statistician answer, int count){
	int max;
	int i;
	max = answer[0];
	for(i=0; i<count; i++){
		if(answer[i] > max) max = answer[i];
	}
	return max;
}
int min(Statistician answer, int count){
	return answer[0];
}
int range(Statistician answer, int count){
	return max(answer,count) - min(answer,count);
}
void valueFrequency(int valFreq[],Statistician answer, int count){
	int i;
	for(i=0; i<9; i++) valFreq[i]=0;
	for(i=0;i<count;i++){
		valFreq[answer[i]-1]++;
	}
	return;
}
void mode(int valFreq[],int freq[],int *freqsize, Statistician answer, int count){
	int i;
	int hasmode = 0,freq_count=0;
	*freqsize=0;
	for(i=0;i<9;i++) freq[i] = 0;
	valueFrequency(valFreq,answer,count);
	
	int mode_val = max(valFreq,9);
	int mode_flag[9] = {0};
	
	for(i=0;i<9;i++){
		if(valFreq[i] > 0){
			freq_count++;
		}
		if(valFreq[i] == mode_val && mode_flag[i]== 0){
			mode_flag[i] = 1;
			*freqsize = *freqsize + 1;
			freq[*freqsize-1] = i+1;
		}
	}
	if(freq_count == *freqsize){
		
		for(i=0;i<0;i++){
			freq[i] = 0;
		}
		*freqsize = 0;
	}
	return;
}
void histogram(Statistician answer, int count){
	int i,j,n=0;
	int valFreq[9] = {0};
	
	valueFrequency(valFreq,answer,count);
	for(i=0;i<9;i++){
		if(valFreq[i] > n) n = valFreq[i];
	}
	printf("\tH O R I Z O N T A L H I S T O G R A M\n");
	for(i=9;i>0;i--){
		printf("%d | ",i);
//		printf("%d",answer[count-1]);
		for(j=0;j<valFreq[i-1];j++){
			printf("* ");
		}
		printf("\n");
	}
	printf("   ",n);
	for(i=0;i<n+5;i++) printf("%d ",i+1);
	printf("\n");
	return;
}
void displayHeader(){
	printf("SURVEY MASTER 1000\n\n");
}
void displayData(Statistician answer,int count, int vf[]){
	int i;
	if(count != 0){
		printf("Current Answers: {");
		for(i=0;i<count-1;i++){
			printf("%d, ",answer[i]);
		}
		printf("%d}\n",answer[count-1]);
		printf("Current Frequencies: [");
		for(i=0;i<8;i++){
			printf("%d, ",vf[i]);
		}
		printf("%d]\n\n",vf[8]);
	}
	return;
}
void displayChoices(){
	printf("1. Add\n");
	printf("2. Mean\n");
	printf("3. Median\n");
	printf("4. Max\n");
	printf("5. Min\n");
	printf("6. Range\n");
	printf("7. Mode: \n");
	printf("8. Histogram\n\n");
	printf("Enter your choice: ");
	
	return;
}
void runProgram(){
	int ch,i;
	int count=0;
	int freqsize=0,SIZE=10;
	int item=0;
	int vf[9] = {0};
	Statistician answer = (Statistician)malloc((SIZE)*sizeof(int));
	int* freq = (int*)malloc(9*sizeof(int));
	while(1){
	system("cls");
	
	displayHeader();
	valueFrequency(vf,answer,count);
	displayData(answer,count,vf);
	displayChoices();
	scanf("%d",&ch);
	switch(ch){
			case 1:	while(item<1 || item>9){
					printf("Add a number 1-9: ");
					scanf("%d",&item);
					}
					add(answer,&count,&SIZE,item);
					item=0;
					system("pause");
					break;
					
			case 2: printf("Mean: %.2f\n",mean(answer,count));
					system("pause");
					break;
			case 3: printf("Median: %.2f\n",median(answer,count));
					system("pause");
					break;
			case 4: printf("Max: %d\n", max(answer,count));
					system("pause");
					break;
			case 5: printf("Min: %d\n", min(answer, count));
					system("pause");
					break;
			case 6: printf("Range: %d\n", range(answer, count));
					system("pause");
					break;
			case 7: mode(vf,freq,&freqsize,answer,count);
					if(freqsize > 0){
						printf("The mode/modes: {");
						for(i=0;i<freqsize;i++){
						printf(" %d ",freq[i]);
							printf("}\n");
						}
					}else printf("No modes for the set data\n");
				
					system("pause");
					break;
			case 8: histogram(answer,count);
					system("pause");
					break;
	}
}

	return;
}
