//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Un.h"
#include "io.h"
#include "fcntl.h"
#include "stdio.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


double c[100];
double a[100][100];
int cl,an,ay;


int t,k,l;

int gaus(double a[100][100] ,int y,int n)
{// Метод гаусса
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
int proverca(double a[100][100] ,int n,int y)//
{  int i,j,z;
   double min;
   t=0;
while (t!=2){
     t=2;
     for( i=0; i<n ; i++ )
     {
	if (a[i][y]<0)
	{
	   t=t-1;
	   if (t==1) { 	min=a[i][y];}
	       k=i;
	}
	if (a[i][y]<min)
	{
	    min=a[i][y]; k=i;
	}
	if (t==2) return 0;
     }
     z=2;
     for (j=0 ; j<y ; j++)
     {
	    if (a[k][j]<0)
	     {    z=z-1;
	       if (t!=2)
	       {
		       l=j;
		       gaus(a,y,n);
		       j=y;
	       }
	     }
      }
      if (z==2){ Form1->Memo1->Text="Нет решения"; return 0;}
}
   return 0;
}
void ocen(double a[100][100], int n, int y)
{
  int i,j,h,b,d;
  int v[100];
  for(i=0; i<100 ; i++)
  {
       v[i]=-1;
  }
  for (j=0; j<y; j++)
  {
        b=0; h=0;
        for (i=0; i<n; i++)
        {
             if (a[i][j]==0)
             {
                 h++;
             }
             if (a[i][j]==1)
	     {
		b++;
                d=i;
	     }
	 }
	 if ((b==1)&&(h==n-1))
                 v[j]=d;
 }
 Form1->StringGrid3->ColCount=y;
 for(i=0; i<y; i++)
    {
       if (v[i]!=-1)
       {
        Form1->StringGrid3->Cells[i][0]=a[v[i]][y];
       }else         Form1->StringGrid3->Cells[i][0]=0;
    }

return;
}
int ocenki(double a[100][100], double *bb, int n, int y )
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
return 0;
}




void __fastcall TForm1::Button1Click(TObject *Sender)
{
 double tmp,por;
  int f,pos,ti,i;
  char buf[10000];
  if(OpenDialog1->Execute())
    { //Memo1->Text=OpenDialog1->FileName;
      ti=-1;
      if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
           ti=read(f,buf,9999);
      if(ti<=0) {Memo1->Text=(AnsiString)"Oшибка чтения файла "+OpenDialog1->FileName;return;}
      buf[ti]=0;pos=0;
      cl=0;
      while(buf[pos])
      {
          if((buf[pos]==' ')||(buf[pos]=='\r')||(buf[pos]=='\n')||(buf[pos]==','))
             {pos++; continue;}
          if(buf[pos]=='-') por=-1; else por=1;
          if((buf[pos]=='-')||(buf[pos]=='+'))
             pos++;

     for(tmp=0;(buf[pos]>='0')&&(buf[pos]<='9');pos++)
     {
         tmp*=10;
         tmp+=buf[pos]-'0';
     }
     if(buf[pos]=='.')
     {
          pos++;
          while ((buf[pos]>='0')&&(buf[pos]<='9'))
          {
             tmp*=10;
             tmp+=buf[pos]-'0';
             por*=10;
             pos++;
          };
     }
     tmp/=por;
     c[cl++]=tmp;
    }

    StringGrid1->ColCount=cl;
   for(i=0;i<cl;i++)
   {
        StringGrid1->Cells[i][0]=(AnsiString)"X"+(i+1);
        StringGrid1->Cells[i][1]=c[i];
   }
  }
   if (cl<2)
 {
        Memo1->Text=(AnsiString)"Задача не решается симплекс методом "; return;
 }
 else
  {;}
  Memo1->Text=(AnsiString)"Файл прочитан";
  }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  double tmp,por;
  int f,pos,ti,i,ay_tmp,j;
  char buf[10000];
  if(OpenDialog1->Execute())
    { //Memo1->Text=OpenDialog1->FileName;
      ti=-1;
      if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
           ti=read(f,buf,9999);
      if(ti<=0) {Memo1->Text=(AnsiString)"Ошибка чтения файла "+OpenDialog1->FileName;return;}
      buf[ti]=0;pos=0;
      an=0;ay=0;
      while(buf[pos])
      {
        while(buf[pos]==' ') pos++;

        ay_tmp=0;
        while(buf[pos]&&(buf[pos]!='\r')&&(buf[pos]!='\n'))
          {
            while((buf[pos]==' ')||(buf[pos]==','))
             {pos++;}
            if(buf[pos]=='-') por=-1; else por=1;
            if((buf[pos]=='-')||(buf[pos]=='+'))
              pos++;

            for(tmp=0;(buf[pos]>='0')&&(buf[pos]<='9');pos++)
             {
              tmp*=10;
              tmp+=buf[pos]-'0';
             }
           if(buf[pos]=='.')
             {
               pos++;
               while ((buf[pos]>='0')&&(buf[pos]<='9'))
                {
                 tmp*=10;
                 tmp+=buf[pos]-'0';
                 por*=10;
                 pos++;
                };
             }
           tmp/=por;
           a[an][ay_tmp++]=tmp;
          }
        if(!ay)  ay=ay_tmp;
        else
         if(ay!=ay_tmp)
           Memo1->Text="Матрица должна быть прямоугольной";
        an++;
        while(buf[pos]&&(buf[pos]=='\r')||(buf[pos]=='\n')) pos++ ;

      }

     StringGrid2->RowCount=an;
     StringGrid2->ColCount=ay;

     for(i=0;i<an;i++)
      for(j=0;j<ay;j++)
         StringGrid2->Cells[j][i]=a[i][j];



    }
