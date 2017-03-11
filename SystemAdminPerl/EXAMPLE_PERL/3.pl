#!/usr/local/bin/perl -w

format STDOUT = 
@>>>    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< @|||
$count, $fullname,                      $count
.
# Open /etc/passwd for input
open MYFILE, "< /etc/passwd" or die "Cannot open input file: $!";
open OUTFILE, "> ./3.report" or die "Cannot open output file: $!";

$nonmajorpath = "/home/STUDENTS/nonmajors";
$count = 0;
# Use a while loop to access one line at a time
while ($line = <MYFILE>) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   # Split the line at the colon delimiter to create an array of fields
   @splitline = split (/:/, $line);
   # Check the 6th field of the split line to see if the path includes /home/STUDENTS
   if ($splitline[5] =~ m/$nonmajorpath/g){
      $count++;
      $fullname=$splitline[4];
#      $~ = 'OUTFILE';
       write;
   }
}
close MYFILE;
close OUTFILE;
