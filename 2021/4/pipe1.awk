BEGIN {
	getline;
	print $0;
}

/[0-9]/{
	print $1 " " $2 " " $3 " " $4 " " $5
}
