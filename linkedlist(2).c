#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int insertend(struct node* head, int data){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp=head;
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
struct node* insertbeg(struct node* head, int data){
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
int insertafter(struct node* ins, int data){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=ins->next;
    ins->next=temp;
}
struct node* deletehead(struct node* head){
    head=head->next;
}
int deleteend(struct node* head){
    struct node* temp=malloc(sizeof( struct node));
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }temp->next=NULL;
}
int deleteafter(struct node* ins, struct node* head){
    struct node* temp=malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=ins){
        temp=temp->next;
    }temp->next=temp->next->next;
    
}
int main(){
    struct node* head;
    head=malloc(sizeof(struct node));
    head->data=5;
    head->next=NULL;
    struct node*second;
    second=malloc(sizeof(struct node));
    second->data=10;
    second->next=NULL;
    head->next=second;
    insertend(head, 15);
    insertend(head, 20);
    head=deletehead(head);
    insertafter(head->next,34);
    deleteafter(head->next, head);
    head = insertbeg(head, 0);
    struct node* hehe;
    hehe=head;
    deleteend(head);
    printf("%d ", hehe->data);
    while(hehe->next!=NULL){
        hehe=hehe->next;
        printf("%d ", hehe->data);
    }
}
