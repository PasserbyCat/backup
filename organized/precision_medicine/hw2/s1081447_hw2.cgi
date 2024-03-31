#!/usr/bin/perl -w
use strict;
use CGI;
use DBI;
my $cgi = new CGI;
my $uni;
my $ac;
my $ec;
my $pdb;
my $seq;
my $inp = $cgi->param("inp");
my $host = "localhost";
my $id = "PM1092";
my $pw = "PM1092";
my $db = "PM1092";
my $row;
my $dbh = DBI->connect( "DBI:mysql:database=$db;host=$host","$id","$pw",{RaiseError=>1});
my $sth;

if (length($inp)<8) {
  $sth = $dbh->prepare("SELECT * FROM `s1081447` WHERE `AC` LIKE '$inp'") or die "Coundn't prepare : $DBI::errstr\n";
  $sth->execute() or die "Couldn't execite : $DBI::errstr\n";
  $row= $sth->fetchrow_hashref();
  $ac = $inp;
  $uni = $row->{UNI_ID};
  $ec = $row->{EC};
  $pdb = $row->{PDB};
  $seq = $row->{Sequence};
}
else {
  $sth = $dbh->prepare("SELECT * FROM `s1081447` WHERE `UNI_ID` LIKE '$inp'") or die "Coundn't prepare : $DBI::errstr\n";
  $sth->execute() or die "Couldn't execite : $DBI::errstr\n";
  $row = $sth->fetchrow_hashref();
  $ac = $row->{AC};
  $uni = $inp;
  $ec = $row->{EC};
  $pdb = $row->{PDB};
  $seq = $row->{Sequence};
}
my @ref = split /\;/,$pdb; 
print "Content-type: text/html\r\n\r\n";
print "<table>";
print "<tr><td>UNI_ID</td><td>$uni</td></tr>";
print "<tr><td>AC</td><td>$ac</td></tr>";
print "<tr><td>EC</td><td>$ec</td></tr>";

print "<tr><td>PDB</td><td>";
for (@ref) {
  print "<a href=\"javascript:void(0)\" onclick=\"handler('$_')\">$_</a>";
}
print "</td></tr>";

print "<tr><td>Sequence</td><td style=\"word-break: break-all;\" >$seq</td></tr>";
print "</table>";
