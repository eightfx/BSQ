#!/usr/bin/perl
use strict;

die "Usage: program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

# ファイル 'map.txt' を書き込みモードでオープン
open(my $fh, '>', 'map.txt') or die "Could not open file 'map.txt' $!";

# ファイルハンドルにヘッダを書き込む
print $fh "$y.ox\n";

for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print $fh "o";
        } else {
            print $fh ".";
        }
    }
    print $fh "\n";
}

# ファイルハンドルを閉じる
close($fh);
