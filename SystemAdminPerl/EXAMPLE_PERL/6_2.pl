#!/usr/local/bin/perl

open (PS, "ps -aef|");
open OUTFILE, "> ./6.result" or die "Cannot open output file: $!";

@results = <PS>;
@junk = sort @results;
foreach $line (@junk) {
#foreach $line (sort @results) {
   chomp($line); # removes carriage and newline meta characters for both unix and windows line returns
   printf("Line is $line\n");
   
}
close PS;
close OUTFILE;
