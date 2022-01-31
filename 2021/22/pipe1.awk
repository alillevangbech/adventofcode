{
	line = $0;
	gsub("x=", "", line);
	gsub("y=", "", line);
	gsub("z=", "", line);
	gsub("\\.\\.", " ", line);
	gsub(",", " ", line);
	gsub("off", "0", line);
	gsub("on", "1", line);
	print line;
}


