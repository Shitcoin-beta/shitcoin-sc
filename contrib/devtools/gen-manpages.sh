#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

SHITCOIND=${SHITCOIND:-$BINDIR/shitcoind}
SHITCOINCLI=${SHITCOINCLI:-$BINDIR/shitcoin-cli}
SHITCOINTX=${SHITCOINTX:-$BINDIR/shitcoin-tx}
SHITCOINQT=${SHITCOINQT:-$BINDIR/qt/shitcoin-qt}

[ ! -x $SHITCOIND ] && echo "$SHITCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
SHTVER=($($SHITCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for shitcoind if --version-string is not set,
# but has different outcomes for shitcoin-qt and shitcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$SHITCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $SHITCOIND $SHITCOINCLI $SHITCOINTX $SHITCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${SHTVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${SHTVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
