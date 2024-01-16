#include<stdio.h>
#include<stdlib.h>
#include<string.h>                          //Preprocessor Directives
#include<windows.h>
#include<conio.h>
#define MAX 100

//Structure definition
struct stack
{
    char word[20];
    struct stack *link;
};


//Global variable declaration
struct stack *top1=NULL;
struct stack *top2=NULL;

//isEMPTY 1 function declaration
int isEMPTY1(void);

//isEMPTY 2 function declaration
int isEMPTY2(void);

//isFULL function declaration
int isFULL(struct stack*);

//Push 1 function declaration
void push1(char*);

//Pop 1 function declaration
struct stack *pop1(void);

//Undo function declaration
struct stack *undo(void);

//Redo function declaration
struct stack *redo(void);

//File open function declaration
void file_open(FILE *,char*);

//File append function declaration
int file_append(FILE *);

//File save function declaration
int file_save(FILE *);

//File write function declaration
int file_write(FILE *);

//Display function declaration
void display(void);

//Destroy text editor function declaration
void destroy_text_editor(void);


//Main function declaration
int main()
{

    //Local variable declaration
    char str[1000];
    char temp1[20];
    char ptr[20];
    char *rtp;
    int choice,l,l1,i,k;

    //Structure variable declaration
    struct stack *temp;
    printf("\n\n\n\n");
    for(i=0;i<72;i++)
        printf("*");

    //Printing welcome statement
    printf("    Welcome       ");
    for(i=0;i<66;i++)
        printf("*");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    //Infinite while loop statement for menu-driven execution
    while(1)
    {
        printf("\n");

        //Asking the user to choose a choice from the options given
        printf("Choose a choice from the following:-");
        printf("\n");

        //Displaying text editor option
        printf("1   - Open Text editor");
        printf("\n");

        //Displaying undo option
        printf("2   - Perform Undo Function");
        printf("\n");

        //Displaying Redo option
        printf("3   - Perform Redo Function");
        printf("\n");

        //Displaying save option
        printf("4   - Save the text in file");
        printf("\n");

        //Displaying existed file open option
        printf("5   - Open existed file and see the text in existed file");
        printf("\n");

        //Displaying append option
        printf("6   - Append a file with the text present in text editor");
        printf("\n");

        //Displaying overwrite option
        printf("7   - Overwrite a file with the text present in text editor");
        printf("\n");

        //Displaying current text editor option
        printf("8   - Display Current text editor text");
        printf("\n");

        //Displaying clear data option
        printf("9   - Clear data present in the text editor");
        printf("\n");

        //Displaying exit option
        printf("10  - exit");
        printf("\n\n\n\n");

        //Reading choice from the user
        scanf("%d",&choice);
        fflush(stdin);

        //Switch function to execute the required choice
        switch(choice)
        {
            case 1:
                system("cls");
                if(top1!=NULL)
                {
                    printf("\n\n\n\nYou are giving data to the old text editor");
                    printf("\n\n\n");
                }
                else
                {
                    printf("\n\n\nCreated a new text editor");
                    printf("\n");
                }

            //Asking user to enter write up
            printf("Enter write up consisting below 1000 characters:-");
            printf("\n\n\n\n");

            //Reading text entered by the user
            gets(str);
            k=0;
            for(i=0;1;i++)
            {
                if(str[i]==' ')
                {
                    ptr[k++]='\0';

                    //Pushing the strings into stack 1
                    push1(ptr);
                    k=0;
                    continue;
                }
                if(str[i]=='\0')
                {
                    ptr[k++]='\0';

                    //Pushing the last string into the stack 1
                    push1(ptr);
                    break;
                }
                ptr[k++]=str[i];
            }
            system("cls");
            break;
            case 2:

                //Calling undo function
                temp=undo();
                    l=strlen(str);
                   l1=strlen(temp->word);
                   str[l-l1-1]='\0';
                    system("cls");

                   //Displaying action message
                   printf("\n\n\n\t\t\t\tJob to undo the data entered is successfully done");
                   printf("\n\n\n\n");
                   break;
            break;
            case 3:

                //Calling redo function
                temp=redo();
                   strcat(str," ");
                   strcat(str,temp->word);
                   push1(temp->word);
                    system("cls");

                   //Displaying action message
                   printf("\n\n\n\t\t\t\tJob to redo the data is successfully done");
                   printf("\n\n\n\n");
                   break;
            case 5:
                system("cls");
                printf("\n\n\nEnter the existed file to open:-");
                        printf("\n\n\n\n");
                   scanf("%s",temp1);

                   //Opening new file to save the text
                   FILE *fp=fopen(temp1,"r+");

                   //Checking whether the file exist or not
                   if(fp==NULL)
                   {
                       printf("\n\n\n\t\t\t\t\tfile does not exist");
                       printf("\n\n\n\n");
                       break;
                   }

                   //File open function calling
                   file_open(fp,str);
                   fclose(fp);
                   //Printing string from text editor
                   printf("\n\n\n");
                   puts(str);
                   printf("\n\n\n");
            break;
            case 6:
                system("cls");
                printf("\n\n\n\nEnter the existed file name to append the data in the editor:-");
                        printf("\n\n\n\n");

                        //Reading file name from the user
                   scanf("%s",temp1);
                   FILE *fp1=NULL;
                   fp1=fopen(temp1,"a");

                   //Checking whether the file exist or not
                   if(fp1==NULL)
                   {
                       printf("\n\n\n\t\t\t\t\tfile does not exist");
                       printf("\n\n\n\n");
                       break;
                   }

                   //Inserting space into the file
                   fprintf(fp1," ");

                   //Calling file append function
                   int p=file_append(fp1);

                   //Displaying action message
                   if(p==0)
                    {
                            printf("\n\n\n\t\t\t\t\tAppended in the file successfully");
                            printf("\n\n\n\n");
                    }
                    else
                    {
                            printf("\n\n\n\t\t\t\t\tUnable to append to the file specified");
                            printf("\n\n\n\n");
                    }
                    fclose(fp1);
            break;
            case 4:
                system("cls");
                printf("\n\n\nEnter the new file name to create and save the data in the text editor:-");
                printf("\n\n\n\n");

            //Reading file name from the user
            scanf("%s",temp1);
            FILE *fp2=NULL;
            fp2=fopen(temp1,"w");
            int a=file_save(fp2);
            fclose(fp2);
            system("cls");
            //Displaying action message
            if(a==0)
            {
                    printf("\n\n\n\n\n\t\t\t\t\tFile written successfully");
                    printf("\n\n\n\n");
            }
            else
            {
                    printf("\n\nUnable to overwrite or to write newly in the specified file");
                    printf("\n");
            }
            break;
            case 7:
                system("cls");
                printf("\n\n\nEnter the file name to overwrite the current data in the text editor ");
                        printf("\n\n\n");
                   printf("Note :- If file does not exist, then system creates a new file");
                   printf("\n\n\n\n");

                   //Reading file name from the user
                   scanf("%s",temp1);
                   FILE *fp3=NULL;
                   fp3=fopen(temp1,"w");
                   if(fp3==NULL)
                   {
                       printf("File creation failure");
                       printf("\n");
                       break;
                   }
                   int b=file_write(fp3);

                   //Displaying action message
                   if(b==0)
                    {
                            system("cls");
                            printf("\n\n\n\n\t\t\t\t\tOverwritten successfully");
                            printf("\n\n\n\n");
                    }
                    else
                    {
                            system("cls");
                            printf("\n\n\n\n\t\t\t\t\tUnable to overwrite or to write newly in the specified file");
                            printf("\n");
                    }
                    fclose(fp3);
                    break;
             case 8:
                 system("cls");
                 printf("\n\n\n\nCurrent data in the text editor:-");
                    printf("\n");

                    //Calling display function
                display();
                break;
            case 9:

                //Calling destroy text editor function
                destroy_text_editor();
            break;
                case 10:

                    //Exit command to end the execution of the programme
                    exit(0);
                break;
            default:

                //Asking the user to enter a valid choice
                printf("Enter the valid choice");
            printf("\n");
        }
    }
}


