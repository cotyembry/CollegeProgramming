#!/usr/bin/perl
#Author: John Coty Embry
#CMPSC 4983 System Admin With Perl
#Date: 6/25/15
#Scenario 3 of Final Projects

system"date +%F > date.txt"; #the +%F option on the date system command gives the time format I needed
system"pwd > userpath.txt"; #this helps me get the user full name later on
open DATE, "./date.txt" or die "Cannot open date.txt: $!";
while(<DATE>) {
	chomp $_;
	@dateline = split('-', $_); #ha, dateline..
}
$date = "$dateline[1]-$dateline[2]-$dateline[0]";
system"last > ${date}_login_summary.txt";
open USER, "./userpath.txt" or die "Cannot open userpath.txt: $!";
open FH, "./${date}_login_summary.txt" or die "Cannot open last.txt: $!";
open ETC, "/etc/passwd" or die "Cannot open /etc/passwd: $!";

#One issue not a part of the assignment that could be fixed is if the "last" command gives two instances of "still logged in" for the same user the script doesn't account for that and adds each occurrance, and also if the time of logging out is the same I could add to the =~ filter I already have to make it where it doesn't add that to the total time i.e two occurrances of a user logging in and out 12:14 - 12:35 and 12:15 - 12:35 (this is a bug in the last command)
while(<USER>) {
    @userarray = split('/', $_); #this helps me get the current users name; $userarray[4] is the username   
    $username{$userarray[4]} = 0;
}
close USER;
close DATE;
system"rm userpath.txt"; #this cleans up the directory
system"rm date.txt";

while (<FH>) { #this is going through the output from the "last" system command
	chomp ($_);
 	@user = split(' ', $_);
#	element $user[9] is the time that the user was logged in during that particular session
	if(exists $username{$user[0]}) { 
		${$username{$user[0]}}[1]++; #this increments the number of logins
		if($user[9] =~ m/\((.)+\)/g) {
			if((!exists $timehash{$user[0]}) || ((exists $timehash{$user[0]}) && ($timehash{$user[0]} ne "$user[0]$user[6]$user[7]$user[8]"))) {
				@usertime = split('\(', $user[9]);
				@usertime = split('\)', $usertime[1]);
				($addhours, $addminutes) = split(':', $usertime[0]);
				$temp = ${$username{$user[0]}}[2]; #look up how to "free" temp later when I no longer need it
				($hours, $minutes) = split(':', $temp);
				$hours = $hours + $addhours;
				$minutes = $minutes + $addminutes;
				while($minutes >= 60) { #this will convert the minutes appropriately
				    $hours++;
				    $minutes -= 60;
				}
				${$username{$user[0]}}[2] = "$hours:$minutes"; #now the time is updated
			}
		   if(!exists $timehash{$user[0]}) {
				$timehash{$user[0]} = "$user[0]$user[6]$user[7]$user[8]";
			}
		}
  	}
	else { #if the user/key doesn't exist we initialize them
		if(defined $user[0]) { #had to write this because it was putting lines that weren't defined as a key
			$username{$user[0]} = ["temp", 1]  if ($user[0] ne wtmp);
			#even if they aren't yet defined in the hash the "last command" gives data for a users login times
			if($user[9] =~ m/\((.)+\)/g) { #this gets the users time in hours and minutes for me
				@usertime = split('\(', $user[9]);
				@usertime = split('\)', $usertime[1]);
				${$username{$user[0]}}[2] = $usertime[0];
			}
		}
 	}
}
close FH;
system"rm ${date}_login_summary.txt";
#now to get the full names of the users
while(<ETC>) {
  	@etcarray = split(':', $_);
 	($fullname, $userid) = split('\+', $etcarray[4]) if $etcarray[4] =~ m/\+/g || $etcarray[5] =~ m/faculty/g;
	for $id (keys %username) {
		if($etcarray[0] =~ m/$id$/g) {
			${$username{$id}}[0] = $fullname;
		}
   }
}
$numberofusers = 0; #I'll use this later in the end of report summary
foreach $var (keys %username) {
# full name, login numbers, total amount of time logged in, average amount of time per user; that is what is in the hash array
    $numberofusers++;
	($hours, $minutes) = split(':', ${$username{$var}}[2]); #this next part takes the average and does the appropriate hours and minutes conversion
	$total_in_minutes = ($hours*60)+$minutes; #hours conversion to minutes followed by addition of the minutes
	$average = $total_in_minutes/${$username{$var}}[1]; #total time in minutes divided by amount of times logged in gives the average
	$backtohours = 0; #I use this in the while loop
 	while($average >= 60) { #this converts the average from minutes back to hours and minute
		$backtohours++;
		$average -= 60;
 	}
	if($average == 1) {
		${$username{$var}}[3] = "$backtohours hours $average minute" if ($backtohours > 1);
		${$username{$var}}[3] = "$backtohours hour $average minute" if $backtohours == 1;
		${$username{$var}}[3] = "$average minute" if $backtohours == 0;
	}
	else {
		${$username{$var}}[3] = "$backtohours hours $average minutes" if $backtohours > 1;
	  	${$username{$var}}[3] = "$backtohours hour $average minutes" if $backtohours == 1;	
		${$username{$var}}[3] = "$average minutes" if $backtohours == 0;	
	}
}
# I could probably do this part up earlier in the code, but to finish the script I'm just going to do the descending part with in the following section of code

