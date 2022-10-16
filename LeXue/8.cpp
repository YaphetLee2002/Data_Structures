#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXID 8
#define MAXNAME 15

typedef struct students *Student;
typedef int StuID;

struct students
{
    StuID id;
    char name[MAXNAME];
    Student next;
};

Student CreateStudent(void)
{
    Student S;
    S = (Student)malloc(sizeof(struct students));
    S->next = NULL;
    return S;
}

void GetStudent(Student S)
{
    scanf("%d %s", &(S->id), S->name);
}

void PrintNotIn(Student S)
{
    printf("%d %s is not in LIST1.\n", S->id, S->name);
}

int IsSame(const Student S1, const Student S2)
{
    Student TmpCell;
    TmpCell = CreateStudent();
    TmpCell = S1;
    int flag = 1;
    while (TmpCell != NULL)
    {
        if (TmpCell->id == S2->id)
        {
            flag = 0;
            if (strcmp(TmpCell->name, S2->name))
                return 1;
            else
                return 0;
        }
        TmpCell = TmpCell->next;
    }
    return flag;
}

int main()
{
    int StudentNum;
    Student TmpCell, Student[2];
    TmpCell = CreateStudent();
    int i;
    for (i = 0; i < 2; i++)
    {
        Student[i] = CreateStudent();
        scanf("%d", &StudentNum);
        if (!StudentNum)
        {
            printf("the LIST2 is NULL.\n");
            return 0;
        }
        TmpCell = Student[i];
        for (int j = 0; j < StudentNum; j++)
        {
            GetStudent(TmpCell);
            if (j < StudentNum - 1)
            {
                TmpCell->next = CreateStudent();
                TmpCell = TmpCell->next;
            }
        }
    }
    TmpCell = Student[1];
    int flag = 1;
    while (TmpCell != NULL)
    {
        if (IsSame(Student[0], TmpCell))
        {
            flag = 0;
            PrintNotIn(TmpCell);
        }
        TmpCell = TmpCell->next;
    }
    if (flag)
        printf("the records of LIST2 are all in the LIST1.\n");
    return 0;
}