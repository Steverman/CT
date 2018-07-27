class MenuTemplateTitledA extends MenuTemplateTitled
    native;

var() MenuSprite        BottomStrip;

var() MenuSprite        AButtonIcon;
var() MenuText          ALabel;
var() MenuButtonText	AButton;

simulated function OnAButton();

simulated function Init( String Args )
{
	Super.Init( Args );
	
	if ( Caps(GetPlayerOwner().GetLanguage()) == "FRT" ||
		 Caps(GetPlayerOwner().GetLanguage()) == "EST" )
	{
		AButton.BackgroundFocused.ScaleX = 0.27;
		AButton.BackgroundBlurred.ScaleX = 0.27;
	}	
}

simulated function HideAButton(int hide)
{
	if ( !IsOnConsole() )
	{
	    AButton.bHidden = hide;
		return;
	}	
	
	AButtonIcon.bHidden = hide;
    ALabel.bHidden = hide;
}

simulated function HandleStripInfoOpacity(float Opacity)
{
	AButtonIcon.DrawColor.A = 255 * Opacity;
    ALabel.DrawColor.A = 255 * Opacity;
}
/* DON'T DO THIS!
simulated function bool HandleInputGamePad( String ButtonName )
{
    if( ButtonName ~= "A" )
    {
        OnAButton();
        return( true );
    }
    
	return( Super.HandleInputGamePad( ButtonName ) );
}
*/


defaultproperties
{
     BottomStrip=(WidgetTexture=Texture'GUIContent.Menu.CT_ButtonFocus',DrawColor=(A=128),DrawPivot=DP_MiddleMiddle,PosX=0.5,PosY=0.893305,ScaleX=0.95,ScaleY=0.055,ScaleMode=MSCM_FitStretch,Platform=MWP_Console)
     AButtonIcon=(DrawPivot=DP_MiddleLeft,PosX=0.895,PosY=0.896,Platform=MWP_Console,Style="XboxButtonA")
     ALabel=(Text="SELECT :",DrawPivot=DP_MiddleRight,PosX=0.9,PosY=0.896,Platform=MWP_Console,Style="LabelText")
     AButton=(Blurred=(Text="SELECT",PosX=0.85,PosY=0.896),BackgroundBlurred=(PosX=0.85,PosY=0.896,ScaleX=0.19,ScaleY=0.04333),OnSelect="OnAButton",Pass=2,bHidden=1,Platform=MWP_PC,Style="ButtonTextStyle1")
}

