#!/usr/local/bin/perl -w

#Author: John Coty Embry
#System Admin with Perl
#CMPSC 4983
#Project 2
#6/18/15

#to clarify, people who are NOT in active_cs.txt who ARE in the majors directory in /etc/passwd need to be put in non_major.txt correct?

open ETCFILE, "< ./passwd" or die "Cannot open input file: $!"; #these are my file handles
open ACTIVE, "< ./active_cs.txt" or die "Cannot open input file: $!";
open NEWMAJOR, "> ./new_major.txt" or die "Cannot open input file: $!";
open NONMAJOR, "> ./non_major.txt" or die "Cannot open input file: $!";

	while($myline = <ACTIVE>) {
		chomp($myline);
		@array = split(':', $myline);
		$students_in_active{$array[2]} = "$array[2] $array[0] $array[1]";
	}

	while($line = <ETCFILE>) { #here I am reading the file line by line
		chomp($line);
		@array = split(':', $line);
		if(($array[5] =~ m/\/home\/STUDENTS\/majors/g) || ($array[5] =~ m/\/home\/STUDENTS\/nonmajors/g)) { #I have to do this to filter out the garbage in /etc/passwd
			if($array[4] =~ m/\+/g) {
		   		@newarray = split(/\+/, $array[4], 2);
		   		$all_students_in_etc{$newarray[1]} = "$line"; #this is creating a hash with values of all the students
				if((!exists $students_in_active{$newarray[1]}) && ($all_students_in_etc{$newarray[1]} =~ m/\/majors\//g)) { #this handles the students that need to be changed from a major to a nonmajor 
					print(NONMAJOR "$all_students_in_etc{$newarray[1]}\n");
				}
			}
		}else { next; } #this will go to the next iteration of the while loop
	}

	for $student ( keys %students_in_active) {
		if(exists $all_students_in_etc{$student} && $all_students_in_etc{$student} =~ m/\/nonmajors\//g){ #this will handle students who are nonmajors who need to be changed to a major
			print(NEWMAJOR "$all_students_in_etc{$student}\n");
		}
	}

close ETCFILE;
close ACTIVE;
close NEWMAJOR;
close NONMAJOR;