#!/usr/local/bin/perl -w

#open MYFILE, "+< /home/faculty/mkt/admin/2.txt" or die "Cannot open file: $!";
#decided to use separate output file to prevent overwriting original file until I master this stuff
open MYFILE, "< /home/faculty/mkt/admin/2.txt" or die "Cannot open input file: $!";
#added "die" option to output file in case there are problems with write permissions or something that would prevent the file from being accessible.
open OUTFILE, "> /home/faculty/mkt/admin/2.txt2" or die "Cannot open output file: $!";

# Taking Dr. Walker's advice from first assignment and splitting the search string to prevent this script from altering itself.
$orig1="Hel";
$orig2="lo";
$new="Howdy";
# Loading every line in file into an array
# my @filecontent = <MYFILE>;
# For each line in the array, perform substitution
#foreach $line (@filecontent){
# Decided to use a while loop to access one line at a time in case the file is large...
while ($line = <MYFILE>) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   $line =~ s/$orig1$orig2/$new/g;
#Writing to a different file because I want to make sure it works before altering orginal.
#Added newline since I did chomp earlier.
   printf (OUTFILE "$line\n");
}
close MYFILE;
close OUTFILE;
