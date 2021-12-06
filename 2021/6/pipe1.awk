BEGIN {

}

{
	a = $1;
	gsub(","," ",a);
	print a;
}

END {

}
