#include <iostream>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <winbgim.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <mmsystem.h>
#include <windows.h>
using namespace std;
#define FUNDAL CYAN
#define MAX 50
int pag=0; //nr pagina
void beep1()
{
    Beep(523, 500);
}
struct punct
{
    int x, y;
};

struct dreptunghi
{
    punct SS, DJ;
};

void patrat(int x1, int x2)
{
    setcolor(WHITE);
    rectangle(x1, x1, x2, x2);
}

void cercuri(int x, int y, int r)
{
    setcolor(WHITE);
    circle(x, y, r);
}

void linii(int x)
{
    setcolor(WHITE);
    if (x != 250)
    {
        line(x, 150, 800, 600);
        linii(x + 50);
    }
}

void triunghiuri(int x,int y,int d,int l)
{

    line(x, y, x + d, y);
    line(x, y, x + d / 2, y - l);
    line(x + d, y, x + d / 2, y - l);
}

bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;

}

struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};
void triunghiuriNUME(int x,int y,int i,int d,int l)
{

    if(i>0)//nr dr tr/
    {
        line(x, y, x + d, y);// 250 250 450 250
        line(x, y, x + d / 2, y - l);//250 250 350
        line(x + d, y, x + d / 2, y - l);

        if(i==2)
        {
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(350,200,LIGHTBLUE);
            setcolor(LIGHTBLUE);
        }

        if(i>1)
        {
            triunghiuriNUME(x - 80, y + 30, i - 1, d / 2+20,l / 2); ///st
            triunghiuriNUME(x + d / 2 - 80, y - l + 20, i - 1, d / 2+20, l / 2);///sus
            triunghiuriNUME(x + d - 80, y + 30, i - 1, d / 2+20, l / 2);///dr

        }
    }
    setcolor(LIGHTBLUE);
    settextstyle(SANS_SERIF_FONT,0,4);
    outtextxy(250,215," MORPHING ");
    settextstyle(BOLD_FONT,0,1);
    outtextxy(330,84,"ISTRATE");
    outtextxy(333,102,"IUSTIN");
    settextstyle(BOLD_FONT,0,1);
    outtextxy(160,308,"VREME IULIA");
    settextstyle(BOLD_FONT,0,1);
    outtextxy(454,308,"PIRLAC DIANA");

}

buton B1[4];
int nrButoane1=2;
void deseneazaMeniul1()
{
    setcolor(WHITE);
    //rectangle(0,150,getmaxx(),getmaxy());
    setcolor(LIGHTBLUE);

    int i;
    triunghiuriNUME(215, 300, 2, 300, 200);
    settextstyle(SIMPLEX_FONT,0,1);
    for(i=2; i<=3; i++)
    {
        B1[i].D.SS.y=100*(i+1)+60;
        B1[i].D.SS.x=220;
        B1[i].D.DJ.y=100*(i+2)-10;
        B1[i].D.DJ.x=500;
        switch(i)
        {
        case 2:
            strcpy(B1[i].text,"START");
            break;
        case 3:
            strcpy(B1[i].text,"IESIRE");
            break;
        }
        if(i==2)
        {
            setfillstyle(SOLID_FILL,GREEN);
            setbkcolor(GREEN);
            rectangle(B1[i].D.SS.x, B1[i].D.SS.y,B1[i].D.DJ.x,B1[i].D.DJ.y);
            bar(B1[i].D.SS.x, B1[i].D.SS.y, B1[i].D.DJ.x, B1[i].D.SS.y+50);
            settextstyle(COMPLEX_FONT,0,4);
            outtextxy(B1[i].D.SS.x+85,B1[i].D.SS.y+10,B1[i].text);
        }
        else if(i==3)
        {
            setfillstyle(SOLID_FILL,BLUE);
            setbkcolor(BLUE);
            rectangle(B1[i].D.SS.x, B1[i].D.SS.y,B1[i].D.DJ.x,B1[i].D.DJ.y);
            bar(B1[i].D.SS.x, B1[i].D.SS.y, B1[i].D.DJ.x, B1[i].D.SS.y+50);
            settextstyle(COMPLEX_FONT,0,4);
            outtextxy(B1[i].D.SS.x+85,B1[i].D.SS.y+10,B1[i].text);

        }
    }
}

