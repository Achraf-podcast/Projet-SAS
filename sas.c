#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define MAX 100

typedef struct {
	int id;
    char f_name[50];
	char l_name[50];
	int shirtNum;
	char post[50];
	int goals;
	int age;
	char birthday[50];
	char inscription[50];
	char status[50];
} Player;

Player players[MAX];
int playersNum = 0;
bool found = false;
char notification[50] = "";
char negativeNotification[50] = "";

void print(char value[], int error){
	if(strlen(value) <= 6){
		printf("\n|%s\t\t\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 14 && strlen(value) > 6){
		printf("\n|%s\t\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 22 && strlen(value) > 14){
		printf("\n|%s\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 30 && strlen(value) > 22){
		switch(error){
			case 0:
				printf("\n|\t\t\t\t\t\t\t\t       |");
				printf("\n|%s%s %s\t\t\t\t\t       |",RED, value, RESET);
				break;
			case 1:
				printf("\n|\t\t\t\t\t\t\t\t       |");
				printf("\n|%s%s %s\t\t\t\t\t       |",GREEN, value, RESET);
				break;
			case 2:
				printf("\n|%s\t\t\t\t\t       |", value);
		}
		
	}else if(strlen(value) <= 38 && strlen(value) > 30){
		switch(error){
			case 0:
				printf("\n|\t\t\t\t\t\t\t\t       |");
				printf("\n|%s%s %s\t\t\t\t\t       |",RED, value, RESET);
				break;
			case 1:
				printf("\n|\t\t\t\t\t\t\t\t       |");
				printf("\n|%s%s %s\t\t\t\t       |",GREEN, value, RESET);
				break;
			case 2:
				printf("\n|%s\t\t\t\t       |", value);
		}
	}
	else if(strlen(value) <= 46 && strlen(value) > 38){
		printf("\n|%s\t\t\t       |", value);
	}else if(strlen(value) <= 54 && strlen(value) > 46){
		printf("\n|%s\t\t       |", value);
	}else if(strlen(value) <= 62 && strlen(value) > 54){
		printf("\n|%s\t       |", value);
	}else if(strlen(value) <= 70 && strlen(value) > 62){
		printf("\n|%s       |", value);
	}
}

void addIt(char f_name[], char l_name[], int shirtNum, char post[], int goals, int age, char birthday[], char inscription[], char status[]){
	players[playersNum].id = playersNum;	
	strcpy(players[playersNum].f_name, f_name);
	strcpy(players[playersNum].l_name, l_name);
	players[playersNum].shirtNum = shirtNum;
	strcpy(players[playersNum].post, post);
	players[playersNum].goals = goals;
	players[playersNum].age = age;
	strcpy(players[playersNum].birthday, birthday);
	strcpy(players[playersNum].inscription, inscription);
	strcpy(players[playersNum].status, status);
	playersNum++;
}

void addMultiPlayers(int times){
	int exit;
	for(int i = 0; i<times; i++){
		system("cls");
		int day, month, year;
		char s_day[50];
		char s_month[50];
		char s_year[50];
		char fullInscriptionDate[50] = "";
		char fullBirthdayDate[50] = "";

		struct tm birth = {0};
		time_t t = time(NULL);
		struct tm *today = localtime(&t);

		char v1[50];
		char v2[50];
		int v3;
		char v4[50];
		int v5;
		char v6[50];

		printf("\n Prenom: ");
		scanf("%s", &v1);
		printf(" Nom: ");
		scanf("%s", &v2);
		printf(" Numero de maillot: ");
		scanf("%d", &v3);
		printf(" Post: ");
		scanf("%s", &v4);
		printf(" Numero de buts: ");
		scanf("%d", &v5);

		printf(" Date de naissance: ");
		printf("\n\tJour: ");
		scanf("%d", &day);
		printf("\tMois: ");
		scanf("%d", &month);
		printf("\tAnnee: ");
		scanf("%d", &year);

		printf(" Statut: ");
		scanf("%s", &v6);

		birth.tm_mday = day;
		birth.tm_mon = month - 1;
		birth.tm_year = year - 1900;

		int age = today->tm_year - birth.tm_year;
		if (today->tm_mon < birth.tm_mon ||
		(today->tm_mon == birth.tm_mon && today->tm_mday < birth.tm_mday)) {
			age--;
		}
		
		sprintf(s_day, "%d", day);
		strcat(fullBirthdayDate, s_day);
		strcat(fullBirthdayDate, "/");
		sprintf(s_month, "%d", month);
		strcat(fullBirthdayDate, s_month);
		strcat(fullBirthdayDate, "/");
		sprintf(s_year, "%d", year);
		strcat(fullBirthdayDate, s_year);

		sprintf(s_day, "%d", today->tm_mday);
		strcat(fullInscriptionDate, s_day);
		strcat(fullInscriptionDate, "/");
		sprintf(s_month, "%d", today->tm_mon+1);
		strcat(fullInscriptionDate, s_month);
		strcat(fullInscriptionDate, "/");
		sprintf(s_year, "%d", today->tm_year+1900);
		strcat(fullInscriptionDate, s_year);

		addIt(v1, v2, v3, v4, v5, age, fullBirthdayDate, fullInscriptionDate, v6);
	}
	strcpy(notification, "     Joueur(s) ajoutee avec succee.");
	
	printf("\n");
	scanf("%c", &exit);

}

void addPlayer(){
	int command;
	int n;
	
	system("cls");
	printf("\n--------------------- Gestion d'equipe de football ---------------------");
	print("1.  Ajouter un nouveau joueur.", 2);
	print("2.  Ajouter plusieurs joueurs en une seule operation.", 2);
	print("3.  Retour.", 2);
	printf("\n------------------------------------------------------------------------");
	printf("\n Choix:  ");
	scanf("%d", &command);
	
	switch(command){
		case 1:
			addMultiPlayers(1);
			break;
		case 2:
			printf(" Combien de joueurs voulez vous entrer: ");
			scanf("%d", &n);
			addMultiPlayers(n);
			break;
		case 3:
			break;
		default:
			addPlayer();
	}
}

void showPlayers(){
		int exit;
		system("cls");
		for(int i = 0; i<playersNum; i++){
			if(players[i].id >= 0){
				if(strlen(players[i].f_name) <=7  && strlen(players[i].l_name) <=7){
					printf("\nId: %d\tPrenom: %s\t| Nom: %s\t|Maillot: %d| Post: %s | Buts: %d  | Age: %d | date d'inscription: %s | Statut: %s\n", 
					players[i].id, 
					players[i].f_name, 
					players[i].l_name, 
					players[i].shirtNum,
					players[i].post,
					players[i].goals,
					players[i].age,
					players[i].inscription,
					players[i].status);
				}else{
					printf("\nId: %d\tPrenom: %s | Nom: %s |Maillot: %d| Post: %s | Buts: %d  | Age: %d | date d'inscription: %s | Statut: %s\n", i, players[i].f_name, players[i].l_name, players[i].shirtNum,players[i].post,players[i].goals,players[i].age,players[i].inscription,players[i].status);
				}
				printf("-----------------------------------------------------------------------------------------------------------------------------------------------");
			}
			
		}		
		printf("\n");
		scanf("%d", &exit);
	
}
		
void sortPlayersByName() {
    for (int i = 0; i < playersNum-1; i++) {
        for (int j = 0; j < playersNum-1; j++) {
            int cmp = strcmp(players[j+1].f_name, players[j].f_name);
            if (cmp < 0) {
                Player temp = players[j+1];
                players[j+1] = players[j];
                players[j] = temp;
            }
        }
    }
}

int searchById(){
	int id;
	printf("Entrez Id de joueur: ");
	scanf("%d", &id);
		
	for(int i = 0; i < playersNum; i++) {
		if (players[i].id == id) {
	            printf("\n------------------ Joueur trouve ------------------\n");
	            printf("Id: %d\n", players[i].id);
	            printf("Prenom: %s\n", players[i].f_name);
	            printf("Nom: %s\n", players[i].l_name);
	            printf("Numero de maillot: %d\n", players[i].shirtNum);
	            printf("Poste: %s\n", players[i].post);
	            printf("Buts: %d\n", players[i].goals);
	            printf("Age: %d\n", players[i].age);
	            printf("Date de naissance: %s\n", players[i].birthday);
	            printf("Date d'inscription: %s\n", players[i].inscription);
	            printf("Statut: %s\n", players[i].status);
	            printf("---------------------------------------------------\n");
	            found = true;
	            break;
	        }
	}
	return id;
}

void searchByName(){
	char name[50];
	printf("\n Entrez prenom du joueur: ");
	scanf("%s", name);
	for (int i = 0; i < playersNum; i++) {
		if (strcasecmp(players[i].f_name, name) == 0) {
			printf("\n------------------ Joueur trouve ------------------\n");
			printf("Id: %d\n", players[i].id);
			printf("Prenom: %s\n", players[i].f_name);
			printf("Nom: %s\n", players[i].l_name);
			printf("Numero de maillot: %d\n", players[i].shirtNum);
			printf("Poste: %s\n", players[i].post);
			printf("Buts: %d\n", players[i].goals);
			printf("Age: %d\n", players[i].age);
			printf("Date de naissance: %s\n", players[i].birthday);
			printf("Date d'inscription: %s\n", players[i].inscription);
			printf("Statut: %s\n", players[i].status);
			printf("---------------------------------------------------\n");
			found = true;
			break;
		}
	}
}

void editPlayer(){
	system("cls");
	int id= searchById();
	int change;
	char newpost[50];
    int newgoals;
	
	if(found){
        printf("\n1. le poste\n2. le nombre de buts\n Qu est ce que voulez vous modifier: ");
		scanf("%d", &change);
		switch(change){
		    case 1:
		    	printf("\n Le nouveau poste: ");
		 		scanf("%s", newpost);
				if(strcasecmp(newpost, "gardien") == 0 || strcasecmp(newpost, "attaquant") == 0 || strcasecmp(newpost, "deffenseur") == 0){
						strcpy(players[id].post, newpost);
						strcpy(notification, " Poste modifiee avec succes!");
				}else {
					strcpy(negativeNotification, "  Ce poste n'est pas valide!");
				}
				found = false;
				break;
		    case 2:
				printf("\n Le nouveau nombre de buts: ");
				scanf("%d", &newgoals);
				players[id].goals = newgoals;
				strcpy(notification, "Nombre de buts modifiee avec succes!");
				found = false;
		}
	}else{
		strcpy(negativeNotification, "  Cette Id n'existe pas!");
	}
	
}

void deletePlayer(){
	system("cls");
	int id = searchById();
	int answer;

	if(found){
		printf("\n Etes vous sur de supprimer ce joueur (1. yes/0. non): ");
		scanf("%d", &answer);
		if(answer){
			players[id].id = -1;
			strcpy(notification, "  Joueur supprimee avec succee");
		}else if(!answer){
			strcpy(notification, "  Rien n'a ete suprimmee");
		}
	}
	else{
		strcpy(negativeNotification, "  Cette Id n'existe pas!");
	}
	
}

void search(){
	int c;
	int exit;
	system("cls");
	printf("\n 1. Par Id\n 2. Par prenom\n\n Choix: ");
	scanf("%d", &c);
	
	switch(c){
		case 1:
			system("cls");
			searchById();
			if(found){
				scanf("%d", &exit);
			}
			break;
		case 2:
			system("cls");
			searchByName();
			if(found){
				scanf("%d", &exit);
			}
			break;
	}
	if(!found){
		strcpy(negativeNotification, "  Ce joueur n'existe pas!");
	}
	found = false;
	
}

int menu(){
	int command;
	bool do_it = true;
	bool msg = false;
	
	do{
		system("cls");
		printf("\n--------------------- Gestion d'equipe de football ---------------------");
		print("1.   Ajouter un joueur.", 2);
		print("2.   Afficher tout les joueurs.", 2);
		print("3.   Modifier un joueur.", 2);
		print("4.   Supprimer un joueur.", 2);
		print("5.   Rechercher un joueur.", 2);
		print("6.   Statistiques.", 2);
		print("0.   Quitter.", 2);
		if(msg == true){
			print("     Ce choix n' existe pas !", 0);
			msg = false;
		}
		print(notification, 1);
		strcpy(notification, "");
		print(negativeNotification, 0);
		strcpy(negativeNotification, "");
		printf("\n------------------------------------------------------------------------");
	
		printf("\n Choix:  ");
		scanf("%d", &command);
		switch(command){
			case 1:
				do_it = false;
				addPlayer();
				break;
			case 2:
				do_it = false;
				showPlayers();
				break;
			case 3:
				do_it = false;
				editPlayer();
				break;
			case 4:
				do_it = false;
				deletePlayer();
				break;
			case 5:
				do_it = false;
				search();
				break;
			default:
				if(do_it){
					msg = true;
				}
				do_it = true;
		}
	}while(command != 0);
	return 0;
	
}

int main(){
	addIt("Achraf", "Agourram", 11, "Milieu", 9, 17, "05/11/2007", "01/09/2025", "Titluaire");
	addIt("aymen", "modich", 1, "attaquant", 26, 19, "26/07/2006", "14/08/2025", "Remplacant");
	addIt("rayan", "bniazza", 5, "Milieu", 15, 17, "28/02/2008", "01/09/2025", "Remplacant");
	addIt("anas", "brrada", 9, "Gardien", 1, 20, "01/01/2005", "01/09/2023", "Remplacant");
	addIt("mehdi", "lyazir", 4, "attaquant", 29, 24, "13/09/2000", "01/09/2018", "Remplacant");
	addIt("ousssama", "aouni", 23, "Defensseur", 8, 18, "17/12/2006", "01/09/2024", "Titluaire");
	addIt("mounir", "chrif", 7, "Defensseur", 9, 22, "03/03/2003", "01/09/2021", "Remplacant");
	addIt("morad", "lbessri", 99, "attaquant", 35, 21, "08/04/2004", "01/09/2021", "Remplacant");
	addIt("ayoub", "eldokkali", 17, "Milieu", 11, 17, "05/09/2008", "01/09/2025", "Remplacant");
	addIt("mstafa", "elwazani", 2, "attaquant", 30, 18, "19/06/2007", "01/09/2025", "Titluaire");
	
	menu();
	/*for(int i = 0; i<playersNum; i++){
		printf("%d\n", players[i].id);
	}*/                                                                     
	
	return 0;
}
