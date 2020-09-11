#include <stdio.h>
#include <stdlib.h>
void valueFrequency(int valFreq[],int answer[], int count){
	int i;
	for(i=0; i<count; i++) valFreq[i]=0;
	for(i=0;i<count;i++){
		valFreq[answer[i]-1]++;
	}
	return;
}
int max(int answer[], int count){
	int max;
	int i;
	max = answer[0];
	for(i=0; i<count; i++){
		if(answer[i] > max) max = answer[i];
	}
	return max;
}
void mode(int valFreq[],int freq[],int *freqsize, int answer[], int count){
	int i;
	
	valueFrequency(valFreq,answer,count);
	int mode_val = max(valFreq,9);
	int mode_flag[9] = {0};
	printf("Mode value: %d\n",mode_val);
	for(i=0;i<9;i++){
		if(valFreq[i] == mode_val && mode_flag[i]== 0){
			mode_flag[i] = 1;
//			for(i=0;i<9;i++)printf("%d,",mode_flag[i]);
//			printf("\n");
			*freqsize = *freqsize + 1;
			freq[*freqsize-1] = i+1;
		}
	}
	printf("freq size: %d\n",*freqsize);
	
	return;
}
void displayData(int answer[],int count, int vf[]){
	int i;
	valueFrequency(vf,answer,count);
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
		printf("%d]\n",vf[8]);
	}
	return;
}

int main(){
	int answer[11] = {1,2,1,2,3,4,5,6,7,8,9};
	int vf[9] = {0};
	int i, freqsize=0;
	int freq[9] = {0};
	
	displayData(answer,11,vf);
	mode(vf,freq,&freqsize,answer,11);
	for(i=0;i<freqsize;i++){
			printf("%d, ",freq[i]);
	}
	return 0;
}