//IsEmpty 1 function definition
int isEMPTY1(void)
{

    //Checking whether the stack is empty or not
    if(top1==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//IsEmpty 2 function definition
int isEMPTY2(void)
{

    //Checking whether the stack is empty or not
    if(top2==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//IsFULL function definition
int isFULL(struct stack *temp)
{

    //Checking whether the stack is full or not
    if(temp==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Push 1 function definition
void push1(char str[])
{

    //Structure variable definition
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));

    //Calling isFULL function
    if(isFULL(temp))
    {
        printf("Stack overflow");
        printf("\n");
        return;
    }

    //Copying string into node word of stack.
    strcpy(temp->word,str);
    temp->link=top1;
    top1=temp;
}


//Pop 1 function definition
struct stack *pop1(void)
{

    //Calling isEMPTY function
    if(isEMPTY1())
    {
        printf("Stack underflow");
        printf("\n");
        return NULL;
    }

    //Structure variable declaration
    struct stack *temp=top1;
    top1=top1->link;
    return temp;
}


//Push 2  function definition
void push2(char str[])
{

    //Structure variable declaration
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));

    //Calling isFULL function
    if(isFULL(temp))
    {
        printf("Stack overflow");
        printf("\n");
        return;
    }

    //Copying string into node word
    strcpy(temp->word,str);
    temp->link=top2;
    top2=temp;
}


//POP 2 function definition
struct stack *pop2(void)
{

    //Calling isEmpty 2 function
    if(isEMPTY2())
    {
        printf("Stack underflow");
        printf("\n");
        return NULL;
    }
    struct stack *temp=top2;
    top2=top2->link;
    return temp;
}


//Undo function definition
struct stack *undo(void)
{
    //Calling isEMPTY 1 function
    if(isEMPTY1())
    {
        return NULL;
    }
    struct stack *temp=top1;
    top1=top1->link;

    //Pushing string into the stack 2
    push2(temp->word);
    return temp;
}


//Redo function definition
struct stack *redo(void)
{
    if(isEMPTY2())
    {
        printf("Redo operation cannot be done with out performing  undo operation");
        printf("\n");
        return NULL;
    }
    struct stack *temp=top2;
    top2=top2->link;
    return temp;
}


//File open function definition
void file_open(FILE *fp,char str[1000])
{

    //Checking whether the file exists or not
    if(fp==NULL)
    {
        return;
    }

    //Structure variable definition
    struct stack *temp;
    while(top1)
    {
        temp=pop1();
    }
    char ptr[1000];
    char ktr[20];

    //Reading text from file and storing it in a string
    fgets(ptr,sizeof(ptr),fp);
    int k=0,i;
            for(i=0;1;i++)
            {
                if(ptr[i]==' ')
                {
                    ktr[k++]='\0';
                    push1(ktr);
                    k=0;
                    str[i]=ptr[i];
                    continue;
                }
                if(ptr[i]=='\0')
                {
                    ktr[k++]='\0';
                    push1(ktr);
                    str[i]=ptr[i];
                    break;
                }
                ktr[k++]=ptr[i];
                str[i]=ptr[i];
            }
}


//File append function definition
int file_append(FILE *fp)
{

    //Checking whether the file exists or not
    if(fp==NULL)
    {
       return;
    }

    //copying text in the string to the file
    struct stack *temp=top1;
    int p,c=0;
    while(temp!=NULL)
    {
        push2(temp->word);
        temp=temp->link;
        c++;
    }
  while(c>0)
  {
      temp=pop2();
      p=fputs(temp->word,fp);
      fprintf(fp," ");
      c--;
  }
    //Returning indication value
    return p;
}



//File save function definition
int file_save(FILE *fp)
{
    //Checking whether the file exists or not
    if(fp==NULL)
    {
        return;
    }

    //copying text in the string to the file
     struct stack *temp=top1;
    int p,c=0;
    while(temp!=NULL)
    {
        push2(temp->word);
        temp=temp->link;
        c++;
    }
  while(c>0)
  {
      temp=pop2();
      p=fputs(temp->word,fp);
      fprintf(fp," ");
      c--;
  }

    //Returning indication value
    return p;
}


//File write function definition
int file_write(FILE *fp)
{

    //Checking whether the file exists or not
    if(fp==NULL)
    {
        return;
    }
    int i;

    //copying text in the string to the file
     struct stack *temp=top1;
    int p,c=0;
    while(temp!=NULL)
    {
        push2(temp->word);
        temp=temp->link;
        c++;
    }
  while(c>0)
  {
      temp=pop2();
      p=fputs(temp->word,fp);
      fprintf(fp," ");
      c--;
  }
    //Returning indication value
    return p;
}


//Display function definition
void display(void)
{

    //Stricture variable declaration
    struct stack *temp=top1;
    int c=0;

    //Traversing through stack of linked list
    while(temp!=NULL)
    {
        push2(temp->word);
        temp=temp->link;
        c++;
    }
    printf("\n\n\n");
    while(c>0)
    {
        temp=pop2();

        //Printing string of each node
        printf("%s ",temp->word);
        c--;
    }
    printf("\n\n\n");
}


//Destroy text editor function definition
void destroy_text_editor(void)
{

    //structure variable declaration
    struct stack *temp;
    while(top1)
    {
        //Calling pop 1 function
        temp=pop1();
    }
    while(top2)
    {
        //Calling pop 2 function
        temp=pop2();
    }

    //Displaying action message
    system("cls");
    printf("\n\n\n\n\t\t\t\t\tText editor is successfully destroyed");
    printf("\n\n\n\n");
}