int butonAles1()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane1; i++)
            if (apartine(p,B1[i].D))
                return i;
    }
    return 0;
}


buton B[7];
int nrButoane=6;
void deseneazaMeniul()
{
    setcolor(WHITE);
    rectangle(0,130,getmaxx(),getmaxy());
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,WHITE);
    settextstyle(BOLD_FONT,0,1);
    int i;
    for (i=1; i<=nrButoane; i++)
    {
        B[i].D.SS.x=100*i;
        B[i].D.DJ.x=100*(i+1)-10;
        B[i].D.SS.y=50;
        B[i].D.DJ.y=80;
        switch(i)
        {
        case 1:
            strcpy(B[i].text,"Imag 1");
            break;
        case 2:
            strcpy(B[i].text,"Imag 2");
            break;
        case 3:
            strcpy(B[i].text,"Imag 3");
            break;
        case 4:
            strcpy(B[i].text,"Imag 4");
            break;
        case 5:
            strcpy(B[i].text,"Sterg");
            break;
        case 6:
            strcpy(B[i].text,"IESIRE");
            break;
        }
        rectangle(B[i].D.SS.x, B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
        bar(B[i].D.SS.x, B[i].D.SS.y+30, B[i].D.DJ.x, B[i].D.SS.y);
        setbkcolor(WHITE);
        outtextxy(B[i].D.SS.x+15,B[i].D.SS.y+10,B[i].text);
    }
}

int butonAles()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane; i++)
            if (apartine(p,B[i].D))
                return i;
    }
    return 0;
}
void triunghi(int x,int y,int d,int l){
        //setfillstyle(SOLID_FILL,BLACK);
        line(x, y, x +d, y);
        line(x, y, x -d, y );
        line(x + d, y, x -d, y );
        //floodfill(x+1,y+1,WHITE);

}
void linii1(int x)
{
    if (x <=800)
    {
        //line(200, 400, x1, 700);
        line(400, 0, x, 800);
       // linii(x1 - 50);
       // linii1(x+50);
    }
}
void linii2(int x)
{
    if (x >=0)
    {
        line(400, 0, x, 800);
       // linii2(x - 50);
    }
}

void deseneazaMeniul2()
{/*
    setbkcolor(BLACK);
    deseneazaMeniul1();
    setbkcolor(BLACK);
    */
    int x=400;
    int d=0;
      for(int i=1;i<=9;i++)
      {
          if(i!=9)
          {cleardevice();
          /*
          setbkcolor(BLACK);
          deseneazaMeniul1();*/
         setbkcolor(BLACK);
          }
        setfillstyle(SOLID_FILL,RED);
        bar(x+d,0,800,600);
        setfillstyle(SOLID_FILL,RED);
        bar(0,0,x-d,600);
        d=d+50;
        delay(100);
      }


}

struct coordonate
{
    int x,y;
} punct[MAX];
struct surface
{
    int NrPct;
    int Fil;
    int numar;
    coordonate punct[MAX];
} S;
struct desen
{

