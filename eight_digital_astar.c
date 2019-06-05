#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define MAX_size 362880 //9的阶乘9!=362880

typedef struct node
{
    int array[3][3];
    int i_0;
    int j_0;             //空格“0”位置
    int depth;           //搜索深度
    int wrong_number;    //曼哈顿距离平方之和
    int value;           //总代价(采用log10(depth)+
    struct node *father; //指向父节点指针
} node, *p_node;

typedef struct list //顺序表结构体
{
    p_node graph[MAX_size];
    long length;
} list, *p_list;

int Answer_or_not(p_node start_graph,p_node end_graph);   //判断有无解
void initial_node();                           //初始化始末状态节点
int Cal_wrong(p_node graph);                   //计算各棋子不在正确位置的数目
int Evaluate(p_node graph);                    //估价函数
void Print_node(p_node graph);                 //输出八数码
void add_list(p_list list, p_node graph);      //加入结点到OPEN表中或CLOSE表中
void delete_list(p_list list);                 //从OPEN表或CLOSE中删除结点
int Equal_judge(p_node graph1, p_node graph2); //判断两节点是否相等
void move(p_node graph);                       //移动父节点并加入未探索表中（扩展结点）
void list_reverse(p_node n);                   //将链表逆序
int search_list(p_list list, p_node graph);    //对表进行查找，成功返回1
void sort_list(p_list list);                   //对OPEN表进行排序（按f值从小到大）
void copy_node(p_node graph1, p_node graph2);  //生成新的结点（将graph2赋值给graph1）
int up_mov(p_node graph);                      //空格上移
int down_mov(p_node graph);                    //空格下移
int left_mov(p_node graph);                    //空格左移
int right_mov(p_node graph);                   //空格右移

p_node start_graph, end_graph;
p_list OPEN, CLOSED;

static int array1[3][3] = {1,2,3,4,5,6,7,8,0}; //初始位置
static int array2[3][3] = {8,7,6,5,4,3,2,1,0}; //目标位置
static int open_number;
static int steps;

//2,6,4,1,3,7,0,5,8
//8,1,5,7,3,6,4,0,2

//1,2,3,4,5,6,7,8,0
//4,1,2,7,5,3,8,0,6

//2,8,3,1,6,4,7,0,5
//1,2,3,7,8,4,0,6,5

//1,2,3,4,5,6,7,8,0
//1,2,3,7,4,5,8,0,6,（成功案例）

int main(void)
{
    start_graph = (p_node)malloc(sizeof(node)); //初始节点
    end_graph = (p_node)malloc(sizeof(node));   //目标节点

    OPEN = (p_list)malloc(sizeof(list));   //OPEN表
    CLOSED = (p_list)malloc(sizeof(list)); //CLOSE表
    initial_node();
    printf("=========================================================\n\n");
    clock_t start=clock();
    while (OPEN->length != 0 && CLOSED->length <= 1000000) //最多循环次数1000
    {
        p_node n = OPEN->graph[0]; //把Open表的"第一个节点"取出放入Closed表，并记该节点为n
        delete_list(OPEN);         //移动到close之后就删掉
        if (Equal_judge(n, end_graph)) //考察节点n是否为目标节点。
        {
            //list_reverse(n); //逆序
            clock_t end=clock();
            printf("Searching time is:%d ms\n",end-start);
            while (n)
            {
                steps++;
                printf("The %d th step:\n", n->depth + 1);
                Print_node(n);
                n = n->father;
            }
            break;
        }
        add_list(CLOSED, n);
        move(n);         //扩展位于close表中的结点n
        sort_list(OPEN); //扩展一次就进行一次新的排序
    }
    if (OPEN->length == 0 || CLOSED->length > 1000000)
    {
        printf("\nNo suitable path!\n\n");
    }
    printf("The shortest path is %d steps!\n",steps);
    printf("\nExtension node is %d\n",open_number);
    return 0;
}

