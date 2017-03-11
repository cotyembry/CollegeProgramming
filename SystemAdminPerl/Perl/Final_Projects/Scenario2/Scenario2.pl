#!/usr/bin/perl
#Author: John Coty Embry
#CMPSC 4983 System Admin With Perl
#Date: 6/24/15
#Scenario 2 of Final Projects
#Script Comment: This will check to see if the current user has a script running and will not let them run another script if the first script is running and also if the user tries to name their script somthing that ends in .c .cc .pl or .py it will not allow the script to be ran. Otherwise it will start the script for the user. They can still specify the optional naming of their script i.e. running command "script myscriptnamedbob.txt"

#You can alias this script by entering the following on the command line: alias script='/home/STUDENTS/majors/johcemb/SystemAdminWithPerl/Final_Projects/Scenario2/Scenario2.pl
$cannotrunscript = 0;
$firstargument = shift; #since no array is given, ARGV is the default for shift
system"ps -ef | grep script > outputscripts.txt";
system"pwd > userpath.txt";
open FH, "./outputscripts.txt" or die "Cannot open outputscripts.txt: $!";
open USER, "./userpath.txt" or die "Cannot open userpath.txt: $!";
while(<USER>) {
	@userarray = split('/', $_); #this helps me get the username; $userarray[4] is the username
}
close USER;
system"rm userpath.txt"; #this cleans up the directory

#oddly enough I had to alternate the variable I used for this next if statement check (even though they are the same value)... No idea why, but I had to so that the program would function correctly. If you put $line in place of $myvar the program will not function correctly.
while($line = <FH>) {
	$myvar = $line;
	#this if statment filters out if the line has "grep script" in it since this isn't a "script" command and also makes sure the word being looked for is "script" and not i.e. typescript
 	if(($line =~ m&^$userarray[4](.)+(/script|(\s)+script(\s)+)&g) && ($myvar !~ m/(\s)+grep(\s)+script((\s)+|$)/g)) { 
		$cannotrunscript = 1;
   }
}
system"rm outputscripts.txt"; #this cleans up the directory, whoever is looking at this code you may want to comment this line out for debugging
if($cannotrunscript) {
	print"Exit from current Script to run another Script!\n";
}
elsif(defined $firstargument && $firstargument =~ m/(.)+(\.c|\.cc|\.pl|\.py)$/g) {
	print"Warning: The filename provided is unacceptable due to the potential of overwriting the source code!\n";
}
else {
	system"/usr/bin/script $firstargument";
}
close FH;
