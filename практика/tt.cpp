//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tt.h"
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
int verno1=0,verno2=0;


int t,k,l;

int gaus(double a[100][100] ,int y,int n)    //метод гаусса
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

int proverca(double a[100][100],int n,int y) //проверяем файл с мас.лин.огр. на наличие опорного решения
{int i,j,k,h,b,dubl,d,
 cnt=0;// количество найденных столбцов.
 for(i=0;i<n;i++)
  if(a[i][y]<0)
   {Form1->StatusBar1->SimpleText="Статус программы: В матрице лин.огр. содержится не опорный план";
    return 1;
   }


 for(j=0;j<y;j++)
  {h=0;b=0;//
   for(i=0;i<n;i++)
     {if(a[i][j]==0) b++;
      if(a[i][j]==1) {h++;d=i;}
     }
   if((h==1)&&(b==n-1))// столбец "единичный"
     {//проверить что не дублирующийся

      for(int p=0;p<j;p++) //перебираем все предыдущие столбцы
       {dubl=1;
        for(int q=0;q<n;q++)
          if(a[q][j]!=a[q][p])
            dubl=0;
       }
      if(!dubl)
         {
          cnt++;
         }
     }
  }
 if(cnt!=n)
   { Form1->StatusBar1->SimpleText="Статус программы: В матрице лин.огр. содержится не опорный план";
    return 1;
   }

return 0;
}

void ocen(double a[100][100], int n, int y) //выводится оптимальное решение которое находится в симплекс таблице
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