    int NrSurf;
    surface Surf[MAX];

} D, D1, D2;
int OpenGraph( )
{
    int gdrv=VGA, gmd=VGAMED;
    initgraph(&gdrv, &gmd, "");
    pag=0;
    // initgraph(&gdrv, &gmd, "");
}
bool Apartine(int x, int y, int  x1, int y1, int x2, int y2)
{
    if((x1<=x) && (x<=x2) && (y1<=y) &&(y<=y2))
        return true;
    else
        return false;
}
void beep()
{
    Beep(500, 1000);
}
void Bara()
{
    //setviewport(0, 0, 150, 60, ClipCursor());
    clearviewport;
    // setviewport(0, 0, getmaxx(), getmaxy(),ClipCursor());
}
void MouseData(int &x, int &y, int &Button)
{

    Button=0;
    while(Button==0)
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            Button=1;
            getmouseclick(WM_LBUTTONDOWN, x, y);
        }
        if(ismouseclick(WM_RBUTTONDOWN))
        {
            Button=2;
            getmouseclick(WM_RBUTTONDOWN, x, y);
        }
    }

}
void CreateSurface(surface &S)
{
    int const eps=1;
    int b, x1, y1, x2, y2, xs, ys,i, x,y;
    S.NrPct=1;
    bool PrimPunct=false;
    do
    {
        beep();
        MouseData(x1, y1, b);
    }
    while(b!=1);
    S.punct[S.NrPct].x=x1;
    S.punct[S.NrPct].y=y1;
    do
    {
        MouseData(x2,y2, b);
        if(b==1)
        {
            S.NrPct++;
            S.punct[S.NrPct].x=x2;
            S.punct[S.NrPct].y=y2;
            if((abs(S.punct[S.NrPct].x-S.punct[1].x+eps)<=4) && (abs(S.punct[S.NrPct].y-S.punct[1].y+eps)<=4))
            {
                S.NrPct--;
                line(x1, y1, S.punct[1].x, S.punct[1].y);
            }
            else
                line(x1, y1, x2, y2);
        }
        x1=x2;
        y1=y2;
    }
    while(b==1);
    cout<<"Numarul total de puncte care compun suprafata S este: "<<S.NrPct<<endl;
}
void ModifySurface(surface &S)
{
    int const eps=3;
    int b, x, y, x_1, y_1, x_2, y_2, i;
    bool gasit;
    do
    {
        MouseData(x, y, b);
        i=1;
        gasit=false;
        while(i<=S.NrPct && !gasit==true)
        {
            if(b==1 && Apartine(x, y, S.punct[i].x-eps, S.punct[i].y-eps, S.punct[i].x+eps, S.punct[i].y+eps))
            {
                gasit=true;
                Beep(750, 1000);
                delay(500);
                if(i<S.NrPct)
                {
                    x_2=S.punct[i+1].x;
                    y_2=S.punct[i+1].y;
                }
                else if(i==S.NrPct)
                {
                    x_2=S.punct[1].x;
                    y_2=S.punct[1].y;
                }
                if(i>1)
                {
                    x_1=S.punct[i-1].x;
                    y_1=S.punct[i-1].y;
                }
                else if(i==1)
                {
                    x_1=S.punct[S.NrPct].x;
                    y_1=S.punct[S.NrPct].y;
                }
                if((x_1+y_1)!=-2)
                {
                    setcolor(RED);
                    line(x_1, y_1, S.punct[i].x, S.punct[i].y);
                }
                if((x_2+y_2)!=-2)
                {
                    setcolor(RED);
                    line(S.punct[i].x, S.punct[i].y, x_2, y_2);
                }
                setcolor(WHITE);
                if(((x_1+y_1)!=-2) || ((x_2+y_2)!=-2))
                {
                    line(S.punct[i].x, S.punct[i].y, S.punct[i].x, S.punct[i].y);   // PAS INUTIL ;)
                }
                do
                {
                    MouseData(x, y, b);
                    S.punct[i].x=x;
                    S.punct[i].y=y;
                    if((x_1+y_1)!=-2)
                        line(x_1, y_1, x, y);
                    if((x_2+y_2)!=-2)
                        line(x, y, x_2, y_2);
                    delay(50);
                    if((x_1+y_1)!=-2)
                        line(x_1, y_1, x, y);
                    if((x_2+y_2)!=-2)
                        line(x, y, x_2, y_2);
                }
                while(b!=1);
                if((x_1+y_1)!=-2)
                    line(x_1, y_1, x, y);
                if((x_2+y_2)!=-2)
                    line(x, y, x_2, y_2);

                delay(500);
                b=0;
            }
            else i++;
        }
    }
    while(b!=2);
    beep();
}
void CreatePic(desen &D)
{
    int i;
    cout<<"Dati numarul de suprafate care o sa construiasca desenul D: "<<endl;
    cin>>D.NrSurf;
    cout<<"Incepeti sa desenati:"<<endl;
    for(i=1; i<=D.NrSurf; i++)
    {
        cout<<"DETALII SUPRAFATA "<<i<<":"<<endl;
        CreateSurface(D.Surf[i]);
    }
}
void TransfPic(desen &D1, desen &D2, int n)
{
    // Transformarea unui desen D1 intr unul D2 in n pasi;
    surface S1;
    surface S2;
    surface S;
    int k, i,j;
    for(i=1; i<=3; i++)
    {
        for(k=1; k<=D1.NrSurf; k++)
        {
            S1=D1.Surf[k];
            S2=D2.Surf[k];
            S.NrPct=S1.NrPct;
            for(j=1; j<=S1.NrPct; j++)
            {
                S.punct[j].x=round(S1.punct[j].x+i*(S2.punct[j].x-S1.punct[j].x)/n);
                S.punct[j].y=round(S1.punct[j].y+i*(S2.punct[j].y-S1.punct[j].y)/n);
            }
            CreateSurface(S);
        }
        setvisualpage(1-pag);         //!!!!!!!!!!!
        setactivepage(pag);
        cleardevice();
        delay(1000);
        pag=1-pag;
    }
}
void ModifyPic(desen &D)
{
    int i;
    for(i=1; i<=D.NrSurf; i++)
        ModifySurface(D.Surf[i]);
}
void SavePic(desen &D, FILE* fisier)
{
    int i, j;
    if (fisier == NULL)
        printf("Error! opening file");
    fprintf(fisier, "%d\n", D.NrSurf);
    for(i=1; i<=D.NrSurf; i++)
    {
        fprintf(fisier, "%d\n", D.Surf[i].NrPct);
        for(j=1; j<=D.Surf[i].NrPct; j++)
            fprintf(fisier, "%d %d\n",D.Surf[i].punct[j].x, D.Surf[i].punct[j].y);
    }
    fclose(fisier);

}
void LoadPic(desen &D, FILE *fisier)
{
    int i, j;
    if (fisier == NULL)
        printf("Error! opening file");
    fscanf(fisier, "%d", &D.NrSurf);
    for(i=1; i<=D.NrSurf; i++)
    {
        fscanf(fisier, "%d\n", &D.Surf[i].NrPct);
        for(j=1; j<=D.Surf[i].NrPct; j++)
            fscanf(fisier, "%d %d\n", &D.Surf[i].punct[j].x, &D.Surf[i].punct[j].y);
    }
    fclose(fisier);
}
void egalare(desen &D1, desen &D2)
{
    int i, j;
    D2.NrSurf=D1.NrSurf;
    for(i=1; i<=D1.NrSurf; i++)
    {
        D2.Surf[i]=D1.Surf[i];
        for(j=1; j<=D1.Surf[i].NrPct; j++)
        {
            D2.Surf[i].punct[j].x=D1.Surf[i].punct[j].x;
            D2.Surf[i].punct[j].y=D1.Surf[i].punct[j].y;
        }
    }

}
void morph()
{

    FILE *fisier_desen1;
    FILE *fisier_desen2;
    fisier_desen1=fopen("D1.PIC.txt", "r+");
    fisier_desen2=fopen("D2.PIC.txt", "r+");
    //OpenGraph();
    setlinestyle(SOLID_LINE, 3, 3);
    CreatePic(D1);
    SavePic(D1,fisier_desen1);
    Beep(500, 1000);
    delay(1000);
    cleardevice();
    delay(500);
    egalare(D1, D2);
    int i, j;
    for(i=1; i<=D2.NrSurf; i++)
    {
        for(j=1; j<=D2.Surf[i].NrPct; j++)
        {
            circle(D2.Surf[i].punct[j].x, D2.Surf[i].punct[j].y, 2);
        }
    }
    //LoadPic(D2,fisier_desen1);
    //fscanf(fisier_desen1, "%d", &D2.NrSurf);
    ModifyPic(D2);
    SavePic(D2,fisier_desen2);
    closegraph();
    /*
    LoadPic(D2,fisier_desen1);
    ModifyPic(D2);
    SavePic(D2,fisier_desen2);
    cleardevice();
    LoadPic(D1,fisier_desen1);
    LoadPic(D2,fisier_desen2);
    getch();
    closegraph();
    */
}
int main()
{
    initwindow(800, 600);
    setbkcolor(BLACK);
    deseneazaMeniul2();
    setbkcolor(BLACK);

    deseneazaMeniul1();
  //  cout<<Beep(400, 1000);
    int comanda1, butonul_apasat1;
    do
    {

            butonul_apasat1=butonAles1();
            if (butonul_apasat1==2)
        {
            comanda1=butonul_apasat1;
            cout<<"Comanda "<<comanda1<<endl;
            setbkcolor(BLACK);
            cleardevice();
            deseneazaMeniul();
            int comanda, butonul_apasat;
            do
            {
                butonul_apasat=butonAles();
                if (butonul_apasat!=0)
                {
                    if(butonul_apasat==1)
                    {
                        setcolor(LIGHTBLUE);
                        setfillstyle(SOLID_FILL,RED);
                        rectangle(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y,B[butonul_apasat].D.DJ.x,B[butonul_apasat].D.DJ.y);
                        bar(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y+30, B[butonul_apasat].D.DJ.x, B[butonul_apasat].D.SS.y);
                        setbkcolor(RED);
                        outtextxy(B[butonul_apasat].D.SS.x+25,B[butonul_apasat].D.SS.y+10,B[butonul_apasat].text);
                        PlaySound(TEXT("soundImag.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        morph();
                    }
                    if(butonul_apasat==2)
                    {
                        setcolor(LIGHTBLUE);
                        setfillstyle(SOLID_FILL,RED);
                        rectangle(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y,B[butonul_apasat].D.DJ.x,B[butonul_apasat].D.DJ.y);
                        bar(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y+30, B[butonul_apasat].D.DJ.x, B[butonul_apasat].D.SS.y);
                        setbkcolor(RED);
                        outtextxy(B[butonul_apasat].D.SS.x+25,B[butonul_apasat].D.SS.y+10,B[butonul_apasat].text);
                        PlaySound(TEXT("soundImag.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        cercuri(400,350,180);
                    }
                    if(butonul_apasat==3)
                    {
                        setcolor(LIGHTBLUE);
                        setfillstyle(SOLID_FILL,RED);
                        rectangle(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y,B[butonul_apasat].D.DJ.x,B[butonul_apasat].D.DJ.y);
                        bar(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y+30, B[butonul_apasat].D.DJ.x, B[butonul_apasat].D.SS.y);
                        setbkcolor(RED);
                        outtextxy(B[butonul_apasat].D.SS.x+25,B[butonul_apasat].D.SS.y+10,B[butonul_apasat].text);
                        PlaySound(TEXT("soundImag.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        triunghiuri(250, 500, 300, 250);
                    }
                    if(butonul_apasat==4)
                    {
                        setcolor(LIGHTBLUE);
                        setfillstyle(SOLID_FILL,RED);
                        rectangle(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y,B[butonul_apasat].D.DJ.x,B[butonul_apasat].D.DJ.y);
                        bar(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y+30, B[butonul_apasat].D.DJ.x, B[butonul_apasat].D.SS.y);
                        setbkcolor(RED);
                        outtextxy(B[butonul_apasat].D.SS.x+25,B[butonul_apasat].D.SS.y+10,B[butonul_apasat].text);
                        PlaySound(TEXT("soundImag.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        linii(0);
                    }
                    if(butonul_apasat==5)
                    {
                        setcolor(LIGHTBLUE);
                        setfillstyle(SOLID_FILL,RED);
                        rectangle(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y,B[butonul_apasat].D.DJ.x,B[butonul_apasat].D.DJ.y);
                        bar(B[butonul_apasat].D.SS.x, B[butonul_apasat].D.SS.y+30, B[butonul_apasat].D.DJ.x, B[butonul_apasat].D.SS.y);
                        setbkcolor(RED);
                        outtextxy(B[butonul_apasat].D.SS.x+25,B[butonul_apasat].D.SS.y+10,B[butonul_apasat].text);
                        beep1();
                        setbkcolor(BLACK);
                        cleardevice();
                        deseneazaMeniul();

                    }
                    comanda=butonul_apasat;
                    cout<<"Comanda "<<comanda<<endl;
                }
                if(butonul_apasat==6)beep1();
            }
            while(comanda!=6);
            break;
          }
        if(butonul_apasat1==3)
        {
            beep1();
            break;
        }
       }while (comanda1!=3);
        // getch();
        closegraph();


    return 0;
}
