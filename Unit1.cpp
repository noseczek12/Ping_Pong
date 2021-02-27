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

void resetGame()
{
        Form1->b->Left=584;
        Form1->b->Top = 344;
        Form1->b->Visible = true;
        if(player_1_points > player_2_points)
        {
           x=-8; y=-8;
        }
        else
        {
           x=8; y=-8;
        }

        Form1->timer_b->Enabled=true;
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
           //printCounters();
           resetGame();

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
           //printCounters();
           resetGame();

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
        b->Left=584;
        b->Top = 344;
        b->Visible = true;
        x=-8; y=-8;
        timer_b->Enabled=true;
        Button1->Visible = false;
}
//---------------------------------------------------------------------------
