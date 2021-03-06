class ACTION_EnableSecurePosition extends ScriptedAction;

var(Action)		name			NavPtTag;
var(Action)		bool			bEnable;

function bool InitActionFor(ScriptedController C)
{
	local NavigationPoint Point;

	ForEach C.AllActors(class'NavigationPoint', Point, NavPtTag)
	{
		Point.bValidSecurePosition = bEnable;
	}
	return false;	
}

// The following function used as part of the editor for search functionality
function bool ContainsPartialTag(string StartOfTag)
{
	local string TagString;
	TagString = string(NavPtTag);
	if ( Caps(NavPtTag) == Left(Caps(TagString), Len(StartOfTag) ) )
	{
		return true;
	}

	return super.ContainsPartialTag(StartOfTag);
}



defaultproperties
{
}

