#!/usr/local/bin/perl

open (PS, "ps -aef|");

printf("Enter username to kill: ");
$requesteduser = <STDIN>;
chomp ($requesteduser);
@results = <PS>;
delete $results[0];
@results = sort (@results);
$firstline = @results[0];
@splitline = split(/[ ]+/, $firstline);
$currentuser = $splitline[0];
$count = 0;
foreach $line (@results) {
   printf("$line");
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   @splitline = split(/[ ]+/, $line); 
   $owner = $splitline[0];
   if ($requesteduser eq $owner) {
      $cid = $splitline[1];
      $pid = $splitline[2];
      if ($pid == 1 || $splitline[7] =~ m/.\pl|perl/) {
         printf("skipping $line\n");
      }
      else {
         $killcommand = "kill -9 $cid";
         printf("killing: $killcommand\n");
      }
   }
   else {
      printf("skipping $owner\n");
   }
}

close PS;
