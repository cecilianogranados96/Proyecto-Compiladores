int main()
{
	int troll;
	troll = (2 * 2 + 2 * 2 - 4) / 4 + 1;
	
	if(troll == 1){
		troll = 0;
	}
	else if(troll == 2){
		switch (troll){
			case 2:
				troll = troll + 1;

			case 3:	
				troll = troll - 1;

			default:
				troll = 1;

		}
	}else{
		troll = 0;
	}	
}