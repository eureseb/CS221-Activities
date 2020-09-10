#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef int* Statistician;
int SIZE = 10;

void add(Statistician answer, int *count, int *SIZE, int item);
float mean(Statistician answer, int count);
float median(Statistician answer, int count);
int max(Statistician answer, int count);
int min(Statistician answer, int count);
int range(Statistician answer, int count);
void mode(int freq[],int* mode, int *freqsize, Statistician answer, int count);
void valueFreq(int freq[], Statistician answer, int count);
void histogram(Statistician answer, int count);
int main(int argc, char *argv[]) {
	int ch,count=0,freqsize=0, i,item=0,m;
	Statistician answer = (Statistician)malloc((SIZE)*sizeof(int));
	int freq[9] = {0};
	
	while(1){
		system("cls");
		printf("COUNT: %d SIZE: %d\n",count, SIZE);
		
		if(count != 0){
			valueFreq(freq,answer,count);
			for(i=0;i<count;i++){
				printf("%d, ",answer[i]);
			}
			printf("\n{");
			for(i=0;i<8;i++){
				printf("%d, ",freq[i]);
			}
			printf("%d}",freq[8]);
			printf("\n");
			
		}
		printf("This is a survey program\n");
		printf("1. Add\n");
		printf("2. Mean\n");
		printf("3. Median\n");
		printf("4. Max\n");
		printf("5. Min\n");
		printf("6. Range\n7. Mode: \nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	while(item<1 || item>9){
					printf("Add a number 1-9: ");
					scanf("%d",&item);
					}
					add(answer,&count,&SIZE,item);
					item=0;
					break;
					
			case 2: printf("Mean: %.2f\n",mean(answer,count));
					system("pause");
					break;
			case 3: printf("Median: %.2f",median(answer,count));
					system("pause");
					break;
			case 4: printf("Max: %d\n", max(answer,count));
					system("pause");
					break;
			case 5: printf("Min: %d\n", min(answer, count));\
					system("pause");
					break;
			case 6: printf("Range: %d\n", range(answer, count));
					system("pause");
					break;
			case 7: mode(freq,&m,&freqsize,answer,count);
					printf("Mode: %d with a frequency of %d\n",m,freqsize);
					system("pause");
					break;
			
			default: exit(1);
					break;
		}
	}
	
	return 0;
}
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
	int i,max;
	max=answer[0];
	for(i=0;i<count;i++){
		if(answer[i]>max){
			max = answer[i];
		}
	}
	return max;
}
int min(Statistician answer, int count){
	int i,min;
	min=answer[0];
	for(i=0;i<count;i++){
		if(answer[i]<min){
			min = answer[i];
		}
	}
	return min;
}
int range(Statistician answer, int count){
	int range = max(answer,count) - min(answer,count);
	return range;
}
void valueFreq(int freq[],Statistician answer,int count){
	int i;
	for(i=0;i<count;i++) freq[i] = 0;
	for(i=0;i<count;i++){
		switch(answer[i]){
			case 1:	freq[0]++;
					break;
			case 2:	freq[1]++;
					break;
			case 3:	freq[2]++;
					break;
			case 4:	freq[3]++;
					break;
			case 5:	freq[4]++;
					break;
			case 6:	freq[5]++;
					break;
			case 7:	freq[6]++;
					break;
			case 8:	freq[7]++;
					break;
			case 9:	freq[8]++;
					break;
		}
	}
}
void mode(int freq[],int* mode,int *freqsize, Statistician answer, int count){
	int i;
	valueFreq(freq, answer,count);
	*freqsize = max(freq,9);
	*mode = 1;
	for(i=0;i<9;i++) if(freq[i] > *freqsize) *mode = i+1;
}
