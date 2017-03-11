#!/usr/local/bin/perl -w

#Author: John Coty Embry
#Class:	System Admin With Perl 
#CMPSC 4983
#Project 1

#check whether they have a second major code as computer science on their major code

open ETCFILE, "< ./passwd" or die "Cannot open input file: $!"; #these are my file handels
open EXIST, "> ./currentstudents.txt" or die "Cannot open output file: $!";
open DATAFILE, "< ./enrollment.txt" or die "Cannot open data file: $!";
open NOTEXIST, "> ./newstudents.txt" or die "Cannot open not_exist file: $!";
#this first while loop section gets all the students in /etc/passwd and puts them into a hash
	while($line = <ETCFILE>) { #here I am reading the file line by line
		@array = split(':', $line);
		if(($array[5] =~ m/\/home\/STUDENTS\/majors/g) || ($array[5] =~ m/\/home\/STUDENTS\/nonmajors/g)) { #I have to do this to filter out the garbage in /etc/passwd
			if($array[4] =~ m/\+/g) {
		   		($fullname, $userid) = split(/\+/, $array[4], 2);
		   		$all_students_in_etc{$userid} = "$userid $array[0] $fullname"; #this is creating a hash with values of 
			}
		}else { next; } #this will go to the next iteration of the while loop
		$lastline = $line; #I'll use this for formatting when adding new users for the user and group id
	}
	@numberformat = split(':', $lastline);
	$startnum = $numberformat[2];
	$endnum = $numberformat[3];
	$startnum++; $endnum++;	#I increment the userid and groupid to properly add new users later

#this section takes a data file given and will output which students already exist versus the students that need to be added in the correct formats
	while($newlinevar = <DATAFILE>) {
		@thekey = split('\|', $newlinevar);
		if(!exists $all_students_in_etc{$thekey[0]}) {
			if(defined $thekey[4]) { #I had to do these out if else combo to make sure the second major was defined
				if($thekey[3] eq "0510" || $thekey[4] eq "0510") {
					print(NOTEXIST "$thekey[1]:x:$startnum:$endnum:$thekey[2]\+$thekey[0]:/home/STUDENTS/majors/$thekey[1]:bin/bash\n");
					$startnum++; $endnum++;
				}
				else { 
					print(NOTEXIST "$thekey[1]:x:$startnum:$endnum:$thekey[2]\+$thekey[0]:/home/STUDENTS/nonmajors/$thekey[1]:bin/bash\n"); 
					$startnum++; $endnum++;
				}
			}
			else {
				if($thekey[3] eq "0510") {
					print(NOTEXIST "$thekey[1]:x:$startnum:$endnum:$thekey[2]\+$thekey[0]:/home/STUDENTS/majors/$thekey[1]:bin/bash\n");
					$startnum++; $endnum++;
				}
				else { 
					print(NOTEXIST "$thekey[1]:x:$startnum:$endnum:$thekey[2]\+$thekey[0]:/home/STUDENTS/nonmajors/$thekey[1]:bin/bash\n"); 
					$startnum++; $endnum++;
				}
			}
		}
		else {
			print(EXIST "$all_students_in_etc{$thekey[0]}\n");
		}
	}
close NOTEXIST;
close DATAFILE;
close ETCFILE;
close EXIST;
