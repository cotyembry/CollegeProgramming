#!/usr/local/bin/perl

%roster_id_hash;

open ROSTER_FILE, "< ./enrollment.txt"or die "Cannot open $!";
while ($roster_line = <ROSTER_FILE>) {
   chomp($roster_line);
   @split_roster_line = split (/\|/, $roster_line);
   $roster_id_hash{ $split_roster_line[0] } = $roster_line;
}
close ROSTER_FILE;

for $student (sort keys %roster_id_hash) {
   printf "$roster_id_hash{$student}\n";
}
