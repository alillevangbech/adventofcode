/[0-9],[0-9]/ {
	split($0, arr, ",");
	print arr[1] " " arr[2];
}

// {
	 # skip
}

/f/ {
	split($3, fold, "=");
	print fold[1] " " fold[2];
}


