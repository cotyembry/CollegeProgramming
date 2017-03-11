#!/usr/local/bin/perl -w

#messing around with file handeling

open MYFILE, "< ./JoyfulNoise.txt" or die "Cannot open input file: $!";
open($fh, '>', 'JoyfulNoiseParagraphed.txt');
$occurrance = 0;
LINE:	while ($line = <MYFILE>) {
			if($line =~ m/\[(.)+\]/gi) {
				print $fh "$line\n";
				$occurrance = 1;		
			}
			if($occurrance == 1)	{
				until($line =~ m/\[(.)+\]/gi) {
					print $fh "$line\n";
					next LINE;
				}
				$occurrance = 0;
			}
		}

close $fh;
close MYFILE;