Memo1->Text=(AnsiString)"Файл прочитан";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{ int j,i;
  double bb[100];double min;
   Memo1->Text="Решение завершено" ;
  for(int j=0; j<ay;j++)
  {a[an][j]=-c[j];
   a[an+1][j]=0;
   a[an+2][j]=c[j];
  }
 for(int i=0;i<an+2;i++)
 {bb[i]=a[i][ay-1];
 }
ay--;
proverca(a,an,ay);
t=2;
do
{    ocenki(a,bb,an,ay);
     t=2;
     for (j=0; j<ay ; j++)
     {
	     if (a[an][j]<0)
	     {
                 t=t-1;
                 if (t==1)
                 {
                   l=j; min=a[an+1][j];
                 }
                 if (a[an][j]<min)
                 {
                     min=a[an][j]; l=j;
                 }
	      }
     }
     j=0;
     if(t<2)
     {
        for ( i=0 ; i<an ; i++)
        {
            if (a[i][l]>0)
            {
               if (j==0)
               {
                  min=a[i][ay]/a[i][l]; j=2; k=i;
               }
               if ((a[i][ay]/a[i][l])<min)
               {
                  min=a[i][ay]/a[i][l]; k=i;
               }
            }
        }
     	gaus(a,ay,an);
     }
}while (t!=2);
 ocen(a,an,ay);

 StringGrid4->RowCount=an+1;
 StringGrid4->ColCount=ay+1;

 for(int i=0;i<an+1;i++)
  for(int j=0;j<=ay;j++)
  StringGrid4->Cells[j][i]=a[i][j];
 Edit1->Text=a[an][ay];
 Memo2->Text="Решение завершено"  ;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 FILE *f;
 int i,j,q;
 if(!SaveDialog1->Execute()) {Memo2->Text="Ошибка сохранения файла";return;}
 f=fopen(SaveDialog1->FileName.c_str(),"wt");
 if(f==NULL) {Memo2->Text="Ошибка сохранения файла";return;}

 fprintf(f,"Максимум целевой функции %f\n",a[an][ay]);
 fprintf(f,"Решение задачи: ");
 q=StringGrid3->ColCount;
 for(i=0;i<q-1;i++)
   fprintf(f," %s,",StringGrid3->Cells[i][0].c_str());
 fprintf(f," %s\n",StringGrid3->Cells[i][0].c_str());
 fprintf(f,"Последняя симплекс таблица\n");

 for(int i=0;i<an+1;i++)
  {for( j=0;j<ay;j++)
        fprintf(f," %f,",a[i][j]);
   fprintf(f," %f\n",a[i][j]);

  }
  Memo1->Text=(AnsiString)"Файл записан";
 fclose(f);
}
//---------------------------------------------------------------------------


