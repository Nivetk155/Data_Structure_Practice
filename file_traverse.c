
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file {
    char fname[150];
    struct file *next;
    struct file *prev;
};
struct file *head=NULL;
struct file *tail=NULL;
//InserAtBegin the filename
void push_files(char *fname){
    struct file *new=(struct file*)malloc(sizeof(struct file));
    strcpy(new->fname,fname);
    new->prev=NULL;
    new->next=head;
    if(head==NULL){
        head=new;
    }
    else
    {
        head->prev=new;
        head=new;
    }
    printf("file %s added in the directory\n",fname);
}
//display the songs
void display_file(){
    struct file *temp=head;
    if(temp==NULL){
        printf("directory is empty....\n");
        return;
    }
    while(temp->next!=NULL){
        printf("%s\n",temp->fname);
        temp=temp->next;
    }
}
//diplaying files in forward
void file_prev(){
    struct file *temp=head;
    if(temp==NULL){
        printf("no files to display...\n");
        return;
    }
    while(temp!=NULL){
        printf("displaying: %s\n",temp->fname);
        temp=temp->prev;
    }
}
//displaying files in backword
void file_next(){
    struct file *temp=tail;
    if(temp==NULL){
        printf("no files to display...\n");
        return;
    }
    while(temp!=NULL){
        printf("displaying:%s\n",temp->fname);
        temp=temp->next;
    }
}
//main function
int main(){
    int choice;
    char fname[150];
    while(1){
        printf("********File Traverse*********\n");
        printf("1.Add file...\n");
        printf("2.Display forward file..\n");
        printf("3.Display backward file..\n");
        printf("4:Display all files..\n");
        printf("choice:\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
            printf("Enter the file name to push:");
            fgets(fname,sizeof(fname),stdin);
            fname[strcspn(fname, "\n")] = '\0';
            push_files(fname);
            break;
            case 2:
            file_prev();
            break;
            case 3:
            file_next();
            break;
            case 4:
            display_file();
            break;
            default:
            printf("invalid choice..\n");
            }
    }
}

