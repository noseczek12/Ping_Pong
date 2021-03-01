//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8, y=-8;
int player_1_points = 0;
int player_2_points = 0;


void showStart()
{
        Form1->Label3->Caption = "Gra rozpocznie siê za: 3";
        Application->ProcessMessages(); Sleep(1000);
        Form1->Label3->Caption = "Gra rozpocznie siê za: 2";
        Application->ProcessMessages(); Sleep(1000);
        Form1->Label3->Caption = "Gra rozpocznie siê za: 1";
        Application->ProcessMessages(); Sleep(1000);
        Form1->Label3->Caption = "Powodzenia !";
        Form1->Label3->Enabled = false;
        Form1->timer_b->Enabled = true;
}

void resetGame(int whoseBall)
{
        Application->ProcessMessages(); Sleep(2000);
        Form1->counter_1->Visible=false;
        Form1->counter_2->Visible=false;
        Form1->b->Left=584;
        Form1->b->Top = 344;
        Form1->b->Visible = true;
        if(whoseBall==1)
        {
           x=-8; y=-8;
        }
        if(whoseBall==2)
        {
           x=8; y=-8;
        }

        Form1->timer_b->Enabled=true;
}

void printCounter1(int points1)
{
        if(points1 ==0)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d0.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==1)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d1.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==2)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d2.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==3)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d3.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==4)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d4.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==5)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d5.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==6)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d6.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==7)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d7.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==8)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d8.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==9)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d9.bmp");
           Form1->counter_1->Visible=true;
        }
        if(points1 ==10)
        {
           Form1->counter_1->Picture->LoadFromFile("img/d10.bmp");
           Form1->counter_1->Visible=true;
        }
}

void printCounter2(int points2)
{
        if(points2 ==0)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d0.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==1)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d1.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==2)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d2.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==3)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d3.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==4)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d4.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==5)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d5.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==6)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d6.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==7)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d7.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==8)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d8.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==9)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d9.bmp");
           Form1->counter_2->Visible=true;
        }
        if(points2 ==10)
        {
           Form1->counter_2->Picture->LoadFromFile("img/d10.bmp");
           Form1->counter_2->Visible=true;
        }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::timer_bTimer(TObject *Sender)
{
        b->Left += x;
        b->Top += y;

        // bounce from top
        if(b->Top-5 <= tlo->Top) y=-y;
        // bounce from bottom
        if(b->Top + b->Height +5 >= tlo->Height) y=-y;
        // lose ball on the left side
        if(b->Left <= p1->Left-30)
        {
           timer_b->Enabled = false;
           b->Visible = false;
           player_2_points++;
           printCounter1(player_1_points);
           printCounter2(player_2_points);
           resetGame(2);

        } else if (b->Top > p1->Top && b->Top < p1->Top + p1->Height && b->Left < p1->Left+p1->Width)
        {
           if(x<0) x=-x;
        }
        // lose ball on the right side
        if(b->Left + b->Width >= p2->Left + p2->Width + 30)
        {
           timer_b->Enabled = false;
           b->Visible = false;
           player_1_points++;
           printCounter1(player_1_points);
           printCounter2(player_2_points);
           resetGame(1);

        }
        else if (b->Top > p2->Top && b->Top < p2->Top + p2->Height && b->Left+b->Width > p2->Left)
        {
           if(x>0) x=-x;
        }
        //if player 1 wins
        if(player_1_points == 10)
        {
            timer_b->Enabled = false;
            b->Visible = false;
            Button1->Caption = "Wygrana gracza 1! Jeszcze raz ?";
            Button1->Visible = true;
        }
        //if player 2 wins
        if(player_2_points == 10)
        {
            timer_b->Enabled = false;
            b->Visible = false;
            Button1->Caption = "Wygrana gracza 2! Jeszcze raz ?";
            Button1->Visible = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1_upTimer(TObject *Sender)
{
        if(p1->Top > 10) p1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1_downTimer(TObject *Sender)
{
        if(p1->Top + p1->Height < tlo->Height-10) p1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2_upTimer(TObject *Sender)
{
        if(p2->Top > 10) p2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2_downTimer(TObject *Sender)
{
        if(p2->Top + p2->Height < tlo->Height-10) p2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x57) p1_up->Enabled = true;
        if(Key==0x53) p1_down->Enabled = true;
        if(Key==VK_UP) p2_up->Enabled = true;
        if(Key==VK_DOWN) p2_down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x57) p1_up->Enabled = false;
        if(Key==0x53) p1_down->Enabled = false;
        if(Key==VK_UP) p2_up->Enabled = false;
        if(Key==VK_DOWN) p2_down->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        player_1_points = 0;
        player_2_points = 0;

        b->Left=584;
        b->Top =344;
        b->Visible = true;
        x=-8; y=-8;
        timer_b->Enabled=true;
        Button1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnShowMsgClick(TObject *Sender)
{
        AnsiString strMessage1 = "Zapraszam ciê do gry w ping ponga.";
	AnsiString strMessage2 = "Gracz 1 korzysta z klawiszy W i S.";
	AnsiString strMessage3 = "Gracz 2 korzysta z klawiszy strza³ka w górê i dó³.";
        AnsiString strMessage4 = "Kto pierwszy uzyska 10 punktów, ten wygrywa :)";
	AnsiString strMessage5 = "Aby rozpocz¹c grê, wcisnij OK. Powodzenia!.";

	ShowMessage(strMessage1 + sLineBreak + strMessage2 + sLineBreak +
			strMessage3 + sLineBreak + strMessage4 + sLineBreak + strMessage5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
       Form1->timer_b->Enabled = false;
       Form1->btnShowMsg->Click();
       Form1->timer_b->Enabled = true;
       //showStart();
}
//---------------------------------------------------------------------------

