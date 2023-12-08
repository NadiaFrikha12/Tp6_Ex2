#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
	char* p;
	int valide;
	char ch[10];
	char* p1;
	int occurences[26]={0}; // tableau pour stocker les occurences de chaque lettre
	char lettre ; //conversion en majuscule
	
	//Saisir une chaîne de caractères CH non vide formée uniquement par des lettres
	//alphabétiques, l’espace est aussi autorisé,
	
	do{
		printf("donner une chaine:");
		gets(ch);	
		p=ch;
		//verifier si la chaine est formée uniquement par des lettres alphabétiques et des espaces
		valide =0;
		do{
			if (isalpha(*p) || (isspace(*p))) {
				p++;
			}
			else {
				valide =1;
			} 
		} while (!valide && *p); //Si valide est vrai ou si *p est nul, la boucle se termine
	}while ((strlen(ch)<=0) || valide);
	
	//Compter les occurrences des lettres de l'alphabet en faisant abstraction à la casse.
	p1=ch;
	while(*p1){
		if (isalpha(*p1)!=0){
			lettre = toupper(*p1);
			occurences[lettre-'A'] ++; //soustraire le code ASCII de 'a' pour ne pas dépasser 26 	
		}
		*p1 ++; 
	}
	
	for(int i=0;i<26;i++){
		if (occurences[i] != 0){
			printf("%d fois la lettre %c \n",occurences[i],'A'+i);
		}
	}
	
	return 0;
}
