#!/usr/bin/perl
#Author: John Coty Embry
#CMPSC 4983 System Administration With Perl
#Date: 6/22/15
#Script comment: This will identify all print requests greater than or equal to 1MB in size and cancel them (if 
#                permissions allow). It will also generate a report containing the owner's full name and total 
#                number of requests greater than or equal to 1MB made by that user.
%jobcreators;
system"lpstat -o > output.txt"; #this redirects the output from the system command to a file called output.txt
open OUTPUT, "./output.txt" or die "Cannot open output.txt: $!";
while(<OUTPUT>) {
    @array = split(' ', $_) if defined $_;
   if($array[2] >= 1000000) {
		if(exists $jobcreators{$array[1]}) {
	   	$jobcreators{$array[1]}++;
		}
		else {
	   	$jobcreators{$array[1]} = 1;
		}
		system"cancel $array[0]"; #if I have permissions to perform this task, this will cancel the printer job
   }
}
close OUTPUT;
system"rm output.txt"; #this cleans up the directory

open ETC, "/etc/passwd" or die "Cannot open /etc/passwd: $!";
open MYOUTPUT, "> ./studentreport.txt" or die "Cannot open studentreport.txt: $!";
while(<ETC>) {
  	@etcarray = split(':', $_);
 	($fullname, $userid) = split('\+', $etcarray[4]) if $etcarray[4] =~ m/\+/g;
	for $id (keys %jobcreators) {
		if($etcarray[0] =~ m/$id/g) {
	   	print(MYOUTPUT "$fullname\t$jobcreators{$id}\n");
		}
   }
}	
if(exists $jobcreators{unknown}) {
    print(MYOUTPUT "unknown\t\t$jobcreators{unknown}\n");
}
close ETC;
close MYOUTPUT;
