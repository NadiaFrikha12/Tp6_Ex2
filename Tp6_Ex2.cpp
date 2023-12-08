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
	
	//Saisir une cha�ne de caract�res CH non vide form�e uniquement par des lettres
	//alphab�tiques, l�espace est aussi autoris�,
	
	do{
		printf("donner une chaine:");
		gets(ch);	
		p=ch;
		//verifier si la chaine est form�e uniquement par des lettres alphab�tiques et des espaces
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
	
	//Compter les occurrences des lettres de l'alphabet en faisant abstraction � la casse.
	p1=ch;
	while(*p1){
		if (isalpha(*p1)!=0){
			lettre = toupper(*p1);
			occurences[lettre-'A'] ++; //soustraire le code ASCII de 'a' pour ne pas d�passer 26 	
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
