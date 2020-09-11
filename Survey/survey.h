typedef int* Statistician;

void add(Statistician answer, int *count, int *SIZE, int item);
/*
	Adds an item to the list of answers. Initally size is 10. Count is initialized 0; adds 1 for every entry
	When count equal to size, double size to accomodate new entries. No size limit. 
*/
float mean(Statistician answer, int count);
/*
	Finds the mean of the answers.
*/
float median(Statistician answer, int count);
/*
	Finds the median in answers.
*/
int max(Statistician answer, int count);
/*
	Finds the highest score in answers.
*/
int min(Statistician answer, int count);
/*
	Finds the lowest score in answers.
*/
int range(Statistician answer, int count);
/*
	Finds the range of scores in answers.
*/
void valueFrequency(int freq[],Statistician answer, int count);
/*
	Counts the frequency of each answer(1-9)
*/
void mode(int valFreq[],int freq[], int *freqsize, Statistician answer, int count);
/*
	Finds the highest repeating value in "answer" and putting it on "freq[]". There may be more than
	one value; resize freq[] to fit another value and append the value into it.
*/
void histogram(Statistician answer, int count);
/*
	Displays the frequencies of answers in a graphical manner.
*/
void displayData(Statistician answer,int count,int vf[]);
void displayChoices();
void displayHeader();
void runProgram();
