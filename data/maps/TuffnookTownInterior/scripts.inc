TuffnookTownInterior_MapScripts::
	.byte 0

TuffnookTownInterior_EventScript_TownSign::
	msgbox TuffnookTownInterior_Text_TownSign, MSGBOX_SIGN
	end

TuffnookTownInterior_EventScript_GavinsGemsSign::
	msgbox TuffnookTownInterior_Text_GavinsGemsSign, MSGBOX_SIGN
	end

TuffnookTownInterior_Text_TownSign:
	.string "TUFFNOOK TOWN\p"
	.string "“A community as solid as stone\n"
	.string "and as hardy as our homes.”$"

TuffnookTownInterior_Text_GavinsGemsSign:
	.string "A crudely carved out sign which\n"
	.string "seems to be for some kind of store.\p"
	.string "You can barely make out the text\n"
	.string "which seems to say “GAVIN'S GEMS”.$"
