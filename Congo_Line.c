#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct line{
    char pname[100];
    struct line * next;
};
struct line  *head=NULL;
struct line *tail=NULL;
struct line * create(char pname[]){
    struct line * new=(struct line *)malloc(sizeof(struct line));
    strcpy(new->pname,pname);
    new->next=NULL;
    return new;
}
void insert(char pname[]){
    struct line *new=create(pname);
    if(head==NULL){
        tail=head=new;
        return;
    }
    new->next=head;
    head=new;
    printf("%s is added to the congoline\n",pname);
    return;
}
void peek(){
    printf("%s is the first person in the line.\n",tail->pname);
}
void display(){
    struct line* temp=head;
    if(head==NULL){
        printf("No persons in the Congo Lines.\n");
        return;
    }
    while(temp!=NULL){
        printf("%s->",temp->pname);
        temp=temp->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    int op;
    char pname[100];
    printf("op=1 : Add the person\nop=2 : Display the persons\nop=3 : Display the first person\nOtherwise exit\n");
    while (1){
        printf("Enter your option:");
        scanf("%d",&op);
        getchar();
        switch(op){
            case 1:
            fgets(pname,sizeof(pname),stdin);
            pname[strcspn(pname,"\n")]=0;
            insert(pname);
            break;
            case 2:
            display();
            break;
            case 3:
            peek();
            break;
            default:
            printf("Exit");
            return 0;
    }
    }

    return 0;
}
