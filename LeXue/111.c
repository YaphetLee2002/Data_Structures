#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
struct op
{
        char c;
        struct op *before,*next;
};
 
struct number
{
        int num;
        struct number *before,*next;
};
 
void push_number(struct number *head2 ,char *ch,struct number *p2,int fu)
{
        p2->num=atoi(ch);
        if (fu)
        {
                p2->num=-p2->num;
        }
        p2->next=NULL;
        p2->before=head2;
        head2->next=p2;
}
 
void push_op(struct op *head1 ,char ch,struct op *p1)
{
        p1->c=ch;
        p1->next=NULL;
        p1->before=head1;
        head1->next=p1;
}
 
char pop_op(struct op *head1)
{
        struct op *tem;
        char x=head1->c;
        head1->before->next=NULL;
        tem=head1->before;
        free(head1);
        head1=tem;
        return x;
}
 
int pop_number(struct number *head2)
{
        struct number *tem;
        int x=head2->num;
        head2->before->next=NULL;
        free(head2);
        head2=tem;
        return x;
}
 
int compare(char ch1, char ch2)
{
        if (ch1=='(' && ch2==')')
        {
                return 2;
        }
        if ((ch1==ch2&&ch1=='^') || ((ch1=='+' || ch1=='-')&&(ch2=='*' || ch2=='/' || ch2=='%')) || ((ch1=='+'||ch1=='-'||ch1=='*'||ch1=='/'||ch1=='%')&&(ch2=='^')) || ch1=='(' || ch2=='(' )
        {
                return -1;
        }
        else if ((ch1==ch2&&ch1!='^') || ((ch2=='+' || ch2=='-')&&(ch1=='*' || ch1=='/' || ch1=='%')) || ((ch2=='+'||ch2=='-'||ch2=='*'||ch2=='/'||ch2=='%')&&(ch1=='^')) || ch1==')' || ch2==')' )
        {
                return 1;
        }
        else if ((ch1=='+'&&ch2=='-') || (ch1=='-'&&ch2=='+') || (ch1=='*'&&ch2=='/') || (ch1=='/'&&ch2=='*'))
        {
                return 1;
        }
        else return 0;
}
 
int oper(int a,int b,char op)
{
        switch (op)
        {
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
        case '^': return pow(b,a);
        case '%': return b%a;
        }
}
 
