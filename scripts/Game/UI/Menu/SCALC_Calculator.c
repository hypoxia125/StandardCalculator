enum SCALC_ECalculatorOperations
{
	Add,
	Subtract,
	Multiply,
	Divide,
	Modulus,
	Reciprocal,
	Square,
	Sqrt,
}

class SCALC_Calculator
{
	private const float ERROR_VALUE = float.INFINITY;
	
	// singleton
	static ref SCALC_Calculator singleton;
	
	private SCALC_CalculatorMenu _calculatorMenu;
	private TextWidget _outputWidget;
	private string _output;	
	
	void SCALC_Calculator(SCALC_CalculatorMenu menu)
	{
		if (singleton)
		{
			Print("Instance SCALC_Calculator already created. Destroy old to make a new one.", LogLevel.WARNING);
			delete this;
			return;
		}
		
		PrintFormat("Creating calculator instance: %1", this);
		_calculatorMenu = menu;
		_outputWidget = TextWidget.Cast(_calculatorMenu.GetRootWidget().FindAnyWidget("Output"));
		
		_outputWidget.SetText("0");
		
		singleton = this;
	}
	
	static SCALC_Calculator GetInstance(SCALC_CalculatorMenu menu)
	{
		if (!singleton)
		{
			singleton = new SCALC_Calculator(menu);
		}
		return singleton;
	}
	
	//------------------------------------------------------------------------------------------------
	private float Add(float a, float b) { return a + b; }
	
	//------------------------------------------------------------------------------------------------
	private float Subtract(float a, float b) { return a - b; }
	
	//------------------------------------------------------------------------------------------------
	private float Multiply(float a, float b) { return a * b; }
	
	//------------------------------------------------------------------------------------------------
	private float Divide(float a, float b)
	{
		if (b == 0) { return ERROR_VALUE; }
		
		return a / b;
	}
	
	//------------------------------------------------------------------------------------------------
	private float Modulus(float a, float b)
	{
		if (b == 0) { return ERROR_VALUE; }
		
		return Math.Mod(a, b);
	}
	
	//------------------------------------------------------------------------------------------------
	private float Reciprocal(float x)
	{
		if (x == 0) { return ERROR_VALUE; }
		
		return 1 / x;
	}
	
	//------------------------------------------------------------------------------------------------
	private float Square(float x)
	{
		return x * x;
	}
	
	//------------------------------------------------------------------------------------------------
	private float Negation(float x)
	{
		return -x;
	}
}