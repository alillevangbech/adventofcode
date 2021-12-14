 
BEGIN { getline;  first = $0;  getline; second = $0; getline; third = $0;

	print first " " second " " third;
	}

{
	print $0;
}