void initial_node()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            start_graph->array[i][j] = array1[i][j];
            if (start_graph->array[i][j] == 0)
            {
                start_graph->i_0 = i;
                start_graph->j_0 = j; //记住0的位置
            }
        }
    }
    start_graph->depth = 0;
    start_graph->father = NULL;
    start_graph->wrong_number = Cal_wrong(start_graph);
    start_graph->value = Evaluate(start_graph);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            end_graph->array[i][j] = array2[i][j];
            if (end_graph->array[i][j] == 0)
            {
                end_graph->i_0 = i;
                end_graph->j_0 = j;
            }
        }
    }
    end_graph->depth = 0;
    end_graph->wrong_number = Cal_wrong(end_graph);
    end_graph->value = Evaluate(end_graph);

    OPEN->length = 0;
    CLOSED->length = 0;

    add_list(OPEN, start_graph); //初始结点加入OPEN表中

    printf("The initial node is:\n");
    Print_node(start_graph);

    printf("The end node is:\n");
    Print_node(end_graph);
}

void add_list(p_list list, p_node graph) //加入结点到OPEN表中或CLOSE表中
{
    list->graph[list->length] = graph;
    list->length++;
}

void delete_list(p_list list) //从OPEN表或CLOSE中删除结点
{
    int i;
    for (i = 0; i < list->length; i++)
    {
        list->graph[i] = list->graph[i + 1]; //“压缩”
    }
    list->length--;
}

int Evaluate(p_node graph) //估价函数
{
    return (log10(graph->depth+1) + graph->wrong_number);
}

void Print_node(p_node n) //输出八数码
{
    int i, j;
    printf("-------------------");
    printf(" x=%d,y=%d\n", n->i_0, n->j_0);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%5d", n->array[i][j]);
        }
        printf("\n");
    }
    printf("-------------------");
    printf("depth=%d,wrong_number=%d,value=%d\n", n->depth, n->wrong_number, n->value);
}

int Cal_wrong(p_node graph) //计算任意状态下相同数字间曼哈顿距离之和
{
    int count = 0;
    int i1, j1, i2, j2, k;
    //for (i = 0; i < 3; i++)
        //for (j = 0; j < 3; j++)
            //if (graph->array[i][j] != array2[i][j])
                //count++;
    for(k=1;k<=8;k++)
        for (i1 = 0; i1 < 3; i1++)
            for (j1 = 0; j1 < 3; j1++)
                if (graph->array[i1][j1] == k)
                        for (i2 = 0; i2 < 3; i2++)
                            for (j2 = 0; j2 < 3; j2++)
                                if (array2[i2][j2] == k)
                                    count+=pow((abs(i1-i2)+abs(j1-j2)),2);
    return count;
}

int left_mov(p_node graph) //空格左移
{
    int x = graph->i_0, y = graph->j_0;
    if (y == 0)
        return 0;
    int temp;
    temp = graph->array[x][y];
    graph->array[x][y] = graph->array[x][y - 1];
    graph->array[x][y - 1] = temp;
    graph->j_0--;
    return 1;
}

int right_mov(p_node graph) //空格右移
{
    int x = graph->i_0, y = graph->j_0;
    if (y == 2)
        return 0;
    int temp;
    temp = graph->array[x][y];
    graph->array[x][y] = graph->array[x][y + 1];
    graph->array[x][y + 1] = temp;
    graph->j_0++;
    return 1;
}

int up_mov(p_node graph) //空格上移
{
    int x = graph->i_0, y = graph->j_0;
    if (x == 0)
        return 0;
    int temp;
    temp = graph->array[x][y];
    graph->array[x][y] = graph->array[x - 1][y];
    graph->array[x - 1][y] = temp;
    graph->i_0--;
    return 1;
}

int down_mov(p_node graph) //空格下移
{
    int x = graph->i_0, y = graph->j_0;
    if (x == 2)
        return 0;
    int temp;
    temp = graph->array[x][y];
    graph->array[x][y] = graph->array[x + 1][y];
    graph->array[x + 1][y] = temp;
    graph->i_0++;
    return 1;
}

