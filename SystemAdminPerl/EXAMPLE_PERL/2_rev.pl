#!/usr/local/bin/perl -w

#open MYFILE, "+< /home/faculty/mkt/admin/PERL/2.txt" or die "Cannot open file: $!";
open MYFILE, "< /home/faculty/mkt/admin/PERL/2.txt" or die "Cannot open file: $!";
open OUTFILE, "> /home/faculty/mkt/admin/PERL/2.txt2" ;

$orig1="Hel";
$orig2="lo";
$new="Howdy";
my @filecontent = <MYFILE>;
foreach $line (@filecontent){
   $line =~ s/$orig1$orig2/$new/g;
   printf (OUTFILE "$line");
}
close MYFILE;
close OUTFILE;
