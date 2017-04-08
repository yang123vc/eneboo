#!/bin/bash

VERSION=$(git describe --tags)
PROJECT="eneboo"
PVERSION="${PROJECT}-${VERSION}-dba"
SRC="eneboo-build-win64-dba"
test -e "$SRC" || { echo "No existe compilacion dbAdmin para Windows 64 bits! (falta carpeta $SRC)"; exit 1; }

echo "Exportando compilacion dbAdmin Windows 64 bits para $PVERSION . . . "

mv "$SRC" "$PVERSION"
tar cf "$PVERSION-win64.tar" "$PVERSION"
bzip2 -9 "$PVERSION-win64.tar"

mkdir "export/" 2>/dev/null
cp "$PVERSION-win64.tar.bz2" "export/"
unlink "$PVERSION-win64.tar.bz2"
rm -Rf "$PVERSION"

echo "Compilacion exportada a: export/$PVERSION-win64.tar.bz2"