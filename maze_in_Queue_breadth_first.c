#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 5              //最大行数
#define MAX_COL 5              //最大列数
#define N 4                    //方向数
struct point           //定义路径结点数据结构
{
    int row, col;
    int flag;
    struct point *pre;  //前驱结点指针
    struct point *next; //后继结点指针
}node,*pnode;
void print_maze(void);         //打印迷宫
void visit(int row, int col);  //结点访问函数
void enqueue(struct point *p); //入队操作函数
struct point *dequeue(void);   //出队操作函数
int is_empty(void);            //测试队列是否为空函数
struct point *front0 = NULL, *front = NULL, *rear = NULL;
int maze[MAX_ROW][MAX_COL] = {
    //0可以经过，1不可以
    0,1,1,0,0,
    0,0,1,1,1,
    0,0,0,0,0,
    1,0,1,1,0,
    0,1,0,0,0,
};
int stepx[N] = {0, 0, -1, 1}; //方向数组，大小为4
int stepy[N] = {-1, 1, 0, 0};
int n = 2; //访问步骤
int main(void)
{
    struct point *p;
    int i;
    p = (struct point *)malloc(sizeof(struct point));
    p->col = 0;
    p->row = 0;  //初始行列
    p->flag = 0; //未处理标志
    p->next = NULL;
    p->pre = NULL;
    maze[p->row][p->col] = 2; //2表示迷宫的入口
    front0 = p;               //链表头指针指向第一个起始结点（0，0）
    enqueue(p);               //入队列
    while (!is_empty())       //当队列中有可访问节点时操作
    {
        p = dequeue(); //p指向出队结点
        n++;
        if (p->row == MAX_ROW - 1 && p->col == MAX_COL - 1)
            break;
        for (i = 0; i < N; i++)
        {
            if (p->row + stepy[i] < 0 || p->col + stepx[i] < 0)
                continue;
            if (p->row + stepy[i] < MAX_ROW && p->col + stepx[i] < MAX_COL && maze[p->row + stepy[i]][p->col + stepx[i]] == 0)
                visit(p->row + stepy[i], p->col + stepx[i]); //表示可通行
        }
    }
    if (p->row == MAX_ROW - 1 && p->col == MAX_COL - 1)
    {
        print_maze();
        p = front0;   //初始化遍历指针
        while(p != NULL)
        {
            printf("(%d,%d)\t%p\n", p->row, p->col, p);
            p = p->next;
        }
    }
    else
        printf("No path!");
    return 0;
}
void enqueue(struct point *p)
{
    if(rear == NULL)
        rear = p;
    else
    {
        rear->next = p;
        rear = rear->next;
    }
    if(front == NULL)
        front = p;
}
struct point *dequeue(void)    //出队
{
    struct point *p = front;         //“front”指向队列未处理的第一个结点
    if(front != NULL)
    {
        front->flag = 1;       //表示处理过
        front = front->next;
    }
    return p;
}
int is_empty(void)
{
    return(front == rear && (front->flag == 1));        //队列中仅有一结点并且已经处理过，队列为空队列
}
void print_maze(void)
{
    int i, j;
    for(i=0; i<MAX_ROW; i++)
    {
        for(j=0; j<MAX_COL; j++)
            printf("%3d ", maze[i][j]);
        putchar('\n');
    }
}
void visit(int row, int col)
{
    struct point *p;
    maze[row][col] = n;
    p = (struct point *)malloc(sizeof(struct point));     //创建新结点
    p->col = col;
    p->row = row;
    p->flag = 0;
    p->pre = rear;
    p->next = NULL;
    enqueue(p);             //入队
}