#now sort the hash from highest to lowest and print it

$size = scalar @array; #this returns the size of the array, meaning if there are 5 elements it'll return 5
foreach $key (keys %username) { #this for loop puts the time back into strictly minutes so I can compare later and sort the times
    ($thours, $tminutes) = split(':', ${$username{$key}}[2]); #this is the element that gives me the total time logged in
    $timeinminutes = (60 * $thours) + $tminutes;
    ${$username{$key}}[2] = $timeinminutes;
}

#everything else is finished, now I need to sort the array that holds the hashes that holds the array of values, after that do the bottom part and itll be sorted and print the values in a sorted manner. Then created the end of report summary and I'm done with this Script

open FH, "> ./${date}_login_summary.txt" or die "Cannot open ${date}_login_summary.txt: $!";
$totaltime = 0;
$numberoflogins = 0;
foreach(sort { ${$username{$b}}[2] <=> ${${username{$a}}}[2] } keys %username) {
    $myminutes = ${$username{$_}}[2];
    $totaltime += $myminutes; #I'll use this later in the end of report summary
    $numberoflogins += ${$username{$_}}[1];
    $myhours = 0;

    while($myminutes >= 60) {
	$myhours++;
	$myminutes -= 60;
    }
	if($myhours > 0) {
		${$username{$_}}[2] = "$myhours hours $myminutes minutes" if (($myhours != 1) && ($myminutes != 1));
		${$username{$_}}[2] = "$myhours hour $myminutes minutes" if (($myhours == 1) && ($myminutes != 1));				
	}
	else {
		${$username{$_}}[2] = "$myminutes minutes" if $myminutes > 1;
		${$username{$_}}[2] = "$myminutes minute" if $myminutes == 1;
		${$username{$_}}[2] = "0 minutes" if $myminutes == 0;
	}
    print(FH "${$username{$_}}[0] / ${$username{$_}}[1] / ${$username{$_}}[2] / ${$username{$_}}[3]\n");
}
$averagetime = $totaltime/$numberofusers;
#now to convert to hours and minutes
$hours = 0;
while($totaltime >= 60) {
    $hours++;
    $totaltime -= 60;
}
if($hours > 0) {
    $totaltime = "$hours hours $totaltime minutes" if ($hours != 1 && $totaltime != 1);
    $totaltime = "$hours hour $totaltime minutes" if ($hours == 1 && $totaltime != 1);
}
else {
    $totaltime = "$totaltime minutes" if $totaltime > 1;
    $totaltime = "$totaltime minute" if $totaltime == 1;
    $totaltime = "0 minutes" if $totaltime == 0;
}
$hours = 0;
while($averagetime >= 60) {
    $hours++;
    $averagetime -= 60;
}
if($hours > 0) {
    $averagetime = "$hours hours $averagetime minutes" if ($hours != 1 && $averagetime != 1);
    $averagetime = "$hours hour $averagetime minutes" if ($hours == 1 && $averagetime != 1);
}
else {
    $averagetime = "$averagetime minutes" if $averagetime > 1;
    $averagetime = "$averagetime minute" if $averagetime == 1;
    $averagetime = "0 minutes" if $averagetime == 0;
}
print(FH "\n$numberofusers / $numberoflogins / $totaltime / $averagetime\n");
close ETC;
close FH;