int Equal_judge(p_node graph1, p_node graph2) //判断两节点是否相等
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (graph1->array[i][j] != graph2->array[i][j])
                return 0;
        }
    }
    return 1;
}

void copy_node(p_node graph1, p_node graph2) //生成新的结点（将graph2赋值给graph1）
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            graph1->array[i][j] = graph2->array[i][j];
        }
    }
    graph1->i_0 = graph2->i_0;
    graph1->j_0 = graph2->j_0;
    graph1->depth = graph2->depth;
    graph1->wrong_number = graph2->wrong_number;
    graph1->value = graph2->value;
    graph1->father = graph2->father;
}

int search_list(p_list list, p_node graph) //对表进行查找，成功返回1
{
    int i;
    for (i = 0; i < list->length; i++)
    {
        if (Equal_judge(list->graph[i], graph))
            return 1;
    }

    return 0;
}

void move(p_node graph) //（扩展结点，将合法子节点都放入OPEN：可移动，不与父节点相同，在CLOSE和OPEN中未出现）
{
    p_node p1 = (p_node)malloc(sizeof(node));
    p_node p2 = (p_node)malloc(sizeof(node));
    p_node p3 = (p_node)malloc(sizeof(node));
    p_node p4 = (p_node)malloc(sizeof(node));
    copy_node(p1, graph);
    copy_node(p2, graph);
    copy_node(p3, graph);
    copy_node(p4, graph);
    p1->father = graph;
    p2->father = graph;
    p3->father = graph;
    p4->father = graph;
    //如果能够进行移动且在CLOSED表中不存在，则加入OPEN表中(将所有合法的子节点都加入OPEN)
    if (left_mov(p1) && (!Equal_judge(p1, p1->father)) && (!search_list(CLOSED, p1)) && (!search_list(OPEN, p1)))
    {
        open_number++;
        add_list(OPEN, p1);
        p1->depth += 1;
        p1->wrong_number = Cal_wrong(p1);
        p1->value = Evaluate(p1);
    }
    else
        free(p1);

    if (right_mov(p2) && (!Equal_judge(p2, p2->father)) && (!search_list(CLOSED, p2)) && (!search_list(OPEN, p2)))
    {
        open_number++;
        add_list(OPEN, p2);
        p2->depth += 1;
        p2->wrong_number = Cal_wrong(p2);
        p2->value = Evaluate(p2);
    }
    else
        free(p2);

    if (up_mov(p3) && (!Equal_judge(p3, p3->father)) && (!search_list(CLOSED, p3)) && (!search_list(OPEN, p3)))
    {
        open_number++;
        add_list(OPEN, p3);
        p3->depth += 1;
        p3->wrong_number = Cal_wrong(p3);
        p3->value = Evaluate(p3);
    }
    else
        free(p3);

    if (down_mov(p4) && (!Equal_judge(p4, p4->father)) && (!search_list(CLOSED, p4)) && (!search_list(OPEN, p4)))
    {
        open_number++;
        add_list(OPEN, p4);
        p4->depth += 1;
        p4->wrong_number = Cal_wrong(p4);
        p4->value = Evaluate(p4);
    }
    else
        free(p4);
}

void sort_list(p_list list) //对OPEN表进行排序，插入法排序（按f值从小到大）
{
    p_node temp = (p_node)malloc(sizeof(node));
    int i, j;
    for (i = 1; i < list->length; i++)
    {
        copy_node(temp,list->graph[i]);
        for (j = i - 1; j >= 0 && list->graph[j]->value > list->graph[i]->value; j--)
            copy_node(list->graph[j + 1], list->graph[j]);
        copy_node(list->graph[j + 1], temp);
    }
}

void list_reverse(p_node n) //   将Close链表逆序
{
    p_node p1, p2;
    p1 = NULL;
    p2 = n->father;
    while (n)
    {
        n->father = p1;
        p1 = n;
        if (p2 == NULL)
            break;
        n = p2;
        p2 = p2->father;
    }
}
