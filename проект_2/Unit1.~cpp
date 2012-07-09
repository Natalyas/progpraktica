//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "io.h"
#include "fcntl.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double tmp,por;
  int f,pos,ti,i;
  char buf[10000];
  if(OpenDialog1->Execute())
    { Memo1->Text=OpenDialog1->FileName;
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

    StringGrid1->RowCount=cl;
   for(i=0;i<cl;i++)
   {
        StringGrid1->Cells[0][i]=(AnsiString)"X"+(i+1);
        StringGrid1->Cells[1][i]=c[i];
   }
  }
   if (cl<2)
 {
        Memo1->Text=(AnsiString)"Задача не решается симплекс методом "; return;
 }
 else
  {;}
/*
  for(int i=0;i<c_col;i++)
   Memo1->Text=Memo1->Text+","+c[i];
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{  ;

/*   proverca(a,n,y);
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
        if (j==0)
        {
             Memo1->Text=(AnsiString)"Задача не имеет решения, целевая функция не ограничена "; return 0;
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
} */
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button5Click(TObject *Sender)
{
   ShowMessage("QWER");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  double tmp,por;
  int f,pos,ti,i,ay_tmp,j;
  char buf[10000];
  if(OpenDialog1->Execute())
    { Memo1->Text=OpenDialog1->FileName;
      ti=-1;
      if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
           ti=read(f,buf,9999);
      if(ti<=0) {Memo1->Text=(AnsiString)"Oшибка чтения файла "+OpenDialog1->FileName;return;}
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
        else if(ay!=ay_tmp) Memo1->Text="Матрица должна быть прямоугольной";
        an++;
        while(buf[pos]&&(buf[pos]=='\r')||(buf[pos]=='\n')) pos++ ;

      }

     StringGrid2->RowCount=an;
     StringGrid2->ColCount=ay;

     for(i=0;i<an;i++)
      for(j=0;j<ay;j++)
         StringGrid2->Cells[j][i]=a[i][j];



    }
}
//---------------------------------------------------------------------------


