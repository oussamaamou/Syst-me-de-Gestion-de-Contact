#include<stdio.h>
#include<string.h>


#define TAILLE_MAX_NOM 25
#define TAILLE_MAX_MAIL 25
#define TAILLE_MAX_NUMERO 10

typedef struct{
    char Nom[TAILLE_MAX_NOM];
    char Mail[TAILLE_MAX_MAIL];
    char Numero[TAILLE_MAX_NUMERO];
} Contact;

int NombrContact = 0;
Contact Contacts[100];

void AjouterUnContact(){
    
    printf("Entrer le Nom du Contact:");
    scanf(" %[^\n]s",&Contacts[NombrContact].Nom);
   
    printf("Entrer le Mail du Contact:");
    scanf(" %[^\n]s",&Contacts[NombrContact].Mail);   
   
    printf("Entrer le Numero du Telephone:");
    scanf(" %[^\n]s",&Contacts[NombrContact].Numero);
    
    NombrContact ++;
    printf("Le contact est ajoute avec succes.\n");
    
}
void ModifierUnContact(){
    int i;
    
    char Nom[TAILLE_MAX_NOM];
    char NovMail[TAILLE_MAX_MAIL];
    char NovNumero[TAILLE_MAX_NUMERO];   
    
    printf("Entrer le Nom du Contact:");
    scanf(" %[^\n]%*c",&Nom);
    
    
    for(i=0;i<NombrContact;i++){
        if(strcmp(Contacts[i].Nom,Nom)==0){
            printf("Entrer le nouveau Mail du Contact:");
            scanf(" %[^\n]%*c",&NovMail);   
   
            printf("Entrer le nouveau Numero du Telephone:");
            scanf(" %[^\n]%*c",&NovNumero);

            printf("Le contact a ete modifie avec succes.");
            break;                
        }
        
            else
               printf("Ce contact n'existe pas!!");
            break;
    }           
             
        
        
    

}

void SupprimerUnContact(){
    int i, j;
    
    char Nom[TAILLE_MAX_NOM];
    
    printf("Entrer le nom du contact à supprimer: ");
    scanf("%[^\n]%*c",&Nom);
    
    for(i=0;i<NombrContact;i++){
        if(strcmp(Contacts[i].Nom,Nom)==0){
            for (int j = i; j < NombrContact - 1; j++) {
                strcpy(Contacts[j].Nom, Contacts[j + 1].Nom);                               
                Contacts[j] = Contacts[j + 1];
            }
                NombrContact--;
                printf("Le Contact a ete supprimer avec succes.\n");
                
                return;
        }
          
        
     
     }
     if(!Nom)
        printf("Le nom du contact est incorrect!!");
        
      

}

void AfficherTousLesContacts(){
    int i;
    for(i=0;i<NombrContact;i++)
    printf("--%d-- Le Nom : %s // Le Numero : %s // Le Mail : %s \n", i+1,Contacts[i].Nom,Contacts[i].Numero,Contacts[i].Mail );

      

   
}

void RechercherUnContact(){
    int i;
    char Nom[TAILLE_MAX_NOM];
    char Mail[TAILLE_MAX_MAIL];
    char Numero[TAILLE_MAX_NUMERO];
    int Recherche = 0;
    printf("Entrer le nom du contact à rechercher:");
    scanf("%[^\n]%*c",&Nom);
    for(i=0;i<NombrContact;i++){
        if(strcmp(Contacts[i].Nom,Nom)==0){
            printf("Contact Trouve.\n");
            printf("Le mail : %s\n",&Contacts[i].Mail);
            printf("Le numero : %s\n",&Contacts[i].Numero);
            Recherche = 1;
            break;
        }
    }
    if(!Recherche)
    printf("Le contact est indisponible\n!!");
    


}








int main(){
    int Choix;
    printf("\t----------------Gestion Des Contactes----------------\t");
    do{
        printf("-------------------------------------------------------------------\n");
        printf("Appuyer sur 1 pour Ajouter un Contact:\n");
        printf("Appuyer sur 2 pour Modifier un Contact:\n");
        printf("Appuyer sur 3 pour Supprimer un Contact:\n");
        printf("Appuyer sur 4 pour Afficher tous les Contacts:\n");
        printf("Appuyer sur 5 pour Rechercher un Contact:\n");
        printf("Appuyer sur 6 pour Sortir du Programme:\n");
        printf("-------------------------------------------------------------------\n");
        printf("Veuiller entrer votre choix:");
        
        scanf("%d",&Choix);
        getchar();

        switch(Choix){
            case 1:
                  AjouterUnContact();
                  break;
            case 2:
                  ModifierUnContact();
                  break;
            case 3:
                  SupprimerUnContact();
                  break;
            case 4:
                  AfficherTousLesContacts();
                  break;
            case 5:
                  RechercherUnContact();
                  break;
            
            case 6:
                  printf("Programme est ferme.");
                  break;
        }


    }while (Choix != 6);



    return 0;
}


