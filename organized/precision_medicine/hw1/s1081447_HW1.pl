#!/usr/bin/perl -w
use strict;
use DBI;

my $host = "localhost";
my $id = "PM1092";
my $pw = "PM1092";
my $db = "PM1092";
my $dbh = DBI->connect( "DBI:mysql:database=$db;host=$host","$id","$pw",{RaiseError=>1});

open FH, "uniprot_sprot.dat" or die;
#open FH, "P60043.txt" or die;
#open FH, "Q8N3J2.txt" or die;
my $ID;
my $AC;
my $EC;
my $PDB;
my $SQ;
my $Estart = 0;
my $Pstart = 0;
my $Sstart = 0;

foreach (<FH>) {
  chomp;
  if (/^ID\s+(\S+)/) {
    $ID = $1;
    $AC = "";
    $EC = "";
    $PDB = "";
    $SQ = "";
    next;
  }
  if (/^AC\s+(\S.*);$/) {
    my @ac = split / /,$1;
    for (@ac) {
      $AC .= $_;
    }
    next;
  }
  if (/^DE\s+EC=(\S+);$/) {
    if ($Estart == 0) {
      $EC = $1;
      $Estart = 1;
    }
    elsif ($1 !~ $EC) {
      $EC .= ";";
      $EC .= $1;
    }
    next;
  }
  if (/^DE\s+EC=(\S+)/) {
    if ($Estart == 0) {
      $EC = $1;
      $Estart = 1;
    }
    elsif ($1 !~ $EC) {
      $EC .= ";";
      $EC .= $1;
    }
    next;
  }
  if (/^DR\s+PDB;\s+(\S+);.*/) {
    if ($Pstart == 0) {
      $PDB = $1;
      $Pstart = 1;
    }
    elsif ($PDB !~ $1) {
      $PDB .= ";";
      $PDB .= $1;
    }
    next;
  }
  if (/^\/\/$/) {
    if ($Estart == 1) {
      #print "$ID\n$AC\n$EC\n$PDB\n$SQ\n"
      my $sth = $dbh->prepare("INSERT INTO `s1081447` (`UNI_ID`, `AC`, `EC`, `PDB`, `Sequence`) VALUES ('$ID', '$AC', '$EC', '$PDB', '$SQ')") or die "Coundn't prepare : $DBI::errstr\n";
      $sth->execute() or die "Couldn't execite : $DBI::errstr\n";
    }
    $Estart = 0;
    $Pstart = 0;
    $Sstart = 0;
    next;
  }
  if ($Sstart == 1) {
    my @sq = split / /,$_;
    for (@sq) {
      chomp;
      $SQ .= "$_";
    }
  }
  if (/^SQ\s+SEQUENCE\s+/) {
    $Sstart = 1;
    next;
  }
}
close FH;