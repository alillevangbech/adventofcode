{
	f = $3;
	g = $4;
	sub(",","",f);
	sub("x=","",f);
	sub("y=","",g);
	gsub("\\."," ",f);
	gsub("\\."," ",g);

	print f " " g
}