void __fastcall TForm1::Button1Click(TObject *Sender) //чтение файла: открывает окно диалога для открытия файла с массивом коэф.целев.функции
{
 double tmp,por;
  int f,pos,ti,i;
  char buf[10000];
  verno1=0;
  if(OpenDialog1->Execute())
    { //Memo1->Text=OpenDialog1->FileName;
      ti=-1;
      if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
           ti=read(f,buf,9999);
      if(ti<=0) {Form1->StatusBar1->SimpleText="Статус программы: Oшибка чтения файла "+OpenDialog1->FileName;return;}
      buf[ti]=0;pos=0;
      cl=0;
      while(buf[pos])
      {
          if((buf[pos]==' ')||(buf[pos]=='\r')||(buf[pos]=='\n')||(buf[pos]==','))
             {pos++; continue;}
          if(buf[pos]=='-') por=-1; else por=1;
          if((buf[pos]=='-')||(buf[pos]=='+'))
             pos++;
     if((buf[pos]<'0')||(buf[pos]>'9'))
      {Form1->StatusBar1->SimpleText="Статус программы: Неверный формат файла";return;}
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
        Form1->StatusBar1->SimpleText="Статус программы: Задача не решается симплекс-методом "; return;
 }
 else
  {Form1->StatusBar1->SimpleText="Статус программы: Файл прочитан"; verno1=1;}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)   //чтение файла: открывает окно диалога для открытия файла с массивом линей.огранич.
{
  double tmp,por;
  int f,pos,ti,i,ay_tmp,j;
  char buf[10000];
  verno2=0;
  if(OpenDialog1->Execute())
  { //Memo1->Text=OpenDialog1->FileName;
      ti=-1;
      if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
           ti=read(f,buf,9999);
      if(ti<=0) {Form1->StatusBar1->SimpleText="Статус программы: Ошибка чтения файла "+OpenDialog1->FileName;return;}
      buf[ti]=0;pos=0;
      an=0;ay=0;
      while(buf[pos])
      {
         while(buf[pos]==' ')
             pos++;
         ay_tmp=0;
         while(buf[pos]&&(buf[pos]!='\r')&&(buf[pos]!='\n'))
         {
             while((buf[pos]==' ')||(buf[pos]==','))
                 pos++;
             if(buf[pos]=='-') por=-1; else por=1;
             if((buf[pos]=='-')||(buf[pos]=='+'))
                 pos++;
             if((buf[pos]<'0')||(buf[pos]>'9'))
             {
                 Form1->StatusBar1->SimpleText="Статус программы: Неверный формат файла";
                 return;
             }
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
               Form1->StatusBar1->SimpleText="Статус программы: Матрица должна быть прямоугольной";
        an++;
        while(buf[pos]&&(buf[pos]=='\r')||(buf[pos]=='\n')) pos++ ;
     }
     StringGrid2->RowCount=an;
     StringGrid2->ColCount=ay;
     for(i=0;i<an;i++)
        for(j=0;j<ay;j++)
           StringGrid2->Cells[j][i]=a[i][j];
  }
  if (an<2)
     Form1->StatusBar1->SimpleText="Статус программы: Задача не решается симплекс-методом";
  if ((an>96)||(ay>97))
     Form1->StatusBar1->SimpleText="Статус программы: Превышен допустимый размер файла";
  Form1->StatusBar1->SimpleText="Статус программы:Файл прочитан";
  verno2=1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)  //запуск программы
{ int j,i;
  double bb[100];double min;

  if(!verno1)
  {Form1->StatusBar1->SimpleText="Статус программы:Не считан массив коэффициентов целевой функции";
   return;
  }
  if(!verno2)
  {Form1->StatusBar1->SimpleText="Статус программы:Не считана матрица линейных ограничений";
   return;
  }

  if(StringGrid1->ColCount!=(StringGrid2->ColCount-1))
  {Form1->StatusBar1->SimpleText="Статус программы:Размер матрицы коэфф. целевой функции не соответствует системе лин.ограничений.";
   return;
  }

  for(int j=0; j<ay;j++)
  {a[an][j]=-c[j];
   a[an+1][j]=0;
   a[an+2][j]=c[j];
  }
 for(int i=0;i<an+2;i++)
 {bb[i]=a[i][ay-1];
 }
ay--;
if (proverca(a,an,ay)) return;
t=2;
do
{    
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

 for(int i=0;i<an+1;i++)     //вывод решения на форму
  for(int j=0;j<=ay;j++)
  StringGrid4->Cells[j][i]=a[i][j];
 Edit1->Text=a[an][ay];
 Form1->StatusBar1->SimpleText="Статус программы: Решение завершено"  ;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) //вывод в файл
{
 FILE *f;
 int i,j,q;
 if(!SaveDialog1->Execute()) {Form1->StatusBar1->SimpleText="Статус программы: Ошибка сохранения файла";return;}
 f=fopen(SaveDialog1->FileName.c_str(),"wt");
 if(f==NULL) {Form1->StatusBar1->SimpleText="Статус программы: Ошибка сохранения файла";return;}

 fprintf(f,"Максимум целевой функции %.1f\n",a[an][ay]);
 fprintf(f,"Решение задачи: ");
 q=StringGrid3->ColCount;
 for(i=0;i<q-1;i++)
   fprintf(f," %s,",StringGrid3->Cells[i][0].c_str());
 fprintf(f," %s\n",StringGrid3->Cells[i][0].c_str());
 fprintf(f,"Последняя симплекс таблица\n");

 for(int i=0;i<an+1;i++)
  {for( j=0;j<ay;j++)
        if ((a[i][j]<0)||( a[i][j]>=10))
            fprintf(f," %.1f,",a[i][j]);
        else  fprintf(f,"  %.1f,",a[i][j]);
   if ((a[i][j]<0)||( a[i][j]>=10))
        fprintf(f," %.1f\n",a[i][j]);
   else fprintf(f,"  %.1f\n",a[i][j]);
  }
  Form1->StatusBar1->SimpleText="Статус программы: Файл записан";
 fclose(f);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N6Click(TObject *Sender) //пункт меню "Закрыть"
{
 Form1->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)  //Запускает расчет результата. Из меню.
{
 Button3->OnClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N2Click(TObject *Sender)   //открывает окно диалога для открытия файла с коэф.целев. ф-ии.
{
 Button1->OnClick(Sender);         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)  //открывает окно диалога для открытия файла с массивом линей.огранич..
{
 Button2->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     //запуск программы
  if (Key==120)
  {   Button3->OnClick(Sender); }
}
//---------------------------------------------------------------------------

