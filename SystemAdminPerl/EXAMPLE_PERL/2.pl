#!/usr/local/bin/perl -w

#open MYFILE, "+< /home/faculty/mkt/admin/2.txt" or die "Cannot open file: $!";
#decided to use separate output file to prevent overwriting original file until I master this stuff
open MYFILE, "< /home/faculty/mkt/PERL/2.txt" or die "Cannot open file: $!";
open OUTFILE, "> /home/faculty/mkt/PERL/2.txt2" ;

# Taking Dr. Walker's advice from first assignment and splitting the search string to prevent this script from altering itself.
$orig1="Hel";
$orig2="lo";
$new="Howdy";
# Loading every line in file into an array
my @filecontent = <MYFILE>;
# For each line in the array, perform substitution
foreach $line (@filecontent){
   $line =~ s/$orig1$orig2/$new/g;
#Writing to a different file because I want to make sure it works before altering orginal.
   printf (OUTFILE "$line");
}
close MYFILE;
close OUTFILE;
