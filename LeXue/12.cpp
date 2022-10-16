#include <stdio.h>
#include <stdlib.h>
struct flylist
{
    int number;
    struct flylist *next;
};
typedef struct flylist list;

struct way
{
    int time_left;
    int number;
    int checking;
    int busy;
    int waiting;
};
typedef way Way;

list *rear;
void init(list *&head)
{
    head = (list *)malloc(sizeof(list));
    if (!(head))
        printf("error!");
    head->number = -1;
    head->next = NULL;
    rear = head;
}

void addnode(list *head, int num)
{
    list *p;
    list *q;
    p = (list *)malloc(sizeof(list));
    p->number = num;
    p->next = NULL;
    for (q = head; q->next; q = q->next)
        ;
    q->next = p;
}

void pop(list *head)
{
    list *p;
    p = head->next;
    head->next = p->next;
    free(p);
}

int main()
{
    int a;
    int time = 0;
    int take_off_time;
    int land_time;
    int ways;
    scanf("%d %d %d", &ways, &land_time, &take_off_time);
    list *takeofflist, *landlist;
    init(takeofflist);
    init(landlist);

    int take_off_num = 1, land_num = 5001;
    int takeoff, land;
    int i;
    list *p;
    float busycount = 0;
    int check = 0;
    int countt = 0;
    float takeoff_count = 0, land_count = 0;
    float takeoff_wait = 0, land_wait = 0;
    Way waylist[ways + 1];
    for (i = 1; i <= ways; i++)
    {
        waylist[i].busy = 0;
        waylist[i].number = -1;
        waylist[i].time_left = 0;
        waylist[i].checking = 1;
    }
    printf("Current Time:    0\n");
    while (1)
    {
        check = 0;
        if (land != -1)
        {
            scanf("%d %d", &land, &takeoff);
            takeoff_count += takeoff;
            land_count += land;
        }
        for (i = 1; i <= takeoff; i++)
        {
            addnode(takeofflist, take_off_num);
            take_off_num++;
        }
        for (i = 1; i <= land; i++)
        {
            addnode(landlist, land_num);
            land_num++;
        }
        for (i = 1; i <= ways; i++)
        {
            if (waylist[i].time_left == 0)
            {
                if (landlist->next)
                {
                    waylist[i].number = landlist->next->number;
                    waylist[i].busy += land_time;
                    waylist[i].time_left = land_time;
                    waylist[i].checking = 0;
                    printf("airplane %04d is ready to land on runway %02d\n", landlist->next->number, i);
                    pop(landlist);
                }
                else if (landlist->next == NULL)
                {
                    if (takeofflist->next)
                    {
                        waylist[i].number = takeofflist->next->number;
                        waylist[i].busy += take_off_time;
                        waylist[i].time_left = take_off_time;
                        waylist[i].checking = 0;
                        printf("airplane %04d is ready to takeoff on runway %02d\n", takeofflist->next->number, i);
                        pop(takeofflist);
                    }
                }
            }
        }

        for (p = takeofflist->next; p; p = p->next)
        {
            if (p)
            {
                countt++;
            }
        }
        takeoff_wait += countt;
        countt = 0;
        for (p = landlist->next; p; p = p->next)
        {
            if (p)
            {
                countt++;
            }
        }
        land_wait += countt;
        countt = 0;
        time++;
        printf("Current Time: %4d\n", time);
        for (i = 1; i <= ways; i++)
        {
            if (waylist[i].time_left && waylist[i].time_left != 0)
                waylist[i].time_left--;
            if (waylist[i].time_left == 0 && waylist[i].checking == 0)
            {
                printf("runway %02d is free\n", i);
                waylist[i].checking = 1;
            }
            if (waylist[i].time_left)
                check = 1;
        }
        if (land == -1 && takeoff == -1 && check == 0 && landlist->next == NULL && takeofflist->next == NULL)
            break;
    }
    printf("simulation finished\n");
    printf("simulation time: %4d\n", time);
    printf("average waiting time of landing: %4.1f\n", land_wait / (land_count + 1));
    printf("average waiting time of takeoff: %4.1f\n", takeoff_wait / (takeoff_count + 1));
    for (i = 1; i <= ways; i++)
    {
        printf("runway %02d busy time: %4d\n", i, waylist[i].busy);
        busycount += float(waylist[i].busy);
    }
    printf("runway average busy time percentage: %4.1f%%\n", ((busycount / float(ways)) * 100) / time);
}