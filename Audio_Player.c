#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct song{
    char sname[100];
    struct song * next;
};
struct song *head=NULL;
struct song * create(char sname[]){
    struct song * new=(struct song *)malloc(sizeof(struct song));
    strcpy(new->sname,sname);
    new->next=NULL;
    return new;
}
void insert(char sname[]){
    struct song *new=create(sname);
    new->next=head;
    head=new;
    printf("%s is added to the playlist\n",sname);
    return;
}
void display(){
    struct song * temp=head;
    if(temp==NULL){
        printf("No songs are available in the playlist.");
    }
    while(temp!=NULL){
        printf("%s->",temp->sname);
        temp=temp->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    int op;
    char sname[100];
    printf("op=1 : Add the song\nop=2 : Display the song\nop=3 : Otherwise exit\n");
    while (1){
        printf("Enter the op:");
        scanf("%d",&op);
        getchar();
        switch(op){
            case 1:
            fgets(sname,sizeof(sname),stdin);
            sname[strcspn(sname,"\n")]=0;
            insert(sname);
            break;
            case 2:
            display();
            break;
            default:
            printf("Exit");
            return 0;
    }
    }

    return 0;
}
