#! /usr/local/bin/perl

$file = "sys_command.pl";
printf "before\n";
system("chmod ugo+rwx ${file}");
system("ls -al ${file}");
printf "between\n";
system("chmod o-rwx $file");
system("ls -al $file");
printf "end\n";
