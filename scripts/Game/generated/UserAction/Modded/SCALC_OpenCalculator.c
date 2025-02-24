class SCALC_OpenCalculator : ScriptedUserAction
{	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		GetGame().GetMenuManager().OpenMenu(ChimeraMenuPreset.SCALC_CalculatorMenu);
	}
}