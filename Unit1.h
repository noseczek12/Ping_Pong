//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *tlo;
        TImage *b;
        TImage *p1;
        TImage *p2;
        TLabel *Label1;
        TLabel *Label2;
        TImage *counter_1;
        TImage *counter_2;
        TTimer *timer_b;
        TTimer *p1_down;
        TTimer *p1_up;
        TTimer *p2_up;
        TTimer *p2_down;
        TButton *Button1;
        void __fastcall timer_bTimer(TObject *Sender);
        void __fastcall p1_upTimer(TObject *Sender);
        void __fastcall p1_downTimer(TObject *Sender);
        void __fastcall p2_upTimer(TObject *Sender);
        void __fastcall p2_downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
