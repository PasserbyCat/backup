#!/usr/bin/perl -w
use strict;
use CGI;
use DBI;
my $cgi = new CGI;
my $seq = $cgi->param("dna");
#my $seq = "ATGATGATGATGAAATAA";
$seq =~ s/T/U/g;
my @seq = split //, $seq;
my @all;
my %compare = qw/
UUU F
UUC F
UUA L
UUG L
CUU L
CUC L
CUA L
CUG L
AUU I
AUC I
AUA I
AUG M
GUU V
GUC V
GUA V
GUG V
UCU S
UCC S
UCA S
UCG S
CCU P
CCC P
CCA P
CCG P
ACU T
ACC T
ACA T
ACG T
GCU A
GCC A
GCA A
GCG A
UAU Y
UAC Y
CAU H
CAC H
CAA Q
CAG Q
AAU N
AAC N
AAA K
AAG K
GAU D
GAC D
GAA E
GAG E
UGU C
UGC C
UGG W
CGU R
CGC R
CGA R
CGG R
AGU S
AGC S
AGA R
AGG R
GGU G
GGC G
GGA G
GGG G
/;

for (my $i = 0; $i < length($seq); $i++) {
  if (@seq[$i] eq "A" && @seq[$i + 1] eq "U" && @seq[$i + 2] eq "G") {
    my $start = $i;
    my $end = 0;
    for (my $j = $end; $j + $i < length($seq); $j += 3) {
      if (@seq[$i + $j] eq "U") {
        if (@seq[$i + $j + 1] eq "A") {
          if (@seq[$i + $j + 2] eq "A") {
            $end = $j;
            last;
          }
          if (@seq[$i + $j + 2] eq "G") {
            $end = $j;
            last;
          }
        }
        if (@seq[$i + $j + 1] eq "G" && @seq[$i + $j + 2] eq "A") {
            $end = $j;
            last;
        }
      }
    }
    if ($end != 0) {
      my $temp = substr $seq, $i, $end + 3;
      push(@all, $temp);
    }
  }
}

my $host = "localhost";
my $id = "PM1092";
my $pw = "PM1092";
my $db = "PM1092";
my $row;
my $dbh = DBI->connect( "DBI:mysql:database=$db;host=$host","$id","$pw",{RaiseError=>1});

print "Content-type: text/html\r\n\r\n";
print "<table border=\"1px\">";
print "<tr><th>mRNA</th><th>mRNA->sequence</th><th>UNI_ID</th><th>UNI_UD->Sequence</th><th>PDB</th></tr>";
for (@all) {
  my @allsub = split //, $_;
  my $check = "";
  print "<tr><td style=\"word-break: break-all;\">$_</td><td style=\"word-break: break-all;\">";
  my $running = "";
  for (my $i = 0; $i < length($_); $i++) {
    $running .= "@allsub[$i]";
    if ($i % 3 == 2) {
      $check .= $compare{$running};
      $running = "";
    }
  }
  my $sth = $dbh->prepare("SELECT * FROM `s1081447` WHERE `Sequence` LIKE '$check' ORDER BY `s1081447`.`PDB` DESC") or die "Coundn't prepare : $DBI::errstr\n";
  $sth->execute() or die "Couldn't execite : $DBI::errstr\n";
  my $row = $sth->fetchrow_hashref();
  my $pdb = $row->{PDB};
  my $ac = $row->{AC};
  my $dataseq = $row->{Sequence};
  my @ref = split /\;/,$pdb;
  my $uni_id = $row->{UNI_ID};
  print "$check</td><td><a href=\"https://www.uniprot.org/uniprot/$ac\">$uni_id</a></td><td style=\"word-break: break-all;\">$dataseq</td><td>";
  for (@ref) {
    print "<a href=\"javascript:void(0)\" onclick=\"handler('$_')\">$_</a>";
    print "<br>";
  }
  print "</td></tr>";
}
print "</table>";

