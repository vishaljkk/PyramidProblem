#include<unistd.h>
#include<stdlib.h>

//printing the finall output
void printfunction(int arrlen, int last, int arr[arrlen][last]);

//adding the stroke char as 5
void addstroke(int pyramid_size,int arrlen, int last, int arr[arrlen][last]);

//resuing the funvtion to set last and arrlen by passing different flags as a subject of code reusablilty
int computeArrNLast(int maxlevel, int flag);

//initilizing the part print for the entire array 
//i.e including the _ as 1 / as 2 * as 3 and \ as 4
void computePartPrint(int maxlevel, int *p);


void computePartSetupTwoPrint(int *p,int arrlen,int last,int arr[arrlen][last] );


//starting the main function
int main(int argc,char const *argv[]){
	int pyramid_size;
	int counter=0;
	pyramid_size = atoi(argv[1]);
	if(pyramid_size%2 == 0){
		write(2, "please pass an odd number\n", 27);
		return 0;
	}
	int maxlevel= pyramid_size+2; 	
	int last=computeArrNLast(maxlevel, 1);;
	int arrlen=computeArrNLast(maxlevel, 2);;
	int *p = malloc(sizeof(int)*arrlen);
	computePartPrint(maxlevel, p);
	int arr[arrlen][last];
	computePartSetupTwoPrint(p, arrlen, last, arr);
	addstroke(pyramid_size,arrlen,last,arr);
	printfunction(arrlen,last,arr);	
	return 0;
}

void printfunction(int arrlen, int last, int arr[arrlen][last]){
	int i=0;
	while(i<arrlen){
		int j=0;
		while(j<last){
			int k=arr[i][j];
			if(k==1)
				write(2," ",1);
			if(k==2)
				write(2,"/",1);
			if(k==3)
				write(2,"*",1);
			if(k==4)
				write(2,"\\",1);
			if(k==5)
				write(2,"|",1);		
			j++;
		}
		write(2,"\n",2);
		i++;
	}

}
void addstroke(int pyramid_size,int arrlen, int last, int arr[arrlen][last]){
	int i=arrlen-pyramid_size;	
	while(i<arrlen){
		int w = last/2;
		int z = pyramid_size/2;
		int j = w-z;
		int k=w+z+1;
		while(j<k){
			arr[i][j]=5;
			j++;
		}
		i++;
	}

}
int computeArrNLast(int maxlevel, int flag){
	int start=3;
	int k=0;
	int last=0;
	int arrlen=1;
	while(start<=maxlevel){
		int counter=0;
		if(k==0)k=3;
		else{
			k=last+2*3;
			last=k;
			arrlen=arrlen+1;
		}
		int me=start-1;
		while(counter<me){
			k=k+2;
			counter=counter+1;
			last=k;
			arrlen=arrlen+1;
		}
		start=start+1;
	}
	if(flag==1)return last;
	if(flag==2)return arrlen;
}

void computePartPrint(int maxlevel, int *p){
	int start=3;
	int k=0;
	int i = 0;
	int last=0;
	*(p+i)=start;
	i=i+1;
	while(start<=maxlevel){
		int counter=0;
		if(k==0){
			k=3;
		}
		else{
			k=last+2*3;
			last=k;
			*(p+i)=k;
			i=i+1;
		}
		int me=start-1;
		while(counter<me){
			k=k+2;
			counter=counter+1;
			last=k;
			*(p+i)=k;
			i=i+1;
		}
		start=start+1;
	}
}
void computePartSetupTwoPrint(int *p, int arrlen,int last, int arr[arrlen][last]){
	int i=0;
	while(i<arrlen){
		int k =0;
		k=last/2-*(p+i)/2;
		int j=0;
		while(j<k){
			arr[i][j]=1;
			j++;	
		}
		int w=j+*(p+i);
		arr[i][j]=2;
		j=j+1;
		while(j<w-1){
			arr[i][j]=3;
			j++;
		}
		arr[i][j]=4;
		j=j+1;
		w=last;
		while(j<w){
			arr[i][j]=1;
			j++;
		}
		i++;
	}
}

