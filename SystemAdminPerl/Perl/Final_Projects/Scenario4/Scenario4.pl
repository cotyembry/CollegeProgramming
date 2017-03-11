#!/usr/bin/perl
#Author: John Coty Embry
#CMPSC 4983 System Admin With Perl
#Date: 6/28/15
#Scenario 4 of Final Projects


#Problem 1:
	#a.
#		if($input_string =~ m/^The/g); #match The at the beginning of a string
	#b.
#		if($input_string =~ m/:$/g); #match : at the end of a string
	#c.
#		if($_ !~ m/(\S)+/g) #verify if input is not a blank line
	#d.
#		The [ \t]* will look for a space followed by a tab 0 or more times where as the [ |\t]* will look for a space or a tab 0 or more times
#Problem 2:
	print"Enter a valid variable name for the C language\n";
	$input_string = <STDIN>;
	if($input_string =~ m/^[a-zA-Z]+[A-Za-z0-9_]*$/g) {
		print"The input is valid.\n";
	}
	else {
		print"The input is not valid.\n";
	}
#Problem 3:
	print"Enter a valid type and variable name combo for the C language\n";
	$input_string = <STDIN>;
	while($input_string =~ m/^(int|float)((\s)+[a-zA-Z]+[A-Za-z0-9_]*);|((\s)+[a-zA-Z]+[A-Za-z0-9_]*(\s)*(,[\s]+[a-zA-Z]+[A-Za-z0-9_]*(\s)*)+);$/g) {
		print"INPUT is valid\n";
		$input_string = <STDIN>;
	}
#	else {
#		print"INPUT is not valid\n";
#	}
#Problem 4:
	print"Enter a valid phone number with the area code included\n";
	$input_string = <STDIN>;
	if($input_string =~ m/^(\d\d\d-\d\d\d-\d\d\d\d|\(\d\d\d\)\d\d\d-\d\d\d\d)$/g) { #I didn't take into account whitespace since you said I should ignore it during validity checking
		print"INPUT is valid.\n";
	}
	else {
		print"INPUT is not valid.\n";
	}
#Problem 5:
	print"Enter a valid IP Address\n";
	$input_string = <STDIN>;
	if($input_string =~ m/^([0-9]|[0-9][0-9]|[01][0-9][0-9]|2[0-4][0-9]|25[0-5])\.([0-9]|[0-9][0-9]|[01][0-9][0-9]|2[0-4][0-9]|25[0-5])\.([0-9]|[0-9][0-9]|[01][0-9][0-9]|2[0-4][0-9]|25[0-5])\.([0-9]|[0-9][0-9]|[01][0-9][0-9]|2[0-4][0-9]|25[0-5])$/g) {
		print"INPUT is valid.\n";
	}
	else {
		print"INPUT is not valid.\n";
	}