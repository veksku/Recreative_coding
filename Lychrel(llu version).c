#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int brCifara(unsigned long long int x){
	int brojac=0;
	while(x>0){
		x/=10;
		brojac++;
	}
	return brojac;
}

unsigned long long invertujSaberi(unsigned long long int x){
	int vel = brCifara(x);
	unsigned long long temp = x;
	unsigned long long pomocna = 0;
	while(temp>0){
		pomocna += (temp%10) * pow(10,vel-1);
		temp /= 10;
		vel--;
	}
	return pomocna+x;
}

unsigned long long palindrom(unsigned long long int x){
	int vel = brCifara(x);
	unsigned long long temp = x;
	unsigned long long pomocna = 0;
	while(temp>0){
		pomocna += (temp%10) * pow(10,vel-1);
		temp /= 10;
		vel--;
	}
	if(x == pomocna)
		return 1;
	else
		return 0;
}

//3943 staje na 4264578888754624
//196 staje  na 4264578888754624
//39
int main(){
	unsigned long long int x = 295;
	unsigned long long int zbir=0;
	int flag=0;
	int input = 0;
	int brojac = 0;
	//unsigned long long limitTest = 18446744073709551615;
	//printf("%llu\n", limitTest);
	while(1){
		zbir = invertujSaberi(x);
		printf("Broj: %llu\n", zbir);
		if(palindrom(zbir)){
			flag = 1;
			break;
		}
		//getchar();
		x=zbir;
		brojac++;
	}
	if(flag)
		printf("Palindrom\n");
	else
		printf("Nije palindrom\n");
		
	printf("%d\n", brojac);
	return 0;
}


// radi do 18,446,744,073,709,551,615







