#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct hint{
    char hname[200];
    struct hint * next;
};
struct hint *head=NULL;
struct hint * create(char hname[]){
    struct hint * new=(struct hint *)malloc(sizeof(struct hint));
    strcpy(new->hname,hname);
    new->next=NULL;
    return new;
}
void insert(char hname[]){
    struct hint *new=create(hname);
    if (head==NULL){
    head=new;
    }
    else{
    struct hint *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    }
    printf("%s is added to the hunt\n",hname);
    return;
}
void display(){
    if(head==NULL){
        printf("No hints are available\n");
        return;
    }
    struct hint * temp=head;
    while(temp!=NULL){
        printf("%s->",temp->hname);
        temp=temp->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    int op;
    char hname[200];
    printf("Welcome to Scavenger Hunt...\n");
    printf("op=1 : Add the hint\nop=2 : Display the hints\nOtherwise exit\n");
    while (1){
        printf("Enter your options:");
        scanf("%d",&op);
        getchar();
        switch(op){
            case 1:
            fgets(hname,sizeof(hname),stdin);
            sname[strcspn(hname,"\n")]=0;
            insert(hname);
            break;
            case 2:
            display();
            printf("Congratulations Scavenger..!!\nYou won the hunt..!!\n");
            default:
            printf("Exit");
            return 0;
    }
    }

    return 0;
}
