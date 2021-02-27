//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8, y=-8;
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
        if(b->Left <= p1->Left +15)
        {
           timer_b->Enabled = false;
           b->Visible = false;
        }
        // lose ball on the right side
        if(b->Left + b->Width >= p2->Left + p2->Width + 15)
        {
           timer_b->Enabled = false;
           b->Visible = false;
        }
}
//---------------------------------------------------------------------------
