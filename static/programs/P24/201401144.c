#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int x,val;
struct btree {
    int value;
    struct btree *left;
    struct btree *right;
    int depth;
    int lnodes;
    int rnodes;
};
void refreshnodes(struct btree* head){
    int n1,n2;
    if(head->right==NULL)
        n1=0;
    else{
        n1=head->right->rnodes;
        n1+=head->right->lnodes;
        n1+=1;
    }
    if(head->left==NULL)
        n2=0;
    else{
        n2=head->left->rnodes;
        n2+=head->left->lnodes;
        n2+=1;
    }
    head->lnodes=n2;
    head->rnodes=n1;
    return;
}
struct btree* rr(struct btree* head){
    struct btree *oldheadleft = head->left;
    struct btree *oldheadzright = head->left->right;
    oldheadleft->right = head;
    head->left = oldheadzright;
    int h1,h2;
    if(head->left==NULL)h1=0;
    else h1=head->left->depth;
    if (head->right==NULL) {
        h2=0;
    }else
        h2=head->right->depth;
    if (h1>h2) {
        head->depth=h1+1;
    }else
        head->depth=h2+1;
    if(oldheadleft->left==NULL)h1=0;
    else h1=oldheadleft->left->depth;
    if (oldheadleft->right==NULL) {
        h2=0;
    }else
        h2=oldheadleft->right->depth;
    if (h1>h2) {
        oldheadleft->depth=h1+1;
    }else
        oldheadleft->depth=h2+1;
    refreshnodes(head);
    refreshnodes(oldheadleft);
    return oldheadleft;
}
struct btree* lr(struct btree* head){
    struct btree *oldheadright = head->right;
    struct btree *oldheadzleft = head->right->left;
    oldheadright->left = head;
    head->right = oldheadzleft;
    int h1,h2;
    if(head->left==NULL)h1=0;
    else h1=head->left->depth;
    if (head->right==NULL) {
        h2=0;
    }else
        h2=head->right->depth;
    if (h1>h2) {
        head->depth=h1+1;
    }else
        head->depth=h2+1;
    if(oldheadright->left==NULL)h1=0;
    else h1=oldheadright->left->depth;
    if (oldheadright->right==NULL) {
        h2=0;
    }else
        h2=oldheadright->right->depth;
    if (h1>h2) {
        oldheadright->depth=h1+1;
    }else
        oldheadright->depth=h2+1;
    refreshnodes(head);
    refreshnodes(oldheadright);
    return oldheadright;
}
int sub(struct btree *head)
{
    if (head == NULL)
        return 0;
    int h1,h2;
    if(head->left==NULL)h1=0;
    else h1=head->left->depth;
    if (head->right==NULL) h2=0;
    else h2=head->right->depth;
    return h1 - h2;
}
struct btree* insertavl(struct btree *head,int k){
    if(head==NULL){
        struct btree *temp=(struct btree*)malloc(sizeof(struct btree));
        temp->value=k;
        temp->left=NULL;
        temp->right=NULL;
        temp->depth = 1;
        temp->lnodes=0;
        temp->rnodes=0;
        return temp;
    }
    else if(head->value>k){
        head->left=insertavl(head->left,k);
        head->lnodes++;
    }
    else if(head->value<=k){
        head->right=insertavl(head->right,k);
        head->rnodes++;
    }
    int h1,h2;
    if(head->left==NULL)h1=0;
    else h1=head->left->depth;
    if (head->right==NULL) {
        h2=0;
    }else
        h2=head->right->depth;
    if (h1>h2) {
        head->depth=h1+1;
    }else
        head->depth=h2+1;
    int temp;
    temp=sub(head);
    if (temp > 1 && k < head->left->value)
        return rr(head);
    if (temp < -1 && k > head->right->value)
        return lr(head);
    if (temp > 1 && k > head->left->value)
    {
        head->left =  lr(head->left);
        return rr(head);
    }
    if (temp < -1 && k < head->right->value)
    {
        head->right = rr(head->right);
        return lr(head);
    }
    return head;
}
int counting(struct btree *head, int count)
{
    if(head != NULL)
    {
        if (head->value==x) {
            count+=head->lnodes;
            return count;
        }else if(head->value<x){
            return counting(head->right, count+head->lnodes+1);
        }
        else{
            return counting(head->left, count);
        }
    }
    return count;
}
void nth(struct btree *head,int x)
{
    if(head != NULL)
    {
        if(head->lnodes<x){
            if (head->lnodes+1==x) {
                val=head->value;
                return;
            }
            else{
            nth(head->right,x - head->lnodes -1);
            }
        }else
            nth(head->left,x);
        return;
    }
    return;
}
int check(struct btree* head,int x){
    if (head==NULL) {
        return 0;
    }
    if (x==head->value) {
        return 1;
    }
    if(x<head->value){
        return check(head->left, x);
    }else return check(head->right, x);
}
int main() {
    char cmd[25];
    struct btree *root = NULL;
    while (1) {
        scanf("%s",cmd);
        if (!strcmp(cmd,"Quit")){
            break;
        }
        if (!strcmp(cmd, "CheckHealthy")) {
            int temp;
            scanf("%d",&temp);
            if(check(root,temp)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else if (!strcmp(cmd, "SetHealthy")) {
            int temp;
            scanf("%d",&temp);
            root=insertavl(root,temp);
            //printf("%d- %d -%d", root->lnodes,root->value,root->rnodes);
        }else if (!strcmp(cmd, "Healthy")) {
            int x;
            scanf("%d",&x);
            val=0;
            nth(root,x);
            if (val!=0)
                printf("%d\n",val);
            else
                printf("NONE\n");
        }else if (!strcmp(cmd, "RottenBefore")) {
            int count;
            scanf("%d",&x);
            count=0;
            printf("%d\n",counting(root,count));
        }
    }
    return 0;
}
