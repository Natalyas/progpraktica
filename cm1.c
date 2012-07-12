#include <stdio.h>
int t,k,l;

int gaus(double **a ,int y,int n)
{// метод жордана гаусса
   int i, j, z;
   double m;
   i=k; j=l;
   m=a[k][l];
       for(z=0 ; z<=y ; z++)
       {
           a[k][z]=a[k][z]/m;
       }
       for (z=0; z<=n ;z++) 
       {
           for (j=0 ; j<=y+1 ; j++)
           { 
               if (z!=k)
               {
                  if (j!=l)
                  { 
                     a[z][j]=a[z][j]-a[z][l]*a[k][j];
                  }
               }
           }
       }
       for(i=0; i<=n ;i++)
       { 
           if (i!=k) 
           {
              a[i][l]=0;
           }
       }
return 0;
}
int proverca(double **a ,int n,int y)//
{  int i,j,z;
   double min;
do{//цикл в котором производится изменение свободных членов, приводя к стандартному виду задачи, решаемой симплекс методом, с неотрицательными правыми частями
     t=2;//указатель ищет отрицательные правые части
     for( i=0; i<n ; i++ )//ищем минимальный отрицательный свободный член уравнения системы ограничений
     {
        if (a[i][y]<0) //ищем любой отрицательный свободный член(с.ч)
        {
           t=t-1;//индексируем то что нам нужно устранить отриц. своб.член
           if (t==1) { 	min=a[i][y];} 
	       k=i;
        }
        if (a[i][y]<min) //сравниваем с минимумом
        {
            min=a[i][y]; k=i;//приравниваем к минимуму
     }
     if (t==2) return 0;//если нет отриц. своб. член. то нам нужно выйти из этой функции
     z=2;	//счетчик проверки наличия
     for (j=0 ; j<y ; j++)//ищем отрицательный коэффициент при х в той же строкегде был найден минимальный своб.член.
     {
	    if (a[k][j]<0) 
        {    z=z-1;   
	       if (t!=2) 
           {
		       l=j;
		       gaus(a,y,n);//когда найдена разрешающая строка и разрешающий столбец
		       j=y;
		    }
	    }     
      }
      if (z==2){ printf("нет решения"); return 0;}
   }while(t!=2);
   return 0;
}
int ocenki(double **a, double *bb, int n, int y )
{  double min;
   int  i,j;
       for (j=0; j<y ; j++)
      { 
          a[n+1][j]=0;
      }
      for (j=0; j<y ; j++)
      {
 	       if (y-n<=0)
                {        
                    for (i=0; i<n ; i++)
                    {
                     a[n+1][j]=a[n+1][j]+a[i][j]*a[i][y];
                    }
                    a[n+1][j]=a[n+1][j]-bb[y];
                }
               else 
               { 
			for( i=0 ; i<n ; i++)
                        {
                     		a[n+1][j]=a[n+1][j]+a[i][j]*a[i][y];
                        }
               }
      }
    j=0;
return 0;
}


 
int main()
{
  double  **a,P1[5][7]={{2.0,1,1,0,0,64,0},{1.0,3,0,1,0,72,0},{0,1,0,0,1,20,0},{-4,-6,0.0,0,0,0,0},{0,0,0,0,0,0,0,0}}, bb[]={64.0,72.0,20.0}  ;
  int i,j,n=3,y=5 ,v[4]={0,0,0,0},m;// n-количество строк, y-количество столбцов
  double min;
 a=(double**)malloc(5*sizeof(double*));     
 for(i=0;i<5;i++)
   { a[i]=(double*)malloc(7*sizeof(double));
     for(j=0;j<7;j++) a[i][j]=P1[i][j];
   }
       for (i=0; i<=n ;i++) 
       {
           for (j=0 ; j< y+1 ; j++)
           { printf("%.0f   ",a[i][j]); }printf("\n");
       }
//proverca(a,n,y);
t=2;
do
{    ocenki(a,bb,n,y);
     t=2;
     for (j=0; j<y ; j++)
     {          
	     if (a[n][j]<0) 
             {
                 t=t-1;
                 if (t==1) 
                 {
                   l=j; min=a[n+1][j];
                 }
                 if (a[n][j]<min)
                 { 
                     min=a[n][j]; l=j;
                 }
	      }
     }
     printf("AAAAAA%dAAAAAA\n",l);
     j=0;
     if(t<2)
     {
        for ( i=0 ; i<n ; i++)
        {
            if (a[i][l]>0) 
            {
               if (j==0) 
               {
                  min=a[i][y]/a[i][l]; j=2; k=i;
               }
               if ((a[i][y]/a[i][l])<min) 
               {
                  min=a[i][y]/a[i][l]; k=i;
               }
            }   
        }
     	gaus(a,y,n);
     }
     for (i=0; i<=n ;i++) 
       {
           for (j=0 ; j<=y ; j++)
           { printf("%.1f     ",a[i][j]); }printf("\n");
       }
}while (t!=2);

return 0;
}
