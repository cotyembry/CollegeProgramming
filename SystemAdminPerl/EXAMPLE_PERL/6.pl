#!/usr/local/bin/perl

open (PS, "ps -aef|");
open OUTFILE, "> ./6.result" or die "Cannot open output file: $!";

@results = <PS>;
delete $results[0];
@results = sort (@results);
$firstline = @results[0];
@splitline = split(/[ ]+/, $firstline);
$currentuser = $splitline[0];
$count = 0;
foreach $line (@results) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   @splitline = split(/[ ]+/, $line); 
   $owner = $splitline[0];
   if ($currentuser eq $owner) {
      $count++;
      printf("$count: $line\n");
   }
   else {
      printf("$currentuser: $count\n");
      $count = 1;
      $currentuser = $owner;
      printf("Switched to $currentuser\n");
      printf("$count: $line\n");
   }
}
#Must print final user's count
printf("$currentuser: $count\n");

close PS;
close OUTFILE;
