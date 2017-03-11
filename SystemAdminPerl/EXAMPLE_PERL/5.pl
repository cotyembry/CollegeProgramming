#!/usr/local/bin/perl

# Open 5.in for input
open MYFILE, "< ./5.in" or die "Cannot open input file: $!";
open WORD3, "< ./5.three" or die "Cannot open input file: $!";
open WORD4, "< ./5.four" or die "Cannot open input file: $!";
open OUTFILE, "> ./5.result" or die "Cannot open output file: $!";

@three = <WORD3>; 
@four = <WORD4>; 
$three_linecount = @three;
$four_linecount = @four;

# Use a while loop to access one line at a time
while ($line = <MYFILE>) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   # Split the line at the comma-space delimiter separating last name from first name
   $name = $line;
   @splitline = split (/, /, $line);
   # HERE 
   $last4 = lc substr $splitline[0], 0, 4;
   $first3 = lc substr $splitline[1], 0, 3;
   $loginid = "$first3$last4";
   $num = int(rand $three_linecount);
   $pass3 = $three[int(rand $three_linecount)];
   chomp ($pass3);
   $pass4 = $four[int(rand $four_linecount)];
   chomp ($pass4);
   $passwd = $pass3 . "_" . $pass4;
   
   printf(OUTFILE "NAME: $name\nLoginid: $loginid\nPassword: $passwd\n\n");

   
}
close MYFILE;
close WORD3;
close WORD4;
close OUTFILE;