void main()
{
        int n,i,j,k=0,m,len,res,num1,num2,num3,flag=0,op_size=0,flag1,flag2,div0,error_ks,unkonwn,fu;
        struct op *p1,*q1,*head1;
        struct number *p2,*q2,*head2;
        char str[100],ch,op1,op2,temp[20],tem_num[20],pre;
 
        scanf("%d",&n);
        getchar();
 
        for (i=0;i<n;i++)
        {
                pre='\0';
                fu=0;
                unkonwn=0;
                error_ks=0;
                div0=0;
                op_size=0;
                gets(str);
                len=strlen(str);
                head1=(struct op*)malloc(sizeof(struct op));
                head2=(struct number*)malloc(sizeof(struct number));
                head1->next=head1->before=NULL;
                head2->next=head2->before=NULL;
                head1->c='\0';
 
                for (j=0;j<len;j++)
                {
                        if ((pre<='9'&&pre>='0'&&str[j]=='(') || (pre==')'&&(str[j]<='9' && str[j]>='0')) || (pre==')'&&str[j]=='('))
                        {
                                error_ks=1;
                                break;
                        }
                        if (((pre=='+' || pre=='-' || pre=='*' || pre=='/')&&str[j]=='-') || (pre=='\0'&&str[j]=='-') || (pre=='('&&str[j]=='-'))
                        {
                                fu=1;
                                continue;
                        }
                        if (str[j]<='9' && str[j]>='0')
                        {
                                flag=1;
                                tem_num[k++]=str[j];
                                
                        }
                        else        // insert fuhao
                        {
                                if (flag==1)
                                {
                                        tem_num[k]='\0';
                                        p2=(struct number *)malloc(sizeof(struct number));
                                    push_number(head2,tem_num,p2,fu);
                                        fu=0;
                                        p2->next=head2;
                                    head2=p2;
                                        flag=0;
                                        k=0;
                                        tem_num[0]='\0';
                                }
                                if (op_size==0)
                                {
                                        p1=(struct op*)malloc(sizeof(struct op));
                                        push_op(head1,str[j],p1);
                                        p1->next=head1;
                                        head1=p1;
                                        op_size++;
                                }
                                else
                                {
                                        res=compare(head1->c,str[j]);
                                        if (res==-1)
                                        {
                                                p1=(struct op*)malloc(sizeof(struct op));
                                                push_op(head1,str[j],p1);
                                                p1->next=head1;
                                                head1=p1;
                                                op_size++;
                                        }
                                        else if (res==2)
                                        {
                                                head1=head1->before;
 
                                                pop_op(head1->next);
                                                op_size--;
                                        }
                                        else if (res==1)
                                        {
                                                head1=head1->before;
                                                op1=pop_op(head1->next);
                                                op_size--;
                                                head2=head2->before;
                                                
                                                num1=pop_number(head2->next);
                                                head2=head2->before;
                                                if (head2==NULL)
                                                {
                                                        unkonwn=1;
                                                        break;
                                                }
                                                num2=pop_number(head2->next);
                                                if (op1=='/' && num1==0)
                                                {
                                                        printf("Divide 0.\n");
                                                        div0=1;
                                                        break;
                                                }
                                                if (op1=='^' && num1<0)
                                                {
                                                        error_ks=1;
                                                        break;
                                                }
                                                num3=oper(num1,num2,op1);
                                                sprintf(temp,"%d",num3);
                                                p2=(struct number *)malloc(sizeof(struct number));
                                                push_number(head2,temp,p2,0);
                                                p2->next=head2;
                                                head2=p2;
                                                
                                                j--;
                                        }
                                }
                        }
                        pre=str[j];
                }
                if (error_ks || unkonwn)
                {
                        printf("error.\n");
                        error_ks=unkonwn=0;
                        continue;
                }
                if (div0)
                {
                        div0=0;
                        continue;
                }
                if (tem_num[0]!='\0')
                {
                        tem_num[k]='\0';
                        p2=(struct number *)malloc(sizeof(struct number));
                    push_number(head2,tem_num,p2,fu);
                        p2->next=head2;
                           head2=p2;
                        flag=0;
                        k=0;
                        tem_num[0]='\0';
                }
 
                flag1=0;
                flag2=0;
                q1=head1;
                k=op_size;
 
                if (q1->next==NULL && q1->before!=NULL &&q1->before->c!='\0')
                q1=q1->before;
                while(k!=0)
                {
                        ch=q1->c;
                        if (ch=='(')
                        {
                                flag1++;        
                        }
                        else if (ch==')')
                        {
                                flag2++;
                        }
                        k--;
                        q1=q1->next;
                         
                }
                if (flag1!=flag2)
                {
                        printf("error.\n");
                        continue;
                }
 
                while(op_size!=0)
                {
                        head1=head1->before;
                        op1=pop_op(head1->next);
                        op_size--;
                        head2=head2->before;
                        if (head2==NULL)
                        {
                                error_ks=1;
                                printf("error");
                                break;
                        }
                        num1=pop_number(head2->next);
                        head2=head2->before;
                        if (head2==NULL)
                        {
                                error_ks=1;
                                printf("error.\n");
                                break;
                        }
                        num2=pop_number(head2->next);
                        if (op1=='/' && num1==0)
                        {
                                printf("Divide 0.\n");
                                div0=1;
                                break;
                        }
                        if (op1=='^' && num1<0)
                        {
                                error_ks=1;
                                printf("error.\n");
                                break;
                        }
                        num3=oper(num1,num2,op1);
                        sprintf(temp,"%d",num3);
                        p2=(struct number *)malloc(sizeof(struct number));
                        push_number(head2,temp,p2,0);
                        p2->next=head2;
                        head2=p2;
                }
                if (div0 || error_ks)
                {
                        div0=0;
                        error_ks=0;
                        continue;
                }
 
                printf("%d\n",pop_number(head2));
        }
}