BEGIN {
	getline;
	split($0,a,",");
	for (i in a) {
		print a[i];
	}
}


