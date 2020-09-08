#include <stdio.h>
#include <stdlib.h>
#include <time.h>                   //для создания сида рандомизации
#include <graphics.h>        //подключение графической библиотеки
#include <math.h>

#define PI 3.14159265359


int width = 1100;
int hight = 700;



int min_len = 5;
int max_len = 140;
int min_angle = 20;
int max_angle = 60;
int min_len_coef = 8;
int max_len_coef = 10;
int branch_width = 20;
int get_max_iter(int min_len_coef, int max_len, int min_len){
    int count = 0;
    while(max_len>=min_len){
        max_len = (int)((double)(min_len_coef)/10.0  * (double)max_len);
        count++;
    }
    return count;
}
//int max_iter = get_max_iter(min_len_coef, max_len, min_len);

int angle_standart(int angle){
    while(angle<0){
        angle+=360;
    }
    while(angle>=360){
        angle-=360;
    }
    return angle;
}

int get_new_angle(){

    return (rand() % (max_angle-min_angle+1))+min_angle;
}

int get_new_len(int len){
    return len * ((rand() % (max_len_coef-min_len_coef+1))+min_len_coef)/10;
}

void get_branch_point(int *x, int *y, int angle, int len){
    *x = *x - cos((double)angle*PI/(double)180)*len;
    *y = *y - sin((double)angle*PI/(double)180)*len;
}

int get_min_iter(int iter, int max_iter){
    if(iter<max_iter) return iter;
    else return max_iter;
}

void branch(int x, int y, double angle, int len, int iter, int local_max_iter){
    int max_iter =get_min_iter(get_max_iter(min_len_coef, max_len, min_len),local_max_iter);
    if(iter<max_iter){
        iter++;
        int left_branch_angle = angle_standart(angle-get_new_angle());
        int right_branch_angle = angle_standart(angle+get_new_angle());
        //printf("%i %i\n",left_branch_angle,right_branch_angle);

        int xl=x,yl=y;
        get_branch_point(&xl,&yl,left_branch_angle,get_new_len(len));
        int xr=x,yr=y;
        get_branch_point(&xr,&yr,right_branch_angle,get_new_len(len));

        int new_branch_width = (int)((double)branch_width * ((double)(len-min_len)/(double)(max_len-min_len)));
        //printf("%i\n",new_branch_width);
        setlinestyle(SOLID_LINE, 0, new_branch_width);
        line(x,y,xl,yl);
        line(x,y,xr,yr);

        branch(xl,yl,left_branch_angle,(int)(0.8*(double)len), iter, max_iter);
        branch(xr,yr,right_branch_angle,(int)(0.8*(double)len), iter, max_iter);
    }
}

int main()
{
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(width, hight);
    initgraph(&gd, &gm,"");
    setbkcolor(WHITE);
    setcolor(GREEN);
    setlinestyle(SOLID_LINE,0,branch_width);
    int first_x = width/2;
    int first_y = (int)((double)hight*0.9);
    line(first_x,first_y,first_x,first_y - max_len);
    srand(time(NULL));

    branch(first_x,first_y-max_len,90,(int)((double)max_len*0.8),1,100);
    readkey();
    return 0;
}