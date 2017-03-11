#!/usr/local/bin/perl -w

# Open /etc/passwd for input
open MYFILE, "< /etc/passwd" or die "Cannot open input file: $!";
# Open 4.passwd in local directory for output
open OUTFILE, "> ./4.passwd" or die "Cannot open output file: $!";

$studentpath = "/home/STUDENTS";
$newpass = "junk";
# Use a while loop to access one line at a time
while ($line = <MYFILE>) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   # Split the line at the colon delimiter to create an array of fields
   @splitline = split (/:/, $line);
   # Check the 6th field of the split line to see if the path includes /home/STUDENTS
   if ($splitline[5] =~ m/$studentpath/g){
      # Replace the 2nd field (password) with a new password
      $splitline[1] = $newpass;
      # Join the elements of the array back together and put colon delimiters back in place
      $newline = join(":", @splitline);
   }
   else {
      $newline = $line;
   }
# Write output to new file and append newline
   printf (OUTFILE "$newline\n");
}
close MYFILE;
close OUTFILE;
