class Calculator
{
	float Add(float a, float b)
	{
		return a + b;
	}
	
	float Subtract(float a, float b)
	{
		return a - b;
	}
	
	float Multiply(float a, float b)
	{
		return a * b;
	}
	
	float Divide(float a, float b)
	{
		if (b == 0) { return -1 };
		
		return a / b;
	}
	
	float Modulus(float a, float b)
	{
		if (b == 0) { return -1 };
	}
	
	float Reciprocal(float x)
	{
		if (x == 0) { return -1 };
		
		return 1 / x;
	}
	
	float SquareRoot(float x)
	{
		if (x < 0) { return -1 };
		
		return Math.Sqrt(x);
	}
}