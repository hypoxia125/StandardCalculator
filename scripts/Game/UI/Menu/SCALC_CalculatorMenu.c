modded enum ChimeraMenuPreset
{
	SCALC_CalculatorMenu
}

class SCALC_CalculatorMenu : MenuBase
{
	static SCALC_Calculator calculator;
	
	override void OnMenuOpened()
	{
		calculator = SCALC_Calculator.GetInstance(this);
	}
}