enum SCALC_ENumberButton
{
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
}

enum SCALC_EOperationButton
{
	Mod,
	CE,
	C,
	Backspace,
	Reciprocal,
	Square,
	Sqrt,
	Divide,
	Multiply,
	Subtract,
	Add,
	Equals,
	Negation,
	Decimal,
}

class SCALC_CalculatorButtonTextComponent : SCR_ButtonTextComponent 
{	
	[Attribute("Calculator Value", desc: "Value to pass to the calculator.")]
	protected string _calculatorButtonValue;
	
	override void HandlerAttached(Widget w)
	{
		super.HandlerAttached(w);
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		SCALC_CalculatorMenu calculatorMenu = SCALC_CalculatorMenu.Cast(m_ParentMenu);
		SCALC_Calculator calculator = calculatorMenu.calculator;
		if (!calculator)
			return false;
		
		bool isNumberInput = IsNumberInput(w);
		bool isOperatorInput = isOperatorInput(w);
		
		return true;
	}
	
	bool IsNumberInput(Widget widget)
	{
		string widgetName = widget.GetName();
		SCALC_ENumberButton ENumberButton = typename.StringToEnum(SCALC_ENumberButton, widgetName);
		
		if (ENumberButton == -1)
			return false;
		
		return true;
	}
	
	bool IsOperationInput(Widget widget)
	{
		string widgetName = widget.GetName();
		SCALC_EOperationButton EOperationButton = typename.StringToEnum(SCALC_EOperationButton, widgetName);
		
		if (EOperationButton == -1)
			return false;
		
		return true;
	}
};